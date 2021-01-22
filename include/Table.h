#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED
#include "..\Restaurant2\Item.h"
#include "..\Restaurant2\Server.h"

#include <iostream>
#include <vector>
using namespace std;

class Table{
int table_no;//can have same no since active list will be created beforehand
float table_total;
vector<Item*> orders;//vector of pointers for the items table ordered
Server * spt;//pointer to the server assigned for the table

public:
Table(int table_no);//0 for the total of the table and the status
~Table();
Table(const Table & x);//copy constructor
Table & operator = (const Table & x);//assignment operator
void update_total();//calculate and update the total payment of the table
int &refTable_no();
float &refTable_total();
Server *&refSpt();
friend ostream & operator<< (ostream& os, const Table &x);
void put_order(Item * ipt);//put a new item to the order list
void clean_table();//cleans the list of orders and assigned server, doesn't delete table
void print_info();//prints the info of table
void assign_server(Server * spt);//put the server pointer in to the table
void remove_order(Item *item);//removes an item from order list

};


#endif // TABLE_H_INCLUDED
