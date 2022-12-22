#ifndef MATRIX
#define MATRIX
#include <stdlib.h>


class Matrix{
    private:
    struct Element{
        int offset;
        int value;
        struct Element* next;
    };
    struct Row{
        Element* row;
        int offset;
        int maxsize;
        struct Row* next;
    };
    Row* matrix;
    int sizex;
    int sizey;
    int maxsize;
    Row* get_row(int);
    public:
        void set_sizex(int a){this->sizex = a;}
        void set_sizey(int a){this->sizey = a;}
        int get(int, int);
        Matrix();
        void input();
        void insert(int,int,int);
        void remove(int, int);
        Matrix *transform();
        void output();
        ~Matrix();
};
#endif