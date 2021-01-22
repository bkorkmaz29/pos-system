#ifndef RESTAURANT_H_INCLUDED
#define RESTAURANT_H_INCLUDED
#include <iostream>
#include <cstring>
#include <vector>
#include "..\Restaurant2\Server.h"
#include "..\Restaurant2\Item.h"
#include "..\Restaurant2\Table.h"
#include "..\Restaurant2\Table_List.h"

using namespace std;

class Restaurant{
char* restaurant_name;
int amount_table;
Table_List *paid;//table list for tables used throughout the day, paid and left
Table_List *active;//active table list
vector<Table_List*> archive;//vector of pointers to table lists archived
vector<Server*> server_list;//vector of pointers to the servers
vector<Item*> item_list;//vector of pointers to items available
Server *get_Server(int server_no);//gets a pointer to a server
bool exist_server(int server_id);//checks if server exists
bool exist_item(int item_id);//check if item exists
bool check_assigned(int table_no);//checks if a server assigned
Item *get_item_at(int item_id);//returns the item with given id

public:
Restaurant(char *restaurant_name, int amount_table);//creates a restaurant and a list of active table list and paid table list
~Restaurant();
void modify_restaurant(char *restaurant_name, int amount_table);//updating restaurant
void add_server(int server_id, char *server_name);//adds a new server to the server list
void delete_server(int server_id);//removes a server from the server list
void assign_server(int server_id,int table_no);//assign a server to a table
void add_item(int item_id, char* item_name, float item_price);//adds new item to the item list
void delete_item(int item_id);//deletes an existing item from the list
void modify_item(int item_id,char* item_name, float item_price);//modifies an existing item by searching for its id and changing other data
void add_item_to(int table_no, int item_id);//adds an item to a table
void remove_item(int table_no, int item_id);//removes an item from a table
void copy_to_paid(int table_no);//copies an active table and adds it to the paid list, used in clean_table function
void clean_table(int table_no);//copies table to the paid list, cleans the list of orders and assigned server for the table
void end_day(int day,int month,int year);//copies non-empty active table list to the paid list, copies paid list to the archive and cleans both active and paid list
void archive_list(int day,int month,int year);//creates a new list from paid list and adds it to archive vector
void delete_archived(int day,int month,int year);//delete a archived list
void total_day();//calculates the total amount of earnings for the active and paid list
void total_archived_list(int day,int month,int year);//total earnings of a day in archive
void total_month(int month,int year);//calculates the total amount of earnings for all of the lists in given month
void total_year(int year);//calculates the total amount of earnings for the given year
void print_server_list();//prints info of the server
void print_active_assignments();//prints the list of servers assignment info
void print_tables();//prints the active tables
void print_paid_table(int table_no);//prints a table from paid list
void print_paid();//print paid list
void print_items();//prints all the items
void print_table_info(int table_no);//prints the orders of a single table
void print_archived_list(int day, int month, int year);//prints a list from the archive
};

#endif // RESTAURANT_H_INCLUDED
