#include "Wind.h"
using namespace std;

FILETIME GetSystemUpTime() {           //获取系统开机时间
    ULONGLONG uptime = GetTickCount64();

    FILETIME ft;
    GetSystemTimeAsFileTime(&ft);

    ULARGE_INTEGER uli;
    uli.LowPart = ft.dwLowDateTime;
    uli.HighPart = ft.dwHighDateTime;

    ULONGLONG currentTimestamp = uli.QuadPart;
    ULONGLONG uptime100ns = currentTimestamp - (uptime * 10000); // 转换为100纳秒单位

    uli.QuadPart = uptime100ns;

    ft.dwLowDateTime = uli.LowPart;
    ft.dwHighDateTime = uli.HighPart;

    return ft;
}



// 将 FILETIME 转换为北京时间
tm convertFileTimeToBeijingTime(const FILETIME& fileTime)
{
    // 将 FILETIME 转换为 SYSTEMTIME
    SYSTEMTIME systemTime;
    FileTimeToSystemTime(&fileTime, &systemTime);

    // 转换为 struct tm 结构体
    std::tm beijingTime;
    beijingTime.tm_year = systemTime.wYear - 1900;
    beijingTime.tm_mon = systemTime.wMonth - 1;
    beijingTime.tm_mday = systemTime.wDay;
    beijingTime.tm_hour = systemTime.wHour + 8;  // 加上北京时间的偏移量
    beijingTime.tm_min = systemTime.wMinute;
    beijingTime.tm_sec = systemTime.wSecond;
    beijingTime.tm_isdst = -1;  // 自动判断夏令时

    // 调整到正确的范围
    std::mktime(&beijingTime);

    return beijingTime;
}

// 获取当前系统的进程信息
vector<ProcessInfo> getProcessInfo() {
    std::vector<ProcessInfo> processList;

    // 获取进程快照
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE) {
        std::cerr << "Failed to create process snapshot." << std::endl;
        return processList;
    }

    // 设置进程快照结构体
    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32);

    // 遍历进程信息
    if (Process32First(hSnapshot, &pe32)) {
        do {
            ProcessInfo processInfo;
            processInfo.processName = pe32.szExeFile;

            // 获取进程句柄
            HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, pe32.th32ProcessID);
            if (hProcess != nullptr) {
                PROCESS_MEMORY_COUNTERS_EX pmc;
                pmc.cb = sizeof(PROCESS_MEMORY_COUNTERS_EX);

                // 获取进程内存信息
                if (GetProcessMemoryInfo(hProcess, reinterpret_cast<PROCESS_MEMORY_COUNTERS *>(&pmc), sizeof(pmc))) {
                    // 内存使用量
                    SIZE_T memoryUsage = pmc.WorkingSetSize;
                    processInfo.memoryUsage = memoryUsage;
                } else {
                    processInfo.memoryUsage = 0;
                }


                FILETIME creationTime, exitTime, kernelTime, userTime;
                GetProcessTimes(hProcess, &creationTime, &exitTime, &kernelTime, &userTime);

                processInfo.creationTime = creationTime;
                processInfo.exitTime = exitTime;

                DWORD exitCode;
                if (GetExitCodeProcess(hProcess, &exitCode)) {
                    if (exitCode != STILL_ACTIVE) {
                        // 进程已结束
                        processInfo.exitTime = processInfo.creationTime;
                        processInfo.status = 0;
                        for(auto&it:TimeLast){
                            if(it.first==processInfo.processName) {
                                processInfo.lastTime = TimeLast[processInfo.processName];
                                break;
                            }
                        }
                        processList.push_back(processInfo);
                        continue;
                    } else {
                        // 进程仍在运行
                        FILETIME currentTime;
                        GetSystemTimeAsFileTime(&currentTime);
                        processInfo.exitTime = currentTime;
                        processInfo.status = 1;
                    }
                } else {
                    // 获取退出代码失败，将退出时间置为0
                    processInfo.creationTime=GetSystemUpTime();
                    processInfo.exitTime= GetSystemUpTime();
                    processInfo.status = 0;
                    for(auto&it:TimeLast){
                        if(it.first==processInfo.processName) {
                            processInfo.lastTime = TimeLast[processInfo.processName];
                            break;
                        }
                    }
                    processList.push_back(processInfo);
                    continue;
                }

                tm beijingTime1 = convertFileTimeToBeijingTime(processInfo.creationTime);
                tm beijingTime2 = convertFileTimeToBeijingTime(processInfo.exitTime);

                // 计算持续时间
                std::chrono::system_clock::time_point startTime = std::chrono::system_clock::from_time_t(
                        std::mktime(&beijingTime1));
                std::chrono::system_clock::time_point endTime = std::chrono::system_clock::from_time_t(
                        std::mktime(&beijingTime2));
                std::chrono::duration<double> duration = endTime - startTime;
                processInfo.lastTime = duration.count();
                processList.push_back(processInfo);
                CloseHandle(hProcess);
            }
        } while (Process32Next(hSnapshot, &pe32));
    }
        // 关闭进程快照句柄
        CloseHandle(hSnapshot);
        return processList;
}

// 函数：增加秒数
void addSecondsToTime(tm& time, int seconds) {
    // 将tm时间转换为time_t类型
    time_t timeToModify = mktime(&time);

    // 增加秒数
    timeToModify += seconds;

    // 将修改后的时间转换回tm类型
    time = *localtime(&timeToModify);
}


// 打印进程信息
void printProcessInfo(ProcessInfo& processInfo,bool status){
    std::cout << "Process Name: " << processInfo.processName << std::endl;
    std::cout << "Memory Usage: " << processInfo.memoryUsage << std::endl;

    // 将 Creation Time 转换为北京时间
    std::tm beijingTime1 = convertFileTimeToBeijingTime(processInfo.creationTime);
    // 格式化输出北京时间
    std::cout << "Creation Time: "
              << std::put_time(&beijingTime1, "%Y-%m-%d %H:%M:%S") << std::endl;
    std::cout <<"Last Time: "
              << processInfo.lastTime << "seconds" << std::endl;
    if(status==0){
        std::tm beijingTime2 = convertFileTimeToBeijingTime(processInfo.exitTime);
        addSecondsToTime(beijingTime2,processInfo.lastTime);
        if(beijingTime2.tm_year<beijingTime1.tm_year)   beijingTime2=beijingTime1;
        std::cout << "End Time: "
                  << std::put_time(&beijingTime2, "%Y-%m-%d %H:%M:%S") << std::endl;
    }
    std::cout << std::endl;
}

