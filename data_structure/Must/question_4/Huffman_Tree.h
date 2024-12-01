#ifndef QUESTION_4_HUFFMAN_TREE_H
#define QUESTION_4_HUFFMAN_TREE_H
#include <bits/stdc++.h>
using namespace std;

struct CharSum{        //记录字符相关属性
    string ch;
    int Sum;
    CharSum *left,*right;    //方便构建Huffman
    int Encoding;    //字符编码
    CharSum(){
        ch="";
        Sum=0;
        left=right= nullptr;
        Encoding=1;
    }
};

extern vector<CharSum*> CS;        //字符集
bool cmp(CharSum *p,CharSum *q);
string To_Binary(int t);    //转二进制
class Huffman{
    private:
        CharSum *root;
    public:
        Huffman();
        ~Huffman();
        CharSum *Get_Root();
        void CreateTree(vector<CharSum*> cs);     //创建Huffman
        void Huffman_Encode(CharSum *head,CharSum **p,int ct);  //字符编码
        void writeEncodedTextToFile(vector<CharSum*> cs);       //编码写入文件
        void decodeText(const string& encodedText) ;        //解码
};
#endif //QUESTION_4_HUFFMAN_TREE_H
