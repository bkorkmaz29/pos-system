#include "..\Restaurant2\Item.h"
#include <iostream>
#include <cstring>

using namespace std;

Item::Item(int item_id, char *item_name, float item_price){
    this->item_id = item_id;
    this->item_name = new char[strlen(item_name) + 1]();
    strcpy(this->item_name, item_name);
    this->item_price = item_price;
}

Item::~Item(){
    delete[] this->item_name;
}

int &Item::refItem_id(){
    return this->item_id;
}

char *&Item::refItem_name(){
    return this->item_name;
}

float &Item::refitem_price(){
    return this->item_price;
}

ostream & operator<< (ostream& os,const Item &x){
    cout<<x.item_id<<", "<<x.item_name<<", "<<x.item_price<<endl;
}
