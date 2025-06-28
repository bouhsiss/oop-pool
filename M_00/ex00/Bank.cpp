#include "Bank.hpp"
#include <stdexcept>

// static member initialization
const float Bank::FEE_RATE = 0.05;

// constructor for Bank class
Bank::Bank(void) : _liquidity(0) {}
Bank::Bank(int liquidity) {
    if (liquidity < 0) {
        throw std::runtime_error("Initial liquidity cannot be negative");
    }
    _liquidity = liquidity;
}

// get account by ID
Bank::AccountIterator Bank::findAccount(int id)
{
    for (AccountIterator it = _accounts.begin(); it != _accounts.end(); ++it) {
        if (it->getId() == id) {
            return it;
        }
    }
    return _accounts.end();
}

const int& Bank::getLiquidity() const
{
    return _liquidity;
}

// account management
Account& Bank::createAccount(int initial)
{
    int newId = _accounts.empty() ? 1 : _accounts.back().getId() + 1;

    _accounts.push_back(Account(newId, 0));
    std::cout << "Created account with ID: " << newId << std::endl;
    if (initial)
        deposit(newId, initial);
    return _accounts.back();
}

void Bank::deleteAccount(int id)
{
    AccountIterator it = findAccount(id);
    if (it == _accounts.end())
        throw std::runtime_error("Account not found");

    if(it->getBalance() > 0) {
        throw std::runtime_error("Cannot delete account with positive balance");
    }

    _accounts.erase(it);
}


void Bank::deposit(int id, int amount)
{
    if (amount <= 0) {
        throw std::runtime_error("Deposit amount must be positive");
    }

    AccountIterator it = findAccount(id);
    if (it == _accounts.end()) {
        throw std::runtime_error("Account not found");
    }

    float fee = amount * FEE_RATE;
    it->_balance += (amount - fee);
    this->_liquidity += fee;
}

void Bank::withdraw(int id, int amount)
{
    AccountIterator it = findAccount(id);
    if (it == _accounts.end()) {
        throw std::runtime_error("Account not found");
    }
    if (amount <= 0 || amount > it->getBalance()) {
        throw std::runtime_error("Insufficient funds");
    }
    it->_balance -= amount;
}

void Bank::loan(int id, int amount)
{
    if(amount <= 0 || amount > _liquidity) {
        throw std::runtime_error("Loan refused");
    }

    AccountIterator it = findAccount(id);
    if (it == _accounts.end()) {
        throw std::runtime_error("Account not found");
    }
    it->_balance += amount;
    _liquidity -= amount;
}

std::ostream& operator<<(std::ostream &os, const Bank &bank)
{
    os << "Bank liquidity: " << bank._liquidity << "\n";
    os << "Accounts:\n";
    for (Bank::ConstAccountIterator it = bank._accounts.begin(); it != bank._accounts.end(); ++it) {
        os << *it << "\n";
    }
    return os;
}