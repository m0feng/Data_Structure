### 1.题目名称

地铁修建 

### 2.代码行数

69行

### 3.算法思想

#### 并查集

利用并查集来判断两个节点是否已经在一个树中。

#### Krustal

利用Krustal算法生成最小生成树，当加入某一条边使得两个目标节点存在于同一颗树时直接返回该边的权值即可。

### 4.主要/核心函数分析

#### Krustal

```c++
void Krustal(){
    Initial();
    for(int i=0;i<m;i++){
        int x= find(e[i].u);
        int y= find(e[i].v);
        if(x!=y){
            if(Union(x,y)){
                if(find(1)== find(n)){    //找到最大边 直接退出
                    cout<<e[i].w;
                    break;
                }
            }
        }
    }
}
```

利用了Krustal算法的思想,边从小到大插入，因此可以直接找到题目要求的边。

### 5.测试数据(规模,测试次数)

规模:1 ≤ *n* ≤ 100000，1 ≤ *m* ≤ 200000，1 ≤ *a*, *b* ≤ *n*，1 ≤ *c* ≤ 1000000。

测试次数:自行测试1次+参考CSP官网该题测试次数。

测试用例:见自行输入

### 6.运行结果

```c++
F:\data_structure\Must\question_5\cmake-build-debug\question_5.exe
6 6
1 2 4
2 3 4
3 6 7
1 4 2
4 5 5
5 6 6
6
进程已结束,退出代码0

```



### 7.时间复杂度分析

该代码主要利用了Krustal算法，时间复杂度为O(nlogn)。

### 8.结果截屏图片

![](F:\data_structure\Must\question_4\output.png)

### 9.心得体会

对最小生成树以及Krustal算法有了更为深入的理解。

