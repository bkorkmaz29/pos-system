#ifndef TABLE_LIST_H_INCLUDED
#define TABLE_LIST_H_INCLUDED
#include <iostream>
#include <cstring>
#include <vector>
#include "..\Restaurant2\Item.h"
#include "..\Restaurant2\Table.h"

using namespace std;

class Table_List{
int day;
int month;
int year;
vector<Table*> tables;//vector of pointers to the tables in the list
Table *table_at_no(int table_no);//gets the pointer to a table for the given table number

public:
Table_List();
~Table_List();
Table_List(const Table_List & x);//copy constructor
Table_List & operator = (const Table_List & x);//assignment operator
int &refDay();
int &refMonth();
int &refYear();
vector<Table*> &refTables();
void update(int day, int month, int year);
int count_tables();//counts the no of tables in the list
float total_amount();//calculates the total amount of earnings for the list
void copy_all_tables(const Table_List& x);//copying used when copying to a list there are already tables in the list
bool check_if_empty(Table *table);//checks if a table empty or not
void assign_to(Server *server,int table_no);
void print_assignment();//prints assigned servers
void add_table(int table_no);//add new table to the list
void add_table(Table *table);//add a new table to the list
void add_to_table(int table_no, Item *item );//add a item to the table
void print_info_of(int table_no);//print the info of a table
void remove_from_table(int table_no, Item *item);//remove an item from table
void clean_table(int table_no);//clean the items and assigned server from table
Table *copy_of(int table_no);//returns a copy of a table
void print_all();//print the all list
void clean_all();//clean all the list
bool check_table(int table_no);//check if a table empty
float sum_total();//sums up the total earnings from the list
friend ostream & operator<< (ostream& os,const Table_List &x);

};

#endif // TABLE_LIST_H_INCLUDED
