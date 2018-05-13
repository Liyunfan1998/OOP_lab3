//
// Created by Yunfan Li on 2018/5/11.
//
#include <ctime>
#include <string>

using namespace std;

class item {
public:
    string name;
    float price;
    time_t production_data;
    int shelf_life;

    item(string name, float price, int shelf_life, time_t production_data) {
        this->name = name;
        this->price = price;
        this->production_data = production_data;
        this->shelf_life = shelf_life;
    }

    bool equals(item anotherItem) {
        bool a = name == anotherItem.name;
        bool b = this->price == anotherItem.price;
        bool c = this->production_data == anotherItem.production_data;
        bool d = this->shelf_life == anotherItem.shelf_life;

        if (a && b && c && d) {
            return true;
        }
        return false;
    }
};