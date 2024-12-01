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