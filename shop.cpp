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
    warehouse *wh = noWarehouse();
    float salesRecord;

    void sell(item item1) {
        wh->useItem(item1);
    }

    void purchase(item item1) {
        wh->supplyItem(item1);
    }

};