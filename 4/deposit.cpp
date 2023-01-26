#include "deposit.hpp"

Deposit::Deposit(Hash code, double value, double percent, Date date):
 deposit_number(code), value(value), percent(percent), open_date(date), oper_date(date){
}
double Deposit::GetValue() const{
    return value;
}
/**
* Get percents that will add to deposit by current_date.
*/
double Deposit::CountPercents(Date current_date){
    if(current_date < oper_date)
        throw ERROR;
    Date diff = current_date - oper_date;
    oper_date = current_date;
    int months_count =  diff.to_months();
    double midle_count = value, answer = 0;
    for(int a = 0; a < months_count; a++) {
        answer += midle_count * percent;
        midle_count += midle_count * percent; 
    }
    return answer;
}
Hash Deposit::GetCode() const{
    return deposit_number;
}
Date Deposit::GetOpenDate() const{
    return open_date;
}
Date Deposit::GetLastOperationDate() const{
    return oper_date;
}
void Deposit::SetLastOperationDate(Date new_date){
    if(new_date <= oper_date)
        throw ERROR;
    oper_date = new_date;
}
void Deposit::SetValue(double new_value){
    if(new_value > 0)
        value = new_value;
    else
        throw ERROR;
}
void Deposit::AddValue(double new_value){
    double predict = new_value + value;
    if(predict > 0)
        value = predict;
    else
        throw ERROR;
}

std::string Deposit::Show(){
    return fmt::v9::format("Deposit type: Casual\nNumber: {}\nOpen date: {}\nLast operation date: {}\nCurrency: RUB\nValue: {}\nPercent: {}\n", 
    deposit_number, open_date.show(), oper_date.show(), value, percent);
}

/*
* Special output as table row.
*/
std::string Deposit::TableShow(){
    return fmt::v9::format("|{}|{}|{}|{}|{}|{}|{}|{}|", 
    m_to_string(deposit_number, 10),
    " Casual  ", 
    open_date.show(), 
    oper_date.show(),
    "RUB", 
    m_to_string(1.0, 4),
    m_to_string(value, 10), 
    m_to_string(percent, 4));
}

std::string FastDeposit::Show(){
    return fmt::v9::format("Deposit type: Fast\nNumber: {}\nOpen date: {}\nLast operation date: {}\nEnd_date: {}\nCurrency: RUB\nValue: {}\nPercent: {}\n", 
    deposit_number, open_date.show(), oper_date.show(), end_date.show(), value, percent);
}
std::string CurrencyDeposit::Show(){
    return fmt::v9::format("Deposit type: Currency\nNumber: {}\nOpen date: {}\nLast operation date: {}\nCurrency: {}\nValue: {}\nValue(in RUB): {}\nPercent: {}\n", 
    deposit_number, open_date.show(), oper_date.show(),currency_name, value, ToRUB(), percent);
}
double CurrencyDeposit::ToRUB() const{
    return value * currency_diff;
}
FastDeposit::FastDeposit(Hash code, double value, double percent, Date date, Date end): Deposit(code, value, percent, date),
 end_date(end){
}
/*
* Special output as table row.
*/
std::string FastDeposit::TableShow(){
    return fmt::v9::format("|{}|{}|{}|{}|{}|{}|{}|{}|", 
    m_to_string(deposit_number, 10),
    "  Fast   ", 
    open_date.show(), 
    oper_date.show(),
    "RUB", 
    m_to_string(1.0, 4),
    m_to_string(value, 10), 
    m_to_string(percent, 4));
}
CurrencyDeposit::CurrencyDeposit(Hash code, std::string name, double value, double percent,double diff, Date date):
Deposit( code, value, percent, date), currency_name(name), currency_diff(diff){}
/*
* Special output as table row.
*/
std::string CurrencyDeposit::TableShow() {
    return fmt::v9::format("|{}|{}|{}|{}|{}|{}|{}|{}|", 
    m_to_string(deposit_number, 10),
    "Currency ", 
    open_date.show(), 
    oper_date.show(),
    currency_name, 
    m_to_string(currency_diff, 4),
    m_to_string(value, 10), 
    m_to_string(percent, 4));
}