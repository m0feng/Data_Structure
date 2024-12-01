#ifndef QUESTION_1_WINDOWS_H
#define QUESTION_1_WINDOWS_H
#include <bits/stdc++.h>
#include <Windows.h>
#include <tlhelp32.h>
#include <chrono>
#include <psapi.h>
using namespace std;
// 进程信息结构体
struct ProcessInfo {
    string processName;     // 进程名称
    DWORD memoryUsage;           // 内存使用量（示例使用DWORD表示）
    FILETIME creationTime;       // 进程创建时间
    FILETIME exitTime;           // 进程退出时间（已退出的进程）
    double lastTime;
    bool status;
    ProcessInfo(){
        lastTime=0;
    }
};
vector<ProcessInfo> getProcessInfo();
void printProcessInfo(ProcessInfo& processInfo,bool status);
extern map<string,int> TimeLast;
#endif //QUESTION_1_WINDOWS_H

