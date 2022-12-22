#include "./binvec.hpp"
#include <iostream>

void status(BinVec vec)
{
   std::cout << "{";
   int l = vec.len();
   for(int a = 0; a < l; a++)
      std::cout << (int)vec[a] << (a == l - 1 ?'\0':',');
   std::cout << "}\n";
}
template <typename T>
T binput()
{
   T unref;
   std::cin >> unref;
   while(std::cin.fail())
   {
      if(std::cin.eof())
         exit(0);
      std::cout << "Error occured\nTry again: ";
      std::cin.clear();
      std::cin >> unref;
   }
   return unref;

}
void rstatus(BinVec value, std::string operation)
{
   std::cout << operation + " result:\n";
   status(value);
}

int menu(BinVec vec1, BinVec vec2)
{
   int exec = 1;
   char choice;
   int repr;
   while(exec)
   {
      std::cout << "> ";
      choice = binput<char>();
      switch(choice)
      {
         case '1':
         case '2':
            std::cout << "Enter integer value for binary vector: ";
            repr = binput<int>();
            if(choice == '1')
            {
               vec1 = repr;
               rstatus(vec1, "vec1 now");
            }
            else
            {
               vec2 = repr;
               rstatus(vec2, "vec2 now");
            }
            break;
         case 'e':
            exec = 0;
            break;
         case '&':
            rstatus(vec1 & vec2, "AND");
            break;
         case '|':
            rstatus(vec1 | vec2, "OR");
            break;
         case '^':
            rstatus(vec1 ^ vec2, "XOR");
            break;
         case 's':
            vec1.shrink();
            vec2.shrink();
            rstatus(vec1, "vec1 shrink");
            rstatus(vec2, "vec2 shrink");
            break;
         default:
            std::cout << "Invalid option\n";        
      } 
   }
   return 0;
}

int main()
{
   BinVec a, b;
   menu(a,b);
   return 0;
} 