//
// Created by Yunfan Li on 2018/5/11.
//
#include <vector>
#include <iostream>
#include "item.cpp"

/* Warehouse Util */
using namespace std;


const int bigsize = 100;
const int midsize = 50;
const int smlsize = 25;
const int nosize = 0;

enum op {
    SELL, PURCHASE,
};
enum WarehouseSize {
    BIG, MID, SMALL, NO
};

class warehouse {
private:
    vector<item> items;
    int maxSize;

public:
    warehouse(int sizeOfWarehouse) {
        cout << "warehouse 􏰄constructor is i􏰀nvok􏰄􏰅ed" << endl;
        maxSize = sizeOfWarehouse;
    }

    warehouse(int sizeOfWarehouse, vector<item> items) {
        cout << "warehouse 􏰄constructor is i􏰀nvok􏰄􏰅ed" << endl;
        maxSize = sizeOfWarehouse;
        this->items = items;
    }

    ~warehouse() {
        cout << "warehouse dec􏰄􏰀struct􏰄or is i􏰀nvok􏰄􏰅ed" << endl;
    }

    int getSize() { return items.size(); }

    int getMaxSize() {
        return maxSize;
    }

    vector<item> getItems() { return items; }

    bool useItem(item item1) {
        vector<item>::iterator it;
        for (it = items.begin(); it != items.end(); ++it) {
            if (item1.equals(*it)) {
                cout << "sell " + (*it).name << endl;
                items.erase(it);
//                check the warehouse for maxSize change
                return checkWarehouseSize(SELL);
            }
        }
    }

    item getItemOfCertainTypeRandomly(string itemtype) {
        itemType itemType1 = ::getType(itemtype);
        for (auto item1: items) {
            if (item1.type == itemType1) {
                return item1;
            }
        }
        return noitem();
    }

    bool supplyItem(item item1) {
        items.push_back(item1);
        return checkWarehouseSize(PURCHASE);
    }

    bool checkWarehouseSize(op operation) {
        int nowSize = getSize();
        cout << "nowSize: " << getSize() << endl;
        if (operation == SELL && (nowSize == 0 || nowSize == 25 || nowSize == 50)) {
            cout << "sell change maxSize " << endl;
            getSmallerWarehouse();
            return true;
        } else if (operation == PURCHASE && (nowSize == 1 || nowSize == 26 || nowSize == 51)) {
            cout << "purchase change maxSize " << endl;
            getBiggerWarehouse();
            return true;
        }
        return false;
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
        if (this->maxSize == nosize) {
            this->maxSize = smlsize;
        } else if (this->maxSize == smlsize) {
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
