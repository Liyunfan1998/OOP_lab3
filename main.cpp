#include "main.h"

using namespace std;

void readFromCin(familyMart familyMart1) {
    string str;
    string ppwd = getCurrentParentDir();
    vector<string> vec;
    while (getline(cin, str)) {
        string::size_type idx0 = str.find("purchase file");
        string::size_type idx1 = str.find("sell file");
        string::size_type idx2 = str.find("show_sale_amount");
        string::size_type idx3 = str.find("show_all_shop_name");
        string::size_type idx4 = str.find("close");
        if (idx0 != string::npos) {
            vec = split(str, '(', ')');
            string fileName = vec[1];
            familyMart1.loadFromPurchaseFile(ppwd + fileName);
        } else if (idx1 != string::npos) {
            vec = split(str, '(', ')');
            string fileName = vec[1];
            familyMart1.loadFromSellFile(ppwd + fileName);
        } else if (idx2 != string::npos) {
            int saleTotal = 0;
            for (auto shopx: familyMart1.shops) {
                saleTotal += shopx.salesRecord;
            }
            cout << saleTotal << endl;
        } else if (idx3 != string::npos) {
            string allNames;
            for (auto shopx: familyMart1.shops) {
                allNames += shopx.name + '\t';
            }
            cout << allNames << endl;
        } else if (idx4 != string::npos) {
            exit(0);
        }
    }
}


int main() {
//    std::vector<int> a = {11, 2, 13};
//    a.erase(std::find(a.begin(),a.end(),2));
//    a.erase(a.begin() + 1);
//    std::cout << "my vector contains:";
//    for (int i = 0; i < a.maxSize(); i++)
//        std::cout << " " << a[i];
//    std::cout << std::endl;
    familyMart familyMart1;
    string ppwd = getCurrentParentDir();
    cout << ppwd << endl;
    familyMart1.loadFromShopFile(ppwd + "shop.txt");
//    familyMart1.loadFromSellFile(ppwd + "sell.txt");
//    familyMart1.loadFromPurchaseFile(ppwd + "purchase.txt");
    readFromCin(familyMart1);
    return 0;
}