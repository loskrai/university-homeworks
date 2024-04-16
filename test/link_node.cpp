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

        (*pphead)->discount = discount;

        (*pphead)->price = price;

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

        (*pphead)->discount = discount;

        (*pphead)->price = price;

        ++count;

    }

}



void link_node::del(link_node** pphead, link_node* pos) {

    if (pos == *pphead) {

        *pphead = (*pphead)->next;

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