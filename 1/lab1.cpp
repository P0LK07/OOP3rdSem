#include "./matrix.hpp"

int main()
{
   Matrix *a = new Matrix, *b = nullptr;
   a->input();
   a->output();
   b = a->transform();
   b->output();
   delete a;
   delete b;
}