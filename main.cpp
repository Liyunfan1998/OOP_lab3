#include "main.h"

using namespace std;


int main() {
//    std::vector<int> a = {11, 2, 13};
//    a.erase(std::find(a.begin(),a.end(),2));
//    a.erase(a.begin() + 1);
//    std::cout << "my vector contains:";
//    for (int i = 0; i < a.maxSize(); i++)
//        std::cout << " " << a[i];
//    std::cout << std::endl;
    familyMart familyMart1;
    familyMart1.loadFromFile("/Users/luke1998/Desktop/OOP/lab3/lab3/sell.txt");


    familyMart1.loadFromShopFile("/Users/luke1998/Desktop/OOP/lab3/lab3/shop.txt");
    bool b = getType("fruit") == fruit;
    std::cout << b << std::endl;
    return 0;
}