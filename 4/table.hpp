#pragma once 
#include "casual.hpp"
#include "deposit.hpp"
#include <iterator>
#include <cstddef>
#include <memory>
#include <iostream>

/*
*Template map class.
*/
template <class T1, class T2>
class Table {
public:
    struct Element {
        T1 key;
        std::shared_ptr<T2> ptr;
    };
    Table(): tab(nullptr), len(0){}
    Table(Table<T1, T2>&& table): tab(table.tab), len(table.len) {
        table.tab = nullptr;
    }
    Table(const Table<T1, T2> &table)
    {
        tab = new Element[table.size()];
        len = table.size();
        for(int a = 0; a < len; a++)
        {
            tab[a].key = table.tab[a].key;
            tab[a].ptr = table.tab[a].ptr;
        }
    }
    Table<T1, T2>& operator=(const Table<T1, T2>& table){
        _resize(table.len);
        for(int a = 0; a < len; a++)
        {
            tab[a].key = table.tab[a].key;
            tab[a].ptr = table.tab[a].ptr;
        }
        return *this;
    }
    Table<T1, T2>& operator=(Table<T1, T2>&& table){
        size_t mlen = len;
        len = table.len
        table.len = mlen;
        struct Element *ptr = tab;
        tab = table.tab;
        table.tab = ptr;
        return *this;
    }
    void Insert(std::shared_ptr<T2> new_element){
        if(!check_unique(new_element->GetCode()))
            throw ERROR;
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
        for(int a = 0; a < len; a++) {
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
    /**
    * Get value by key.
    */
    std::shared_ptr<T2> operator[](T1 key){
        for(int a = 0; a < len; a++) {
        if(tab[a].key == key)
            return tab[a].ptr;
    }
    throw ERROR;
    }
    /**
    * Output table.
    */    
    void Show(std::string header) const{
        std::cout << header << '\n';
        for(int a = 0; a < len; a++)
            std::cout << tab[a].ptr->TableShow() << '\n';
    }
    size_t size() const { return len; }

    ~Table() {
        if(tab != nullptr)
            delete[] tab;
        len = 0;
    }
private:
    /**
    * Check if key unique for current table.
    */
    bool check_unique(T1 key) const {
        for(int a = 0; a < len; a++)
            if(tab[a].key == key)
                return false;
        return true;
    }
    struct Element *tab;
    size_t len;
    void _resize(size_t new_size) {
        Element* new_tab = new Element[new_size];
        for(int a = 0; a < new_size; a++) {
            if(a < len) {
                new_tab[a].key = tab[a].key;
                new_tab[a].ptr = tab[a].ptr;
           }else{
                new_tab[a].key = 0;
               new_tab[a].ptr = nullptr;
           }
        }
        if(tab != nullptr)
           delete[] tab;
        tab = new_tab;
        len = new_size;
    }
};
