### 1.题目名称

**魔法优惠券**

### 2.代码行数

47行

### 3.算法思想

先从小到大排序，从小到大遍历。

再从大到小遍历。

### 4.主要/核心函数分析

#### FindMax

```c++
int FindMax(vector<ll> value ,vector<ll> cons,int n,int m){        //寻找最大回报
    sort(value.begin(),value.end());
    sort(cons.begin(),cons.end());
    ll sum=0;
    for(int i=0;i<min(n,m);i++){        //从小往大遍历
        if(value[i]<0 && cons[i]<0)    sum+=value[i]*cons[i];
    }
    reverse(value.begin(), value.end());
    reverse(cons.begin(),cons.end());
    for(int i=0;i<min(n,m);i++){         //从大往小遍历
        if(value[i]>0 && cons[i]>0)    sum+=value[i]*cons[i];
    }
    return sum;
}
```

先从小到大排序，从小到大遍历,优惠卷及价值均为负则相乘。

再倒序，从前往后遍历，优惠卷及价值均为正则相乘。

### 5.测试数据(规模,测试次数)

规模:N和M在[1,10^6^]之间，所有的数据大小不超过2^30^.

测试次数:3

测试用例:见测试文件

### 6.运行结果

第i行对应第i个测试用例.

```c++
43
49
1
```

### 7.时间复杂度分析

时间复杂度最大的是sort排序，因此时间复杂度为O(nlogn)。

### 8.结果截屏图片

![](F:\data_structure\Choice\question11\output.png)

### 9.心得体会

对这种求最大回报的题目有了更深的认识与理解。