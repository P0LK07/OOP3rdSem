#pragma once
#include "table.hpp"
#include "casual.hpp"
#include "deposit.hpp"
#include <iostream>
#include <cstdlib>

class App {
private:
    Table<Hash, Deposit> table;
    void show_help() const;
    void insert();
    int main_menu();
    void manage_deposit();
    void insert_casual();
    void insert_fast();
    void insert_currency();
    void modify_deposit(std::shared_ptr<Deposit>);
    void close_deposit(std::shared_ptr<Deposit>);
    void insert_money(std::shared_ptr<Deposit>);
    void take_perc(std::shared_ptr<Deposit>);
    void take_money(std::shared_ptr<Deposit>);
public:
    App();
    void start();
};