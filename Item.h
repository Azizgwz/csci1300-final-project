#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item {
private:
    string name;
    string type;
    int value;
    bool bundleItem;

public:
    Item(string n, string t, int v, bool bundle);
    string getName();
    string getType();
    int getValue();
    bool isBundleItem();
    void displayItem();
};

#endif