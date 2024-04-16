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

};

