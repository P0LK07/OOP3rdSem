#include "binvec.hpp"
#include <iostream>
BinVec::BinVec()
{
    vec = nullptr;
    size = 0;
}
void BinVec::_resize(const int new_size)
{
    if(size == new_size)
        return;
    char *n = new char[new_size];
    for(int i = new_size - 1, a = size - 1; (i + 1); a--, i--)
    {
        n[i] = (a > 0 ? vec[a]: 0);
    }
    if(vec)
        delete[] vec;
    vec = n;
    size = new_size;
}

BinVec::BinVec(const BinVec& vector)
: size(vector.len())
{
    vec = new char[size];
    for(int a = 0; a < size; a++)
        vec[a] = vector[a];
}

BinVec::BinVec(BinVec&& p)
: vec(p.vec)
, size(p.len())
{
    p.vec = nullptr;
    p.size = 0;
}

BinVec::BinVec(int number)
{
    std::string bin = "";
    while(number)
    {
        bin = (char)(number % 2) + bin; 
        number /= 2;
    }
    size = bin.length();
    vec = new char[size];
    for(int i = 0; i < size; i++)
        vec[i] = bin[i];
}

BinVec& BinVec::operator=(int number)
{
    if(size)
    {
        delete[] vec;
    }
    std::string bin = "";
    while(number)
    {
        bin = (char)(number % 2) + bin; 
        number /= 2;
    }
    size = bin.length();
    vec = new char[size];
    for(int i = 0; i < size; i++)
        vec[i] = bin[i];
    return *this;
}

int BinVec::len() const
{
    return size;
}
char BinVec::operator[](int index) const
{
    if(index < size && index >= 0)
        return vec[index];
    else
        throw std::range_error("vector not initialized");
        
}
char& BinVec::operator[](int index)
{
    if(index < size && index >= 0)
        return vec[index];
    else
        throw std::range_error("vector not initialized");
        
}

BinVec& BinVec::operator=(const BinVec& vector)
{
    int maxsize = (size > vector.len() ? size : vector.len());
    this->_resize(maxsize);
    for(int a = size - 1, b = vector.len() -1; a >= 0; a--, b--)
        vec[a] = (b >= 0 ? vector[b] : 0 );
    return *this;
}

BinVec BinVec::operator^(const BinVec vector)
{
    BinVec res;
    int minsize = (size < vector.len() ? size : vector.len());
    res._resize(minsize);
    for(int a = size - 1, b = vector.len() - 1; (a + 1); a--, b--)
        res[(a < b ? a : b)] = vec[a] ^ vector[b]; 
    return res;
}
BinVec BinVec::operator|(const BinVec vector)
{
    BinVec res;
    int minsize = (size < vector.len() ? size : vector.len());
    res._resize(minsize);
    minsize--;
    for(int a = size - 1, b = vector.len() - 1; (a + 1); a--, b--)
        res[(a < b ? a : b)] = vec[a] | vector[b];
    return res;
}
BinVec BinVec::operator&(const BinVec vector)
{
    BinVec res;
    int minsize = (size < vector.len() ? size : vector.len());
    res._resize(minsize);
    for(int a = size - 1, b = vector.len() - 1;(a + 1); a--, b--)
        res[(a < b ? a : b)] = vec[a] & vector[b];
    return res;
}//BinVec shrink(BinVec);
void BinVec::shrink()
{
    int l_offset = 0, r_offset = size - 1;
    for(; l_offset < size && !vec[l_offset]; l_offset++);
    for(; (r_offset + 1) && !vec[r_offset]; r_offset--);
    size = r_offset - l_offset + 1;
    char *new_ptr = new char[size];
    for(int a = l_offset, b = 0; a <= r_offset; a++, b++)
        new_ptr[b] = vec[a];
    delete[] vec;
    vec = new_ptr;
}
BinVec::~BinVec()
{
    delete[] vec;
}