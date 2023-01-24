#pragma once 
#include "casual.hpp"
#include "deposit.hpp"
#include <iterator>
#include <cstddef>
#include <memory>
#include <iostream>

template <class T1, class T2>
class Table {
public:
    struct Element {
        T1 key;
        std::shared_ptr<T2> ptr;
    };
    Table(): tab(nullptr), len(0){}
    void Insert(std::shared_ptr<T2> new_element){
    size_t prev_len = len;
    _resize(len + 1);
    tab[prev_len].key = new_element->GetCode();
    tab[prev_len].ptr = new_element; 
    }
    void DeleteElement(T1 key){
    if(!len)
        throw ERROR;
    Element* prev = &(tab[0]);
    bool flag = false;
    for(int a = 0; a < len; a++)
    {
        if(flag){
            prev->key = tab[a].key;
            prev->ptr = tab[a].ptr;
        }
        if(tab[a].key == key)
            flag = true;
        prev = &(tab[a]);
    }
    if(!flag)
        throw ERROR;
    _resize(len-1);
    }
    std::shared_ptr<T2> operator[](T1 key){
    for(int a = 0; a < len; a++)
    {
    if(tab[a].key == key)
        return tab[a].ptr;
    }
    throw ERROR;
    }    
    void Show(std::string header)
    {
        std::cout << header << '\n';
        for(int a = 0; a < len; a++)
            std::cout << tab[a].ptr->TableShow() << '\n';
    }
    size_t size(){return len;};
    ~Table(){
    delete tab;
    len = 0;
    }
private:
    struct Element *tab;
    size_t len;
    void _resize(size_t new_size){
    Element* new_tab = new Element[new_size];
    for(int a = 0; a < new_size; a++)
    {
        if(a < len)
        {
            new_tab[a].key = tab[a].key;
            new_tab[a].ptr = tab[a].ptr;
        }else{
            new_tab[a].key = 0;
            new_tab[a].ptr = nullptr;
        }
    }
    delete[] tab;
    tab = new_tab;
    len = new_size;
}
};
