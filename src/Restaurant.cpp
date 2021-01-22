#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include "..\Restaurant2\Table_List.h"
#include "..\Restaurant2\Item.h"
#include "..\Restaurant2\Table.h"
#include "..\Restaurant2\Restaurant.h"

using namespace std;

Restaurant::Restaurant(char *restaurant_name, int amount_table){
    this->restaurant_name = restaurant_name;
    this->restaurant_name = new char[strlen(restaurant_name) + 1]();
    this->amount_table = amount_table;
    this->active = new Table_List();
    this->paid = new Table_List();
    for(int i = 0; i<amount_table; ++i){
        this->active->add_table(i+1);
        }
    }


Restaurant::~Restaurant(){
    delete[] this->restaurant_name;
    delete this->active;
    delete this->paid;
}


void Restaurant::modify_restaurant(char *restaurant_name, int amount_table){
    this->restaurant_name = restaurant_name;
    this->restaurant_name = new char[strlen(restaurant_name) + 1]();
    this->amount_table = amount_table;
}

bool Restaurant::exist_server(int server_id){
    auto it = server_list.begin();
    while (it != server_list.end() && (*it)->refServer_id() != server_id){
        ++it;
    }
    if (it == server_list.end()){
        return false;
    }
    return true;
}


void Restaurant::add_server(int server_id, char *server_name){
    if(this->exist_server(server_id))
        cout<<"Server with this id already exist"<<endl;
    else
    this->server_list.push_back(new Server(server_name,server_id));
}

void Restaurant::delete_server(int server_id){
    for(unsigned i = 0;i < this->server_list.size(); ++i){
        if (this->server_list[i]->refServer_id() == server_id){
            delete server_list[i];
            this->server_list.erase(this->server_list.begin() + i);
            cout<<"Server "<<server_id<<" deleted"<<endl;
        }
    }

}

Server *Restaurant::get_Server(int server_id){
    auto it = this->server_list.begin();
    while (it != this->server_list.end() && (*it)->refServer_id() != server_id){
        it++;
    }
    return *it;
}

void Restaurant::print_server_list(){
    for(unsigned i = 0; i < server_list.size(); ++i){
    cout<<*server_list[i];
    }
    cout<<endl;
}

void Restaurant::assign_server(int server_id,int table_no){
    if(!(this->exist_server(server_id)))
        cout<<"Server with this id doesn't exist"<<endl;
    else
        this->active->assign_to(get_Server(server_id),table_no);
        cout<<"Server "<<server_id<<" assigned to table  "<<table_no<<endl;
}

void Restaurant::print_active_assignments(){
    active->print_assignment();
}

void Restaurant::print_tables(){
    cout<<*active<<endl;
}

void Restaurant::add_item(int item_id, char* item_name, float item_price){
    if(this->exist_item(item_id))
        cout<<"Item with this id already exist"<<endl;
    else
    item_list.push_back(new Item(item_id, item_name, item_price));
}

void Restaurant::delete_item(int item_id){
    auto it = item_list.begin();
    while (it != item_list.end()){
        if((*it)->refItem_id() == item_id){
        delete *it;
        this->item_list.erase(it);
        cout<<"Item "<<item_id<<" deleted"<<endl;
        return;
        }
    it++;
    }
}

Item *Restaurant::get_item_at(int item_id){
    auto it = item_list.begin();
    while (it != item_list.end() && (*it)->refItem_id() != item_id){
        it++;
    }
    return *it;
}

void Restaurant::add_item_to(int table_no, int item_id){
    if(!(this->exist_item(item_id)))
        cout<<"Item with this id doesn't exist"<<endl;
    else if(table_no > this->amount_table)
        cout<<"Table with this number doesn't exist"<<endl;
    else
        this->active->add_to_table(table_no, this->get_item_at(item_id));
        cout<<"Item: "<<item_id<<" "<<"added to table "<<table_no<<endl;
}

void Restaurant::print_items(){
    if(item_list.empty())
        cout<<"item list is empty"<<endl;
    else
     for(unsigned i = 0; i < item_list.size(); ++i){
        cout<<*item_list[i];
    }
    cout<<endl;
}

void Restaurant::print_table_info(int table_no){
    cout<<endl;
    this->active->print_info_of(table_no);
}

void Restaurant::remove_item(int table_no, int item_id){
    if(table_no > this->amount_table)
        cout<<"Table with this number doesn't exist"<<endl;
    else
        this->active->remove_from_table(table_no, this->get_item_at(item_id));
        cout<<"Item "<<item_id<<" removed from "<<table_no<<endl;
}

void Restaurant::clean_table(int table_no){
    if(table_no <= amount_table){
        if(this->active->check_table(table_no)){
            copy_to_paid(table_no);
            this->active->clean_table(table_no);
        }
    else
        return;
    }
}

void Restaurant::print_paid_table(int table_no){
   this->paid->print_info_of(table_no);
}

void Restaurant::copy_to_paid(int table_no){
    paid->add_table(this->active->copy_of(table_no));
}

void Restaurant::print_paid(){
    cout<<*paid<<endl;
}

bool Restaurant::exist_item(int item_id){
    auto it = item_list.begin();
    while (it != item_list.end() && (*it)->refItem_id() != item_id){
        it++;
    }
    if (it == item_list.end()){
        return false;
    }
    return true;
}

void Restaurant::archive_list(int day, int month, int year){

    Table_List *copyList = new Table_List(*paid);

    if(day > 0 && day < 32 && month > 0 && month < 13 && year > 0){
    copyList->refDay() = day;
    copyList->refMonth() = month;
    copyList->refYear() = year;
    }
    else
        cout<<"invalid arguments"<<endl;

    archive.push_back(copyList);

}

void Restaurant::print_archived_list(int day, int month, int year){
    for(unsigned i = 0; i < archive.size(); ++i){
        if(archive[i]->refDay() == day && archive[i]->refMonth() == month && archive[i]->refYear() == year)
            cout<<*archive[i]<<endl;
    }
}


void Restaurant::end_day(int day,int month,int year){
    for(int i=1; i != this->amount_table; ++i){
        this->clean_table(i);
    }
    this->archive_list(day,month,year);

}

void Restaurant::total_day(){
    float total = 0;
    total =  this->paid->sum_total();
    cout<<"Total earnings of today: "<<total<<endl;
}

void Restaurant::total_archived_list(int day,int month,int year){
     for(unsigned i = 0; i < archive.size(); ++i){
        if(archive[i]->refDay() == day && archive[i]->refMonth() == month && archive[i]->refYear() == year)
            cout<<"Total earnings of "<<day<<"/"<<month<<"/"<<year<<" : "<<archive[i]->sum_total()<<endl;
    }
}

void Restaurant::total_month(int month, int year){
     float Total = 0;

     for(unsigned i = 0; i < archive.size(); ++i){
        if(archive[i]->refMonth() == month && archive[i]->refYear() == year)
           Total = archive[i]->sum_total() + Total;
        }

    cout<<"Total earnings of "<<month<<"/"<<year<<" : "<<Total<<endl;

}

void Restaurant::total_year(int year){
     float Total = 0;

     for(unsigned i = 0; i < archive.size(); ++i){
        if(archive[i]->refYear() == year)
           Total = archive[i]->sum_total() + Total;
        }
    cout<<"Total earnings of "<<year<<" : "<<Total<<endl;
}

void Restaurant::delete_archived(int day,int month,int year){
    auto it =  archive.begin();
    while (it != archive.end()){
        if((*it)->refDay() == day && (*it)->refMonth() == month && (*it)->refYear() == year){
            delete *it;
            this->archive.erase(it);
            return;
        }
        it++;
    }
}


