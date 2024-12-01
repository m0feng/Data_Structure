### 1.题目名称

**Huffman编码与解码**

### 2.代码行数

228行

### 3.算法思想

#### 1.创建Huffman树

每次选取最小的两个节点，从vector中拿出来，并开一个新的节点，左右孩子节点指向拿出的两个节点，将该节点插入vector。

#### 2.编码

从根节点开始，如果往左子树走则编码左移并低位置0，反之编码左移置1。找到目标节点则返回编码。

这里为了移位方便，我初始编码为1，后续转二进制会对之进行处理。

#### 3.编码以比特位写入文件

每次8个bit写入文件，如最后剩余bit数不足8个则左移后写入文件。

#### 4.解码

按照获取的编码对Huffman树进行遍历，找到叶子节点则退出，从根节点重新开始遍历。

### 4.主要/核心函数分析

#### CreateTree

```c++
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
```

通过循环不断地取出字符频率统计数组中频率最小的两个节点，合并成一个新的节点，然后将新节点加入字符频率统计数组。重复这个过程，直到字符频率统计数组中只剩下一个节点，这个节点即为赫夫曼树的根节点。

#### Huffman_Encode

```c++
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
```

从根节点开始，如果往左子树走则编码左移并低位置0，反之编码左移置1。找到目标节点则返回编码。

这里为了移位方便，我初始编码为1，后续转二进制会对之进行处理。

#### writeEncodedTextToFile

```c++
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
```

以二进制模式写入文件，对编码按每8个bit写入文件，如最后剩余bit数不足8个则左移后写入文件。

#### decodeText

```c++
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
```

按照获取的编码对Huffman树进行遍历，如果为0则往左子树遍历，反之则往右子树遍历，找到叶子节点则退出，从根节点重新开始遍历。

### 5.测试数据(规模,测试次数)

规模:不少于5000字符的英文文章

测试次数:1

测试用例:见测试文件

### 6.运行结果

#### Huffman.txt

```txt
2		23		001001110
10		161		001000
13		161		1111111
32		1827		101
%		2		1111110011001
'		1		11111100111010
(		19		1111110101
)		21		1111110110
,		110		1101000
-		49		10010001
.		104		1001001
/		1		11111100111011
0		2		1111110011100
1		6		11010010110
2		3		1111110111101
3		1		11111100110101
4		1		11111100110100
9		2		1111110011000
:		1		11111101111000
;		5		111111011100
A		22		001001101
B		4		111111001111
C		21		001001010
D		25		110100100
E		7		11010010111
F		13		1101001010
G		15		1101001101
H		6		111111011111
I		24		100100000
L		1		11111101111001
M		22		001001011
N		12		0010011111
O		14		1101001100
P		12		1001000011
R		5		111111011101
S		12		1001000010
T		32		111111000
U		8		11111100100
V		2		1111110011011
W		11		0010011110
a		899		1100
b		135		1111000
c		416		01101
d		356		00101
e		1295		000
f		233		110101
g		217		100101
h		369		01100
i		856		1000
j		22		001001100
k		42		00100100
l		454		10011
m		271		110111
n		750		0101
o		829		0111
p		275		111101
q		19		1111110100
r		703		0100
s		696		0011
t		1080		1110
u		283		111110
v		132		1101101
w		123		1101100
x		31		110100111
y		138		1111001
z		8		11111100101

```

#### code.dat

由于是比特位写入，因此这里给出编码，不给出文件内容。

```txt
0010011100010001111111101111111001100111111100111010111111010111111101101101000100100011001001111111001110111111110011100110100101101111110111101111111001101011111110011010011111100110001111110111100011111101110000100110111111100111100100101011010010011010010111110100101011010011011111110111111001000001111110111100100100101100100111111101001100100100001111111101110110010000101111110001111110010011111100110110010011110110011110000110100101000110101100101011001000001001100001001001001111011101010111111101111111010001000011111011111011011011101100110100111111100111111100101
```

#### decode.txt

```txt
2		23		001001110
10		161		001000
13		161		1111111
32		1827		101
%		2		1111110011001
'		1		11111100111010
(		19		1111110101
)		21		1111110110
,		110		1101000
-		49		10010001
.		104		1001001
/		1		11111100111011
0		2		1111110011100
1		6		11010010110
2		3		1111110111101
3		1		11111100110101
4		1		11111100110100
9		2		1111110011000
:		1		11111101111000
;		5		111111011100
A		22		001001101
B		4		111111001111
C		21		001001010
D		25		110100100
E		7		11010010111
F		13		1101001010
G		15		1101001101
H		6		111111011111
I		24		100100000
L		1		11111101111001
M		22		001001011
N		12		0010011111
O		14		1101001100
P		12		1001000011
R		5		111111011101
S		12		1001000010
T		32		111111000
U		8		11111100100
V		2		1111110011011
W		11		0010011110
a		899		1100
b		135		1111000
c		416		01101
d		356		00101
e		1295		000
f		233		110101
g		217		100101
h		369		01100
i		856		1000
j		22		001001100
k		42		00100100
l		454		10011
m		271		110111
n		750		0101
o		829		0111
p		275		111101
q		19		1111110100
r		703		0100
s		696		0011
t		1080		1110
u		283		111110
v		132		1101101
w		123		1101100
x		31		110100111
y		138		1111001
z		8		11111100101

```



### 7.时间复杂度分析

`CreateTree`循环内主要复杂度取决于排序的操作，时间复杂度为o(n^2^logn)

`Huffman_Encode`遍历节点时间复杂度为O(n)

`writeEncodedTextToFile`：

1. 将每个字符的编码转换为二进制字符串：O(n)
2. 将这些二进制字符串连接成一个大的二进制字符串：O(n)
3. 将这个大的二进制字符串分成 8 位一组：O(n)
4. 将这些 8 位一组的二进制字符串写入文件：O(n)

因此，整体上，这段代码的时间复杂度为 O(n)。

`decodeText`:

1. 遍历编码文本并解码字符：O(n)
2. 将叶节点的权重和编码添加到两个向量中：O(n)
3. 将解码文本和叶节点的权重和编码写入文件中的过程：O(n)

因此程序复杂度为O(n^2^logn)。

### 8.结果截屏图片

![](F:\data_structure\Must\question_3\output.png)

### 9.心得体会

通过该题,对Huffman树的基本性质有了更深入的了解，同时,对Huffman在编码以及解码这一方面的应用以及实现更为熟悉了。