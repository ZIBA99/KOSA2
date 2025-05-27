#include "client.h"

// 생성자
Client::Client(int id, std::string name, std::string phoneNumber, std::string address)
    : m_id(id), m_name(name), m_phoneNumber(phoneNumber), m_address(address) {
}

// Getter
int Client::id() const { return m_id; }
std::string Client::getName() const { return m_name; }
std::string Client::getPhoneNumber() const { return m_phoneNumber; }
std::string Client::getAddress() const { return m_address; }

// Setter (const std::string&)
void Client::setName(const std::string& name) { m_name = name; }
void Client::setPhoneNumber(const std::string& phoneNumber) { m_phoneNumber = phoneNumber; }
void Client::setAddress(const std::string& address) { m_address = address; }

// 비교 연산자
bool Client::operator==(const Client& other) const {
    return m_name == other.m_name;
}
