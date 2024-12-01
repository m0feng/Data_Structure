#include "Wind.h"
using namespace std;

struct LinerList{   //定义单向链表结构
    ProcessInfo p;
    LinerList *next;
    LinerList(){
        next= nullptr;
    }
};

struct CircleList{  //定义双向链表结构
    ProcessInfo p;
    CircleList *pre;
    CircleList *next;
    CircleList(){
        pre= nullptr;
        next= nullptr;
    }
};

set<string> tstart;
set<string> tend;
map<string,int> TimeLast;

void updateList(LinerList **Hder , CircleList **Hd, LinerList **Eder , CircleList **Ed, ProcessInfo tmp, bool flag, bool same){    //更新链表
    if(flag==0){                 //直接寻找合适节点插入
        if(same==1){
            if((*Hder)== nullptr){
                (*Hder)=new LinerList;
                (*Hder)->p=tmp;
                (*Eder)=(*Hder);
                (*Eder)->next= nullptr;
                return;
            }
            LinerList *tp;
            if((*Hder)->p.memoryUsage <= tmp.memoryUsage){
                tp = new LinerList;
                tp->p=tmp;
                tp->next=(*Hder);
                (*Hder)=tp;
                return;
            }
            LinerList *tq;
            tp=(*Hder);
            while(tp!=nullptr){
                if(tp->next== nullptr && tp->p.memoryUsage>=tmp.memoryUsage){
                    tq=new LinerList;
                    tq->p=tmp;
                    tp->next=tq;
                    tq->next= nullptr;
                    (*Eder)=tq;
                    return;
                }else if(tp->p.memoryUsage>=tmp.memoryUsage && (tp->next->p.memoryUsage<=tmp.memoryUsage)){
                    tq=new LinerList;
                    tq->p=tmp;
                    tq->next=tp->next;
                    tp->next=tq;
                    return;
                }
                tp=tp->next;
            }
        }else{
            if((*Hd)== nullptr){
                (*Ed)=new CircleList;
                (*Ed)->p=tmp;
                (*Hd)=(*Ed);
                (*Ed)->next= nullptr;
                (*Hd)->pre= nullptr;
                return;
            }
            CircleList *tp;
            if((*Ed)->p.memoryUsage <= tmp.memoryUsage){
                tp=new CircleList;
                tp->p=tmp;
                (*Ed)->next=tp;
                tp->pre=(*Ed);
                tp->next= nullptr;
                (*Ed)=tp;
                return;
            }
            CircleList *tq;
            tp=(*Ed);
            while(tp!=nullptr) {
                if (tp->pre == nullptr && tp->p.memoryUsage >= tmp.memoryUsage) {
                    tq = new CircleList;
                    tq->p = tmp;
                    tq->next = tp;
                    tp->pre = tq;
                    tq->pre = nullptr;
                    (*Hd) = tq;
                    return;
                } else if (tp->p.memoryUsage >= tmp.memoryUsage && (tp->pre->p.memoryUsage <= tmp.memoryUsage)) {
                    tq = new CircleList;
                    tq->p = tmp;
                    tq->pre = tp->pre;
                    tp->pre->next = tq;
                    tq->next = tp->pre;
                    tp->pre = tq;
                    return;
                }
                tp=tp->pre;
            }
        }
    }else{                             //寻找已存在的节点,对其进行处理
        if(same==1){
            LinerList *tp= *Hder;
            LinerList *pre= tp;
            if(tp->p.processName==tmp.processName){
                (*Hder)->p=tmp;
                return;
            }
            while(tp->next!=nullptr){
                if(tp->next->p.processName==tmp.processName){
                    pre=tp;
                    tp=tp->next;
                    break;
                }
                tp=tp->next;
            }
            if(tmp.status==1){
                tp->p=tmp;
            }else{                        //进程已结束,拿出节点,插入结束链表
                pre->next=tp->next;
                if(tp->next== nullptr){
                    (*Eder)=pre;
                }
                tstart.erase(tmp.processName);
                tend.insert(tmp.processName);
                updateList(Hder, Hd, Eder, Ed, tmp, 0, 0);
            }
        }else{
            CircleList *tp= *Ed;
            CircleList *next= tp;
            if(tp->p.processName==tmp.processName){
                tp->p=tmp;
                return;
            }
            while(tp->pre!=nullptr){
                if(tp->pre->p.processName==tmp.processName){
                    next=tp;
                    tp=tp->pre;
                    break;
                }
                tp=tp->pre;
            }
            if(tmp.status==0){
                tp->p=tmp;
            }else{
                next->pre=tp->pre;
                if(tp->pre== nullptr){
                    (*Hd)=next;
                }else{
                    next->pre->next=next;
                }
                tend.erase(tmp.processName);
                tstart.insert(tmp.processName);
                updateList(Hder, Hd, Eder, Ed, tmp, 0, 1);
            }
        }
    }
}


int getListLength(LinerList* head) {
    int length = 0;
    LinerList* current = head;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    return length;
}

// 交换节点值
void swapNodes(LinerList* node1, LinerList* node2) {
    ProcessInfo temp = node1->p;
    node1->p = node2->p;
    node2->p = temp;
}

// 对链表节点按内存从大到小进行排序
void sortListByMemory(LinerList*& head) {
    int length = getListLength(head);

    for (int i = 0; i < length - 1; i++) {
        LinerList* current = head;
        LinerList* nextNode = head->next;

        for (int j = 0; j < length - i - 1; j++) {
            if (current->p.memoryUsage < nextNode->p.memoryUsage) {
                swapNodes(current, nextNode);
            }

            current = current->next;
            nextNode = nextNode->next;
        }
    }
}

// 获取循环链表长度
int getListLength(CircleList* head) {
    if (head == nullptr) {
        return 0;
    }

    int length = 0;
    CircleList* current = head;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    return length;
}

// 交换节点值
void swapNodes(CircleList* node1, CircleList* node2) {
    ProcessInfo temp = node1->p;
    node1->p = node2->p;
    node2->p = temp;
}

// 对循环链表节点按内存从小到大进行排序
void sortListByMemory(CircleList*& head) {
    int length = getListLength(head);

    for (int i = 0; i < length - 1; i++) {
        CircleList* current = head;
        CircleList* nextNode = head->next;

        for (int j = 0; j < length - i - 1; j++) {
            if (current->p.memoryUsage > nextNode->p.memoryUsage) {
                swapNodes(current, nextNode);
            }
            current = current->next;
            nextNode = nextNode->next;
        }
    }
}

int main() {
    LinerList *Header= nullptr,*Ender = nullptr;
    CircleList *Head = nullptr ,*End= nullptr;
    vector<ProcessInfo> processList;
    int t=0;
    while (t<=10) {
        // 获取进程信息
        Sleep(1000);
        processList.clear();
        processList = getProcessInfo();

        int same,flag;
        for (const ProcessInfo& processInfo : processList) {          //进行进程的插入
            TimeLast[processInfo.processName]=processInfo.lastTime;
            if(processInfo.processName=="TIM.exe" && processInfo.status==0){
                cout<<"1";
            }
            if(tstart.find(processInfo.processName)!=tstart.end()){
                flag=1;
                same=1;
            }else if(tend.find(processInfo.processName)!=tend.end()){
                flag=1;
                same=0;
            }else{
                flag=0;
                same=processInfo.status;
                if(processInfo.status==0){
                    tend.insert(processInfo.processName);
                }else{
                    tstart.insert(processInfo.processName);
                }
            }
            updateList(&Header,&Head,&Ender,&End,processInfo,flag,same);
        }
        sortListByMemory(Header);   //按内存进行排序
        sortListByMemory(Head);
        cout<<"Status: 1"<<endl;
        for(LinerList *p =Header;p!= nullptr;p=p->next ){
            printProcessInfo(p->p,1);
        }
        cout<<"Status: 0"<<endl;
        for(CircleList *p =Head;p!= nullptr;p=p->next ){
            printProcessInfo(p->p,0);
        }
        t++;
    }
    return 0;
}