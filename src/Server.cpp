#include <iostream>
#include <cstring>
#include <cmath>
#include "..\Restaurant2\Server.h"

using namespace std;


Server::Server(char *server_name, int server_id){
    this->server_name = new char[strlen(server_name) + 1]();
    strcpy(this->server_name, server_name);
    this->server_id = server_id;
}

Server::~Server(){
    delete[] this->server_name;
}

char *&Server::refServer_name(){
    return this->server_name;
}

int &Server::refServer_id(){
    return this->server_id;
}

ostream & operator<< (ostream& os, const Server &x){
    os << x.server_name << ", " << x.server_id<<endl;
    return os;
}
