#ifndef DEPOSIT
#define DEPOSIT
#include "casual.hpp"
#include <string>

class Deposit {
    protected:
    Hash deposit_number;
    double value;
    double percent;
    Date open_date;
    Date oper_date;
    public:
    Deposit(Hash, double, double, Date);
    double GetValue() const;
    double GetPercent() const {return percent;};
    double CountPercents(Date);
    Hash GetCode() const;
    Date GetOpenDate() const;
    Date GetLastOperationDate() const;
    void SetLastOperationDate(Date new_date);
    void SetValue(double new_value);
    void AddValue(double);
    virtual std::string Show();
    virtual std::string TableShow();
};

class FastDeposit : public Deposit{
    private:
    Date end_date;

    public:
    FastDeposit(Hash, double, double, Date ,Date);
    std::string Show();
    std::string TableShow();
};
class CurrencyDeposit : public Deposit{
    private:
    std::string currency_name;
    double currency_diff;
    double ToRUB() const;
    public:
    CurrencyDeposit(Hash code, std::string, double value, double percent,double, Date date);
    std::string Show();
    std::string TableShow();
};
#endif