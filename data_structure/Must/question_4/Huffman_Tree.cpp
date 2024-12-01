#include "Huffman_Tree.h"
#include <bits/stdc++.h>
using namespace std;

Huffman::Huffman() {
    root= nullptr;
}

Huffman::~Huffman() {
    root= nullptr;
}

bool cmp(CharSum *p, CharSum *q) {
    return p->Sum<q->Sum;
}


string To_Binary(int t){
    string rs="";
    while(t){
        rs = to_string(t&1)+rs;
        t>>=1;
    }
    rs.erase(rs.begin());
    return rs;
}


void Huffman::CreateTree(vector<CharSum*> cs){
    CharSum *temp;
    while(cs.size()>1){        //每次寻找两个最小的合成一个节点
        sort(cs.begin(),cs.end(),cmp);
        temp=new CharSum;
        temp->left=cs.front();
        cs.erase(cs.begin());
        temp->right=cs.front();
        cs.erase(cs.begin());
        temp->ch=temp->left->ch+"+"+temp->right->ch;
        temp->Sum=temp->left->Sum+temp->right->Sum;
        cs.push_back(temp);
    }
    root=cs.front();
    cs.pop_back();
    return;
}

void Huffman::Huffman_Encode(CharSum *head , CharSum **p ,int ct) {
    if((*p)->ch==head->ch){
        (*p)->Encoding=ct;
        return ;
    }

    if(head->left!= nullptr){
        ct<<=1;    //置0
        Huffman_Encode(head->left,p,ct);
        ct>>=1;
    }

    if(head->right!= nullptr){
        ct=(ct<<1)|1;   //置1
        Huffman_Encode(head->right,p,ct);
        ct>>=1;
    }
}

CharSum *Huffman::Get_Root() {
    return root;
}

void Huffman::writeEncodedTextToFile(vector<CharSum *> cs) {
    string encodedText="";
    for(int i=0;i<cs.size();i++){
        encodedText+= To_Binary(cs[i]->Encoding);
    }

    fstream fileout;
    fileout.open("../code.dat",ios::out|ios::binary);
    if(!fileout.is_open()){
        cout<<"Write Error"<<endl;
        exit(0);
    }

    bitset<8> bits;
    for (char c : encodedText) {         //8位一组写入文件
        bits <<= 1;
        if (c == '1') {
            bits |= 1;
        }
        if (bits.size() == 8) {
            fileout.put(static_cast<unsigned char>(bits.to_ulong()));
            bits.reset();
        }
    }
    if (bits.size() > 0) {
        bits <<= (8 - bits.size());
        fileout.put(static_cast<unsigned char>(bits.to_ulong()));
    }
    fileout.close();
}

void Huffman::decodeText(const string& encodedText) {
    string decodedText;
    CharSum* current = root;
    vector<int> Count;
    vector<int> Huffman;
    for (char c : encodedText) {          //照着遍历,找到节点则解码成功
        if (c == '0') {
            current = current->left;
        } else if (c == '1') {
            current = current->right;
        }

        if (current->left == nullptr && current->right == nullptr) {
            decodedText += current->ch;
            Count.push_back(current->Sum);
            Huffman.push_back(current->Encoding);
            current = root;
        }
    }

    fstream fileout;
    fileout.open("../decode.txt",ios::out);
    if(!fileout.is_open()){
        cout<<"Write Decode.txt Error"<<endl;
        exit(0);
    }
    for(auto it : decodedText){
        char kt=it;
        if (kt >= 0 && kt <= 32) {
            fileout << (int)kt <<"\t\t"<< Count.front()<<"\t\t"<<To_Binary(Huffman.front())<<std::endl;
        } else {
            fileout << kt <<"\t\t"<< Count.front()<<"\t\t"<<To_Binary(Huffman.front())<<std::endl;
        }
        Count.erase(Count.begin());
        Huffman.erase(Huffman.begin());
    }
    fileout.close();
    return ;
}