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

vector<item> copyVec;

warehouse *copyWarehouse(warehouse* wh);

class shop {
public:
    string name;
    warehouse *wh;
    float salesRecord;

    void sell(item item1, float discount) {
        if (this->wh != nullptr) {
            salesRecord += discount * item1.price;
            bool whSizeChanged = wh->useItem(item1);
            if (whSizeChanged) {
                this->wh = copyWarehouse(wh);
            } else
                return;
            cout << copyVec.size() << endl;
            if (this->wh->getSize() == 0) {
                delete this->wh;
                this->wh = nullptr;
            }
        }
    }

    void purchase(item item1) {
        if (this->wh->getSize() >= 100) {
            cout << "warehouse full!" << endl;
            return;
        }
        if (this->wh == nullptr) {
            this->wh = noWarehouse();
        }

        bool whSizeChanged = wh->supplyItem(item1);
        if (whSizeChanged) {
            this->wh = copyWarehouse(wh);
        } else
            return;
        cout << copyVec.size() << endl;
    }

    shop(string name) {
        this->name = name;
        this->wh = nullptr;
        cout << "tmpShop constructor is invoked􏰀" << endl;
    }

    shop(string name, string itemNumStr) {
        int itemNum = stoi(itemNumStr);
        this->name = name;
        this->wh = noWarehouse();
        int warehouse_size = 0;
        if (itemNum <= 25) {
            warehouse_size = 25;
        } else if (itemNum <= 50) {
            warehouse_size = 50;
        } else if (itemNum <= 100) {
            warehouse_size = 100;
        }
        cout << name << ", " << warehouse_size << ", constructor is invoked􏰀􏰀" << endl;
    }

    ~shop() {
        if (this->wh != nullptr) {
            cout << name << ", " << this->wh->getSize() << ", dec􏰄􏰀struct􏰄or is invoked" << endl;
            delete this->wh;
            this->wh = nullptr;
        }
    };
};

warehouse *copyWarehouse(warehouse* wh) {
    copyVec.clear();
    vector<item> v2 = wh->getItems();
    copyVec.insert(copyVec.end(), v2.begin(), v2.end());
    int maxSize = wh->getMaxSize();
    delete wh;
    return new warehouse(maxSize, copyVec);
}