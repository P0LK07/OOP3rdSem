#ifndef CURVE
#define CURVE
#include <cmath>
// x^3 + y^3 = nxy
class Curve{
    private:
        double n;
        double angle;
    public:
        Curve();
        void set_n(double new_value){this->n = new_value;}
        double get_n(){return this->n;}
        void set_angle(double new_value){this->angle = new_value;}
        double get_angle(){return this->angle;}
        double get_square();
        double get_chord();
        double get_center_polar();
        double get_Rcurve_top();
        double get_Rcurve_bottom();
        double get_len_of_biggest();
        double get_len_to_biggest();   
};
#endif