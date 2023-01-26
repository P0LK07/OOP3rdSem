#pragma once
#include <ctime>
#include <fmt/core.h>
#include <string>
#define EXIT -1
#define OK 0;
#define ERROR 1;

typedef int Hash; 


template<class T>
std::string m_to_string(T value, int size) {
    std::string res = std::to_string(value);
    if(size < res.size())
        res.resize(size);
    else
        for(int a = res.size(), b = 1; a < size;a++)
            if(b){
                res = ' ' + res;
                b = 0;
            } else {
                res += ' ';
                b = 1;
            }
    return res;
}
/**
* My own class for counting date.
*/
class Date{
private:
    unsigned year;
    unsigned month;
    unsigned day;
public:
    Date(unsigned, unsigned, unsigned);
    unsigned to_months() const;
    unsigned to_years() const;
    Date operator-(const Date) const;
    bool operator==(const Date) const;
    bool operator<(const Date) const;
    bool operator<=(const Date) const;
    bool operator>(const Date) const;
    bool operator>=(const Date) const;
    std::string show() const;
};