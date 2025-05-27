#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
private:
    int m_id;
    std::string m_name;
    std::string m_phoneNumber;
    std::string m_address;

public:
    Client(int id, std::string name, std::string phoneNumber, std::string address);

    // Getter
    int id() const;
    std::string getName() const;
    std::string getPhoneNumber() const;
    std::string getAddress() const;

    // Setter (const std::string&로 수정)
    void setName(const std::string& name);
    void setPhoneNumber(const std::string& phoneNumber);
    void setAddress(const std::string& address);

    // 비교 연산자
    bool operator==(const Client& other) const;
};

#endif



