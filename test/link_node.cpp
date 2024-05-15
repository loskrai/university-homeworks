#include"link_node.h"



int link_node::count = 0;


link_node* link_node::appSpace() {

    link_node* newNode = new link_node;

    if (newNode == NULL) {

        perror("Fail to apply new space");

        exit(0);

    }

    return newNode;

}

TakeoutOrder* TakeoutOrder::appSpace() {

    TakeoutOrder* newNode = new TakeoutOrder;

    if (newNode == NULL) {

        perror("Fail to apply new space");

        exit(0);

    }

    return newNode;

}

CanteenOrder* CanteenOrder::appSpace() {

    CanteenOrder* newNode = new CanteenOrder;

    if (newNode == NULL) {

        perror("Fail to apply new space");

        exit(0);

    }

    return newNode;

}



void link_node::add(link_node** pphead, string num, string name,  string discount, string price) {

    link_node* newNode = appSpace();

    if ((*pphead) == NULL) {

        (*pphead) = newNode;

        (*pphead)->name = name;

        (*pphead)->num = num;

        (*pphead)->discount = discount;

        (*pphead)->price = price;

        ++count;

    }

    else {

        link_node* cur = *pphead;

        while (cur->next) {

            cur = cur->next;

        }

        cur->next = newNode;

        cur->next->pri = cur->next;

        cur->next->num = num;

        cur->next->name = name;

        cur->next->discount = discount;

        cur->next->price = price;

        ++count;

    }

}

void link_node::add(link_node** pphead, string num, string name, string discount, string price,string sale) {

    link_node* newNode = appSpace();

    if ((*pphead) == NULL) {

        (*pphead) = newNode;

        (*pphead)->name = name;

        (*pphead)->num = num;

        (*pphead)->discount = discount;

        (*pphead)->price = price;

        (*pphead)->sale = sale;

        ++count;

    }

    else {

        link_node* cur = *pphead;

        while (cur->next) {

            cur = cur->next;

        }

        cur->next = newNode;

        cur->next->pri = cur->next;

        cur->next->num = num;

        cur->next->name = name;

        cur->next->sale = sale;

        cur->next->discount = discount;

        cur->next->price = price;

        ++count;

    }

}



void link_node::del(link_node** pphead, link_node* pos) {

    if (pos == *pphead) {

        *pphead = (*pphead)->next;

        pphead = &(*pphead);

        (*pphead)->pri = 0;

        delete pos;

        pos = NULL;

        --count;

    }

    else {

        pos->pri->next = pos->next;

        pos->next->pri = pos->pri;

        delete pos;

        pos = NULL;

        --count;

    }

}



void link_node::change(link_node** pphead, link_node* pos, string num, string name, string discount, string price) {

    pos->name = name;

    pos->num = num;

    pos->discount = discount;

    pos->price = price;
}

void link_node::change(link_node** pphead, link_node* pos, string num, string name, string discount, string price, string sale) {

    pos->name = name;

    pos->num = num;

    pos->discount = discount;

    pos->price = price;

    pos->sale = sale;
}


void link_node::insert(link_node** pphead, link_node* pos, string num, string name,string discount, string price) {

    link_node* newNode = appSpace();

    link_node* next = pos->next;

    pos->next = newNode;

    newNode->num = num;

    newNode->name = name;

    newNode->discount = discount;

    newNode->price = price;

    newNode->pri = pos;

    newNode->next = next;

    next->pri = newNode;

    ++count;

}



link_node* link_node::find(link_node* phead, string num) {

    while (phead) {

        if (phead->num == num) {

            return phead;

        }

        phead = phead->next;

    }

    return NULL;

}



void link_node::show(link_node* phead) {

    link_node* cur = phead;

    int icount = 1;

    while (cur) {

        cout << icount << "\t" << cur->num << "\t" << cur->name << "\t" << cur->price << "\t" << cur->discount << "\n";

        cur = cur->next;

        ++icount;

    }

    cout << "Null\n";

}



void link_node::sortList(link_node** pphead) {

    if ((*pphead) == NULL) {

        perror("No list");

        return;

    }

    link_node* temp = (*pphead);

    link_node* start = temp;

    //StudentList* next;*/

    bool flag = 0;

    for (int i = 0; i < count - 1; ++i) {

        for (int j = 0; j < count - 1 - i; ++j) {

            if (temp->num > temp->next->num) {

                string a;

                string b;

                a = temp->next->num;

                temp->next->num = temp->num;

                temp->num = a;

                b = temp->next->name;

                temp->next->name = temp->name;

                temp->name = b;

            }

        }

        temp = temp->next;

        start = temp->next;

    }

}



void link_node::destory(link_node** pphead) {

    while (*pphead) {

        count = 0;

        link_node* next = (*pphead)->next;

        delete* pphead;

        *pphead = next;

    }
}


void TakeoutOrder::show(TakeoutOrder *phead) {

    TakeoutOrder* cur = phead;

        int icount = 1000;

        cout << "number\tname\tprice\tdiscount\tamount\n";

        while (cur) {

            cout << icount << "\t" << cur->name << "\t" << cur->price << "\t" << cur->discount << "\t" << cur->amount << "\n";
            cur = cur->next;

            ++icount;

        }
        cout << "送餐时间：" << phead->sendTime << "\n";
        cout << "送餐地点：" << phead->basho << "\n";
        cout << "联系电话：" << phead->callNum << "\n";
        cout << "外卖服务费：" << phead->sendCost << "\n";
        cout << "总价：" << phead->getTotalPrice(phead) << "\n";

        cout << "\n";

}


void CanteenOrder::show(CanteenOrder* phead) {

    CanteenOrder* cur = phead;

    int icount = 1000;

    cout << "number\tname\tprice\tdiscount\tamount\n";

    while (cur) {

        cout << icount << "\t" << cur->name << "\t" << cur->price << "\t" << cur->discount << "\t" << cur->amount << "\n";
        cur = cur->next;

        ++icount;

    }
    cout << "是否有包厢" << (phead->doesBox ? "是" : "否") << endl;
    cout << "包厢费用：" << phead->boxFee << "\n";
    cout << "桌号：" << phead->tableNum << "\n";
    cout << "总价：" << phead->getTotalPrice(phead) << "\n";

    cout << "\n";

}

double CanteenOrder::getTotalPrice(CanteenOrder* phead) {
    CanteenOrder* cur = phead;
    double price = 0;
    while (cur) {

        price += (stod(cur->price) * cur->amount);

        cur = cur->next;

    }
    price += phead->boxFee;
    return price;
}

double TakeoutOrder::getTotalPrice(TakeoutOrder* phead) {
    TakeoutOrder* cur = phead;
    double price = 0;
    while (cur) {

        price += (stod(cur->price) * cur->amount);

        cur = cur->next;

    }
    price += phead->sendCost;
    return price;
}

void TakeoutOrder::save(TakeoutOrder *phead) {
    SYSTEMTIME now;
    GetLocalTime(&now);
    string time =(to_string(now.wYear) + to_string(now.wMonth) + to_string(now.wDay)+".txt");
    ofstream take(time, ios::app);
    if (!take.is_open()) {
        ofstream take(time);
    }
    TakeoutOrder* cur = phead;

    int icount = 1000;

    take << "number\tname\tprice\tdiscount\tamount\n";

    while (cur) {
        take << icount << "\t" << cur->name << "\t" << cur->price << "\t" <<cur->discount << "\t" << cur->amount << "\n";
        cur = cur->next;
        ++icount;
    }
    take << "送餐时间：" << phead->sendTime << "\n";
    take << "送餐地点：" << phead->basho << "\n";
    take << "联系电话：" << phead->callNum << "\n";
    take << "外卖服务费：" << phead->sendCost << "\n";
    take << "总价：" << phead->getTotalPrice(phead) << "\n";

    take << "\n";
    take.close();
}

void CanteenOrder::save(CanteenOrder* phead) {
    SYSTEMTIME now;
    GetLocalTime(&now);
    string time = (to_string(now.wYear) + to_string(now.wMonth) + to_string(now.wDay) + ".txt");
    ofstream take(time, ios::app);
    if (!take.is_open()) {
        ofstream take(time);
    }
    CanteenOrder* cur = phead;

    int icount = 1;

    take << "number\tname\tprice\tdiscount\tamount\n";

    while (cur) {
        take << cur->orderNum << "\t" << cur->name << "\t" << cur->price << "\t" << cur->discount << "\t" << cur->amount << "\n";
        cur = cur->next;
        ++icount;
    }

    take << "是否有包厢" << (phead->doesBox ? "是" : "否") << "\n";
    take << "包厢费用：" << phead->boxFee << "\n";
    take << "桌号：" << phead->tableNum << "\n";
    take << "总价：" << phead->getTotalPrice(phead) << "\n";

    take << "\n";
    take.close();
}


void TakeoutOrder::add(TakeoutOrder** pphead, string num, string name, 
    string discount, string price, string sale,string basho,unsigned callNum,double sendCost, string sendTime,int amount) {

    TakeoutOrder* newNode = appSpace();

    if ((*pphead) == NULL) {

        (*pphead) = newNode;

        (*pphead)->name = name;

        (*pphead)->num = num;

        (*pphead)->discount = discount;

        (*pphead)->price = price;

        (*pphead)->sale = sale;

        (*pphead)->basho = basho;

        (*pphead)->callNum = callNum;

        (*pphead)->sendCost = sendCost;

        (*pphead)->sendTime = sendTime;

        (*pphead)->amount = amount;

        (*pphead)->amount = amount;

        (*pphead)->orderNum = TakeCount + 1000;

        ++TakeCount;

    }

    else {

        TakeoutOrder* cur = *pphead;

        while (cur->next) {

            cur = cur->next;

        }

        cur->next = newNode;

        cur->next->pri = cur->next;

        cur->next->num = num;

        cur->next->name = name;

        cur->next->sale = sale;

        cur->next->discount = discount;

        cur->next->price = price;

        cur->basho = basho;

        cur->callNum = callNum;

        cur->sendCost = sendCost;

        cur->sendTime = sendTime;

        cur->amount = amount;

    }

}


void CanteenOrder::add(CanteenOrder** pphead, string num, string name,
    string discount, string price, string sale,double boxFee, bool doesBox, int tableNum, int amount) {

    CanteenOrder* newNode = appSpace();

    if ((*pphead) == NULL) {

        (*pphead) = newNode;

        (*pphead)->name = name;

        (*pphead)->num = num;

        (*pphead)->discount = discount;

        (*pphead)->price = price;

        (*pphead)->sale = sale;

        (*pphead)->boxFee = boxFee;

        (*pphead)->doesBox = doesBox;

        (*pphead)->tableNum = tableNum;

        (*pphead)->amount = amount;

        (*pphead)->orderNum = CanteenCount + 5000;

        ++CanteenCount;

    }

    else {

        CanteenOrder* cur = *pphead;

        while (cur->next) {

            cur = cur->next;

        }

        cur->next = newNode;

        cur->next->pri = cur->next;

        cur->next->num = num;

        cur->next->name = name;

        cur->next->sale = sale;

        cur->next->discount = discount;

        cur->next->price = price;

        cur->tableNum = tableNum;

        cur->doesBox = doesBox;

        cur->boxFee = boxFee;

        cur->amount = amount;

    }

}