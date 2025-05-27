#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include <map>
#include <vector>
#include <string>
#include <iostream>

#include "client.h"

class ClientManager {
private:
    std::map<int, Client*> clientList;

    int makeId();
    std::vector<std::string> parseCSV(std::istream& file, char delimiter);

public:
    ClientManager();
    ~ClientManager();

    bool displayMenu();
    void displayInfo();
    void inputClient();
    void deleteClient(int key);
    void modifyClient(int key);
    Client* search(int id);
    void addClient(Client* c);
};

#endif
