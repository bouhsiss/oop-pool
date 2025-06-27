#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>

class Account {
    private:
        int _id;
        int _balance;

        // only bank creates accounts
        Account(int id, int initial);

    public:
        // read only accessors
        const int& getId() const;
        const int& getBalance() const;

        // friends classes/methods
        friend class Bank;
        friend std::ostream& operator<<(std::ostream &os, const Account &account);
};

std::ostream& operator<<(std::ostream &os, const Account &account);


#endif