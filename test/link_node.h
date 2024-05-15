#pragma once
#include"headfile.h"

class link_node {
public:

    string num;

    string name;

    string price;

    string discount;

    string sale;

    static int count;

    link_node* pri;

    link_node* next;

    link_node() : pri(0), next(0) {}

    link_node* appSpace();

    link_node* find(link_node* phead, string num);

    void add(link_node** pphead, string num, string name, string discount, string price);

    void add(link_node** pphead, string num, string name, string discount, string price, string sale);

    void del(link_node** pphead, link_node* pos);

    void change(link_node** pphead, link_node* pos, string num, string name, string discount, string price);

    void change(link_node** pphead, link_node* pos, string num, string name, string discount, string price, string sale);

    void insert(link_node** pphead, link_node* pos, string num, string name, string discount, string price);

    void show(link_node* phead);

    void sortList(link_node** pphead);

    void destory(link_node** pphead);

    ~link_node() {}


};


class CanteenOrder :public link_node {
public:
    static int CanteenCount;
    CanteenOrder():next(nullptr) {}
    inline void setBoxFee(double boxFee) { boxFee = boxFee; }
    inline void setTableNum(double tableNum) { this->tableNum = tableNum; }
    inline double getBoxFee() { return this->boxFee; }
    inline int getTableNum() { return this->tableNum; }
    void show(CanteenOrder* phead);
    double getTotalPrice(CanteenOrder* phead);
    void save(CanteenOrder* phead);
    void add(CanteenOrder** pphead, string num, string name, string discount, string price, string sale, double boxFee, bool doesBox, int tableNum, int amoun);
private:
    int orderNum;
    CanteenOrder* appSpace();
    CanteenOrder* next;
    bool doesBox;
    double boxFee;
    int tableNum;
    int amount;
};



class TakeoutOrder :public link_node {
public:
    static int TakeCount;
    TakeoutOrder():next(nullptr) {}
    inline void SetBasho(string basho) { this->basho = basho; }
    inline void setCallNum(unsigned int callNum) { this->callNum = callNum; }
    inline void setSendCost(double sendCost) { this->sendCost = sendCost; }
    inline void setSendTime(string sendtime) { this->sendTime = sendtime; }
    inline string getBasho() { return this->basho; }
    inline int getCallNum() { return this->callNum; }
    inline  unsigned getSendCost() { return this->sendCost; }
    inline string getSendTime() { return this->sendTime; }
    void show(TakeoutOrder* phead);
    double getTotalPrice(TakeoutOrder* phead);
    void save(TakeoutOrder* phead);
    void add(TakeoutOrder** pphead, string num, string name, string discount, string price, string sale,string basho,unsigned callNum, double sendCost,string sendTime,int amount);
private:
    int orderNum;
    TakeoutOrder* next;
    string basho;
    unsigned int callNum;
    double sendCost;
    string sendTime;
    int amount;
    TakeoutOrder* appSpace();
};
