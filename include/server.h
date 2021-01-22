#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED

#include <iostream>
using namespace std;


class Server{
char* server_name;
int server_id;

public:
Server(char *server_name, int server_id);
~Server();
char *&refServer_name();
int &refServer_id();
friend ostream & operator<< (ostream& os,const Server &x);
};


#endif // SERVER_H_INCLUDED
