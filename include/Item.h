#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#include <iostream>

using namespace std;

class Item {
int item_id;
char* item_name;
char* item_type;
float item_price;

public:
Item(int item_id, char *item_name, float item_price);
~Item();
int &refItem_id();
char *&refItem_name();
float &refitem_price();
friend ostream & operator<< (ostream& os,const Item &x);
};


#endif // ITEM_H_INCLUDED
