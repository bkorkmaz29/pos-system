#include <iostream>


#include "..\Restaurant2\Server.h"
#include "..\Restaurant2\Item.h"
#include "..\Restaurant2\Table.h"
#include "..\Restaurant2\Restaurant.h"
#include "..\Restaurant2\Table_List.h"
using namespace std;

int main()
{

//Initialization of the restaurant
Restaurant *rest = new Restaurant ("EOOP",8);

rest->add_item(1,"Salad",8.99);
rest->add_item(2,"Soup",6.00);
rest->add_item(3,"Pasta",14.99);
rest->add_item(4,"Steak",28.99);
rest->add_item(5,"Burger",24.25);
rest->add_item(6,"Cake",7.99);
rest->add_item(7,"Water",1.99);
rest->add_item(8,"Cola",2.99);

rest->print_items();

rest->add_server(1,"Mike");
rest->add_server(2,"Derek");
rest->add_server(3,"Sarah");
rest->add_server(4,"Maria");

rest->print_server_list();

{//Testing the delete function of server and item//commented out for other testing to work

    cout<<"--------Testing of server and item list delete functions---------"<<endl;

    rest->delete_item(6);
    rest->print_items();
    rest->delete_item(6);
    rest->delete_item(7);
    rest->delete_item(17);//nothing happens if item doesn't exist
    cout<<"List after deleting item 6 and 7"<<endl;
    rest->print_items();
    rest->add_item(6,"Ice Cream",7.99);
    rest->add_item(7,"Wine",10.50);

    rest->delete_server(4);
    cout<<"List after deleting server 4"<<endl;
    rest->print_server_list();
    rest->delete_server(7);//nothing happens if server doesn't exist
    rest->delete_server(3);
    rest->delete_server(2);
    rest->delete_server(1);
    rest->print_server_list();
    rest->delete_server(1);
    rest->add_server(1,"Brock");//servers can be added again after deletion
    rest->add_server(2,"Jake");
    rest->add_server(3,"Susan");
    rest->add_server(4,"Emma");
    rest->print_server_list();
}

{
    cout<<"---------Testing of assigning servers to tables----------"<<endl;
    rest->assign_server(3,1);
    rest->assign_server(2,2);
    rest->assign_server(1,4);
    rest->assign_server(2,5);
    rest->assign_server(4,6);
    rest->assign_server(3,7);
    rest->print_active_assignments();


    rest->assign_server(4,7);//reassigning table
    rest->print_active_assignments();
    rest->assign_server(2,11);//assigning to a table doesn't exist
    rest->print_active_assignments();

}

{
    cout<<"----------Testing of adding items to and removing items from tables-----------"<<endl;

    rest->add_item_to(1,1);
    rest->add_item_to(1,2);
    rest->add_item_to(1,1);
    rest->add_item_to(2,8);
    rest->add_item_to(2,2);
    rest->add_item_to(4,5);
    rest->add_item_to(4,3);
    rest->add_item_to(4,1);
    rest->add_item_to(5,6);
    rest->add_item_to(6,2);
    rest->add_item_to(6,3);
    rest->add_item_to(6,7);
    rest->add_item_to(7,5);
    rest->print_tables();



    rest->add_item_to(8,4);//If a table has no server, can't add item
    rest->add_item_to(12,2);//if a table doesn't exist, can't add item
    rest->add_item_to(6,9);//if an item doesn't exist, can't add item

    rest->remove_item(4,1);
    rest->remove_item(7,5);
    rest->remove_item(7,1);//Nothing happens if the table is already empty
    rest->remove_item(11,5);//If table doesn't exist, can't remove item
    rest->remove_item(6,4);//nothing happens if the table doesn't have that item
    cout<<"Deleted item 1 from table 4"<<endl;
    rest->print_tables();
}

{   cout<<"---------Testing cleaning tables----------"<<endl;
    rest->clean_table(1);
    rest->clean_table(3);
    rest->clean_table(11);//nothing happens if table doesn't exist
    rest->print_tables();
    rest->print_paid();
}

{
    cout<<"---------Testing ending day---------"<<endl;
    rest->end_day(29,5,2020);
    rest->print_tables();
    rest->print_archived_list(29,5,2020);

}


{
   cout<<"-----------Simulating a new day--------"<<endl;
    cout<<"Everything should be empty after ending last day"<<endl;
    rest->print_active_assignments();
    rest->print_paid();
    rest->print_tables();
    rest->assign_server(1,1);
    rest->assign_server(2,2);
    rest->assign_server(3,3);
    rest->assign_server(4,4);

    rest->add_item_to(1,2);
    rest->add_item_to(1,3);
    rest->add_item_to(2,5);
    rest->add_item_to(3,2);
    rest->add_item_to(3,6);
    rest->add_item_to(4,8);

    rest->clean_table(1);
    rest->clean_table(2);
    rest->assign_server(2,1);
    rest->assign_server(1,2);
    rest->add_item_to(2,1);
    rest->add_item_to(2,3);
    rest->add_item_to(1,4);
    rest->add_item_to(1,6);

    rest->end_day(229,1111,202);//won't work because of invalid date
    rest->end_day(30,5,2020);

    cout<<"printing list"<<endl;
    rest->print_archived_list(11,5,2020);//won't work because list doesn't exist
    rest->print_archived_list(30,5,2020);
}


{
    cout<<"----------Testing summing up total earnings---------"<<endl;
    rest->total_day();//should show the total of today
    rest->total_archived_list(29,5,2020);
    rest->total_archived_list(30,5,2020);
    rest->total_month(5,2020);
    rest->total_month(5,2020);
    rest->total_year(2020);
    rest->total_month(1,2020);//nothing happens because no list from that month
    rest->total_year(2020);//nothing happens because no list from that year

}


{
    cout<<"----------Testing deleting archived list---------"<<endl;
    rest->total_month(5,2020);
    rest->delete_archived(30,5,2020);
    cout<<"30.05 deleted"<<endl;
    rest->total_month(5,2020);
}






delete rest;


    return 0;
}
