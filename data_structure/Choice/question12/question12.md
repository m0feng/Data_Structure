### 1.题目名称

 **点击窗口**

### 2.代码行数

60行

### 3.算法思想

利用哈希表来存储窗口信息。

### 4.主要/核心函数分析

```c++
#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>
using namespace std;

struct Matrix {
    int x[2];
    int y[2];
};

int main() {
    fstream filein;
    filein.open("../test.txt",ios::in);
    int n, m;
    filein >> n >> m;

    unordered_map<int, Matrix> windows; // 使用哈希表存储窗口信息
    for (int i = 0; i < n; i++) {
        Matrix matrix;
        for (int j = 0; j < 2; j++) {
            filein >> matrix.x[j] >> matrix.y[j];
        }
        windows[i + 1] = matrix; // 窗口序号从1开始
    }

    vector<int> answer(m, 0);
    for (int i = 0; i < m; i++) {
        int x, y;
        filein >> x >> y;

        int clickedWindow = -1;
        for (auto it = windows.begin(); it != windows.end(); ++it) {            //找到目标窗口
            const Matrix& matrix = it->second;
            if (x >= matrix.x[0] && x <= matrix.x[1] && y >= matrix.y[0] && y <= matrix.y[1]) {
                clickedWindow = it->first;
                break;
            }
        }

        answer[i] = clickedWindow;
        if (clickedWindow != -1) {
            // 将点击的窗口放到哈希表的最前面
            Matrix clickedMatrix = windows[clickedWindow];
            windows.erase(clickedWindow);
            windows[clickedWindow] = clickedMatrix;
        }
    }

    for (int i = 0; i < m; i++) {
        if (answer[i] != -1) {
            cout << answer[i] << endl;
        } else {
            cout << "IGNORED" << endl;
        }
    }
    filein.close();
    return 0;
}
```

利用unordered_map这种数据结构来存储窗口信息。找到窗口，则置到hash表最前面。

### 5.测试数据(规模,测试次数)

规模:(1 ≤ N ≤ 10,1 ≤ M ≤ 10)	 x, y 坐标分别不超过 2559 和1439。

测试次数:1

测试用例:见测试文件

### 6.运行结果

```txt
F:\data_structure\Choice\question12\cmake-build-debug\question12.exe
2
1
1
IGNORED

进程已结束,退出代码0

```

### 7.时间复杂度分析

各操作时间复杂度均小于等于O(n)，因此代码复杂度为O(n)。

### 8.结果截屏图片

![](F:\data_structure\Choice\question12\output.png)

### 9.心得体会

对于Hash表的应用更为熟悉与理解。