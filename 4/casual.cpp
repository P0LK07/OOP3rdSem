#include "casual.hpp"
/**
* Create Date class object.
* @param D Days
* @param M Month
* @param Y Year
*/
Date::Date(unsigned D, unsigned M, unsigned Y):
year(Y), month(M), day(D){}
/**
* Count number of months between date 0.0.0000 and current date. 
*/
unsigned Date::to_months() const {
    return month + year * 12;
    
}
/**
* Count number of years between date 0.0.0000 and current date. 
*/
unsigned Date::to_years() const {
    return year;
}

bool Date::operator==(const Date date) const {
    return date.day == day && date.month == month && date.year == year;
}
/**
* Get difference between current date and some date. 
*/
Date Date::operator-(const Date a) const {
    Date ret(0,0,0);
    ret.year = year - a.year;
    ret.month = month - a.month;
    ret.day = day - a.day;
    if(ret.day <= 0){
        ret.day += 31;
        ret.month -= 1;
    }
    if(ret.month <= 0) {
        ret.month += 12;
        ret.year -= 1;
    }
    return ret;
}
std::string special(unsigned var, unsigned size){
    std::string res = std::to_string(var);
    while(res.size() < size)
        res = '0' + res;
    return res;
}
bool Date::operator<=(const Date date) const {
    return year < date.year || (year == date.year && month < month 
    || (month == date.month && day <= date.day));
}

bool Date::operator<(const Date date) const {
    return year < date.year || (year == date.year && month < month 
    || (month == date.month && day < date.day));
}

bool Date::operator> (const Date date) const {
    return year > date.year || (year == date.year && month > month 
    || (month == date.month && day > date.day));
}

bool Date::operator>= (const Date date) const {
    return year > date.year || (year == date.year && month > month 
    || (month == date.month && day >= date.day));
}
/**
* Return string in DD.MM.YYYY format.
*/
std::string Date::show() const {
    return fmt::v9::format("{}.{}.{}", special(day, 2), special(month, 2), special(year, 4));
}