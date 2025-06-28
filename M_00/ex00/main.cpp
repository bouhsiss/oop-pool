#include "Bank.hpp"
#include <iostream>

void tryDelete(Bank& bank, int id) {
    try {
        bank.deleteAccount(id);
        std::cout << "Account " << id << " deleted successfully." << std::endl;
    } catch (std::exception& e) {
        std::cout << "delete failed for account " << id << ": " << e.what() << std::endl;
    }
}

void tryDeposit(Bank& bank, int id, int amount) {
    try {
        bank.deposit(id, amount);
        std::cout << "Deposit of " << amount << " to account " << id << " successful." << std::endl;
    } catch (std::exception& e) {
        std::cout << "Deposit failed for account " << id << ": " << e.what() << std::endl;
    }
}

void tryWithdraw(Bank& bank, int id, int amount) {
    try {
        bank.withdraw(id, amount);
        std::cout << "Withdrawal of " << amount << " from account " << id << " successful." << std::endl;
    } catch (std::exception& e) {
        std::cout << "Withdrawal failed for account " << id << ": " << e.what() << std::endl;
    }
}

int main()
{
    try
    {
        Bank bank(1000);

        Account& acc1 = bank.createAccount(100);
        Account& acc2 = bank.createAccount(200);
        Account& acc3 = bank.createAccount(0);

        std::cout << "== intial state  ==\n" << bank << std::endl;

        // valid operations
        tryDeposit(bank, acc1.getId(), 300);
        tryWithdraw(bank, acc2.getId(), 50);
        bank.loan(acc3.getId(), 400);

        std::cout << "== after valid operations ==\n" << bank << std::endl;

        // error cases
        tryDeposit(bank, acc1.getId(), -10);
        tryWithdraw(bank, acc1.getId(), 99999);
        tryDelete(bank, acc2.getId());

        // deleting accounts
        tryWithdraw(bank, acc2.getId(), acc2.getBalance());
        tryDelete(bank, acc2.getId());

        std::cout << "== after deleting accounts ==\n" << bank << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}