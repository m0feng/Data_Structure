#include <bits/stdc++.h>
using namespace std;
typedef void (*funcPtr1)(int length);                      //做函数指针，Timer的函数
typedef void (*funcPtr2)(int length, int left, int right); //做函数指针，Timer的函数
int nums[500005] = {0};

class Timer
{
private:
    clock_t start;
    clock_t end;

public:
    Timer()
    {
        start = 0;
        end = 0;
    }
    auto timeit(funcPtr1 func, int length)
    {
        start = clock(); //函数开始计时
        func(length);
        end = clock(); //函数结束用时
        return end - start;
    }
    auto timeit(funcPtr2 func, int length, int left, int right)
    {
        start = clock(); //函数开始计时
        func(length, left, right);
        end = clock(); //函数结束用时
        return end - start;
    }
};

void generateData(int length)
{
    ofstream file;
    //升序
    file.open("task-1.txt", ios::out);
    for (int i = 0; i < length; i++)
        file << i << endl;
    file.close();
    //降序
    file.open("task-2.txt", ios::out);
    for (int i = 0; i < length; i++)
        file << length - i << endl;
    file.close();
    //乱序
    for (int k = 3; k <= 10; k++)
    {
        srand(time(NULL));
        string fileName = "task-" + to_string(k) + ".txt";
        file.open(fileName, ios::out);
        for (int i = 0; i < length - 1; i++)
        {
            int val = (rand() % 5000000);
            file << val << endl;
        }
        file << (rand() % 5000000);
        file.close();
    }
}
int readData(string fileName, int nums[])
{
    fstream file(fileName, ios::in);
    int length = 0;
    if (!file)
    {
        cout << "ERROR" << endl;
        exit(0);
    }
    while (!file.eof())
    {
        file >> nums[length++];
    }
    file.close();
    return length;
}

void insertSort(int length)
{
    for (int i = 1; i < length; i++)
    {
        int temp = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > temp)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = temp;
    }
}

void bubbleSort(int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int cnt = 0;
        for (int j = 0; j < length - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
                cnt++;
            }
        }
        if (cnt == 0) //没有交换，说明已经有序
            break;
    }
}

void selectSort(int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < length; j++)
        {
            if (nums[j] < nums[min])
            {
                min = j;
            }
        }
        int temp = nums[i];
        nums[i] = nums[min];
        nums[min] = temp;
    }
}
void shellSort(int length)
{
    int gap = length / 2;
    while (gap > 0)
    {
        for (int i = gap; i < length; i++)
        {
            int temp = nums[i];
            int j = i - gap;
            while (j >= 0 && nums[j] > temp)
            {
                nums[j + gap] = nums[j];
                j -= gap;
            }
            nums[j + gap] = temp;
        }
        gap /= 2;
    }
}
void heapAdjust(int i, int length)
{
    int temp = nums[i];
    for (int k = 2 * i + 1; k < length; k = 2 * k + 1)
    {
        if (k + 1 < length && nums[k] < nums[k + 1])
            k++;
        if (nums[k] > temp)
        {
            nums[i] = nums[k];
            i = k;
        }
        else
            break;
    }
    nums[i] = temp;
}
void heapSort(int length)
{
    // 构建大顶堆
    for (int i = length / 2 - 1; i >= 0; i--)
        heapAdjust(i, length);
    // 交换堆顶元素和最后一个元素
    for (int i = length - 1; i > 0; i--)
    {
        int temp = nums[i];
        nums[i] = nums[0];
        nums[0] = temp;
        heapAdjust(0, i);
    }
}
void radixSort(int length)
{
    int max=nums[0];
    for(int i=0;i<10;i++){
        max= (max > nums[i]) ? max : nums[i];
    }
    int maxdight=0;
    while(max!=0){
        max/=10;
        maxdight+=1;
    }
    int ps[10];
    int tmp[10];
    int radix=1;
    for(int i=1;i<=maxdight;i++){
        ::memset(ps,0,sizeof(ps));
        ::memset(tmp,0,sizeof(tmp));
        for(int j=0;j<10;j++){
            int k= (nums[j] / radix) % 10;
            ps[k]++;
        }
        for(int j=1;j<10;j++){
            ps[j]=ps[j]+ps[j-1];
        }
        for(int j=10-1;j>=0;j--){
            int k= (nums[j] / radix) % 10;
            tmp[ps[k]-1]=nums[j];
            ps[k]--;
        }
        for(int j=0;j<10;j++){
            nums[j]=tmp[j];
        }
        radix*=10;
    }
}

void quickSort(int length, int left, int right)
{
    if (left >= right)
        return;
    int pivot = nums[left]; // 选择第一个元素作为基准值
    int i = left, j = right;
    while (i < j)
    {
        while (i < j && nums[j] >= pivot)
            j--;
        nums[i] = nums[j];

        while (i < j && nums[i] <= pivot)
            i++;
        nums[j] = nums[i];
    }
    nums[i] = pivot;                 // 将基准值放到正确的位置
    quickSort(length, left, i - 1);  // 递归对基准值左侧的子数组进行快速排序
    quickSort(length, i + 1, right); // 递归对基准值右侧的子数组进行快速排序
}
int Partition(int low, int high) //划分算法
{
    //假设每次都以第一个元素作为枢轴值，进行一趟划分：
    int pivot = nums[low];
    while (low < high)
    {
        while (low < high && nums[high] >= pivot)
            --high;
        nums[low] = nums[high]; //停下来做交换
        while (low < high && nums[low] <= pivot)
            ++low;
        nums[high] = nums[low]; //停下来做交换
    }
    nums[low] = pivot; // pivot的最终落点
    return low;
}
void QuickSort(int length, int left, int right) //非递归快排
{
    //手动利用栈来存储每次分块快排的起始点
    //栈非空时循环获取中轴入栈
    stack<int> s;
    if (left < right)
    {
        int boundary = Partition(left, right);
        if (boundary - 1 > left) //确保左分区存在
        {
            //将左分区端点入栈
            s.push(left);
            s.push(boundary - 1);
        }
        if (boundary + 1 < right) //确保右分区存在
        {
            s.push(boundary + 1);
            s.push(right);
        }
        while (!s.empty())
        {
            //得到某分区的左右边界
            int r = s.top();
            s.pop();
            int l = s.top();
            s.pop();
            boundary = Partition(l, r);
            if (boundary - 1 > l) //确保左分区存在
            {
                //将左分区端点入栈
                s.push(l);
                s.push(boundary - 1);
            }
            if (boundary + 1 < r) //确保右分区存在
            {
                s.push(boundary + 1);
                s.push(r);
            }
        }
    }
}

void Merge(int length, int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = 0;
    int *temp = (int *)malloc((right - left + 1) * sizeof(int));
    if (!temp)
    {
        cout << "空间不足！" << endl;
        system("pause");
        exit(0);
    }
    while (i <= mid && j <= right)
    {
        if (nums[i] <= nums[j])
            temp[k++] = nums[i++];
        else
            temp[k++] = nums[j++];
    }
    while (i <= mid)
        temp[k++] = nums[i++];
    while (j <= right)
        temp[k++] = nums[j++];
    for (i = 0; i < k; i++)
        nums[left + i] = temp[i];
}
void MergeSort(int length, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        MergeSort(length, left, mid);
        MergeSort(length, mid + 1, right);
        Merge(length, left, mid, right);
    }
}

string f_name1[6] = {"插入排序", "冒泡排序", "选择排序", "希尔排序", "堆排序  ", "基数排序"};
string f_name2[2] = {"快速排序", "归并排序"};
funcPtr1 f1[6] = {insertSort, bubbleSort, selectSort, shellSort, heapSort, radixSort};
funcPtr2 f2[2] = {QuickSort, MergeSort};

void single(Timer timer, string fileName)
{
    int length = readData(fileName, nums);
    cout << "样本数据文件：" << fileName << endl
         << "样本数据量大小：" << length << endl
         << endl
         << "┌───────────────┬───────┐" << endl;
    for (int i = 0; i <= 5; i++) //排序算法
    {
        cout << "│" << f_name1[i] << "\t│";
        readData(fileName, nums);
        cout << timer.timeit(f1[i], length) << "\t│" << endl;
    }
    for (int i = 0; i <= 1; i++) //排序算法
    {
        cout << "│" << f_name2[i] << "\t│";
        readData(fileName, nums);
        cout << timer.timeit(f2[i], length, (int)0, length) << "\t│" << endl;
    }
    cout << "└───────────────┴───────┘" << endl;
}
void runAll(Timer timer, int length)
{
    cout << "样本数据量大小：" << length << endl
         << endl
         << "┌───────────────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐" << endl
         << "│排序方式\t│task-1\t│task-2\t│task-3\t│task-4\t│task-5\t│task-6\t│task-7\t│task-8\t│task-9\t│task-10│" << endl
         << "├───────────────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤" << endl;
    for (int i = 0; i <= 5; i++) //排序算法
    {
        cout << "│" << f_name1[i] << "\t│";
        for (int j = 1; j <= 10; j++) //测试点
        {
            string fileName = "task-" + to_string(j) + ".txt";
            readData(fileName, nums);
            cout << timer.timeit(f1[i], length) << "\t│";
        }
        cout << endl;
    }
    for (int i = 0; i <= 1; i++) //排序算法
    {
        cout << "│" << f_name2[i] << "\t│";
        for (int j = 1; j <= 10; j++) //测试点
        {
            string fileName = "task-" + to_string(j) + ".txt";
            readData(fileName, nums);
            cout << timer.timeit(f2[i], length, (int)0, length) << "\t│";
        }
        cout << endl;
    }
    cout << "└───────────────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘" << endl;
}

int main()
{
    Timer timer;
    string fileName;

    cout << "选择样本输入方式：" << endl
         << "1. 随机生成" << endl
         << "2. 读取文件" << endl;
    int choice, length;
    cin >> choice;
    if (choice == 1)
    {
        cout << "输入随机生成样本数据量：" << endl;
        cin >> length;
        generateData(length);
        runAll(timer, length);
    }
    else if(choice==2)
    {
        cout << "输入样本文件名：" << endl;
        cin >> fileName;
        single(timer, fileName);
    }else{
        cout<<"输入错误"<<endl;
    }
    return 0;
}
