#include "clientmanager.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>

ClientManager::ClientManager() {
    std::ifstream file("clientlist.txt");
    if (file.is_open()) {
        while (!file.eof()) {
            std::vector<std::string> row = parseCSV(file, ',');
            if (!row.empty() && row.size() >= 4) {
                int id = std::stoi(row[0]);
                Client* c = new Client(id, row[1], row[2], row[3]);
                clientList.insert({ id, c });
            }
        }
    }
    file.close();
}

ClientManager::~ClientManager() {
    std::ofstream file("clientlist.txt");
    if (file.is_open()) {
        for (const auto& v : clientList) {
            Client* c = v.second;
            file << c->id() << ", " << c->getName() << ", "
                << c->getPhoneNumber() << ", " << c->getAddress() << std::endl;
        }
    }
    file.close();

    // �޸� ����
    for (auto& pair : clientList) {
        delete pair.second;
    }
}

int ClientManager::makeId() {
    return clientList.empty() ? 0 : (--clientList.end())->first + 1;
}

std::vector<std::string> ClientManager::parseCSV(std::istream& file, char delimiter) {
    std::vector<std::string> row;
    std::string line;
    if (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        while (std::getline(ss, cell, delimiter)) {
            cell.erase(0, cell.find_first_not_of(" \n\r\t"));
            cell.erase(cell.find_last_not_of(" \n\r\t") + 1);
            row.push_back(cell);
        }
    }
    return row;
}

void ClientManager::inputClient() {
    std::string name, number, address;
    std::cout << "name : "; std::cin >> name;
    std::cout << "number : "; std::cin >> number;
    std::cin.ignore();  // ���� ����
    std::cout << "address : "; std::getline(std::cin, address);

    int id = makeId();
    Client* c = new Client(id, name, number, address);
    clientList.insert({ id, c });
}

Client* ClientManager::search(int id) {
    auto it = clientList.find(id);
    return (it != clientList.end()) ? it->second : nullptr;
}

void ClientManager::deleteClient(int key) {
    auto it = clientList.find(key);
    if (it != clientList.end()) {
        delete it->second;
        clientList.erase(it);
    }
}

void ClientManager::modifyClient(int key) {
    Client* c = search(key);
    if (!c) {
        std::cout << "Client not found.\n";
        return;
    }
    std::cout << "  ID  |     Name     | Phone Number |       Address" << std::endl;
    std::cout << std::setw(5) << std::setfill('0') << std::right << c->id() << " | "
        << std::left << std::setw(12) << c->getName() << " | "
        << std::setw(12) << c->getPhoneNumber() << " | "
        << c->getAddress() << std::endl;

    std::string name, number, address;
    std::cout << "name : "; std::cin >> name;
    std::cout << "number : "; std::cin >> number;
    std::cin.ignore();
    std::cout << "address : "; std::getline(std::cin, address);

    c->setName(name);
    c->setPhoneNumber(number);
    c->setAddress(address);
}

void ClientManager::displayInfo() {
    std::cout << "\n  ID  |     Name     | Phone Number |       Address\n";
    for (const auto& v : clientList) {
        Client* c = v.second;
        std::cout << std::setw(5) << std::setfill('0') << std::right << c->id() << " | "
            << std::left << std::setw(12) << c->getName() << " | "
            << std::setw(12) << c->getPhoneNumber() << " | "
            << c->getAddress() << std::endl;
    }
}

void ClientManager::addClient(Client* c) {
    clientList.insert({ c->id(), c });
}
bool ClientManager::displayMenu() {
    int ch, key;
    std::cout << "\033[2J\033[1;1H";
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++\n";
    std::cout << "              �� ���� ���α׷�                \n";
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++\n";
    std::cout << "  1. �� ��� ����                            \n";
    std::cout << "  2. �� ���� �Է�                            \n";
    std::cout << "  3. �� ���� ����                            \n";
    std::cout << "  4. �� ���� ����                            \n";
    std::cout << "  5. ���α׷� ����                             \n";
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++\n";
    std::cout << " �����ϼ���: ";
    std::cin >> ch;
    std::cin.ignore();  // ���� ó��

    switch (ch) {
    case 1:
    default:
        displayInfo();
        std::cin.ignore();
        getchar();
        break;
    case 2:
        inputClient();
        break;
    case 3:
        displayInfo();
        std::cout << " ������ �� ID�� �Է��ϼ���: ";
        std::cin >> key;
        deleteClient(key);
        break;
    case 4:
        displayInfo();
        std::cout << " ������ �� ID�� �Է��ϼ���: ";
        std::cin >> key;
        modifyClient(key);
        break;
    case 5:
        return false;
    }
    return true;
}

