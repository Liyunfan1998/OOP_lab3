//
// Created by Yunfan Li on 2018/5/11.
//
#include <vector>
#include <iostream>
#include "warehouse.cpp"

using namespace std;

extern warehouse *noWarehouse();

extern const int bigsize;
extern const int midsize;
extern const int smlsize;
extern const int nosize;

class shop {
public:
    string name;
    warehouse *wh = noWarehouse();
    float salesRecord;

    void sell(item item1, float discount) {
        salesRecord += discount * item1.price;
        wh->useItem(item1);
    }

    void purchase(item item1) {
        wh->supplyItem(item1);
    }

    shop(string name) {
        this->name = name;
//        cout << name << " " << "warehouse_size" << "c􏰄􏰀onstruct􏰄or/dec􏰄􏰀struct􏰄or is i􏰀nvok􏰄􏰅ed􏰀" << endl;
    }

    shop(string name, string itemNumStr) {
        int itemNum = stoi(itemNumStr);
        this->name = name;
        int warehouse_size = 0;
        if (itemNum <= 25) {
            warehouse_size = 25;
        } else if (itemNum <= 50) {
            warehouse_size = 50;
        } else if (itemNum <= 100) {
            warehouse_size = 100;
        }
        cout << name << " " << warehouse_size << " " << "c􏰄􏰀onstruct􏰄or is i􏰀nvok􏰄􏰅ed􏰀" << endl;
    }
};