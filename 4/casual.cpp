#include "casual.hpp"
Date::Date(unsigned D, unsigned M, unsigned Y):
year(Y), month(M), day(D){}
unsigned Date::to_months()
{
    return month + year * 12;
    
}
unsigned Date::to_years()
{
    return year;
}
Date& Date::operator-(Date a)
{
    year -= a.year;
    month -= a.month;
    day -= a.day;
    if(day <= 0){
        day += 31;
        month -= 1;
    }
    if(month <= 0)
    {
        month += 12;
        year -= 1;
    }
    return *this;
}
std::string special(unsigned var, unsigned size){
    std::string res = std::to_string(var);
    while(res.size() < size)
        res = '0' + res;
    return res;
}
std::string Date::show()
{
    return fmt::v9::format("{}.{}.{}", special(day, 2), special(month, 2), special(year, 4));
}