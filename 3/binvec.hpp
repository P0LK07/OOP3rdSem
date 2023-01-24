#ifndef BINVEC
#define BINVEC
#include<stdexcept>

class BinVec{
    private:
        char *vec;
        int size;
        void _resize(int);
    public:
        BinVec();
        BinVec(const BinVec&);
        BinVec(BinVec&&);
        BinVec(int);
        int len() const;
        BinVec& operator=(const BinVec&);
        BinVec& operator=(int);
        BinVec operator^(const BinVec);
        char operator[](int index) const;
        char& operator[](int index);
        BinVec operator|(const BinVec);
        BinVec operator&(const BinVec);
        
        void shrink();
        ~BinVec();
};
#endif