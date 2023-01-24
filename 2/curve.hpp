#ifndef CURVE
#define CURVE
#include <cmath>
// x^3 + y^3 = nxy
class Curve{
    private:
        double n;
    public:
        Curve();
        void set_n(double new_value){this->n = new_value;}
        double get_n() const {return this->n;}
        double get_square() const;
        double get_chord() const;
        double get_center_polar(double) const;
        double get_Rcurve_top() const;
        double get_Rcurve_bottom() const;
        double get_len_of_biggest() const;
        double get_len_to_biggest() const;   
};
#endif