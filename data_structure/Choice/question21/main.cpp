#include <bits/stdc++.h>

using namespace std;

int n,m;

struct Tree{
    string data;
    vector<Tree*> Child;
};



Tree* Deal(string json,string ct){          //处理Json数据
    Tree *root= new Tree;
    root->data=ct;
    int k=0;
    if(json[0]=='{'){
        json.erase(json.begin());
    }
    if(json[json.size()-1]=='}'){
        json.erase(json.end()-1);
    }
    Tree *p=new Tree;
    while(k<json.size()){
        if(json[k]=='{'){
            string temp="";
            k+=1;
            while(json[k]!='}'){
                temp+=json[k];
                k++;
            }
            k++;
            root->Child.push_back(Deal(temp,p->data));  //进行递归,遍历该json
            p=new Tree;
        }
        if(json[k]=='"'){
            k+=1;
            while(json[k]!='"'){
                if(json[k]=='\\'){
                    k++;
                    p->data+=json[k];
                }else
                    p->data+=json[k];
                k++;
            }
            k++;
        }
        if(json[k]==':'){
            k+=2;
            Tree *q=new Tree;
            if(json[k]=='"'){
                k+=1;
                while(json[k]!='"'){
                    if(json[k]=='\\'){
                        k++;
                        q->data+=json[k];
                    }else
                        q->data+=json[k];
                    k++;
                }
                k++;
                p->Child.push_back(q);
                root->Child.push_back(p);
                p=new Tree;
            }
        }

        if(json[k]==' ' || json[k]==','){
            k++;
            continue;
        }

    }
    return root;
}

void findValue(Tree* root, const std::string& ct) { //查找相关值
    string cp = "", cq = "";
    int flag=0;
    for (int j = 0; j < ct.size(); j++) {
        if (ct[j] == '.') {
            flag = 1;
            continue;
        }
        if (!flag) {
            cp += ct[j];
        } else {
            cq += ct[j];
        }
    }
    for (int j = 0; j < root->Child.size(); j++) {
        if (root->Child[j]->data == cp) {
            if (cq == "") {
                if (root->Child[j]->Child[0]->Child.size() > 0) {
                    std::cout << "OBJECT" << std::endl;
                    return;
                } else {
                    std::cout << "STRING" << " " << root->Child[j]->Child[0]->data << std::endl;
                    return;
                }
            } else {
                findValue(root->Child[j], cq);  //进入Json寻找
                return;
            }
        }
    }
    cout<<"NOTEXIST"<<endl;
}





int main(){
    fstream filein;
    filein.open("../Json.txt",ios::in);
    string json="";
    filein>>n>>m;
    string temp;
    for(int i=0;i<=n;i++){
        getline(filein,temp);
        json+=temp;
    }
    Tree *root=Deal(json,"");
    string ct;
    for(int i=0;i<m;i++) {
        filein >> ct;

        findValue(root,ct);  //寻找节点
    }
    filein.close();
    return 0;
}