#include "Item.h"
#include <iostream>
using namespace std;

Item::Item(string n, string t, int v, bool bundle) {
    name = n;
    type = t;
    value = v;
    bundleItem = bundle;
}

string Item::getName() { return name; }
string Item::getType() { return type; }
int Item::getValue() { return value; }
bool Item::isBundleItem() { return bundleItem; }

void Item::displayItem() {
    cout << "- " << name << " (" << type << ") - $" << value << endl;
}