#include <bits/stdc++.h>
#include "Huffman_Tree.h"
using namespace std;

vector<CharSum*> CS;

int main(){
    fstream filein;
    filein.open("../source.txt",ios::in);
    if(!filein.is_open()){
        cout<<"Read Error"<<endl;
        exit(0);
    }
    char ch;
    map<char,int> CharMap;
    while(filein>>noskipws>>ch){
        CharMap[ch]+=1;
    }
    filein.close();
    CharSum *p;
    for(auto &it:CharMap){
        p=new CharSum;
        p->ch=it.first;
        p->Sum=it.second;
        CS.push_back(p);
    }
    Huffman hft;
    hft.CreateTree(CS);
    cout<<"Huffman 构建完成"<<endl;
    fstream fileout;                //task1
    fileout.open("../Huffman.txt",ios::out);
    if(!fileout.is_open()){
        cout<<"Write Error"<<endl;
        exit(0);
    }
    string encodedText="";
    for(int i=0;i<CS.size();i++){
        hft.Huffman_Encode(hft.Get_Root(),&CS[i],1);
        encodedText+= To_Binary(CS[i]->Encoding);
        char kt=CS[i]->ch[0];
        if (kt >= 0 && kt <= 32) {
            fileout << (int)kt << "\t\t" << CS[i]->Sum << "\t\t" << To_Binary(CS[i]->Encoding) << std::endl;
        } else {
            fileout << kt << "\t\t" << CS[i]->Sum << "\t\t" << To_Binary(CS[i]->Encoding) << std::endl;
        }
    }
    fileout.close();
    fileout.clear();

    hft.writeEncodedTextToFile(CS);     //编码写入文件
    hft.decodeText(encodedText);           //解码
    return 0;
}