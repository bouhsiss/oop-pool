#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <vector>
#include <set>
#include <list>

#include "Account.hpp"

class Bank {
    private:
        int _liquidity;
        std::list<Account> _accounts;
        std::set<int> _usedIds;

        static const float FEE_RATE;

        // accounts iterators
        typedef std::list<Account>::iterator AccountIterator;
        typedef std::list<Account>::const_iterator ConstAccountIterator;

        // get account by ID
        AccountIterator findAccount(int id);
    
    public:
        Bank(void);
        Bank(int _liquidity);

        // read only accessors
        const int& getLiquidity() const;

        // account management
        Account& createAccount(int initial = 0);
        void deleteAccount(int id);

        // account operations
        void deposit(int id, int amount);
        void withdraw(int id, int amount);
        void loan(int id, int amount);

        // friend classes/methods
        friend std::ostream& operator<<(std::ostream &os, const Bank &bank);
};

std::ostream& operator<<(std::ostream &os, const Bank &bank);

#endif