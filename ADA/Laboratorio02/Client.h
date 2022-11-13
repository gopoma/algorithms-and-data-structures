#include <string>

class Client {
    private:
        std::string firstname;
        std::string lastname;
        std::string dni;
        std::string password;
        std::string accountNumber;
        double balance; 
    public:
        Client(std::string _firstname, std::string _lastname, std::string _dni, std::string _password, std::string _accountNumber, double _balance);
        void setFirstname(std::string _firstname);
        std::string getFirstname();
        void setLastname(std::string _lastname);
        std::string getLastname();
        void setDNI(std::string _dni);
        std::string getDNI();
        void setPassword(std::string _password);
        std::string getPassword();
        void setAccountNumber(std::string _accountNumber);
        std::string getAccountNumber();
        void setBalance(double _balance);
        double getBalance();
};

Client::Client(std::string _firstname, std::string _lastname, std::string _dni, std::string _password, std::string _accountNumber, double _balance) {
    setFirstname(_firstname);
    setLastname(_lastname);
    setDNI(_dni);
    setPassword(_password);
    setAccountNumber(_accountNumber);
    setBalance(_balance);
}

void Client::setFirstname(std::string _firstname) {
    firstname = _firstname;
}

std::string Client::getFirstname() {
    return firstname;
}

void Client::setLastname(std::string _lastname) {
    lastname = _lastname;
}

std::string Client::getLastname() {
    return lastname;
}

void Client::setDNI(std::string _dni) {
    dni = _dni;
}

std::string Client::getDNI() {
    return dni;
}

void Client::setPassword(std::string _password) {
    password = _password;
}

std::string Client::getPassword() {
    return password;
}

void Client::setAccountNumber(std::string _accountNumber) {
    accountNumber = _accountNumber;
}

std::string Client::getAccountNumber() {
    return accountNumber;
}

void Client::setBalance(double _balance) {
    balance = _balance;
}

double Client::getBalance() {
    return balance;
}