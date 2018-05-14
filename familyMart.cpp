//
// Created by Yunfan Li on 2018/5/13.
//
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

#include "shop.cpp"

using namespace std;

const vector<string> split(string s, char c);

const time_t str2Time(string dateStr);


class familyMart {

public:
    vector<shop> shops;

    vector<string> loadFromFile(string filePath) {
        vector<string> out;
        char buffer[256];
        ifstream in(filePath);
        if (!in.is_open()) {
            cout << "Error opening file";
            exit(1);
        }
        while (!in.eof()) {
            in.getline(buffer, 100);
            out.push_back(buffer);
        }
        cout << "I" << endl;
        return out;
    }

    shop getShopByName(string shopName) {
        for (auto shop :shops) {
            if (shop.name == shopName) {
                return shop;
            }
        }
    }


    void loadFromSellFile(string filePath) {
        char buffer[256];
        vector<string> out;
        float discount;
        shop tmpShop = shop("");
        ifstream in(filePath);
        if (!in.is_open()) {
            cout << "Error opening file";
            exit(1);
        }
        while (!in.eof()) {
            in.getline(buffer, 100);
            string bufferStr = buffer;
            if (bufferStr.length() == 0) {
                continue;
            }
            string::size_type idx1 = bufferStr.find("SALE");
            if (idx1 != string::npos) {
                out = split(bufferStr, ' ', '\t');
                string::size_type idx2 = out[1].find("SHOP");
                if (idx2 != string::npos) {
                    discount = 1;
                    tmpShop = getShopByName(out[1]);
                } else {
                    discount = stof(out[1]);
                    tmpShop = getShopByName(out[2]);
                }
                continue;
            } else {
                item item1 = tmpShop.wh->getItemOfCertainTypeRandomly(bufferStr);
                if (item1.type == noType) {
                    cout << "no item(" << bufferStr << ") left" << endl;
                    continue;
                }
                tmpShop.sell(item1, discount);
                cout << "Sales record:  " << tmpShop.salesRecord << endl;
                if (tmpShop.salesRecord >= 55) {
                    shop newShop = shop("SHOP" + (shops.size() + 1));
                    shops.push_back(newShop);
                    tmpShop.salesRecord -= 55;
                }
            }
        }
        cout << "sell finish" << endl;
    }

    void loadFromShopFile(string filePath) {
        vector<string> out;
        shop tmpShop = shop("");
        char buffer[256];

        ifstream in(filePath);
        if (!in.is_open()) {
            cout << "Error opening file";
            exit(1);
        }
        while (!in.eof()) {
            in.getline(buffer, 100);
            string bufferStr = buffer;
            string::size_type idx1 = bufferStr.find("SHOP");
            if (idx1 != string::npos) {
                out = split(bufferStr, ' ', '\t');
                shop shop1 = shop(out[0],out[1]);
                shops.push_back(shop1);
                tmpShop = shop1;
                continue;
            }
            string::size_type idx2 = bufferStr.find("name");
            if (idx2 != string::npos) {
                continue;
            }
            string::size_type idx3 = bufferStr.find("/");
            if (idx3 == string::npos) {
                continue;
            }
            out = split(bufferStr, ' ', '\t');
            item newItem = item(out[0], stof(out[1]), stoi(out[2]), str2Time(out[3]));
            tmpShop.wh->supplyItem(newItem);
        }
        cout << "load finish" << endl;
    }

    void loadFromPurchaseFile(string filePath) {
        vector<string> out;
        shop tmpShop = shop("");
        char buffer[256];

        ifstream in(filePath);
        if (!in.is_open()) {
            cout << "Error opening file";
            exit(1);
        }
        while (!in.eof()) {
            in.getline(buffer, 100);
            string bufferStr = buffer;
            if (bufferStr.length() == 0) {
                continue;
            }
            string::size_type idx1 = bufferStr.find("PURCHASE");
            if (idx1 != string::npos) {
                out = split(bufferStr, ' ', '\t');
                tmpShop = getShopByName(out[2]);
                continue;
            }
            string::size_type idx2 = bufferStr.find("name");
            if (idx2 != string::npos) {
                continue;
            }
            string::size_type idx3 = bufferStr.find("/");
            if (idx3 == string::npos) {
                continue;
            }
            out = split(bufferStr, ' ', '\t');
            item newItem = item(out[0], stof(out[1]), stoi(out[2]), str2Time(out[3]));
            tmpShop.wh->supplyItem(newItem);
        }
        cout << "purchase finish" << endl;
    }

};

/*
shop initShopFromVecStr(vector<string> vs) {
    vector<string> tmp;
    shop shop1;
    for (auto s : vs) {
        tmp = split(s, ' ');
        item newItem = item(tmp[0], stof(tmp[1]), stoi(tmp[2]), str2Time(tmp[3]));
        shop1.wh->supplyItem(newItem);
    }
    return shop1;
}*/