#include <iostream>
#include <cstring>
#include <vector>
#include "..\Restaurant2\Table.h"

using namespace std;

Table::Table(int table_no){
    this->table_no = table_no;
    this->table_total = 0;
    this->spt = NULL;
}

Table::~Table(){
}

int &Table::refTable_no(){
    return this->table_no;
}

float &Table::refTable_total(){
    return this->table_total;
}

Server *&Table::refSpt(){
    return this->spt;
}

Table::Table(const Table & x){
    this->table_no = x.table_no;
    this->table_total = x.table_total;
    this->spt = x.spt;
    this->orders = x.orders;
}

Table &Table::operator = (const Table & x){
    this->~Table();
    Table *table = new Table(x);
    return *table;
}

void Table::assign_server(Server *server){
    this->spt = server;
}

void Table::put_order(Item *item){
    orders.push_back(item);
    this->update_total();
}

void Table::print_info(){
    if(this->spt == NULL){
        cout<<"No server"<<endl;
    }
    else{
    cout<<this->spt->refServer_name()<<endl;
    }

    if(orders.empty())
        cout<<"No order"<<endl;
    else{
    for(unsigned i = 0; i<orders.size(); ++i){
        cout<<*orders[i];
    }
        cout<<"Total: "<<table_total<<endl;
    }
}

void Table::remove_order(Item *item){
    for(unsigned i = 0;i < orders.size(); ++i){
        if (orders[i] == item){
            orders.erase(orders.begin() + i);
        }
    }
    this->update_total();
}

void Table::clean_table(){
    this->spt = NULL;

    orders.clear();
}

void Table::update_total(){
    this->table_total = 0;
    for(unsigned i = 0;i < orders.size(); ++i){
        this->table_total = this->table_total + (orders[i]->refitem_price());
    }
}


ostream & operator<< (ostream& os, const Table &x){
    cout<<"Table No: "<<x.table_no<<"  ";
    if(x.spt == NULL){
        cout<<"No server"<<endl;
    }
    else {
        cout<<x.spt->refServer_name()<<endl;
    }

    if(x.orders.empty())
        cout<<"No order"<<endl;
    else {
        for(unsigned i = 0; i<x.orders.size(); ++i){
            cout<<*x.orders[i];
            }
        cout<<"Total: "<<x.table_total<<endl;
    }

    return os;
}

