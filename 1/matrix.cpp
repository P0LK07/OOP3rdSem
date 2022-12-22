#include "matrix.hpp"
#include <iostream>
#include <stdlib.h>
#include <cstring>

Matrix::Matrix()
{
    this->matrix = nullptr;
    this->sizex = 0;
    this->sizey = 0;
    this->maxsize = 0;
}

int count_number(int a)
{
    int res = 1;
    while(a / 10)
    {
        res++;
        a /= 10;
    }
    return res;
}

Matrix::Row* Matrix::get_row(int y)
{
    Row* ret = this->matrix;
    while(ret->offset != y && ret->next != nullptr)
        ret = ret->next;
    return ret;

}
void Matrix::insert(int y, int x, int value)
{
    if(!value)
        return;
    int count = count_number(value);
    this->maxsize =(this->maxsize > count ? this->maxsize : count);
    if(!this->matrix)
    {
        //std::cout << "[DBG]matrix_done;Inserted value " << value << " with offset y " << y << " and x " << x << "\n";
        this->matrix = (Row*)calloc(1, sizeof(Row));
        this->matrix->row = (Element*)calloc(1, sizeof(Element));
        this->matrix->maxsize = count;
        this->matrix->offset = y;
        this->matrix->row->value = value;
        this->matrix->row->offset = x;
        return;

    }
    Row* insert_row = this->get_row(y);
    if(insert_row->offset != y)
    {
        insert_row->next = (Row*)calloc(1, sizeof(Row));
        insert_row = insert_row->next;
        insert_row->row = (Element*)calloc(1, sizeof(Element));
        insert_row->maxsize = count;
        insert_row->offset = y;
        insert_row->row->value = value;
        insert_row->row->offset = x;
        //std::cout << "[DBG]Inserted new Element at the end with value " << value << " with offset y " << y << " and x " << x << "\n";
    }else{
        //std::cout << "[DBG]Inserted new Element in the middle value " << value << " with offset y " << y << " and x " << x << "\n";
        Element* n = (Element*)calloc(1, sizeof(Element));
        Element* current = insert_row->row;
        while(current->offset < x && current->next != nullptr)
            current = current->next;
        insert_row->maxsize = (insert_row->maxsize > count ? insert_row->maxsize : count);
        if(current->offset > x)
        {
            std::memcpy(n, current, sizeof(Element));
            current->next = n;
            current->value = value;
            current->offset = x;   
        }else{
            current->next = n;
            n->value = value;
            n->offset = x;
        }
    }

}
void Matrix::remove(int y, int x)
{
    if(!this->matrix)
        return;
    Row* remove_row = this->get_row(y);
    if(remove_row->offset == y)
    {
        Element* current = remove_row->row;
        while(current->offset != x && current->next != nullptr)
            current = current->next;
        if(current->offset == x)
        {
            current->value = 0;
        }
    }

}

void Matrix::input()
{
    std::cout << "Enter column number: ";
    std::cin >> this->sizex;
    std::cout << "Enter rows number: ";
    std::cin >> this->sizey;
    std::cout << "Enter matrix:\n";
    for(int a = 0; a < this->sizey; a++)
        for(int b = 0; b < this->sizex; b++)
        {
            int value;
            std::cin >> value;
            if(value)
                this->insert(a,b,value);
        }
}



Matrix* Matrix::transform()
{
    Matrix* ret = new Matrix;
    Row* matrix = this->matrix;
    int maxx = 0;
    while(matrix != nullptr)
    {
        Element* row = matrix->row;
        int i = 0;
   //     std::cout << "MAX count of numbers in " << matrix->offset << " is " <<matrix->maxsize << "\n";
        while(row != nullptr)
        {
            if(count_number(row->value) == matrix->maxsize)
            {
                ret->insert(matrix->offset, i, row->value);
                i++;
            }
            row = row->next;
        }
        maxx = (maxx > i ? maxx : i);
        matrix = matrix->next;
    }
    ret->set_sizey(this->sizey);
    ret->set_sizex(maxx);
    return ret;
}

void write_line(int size)
{
    for(int a = 0; a < size; a++)
        std::cout << '-';
    std::cout << '\n'; 
}

int Matrix::get(int x,int y)
{
    Row *m = this->matrix;
    while(m)
    {
        Element *r = m->row;
        if(m->offset == y)
            while(r)
            {
                if(r->offset == x)
                    return r->value;
                r = r->next;
            }
        m = m->next;
    }
    return 0;
}

void Matrix::output()
{
    write_line(this->maxsize*this->sizex); 
    for(int a = 0; a < this->sizey; a++)
    {
        for(int b = 0; b < this->sizex; b++)
            std::cout << this->get(b,a) << ' ';
        std::cout << '\n';
    }
    write_line(this->sizex*this->maxsize);
}
Matrix::~Matrix()
{
    Row* m = this->matrix;
    while(m)
    {
        Row *f = m;
        m = m->next;
        Element *r = f->row;
        while(r)
        {
            Element *ff = r;
            r = r->next;
            free(ff);
        }
        free(f);
    }
}