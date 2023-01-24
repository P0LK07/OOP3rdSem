#include "./curve.hpp"
#include <iostream>
#include <climits>
void status(Curve *curve, double angle)
{
   std::string list[] = {
      "----------------------------------------\n",
      "n = ",
      "angle = ",
      "Size of chord: ",
      "Square of loop: ",
      "Length to the center of polar coordinates: ",
      "Radius of curvature in top: ",
      "Radius of curvature in botom: ",
      "Length of the biggest diameter: ",
      "Length to the biggest diameter: "
   };
   double values[] = {
      curve->get_n(),
      angle,
      curve->get_chord(),
      curve->get_square(),
      curve->get_center_polar(angle),
      curve->get_Rcurve_top(),
      curve->get_Rcurve_bottom(),
      curve->get_len_of_biggest(),
      curve->get_len_to_biggest()
   };
   std::cout << list[0];
   for(int i = 0; i < 8; i++)
   {
      std::cout << list[i + 1] << values[i] << '\n';
   }
   std::cout << list[0];
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
int main()
{
   Curve curve;
   bool exec = 1;
   double angle = 1.0;
   int option;
   double new_value;
   std::cout << "Decart list curve:\nx^3 + y^3 = nxy\n1 - change n\n2 - change angle\nEnter 3 to exit\n";
   while(exec)
   {
      status(&curve, angle);
      std::cout << "> ";
      option = binput<int>();
      switch(option)
      {
         case 1:
            std::cout << "Enter new n: ";
            new_value = binput<double>();
            curve.set_n(new_value);
            break;
         case 2:
            std::cout << "Enter new angle: ";
            angle = binput<double>();
            break;
         case 3:
            exec = 0;
            break;
         default:
            std::cout << "Ivalid choice\n";
      }
   }
}