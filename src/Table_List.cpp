#include <iostream>
#include <cstring>
#include <vector>
#include "..\Restaurant2\Table_List.h"
#include "..\Restaurant2\Item.h"
#include "..\Restaurant2\Table.h"


using namespace std;

Table_List::Table_List(){
    this->day = 0;
    this->month = 0;
    this->year = 0;
}

Table_List::~Table_List(){
}

int &Table_List::refDay(){
    return this->day;
}

int &Table_List::refMonth(){
    return this->month;
}

int &Table_List::refYear(){
    return this->year;
}

vector<Table*> &Table_List::refTables(){
    return this->tables;
}

void Table_List::add_table(int table_no){
    Table *table = new Table(table_no);
    this->tables.push_back(table);
}

void Table_List::add_table(Table *table){
    this->tables.push_back(table);
}

Table_List::Table_List(const Table_List & x){
    this->day = x.day;
    this->month= x.month;
    this->year = x.year;
    this->tables = x.tables;
}

void Table_List::update(int day, int month, int year){
    this->day = day;
    this->month = month;
    this->year = year;
}

int Table_List::count_tables(){
    return tables.size();
}

Table *Table_List::table_at_no(int table_no){
    auto it = this->tables.begin();
    while (it != this->tables.end() && (*it)->refTable_no() != table_no){
        it++;
    }
    return *it;

}

void Table_List::print_assignment(){

    for(unsigned i = 0; i < this->tables.size(); ++i){
        if(tables[i]->refSpt() != NULL){
        cout<<i+1<<" "<<this->tables[i]->refSpt()->refServer_name()<<endl;
        }
        else
            cout<<i+1<<" "<<"has no server assigned"<<endl;
    }
    cout<<endl;
}

ostream & operator<< (ostream& os,const Table_List &x){
    for(unsigned i = 0; i < x.tables.size(); ++i){
        cout<<*x.tables[i]<<endl;
    }
    return os;
}

void Table_List::assign_to(Server *server,int table_no){
    for(unsigned i = 0; i < tables.size(); ++i){
        if (table_no == tables[i]->refTable_no())
            tables[i]->assign_server(server);
    }
}

void Table_List::add_to_table(int table_no, Item *item){
    if(this->check_table(table_no))
        this->tables[(table_no - 1)]->put_order(item);
    else
        cout<<"This table has no server"<<endl<<endl;
}

void Table_List::print_info_of(int table_no){
    cout<<"Table: "<<table_no<<" server : ";
    this->tables[(table_no - 1)]->print_info();
}

void Table_List::remove_from_table(int table_no, Item *item){
    this->tables[(table_no - 1)]->remove_order(item);
}


void Table_List::clean_table(int table_no){
    if(this->table_at_no(table_no)->refSpt() != NULL)
        this->table_at_no(table_no)->clean_table();
    else
        return;
}

Table *Table_List::copy_of(int table_no){
    Table *copyTable = new Table(*this->table_at_no(table_no));
    return copyTable;
}

void Table_List::clean_all(){
    auto it = this->tables.begin();
    while (it != this->tables.end()){
        (*it)->clean_table();
        it++;
    }
}

bool Table_List::check_table(int table_no){
    auto it = this->tables.begin();
    while (it != this->tables.end() && (*it)->refTable_no() != table_no){
        it++;
    }
    if((*it)->refSpt() == NULL)
        return 0;
    else
        return 1;
}

float Table_List::sum_total(){
    float Total = 0;

    auto it = this->tables.begin();
    while (it != this->tables.end()){
        Total = (*it)->refTable_total() + Total;
        it++;
    }
    return Total;
}


