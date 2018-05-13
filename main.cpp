#include "main.h"

using namespace std;

string getDateStr(time_t nowtime) {
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y/%m/%d", localtime(&nowtime));
    return tmp;
}

const vector<string> split(const string &s, const char &c) {
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

const int str2int(const string &string_temp) {
    return atoi(string_temp.c_str());
}

const time_t str2Time(const string dateStr) {
    const char pat = '/';
    vector<string> ymd = split(dateStr, pat);
    int y = str2int(ymd[0]);
    int m = str2int(ymd[1]);
    int d = str2int(ymd[2]);
    struct tm date;
    date.tm_year = y;
    date.tm_mon = m;
    date.tm_mday = d;
    time_t dt = mktime(&date);
    return dt;
}


int main() {
//    std::vector<int> a = {11, 2, 13};
//    a.erase(std::find(a.begin(),a.end(),2));
//    a.erase(a.begin() + 1);
//    std::cout << "my vector contains:";
//    for (int i = 0; i < a.maxSize(); i++)
//        std::cout << " " << a[i];
//    std::cout << std::endl;
    shop shop1;
    time_t time1 = str2Time("2018/05/11");
    item item1 = item("1", 1, 1, time1);
    item item2 = item("2", 1, 1, time1);
    item item3 = item("3", 1, 1, time1);
//    shop1.items.push_back(item1);
//    shop1.items.push_back(item2);
//    shop1.items.push_back(item3);
    shop1.purchase(item1);
    shop1.purchase(item2);
    shop1.purchase(item3);
    for (int i = 0; i < shop1.items.size(); i++)
        std::cout << " " << shop1.items[i].name;
    std::cout << std::endl;
    shop1.sell(item2);
    for (int i = 0; i < shop1.items.size(); i++)
        std::cout << " " << shop1.items[i].name;
    shop1.sell(item1);
    shop1.sell(item3);
    return 0;
}