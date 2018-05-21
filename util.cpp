//
// Created by Yunfan Li on 2018/5/14.
//

#include <ctime>
#include <string>
#include <vector>

using namespace std;

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

const vector<string> split(string s, char c1, char c2) {
    string buff = "";
    vector<string> v;

    for (auto n:s) {
        if (n != c1 && n != c2) {
            buff += n;
        } else if ((n == c1 || n == c2) && buff != "") {
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
    time_t dt;
    struct tm *timeinfo;
    timeinfo = localtime(&dt);
    dt = mktime(timeinfo);
    return dt;
}

#include <unistd.h>

char *getcwd(char *buf, size_t size);

string getCurrentParentDir() {
    char *cwd;
    string ppwd = (string) getcwd(cwd, (size_t) (100));
    string string1 = "/cmake-build-debug";
    string::size_type idx2 = ppwd.find(string1);
    if (idx2 != string::npos) {
        ppwd = ppwd.substr(0, ppwd.length() - string1.length() + 1);

    }
    std::cout << "PWD: " << ppwd << std::endl;
    return ppwd;
}