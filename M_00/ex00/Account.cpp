#include "Account.hpp"

// constructor for Account class
Account::Account(int id, int initial) : _id(id), _balance(initial) {}

// read only accessors
const int& Account::getId() const {
    return _id;
}
const int& Account::getBalance() const {
    return _balance;
}

// friend function to output account details
std::ostream& operator<<(std::ostream &os, const Account &account) {
    os << "[" << account._id << "] - [" << account._balance << "]";
    return os;
}

