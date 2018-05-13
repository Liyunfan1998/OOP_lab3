//
// Created by Yunfan Li on 2018/5/11.
//
#include <vector>
#include <iostream>
#include "item.cpp"

/* Warehouse Util */
using namespace std;
enum WarehouseSize {
    BIG, MID, SMALL, NO
};
const int bigsize = 100;
const int midsize = 50;
const int smlsize = 25;
const int nosize = 0;

enum op {
    SELL, PURCHASE,
};

class warehouse {
private:
    vector<item> items;
    int maxSize;

public:
    warehouse(int sizeOfWarehouse) {
        maxSize = sizeOfWarehouse;
    }

    int getSize() { return items.size(); }

    void useItem(item item1) {
        vector<item>::iterator it;
        for (it = items.begin(); it != items.end(); ++it) {
            if (item1.equals(*it)) {
                cout << "sell " + (*it).name << endl;
                items.erase(it);
//                check the warehouse for maxSize change
                checkWarehouseSize(SELL);
                break;
            }
        }
    }

    void supplyItem(item item1) {
        items.push_back(item1);
        checkWarehouseSize(PURCHASE);
    }

    void checkWarehouseSize(op operation) {
        int nowSize = getSize();
        cout << "nowSize: " << getSize() << endl;
        if (operation == SELL && (nowSize == 0 || nowSize == 25 || nowSize == 50)) {
            cout << "sell change maxSize " << endl;
            getSmallerWarehouse();
        } else if (operation == PURCHASE && (nowSize == 1 || nowSize == 26 || nowSize == 51)) {
            cout << "purchase change maxSize " << endl;
            getBiggerWarehouse();
        }
    }

    WarehouseSize getType() {
        switch (maxSize) {
            case bigsize:
                return BIG;
            case midsize:
                return MID;
            case smlsize:
                return SMALL;
            case nosize:
                return NO;
        }
    }

    void getBiggerWarehouse() {
        if (this->maxSize == smlsize) {
            this->maxSize = midsize;
        } else if (this->maxSize == midsize) {
            this->maxSize = bigsize;
        } else if (this->maxSize == nosize) {
            this->maxSize = smlsize;
        }
    }

    void getSmallerWarehouse() {
        if (this->maxSize == bigsize) {
            this->maxSize = midsize;
        } else if (this->maxSize == midsize) {
            this->maxSize = smlsize;
        }
//        不知道要不要算商店倒闭的情况
    }

};

warehouse *bigWarehouse() {
    return new warehouse(bigsize);
}

warehouse *midWarehouse() {
    return new warehouse(midsize);
}

warehouse *smlWarehouse() {
    return new warehouse(smlsize);
}

warehouse *noWarehouse() {
    return new warehouse(nosize);
}