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

    void loadFromSellFile(string filePath) {
        vector<vector<string>> vecs;
        vector<string> vec = loadFromFile(filePath);
        for (auto s: vec) {
            split(s, ' ');
        }
    }

    void loadFromShopFile(string filePath) {
        vector<shop> vecShop;
        vector<string> out;
        shop tmpShop;
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
                shop shop1 = shop();
                vecShop.push_back(shop1);
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
            out = split(bufferStr, '\t');
            item newItem = item(out[0], stof(out[1]), stoi(out[2]), str2Time(out[3]));
            tmpShop.wh->supplyItem(newItem);
            out.push_back(buffer);
        }
        cout << "load finish" << endl;
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

const vector<string> split(string s, char c) {
    string buff = "";
    vector<string> v;

    for (auto n:s) {
        if (n != c) {
            buff += n;
        } else if (n == c && buff != "") {
            v.push_back(buff);
            buff = "";
        }
    }
    if (buff != "") v.push_back(buff);

    return v;
}

string getDateStr(time_t nowtime) {
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y/%m/%d", localtime(&nowtime));
    return tmp;
}

const time_t str2Time(string dateStr) {
    char pat = '/';
    vector<string> ymd = split(dateStr, pat);
    int y = stoi(ymd[0]);
    int m = stoi(ymd[1]);
    int d = stoi(ymd[2]);
    struct tm date;
    date.tm_year = y;
    date.tm_mon = m;
    date.tm_mday = d;
    time_t dt = mktime(&date);
    return dt;
}