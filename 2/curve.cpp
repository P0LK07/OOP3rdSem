#include "curve.hpp"
Curve::Curve()
{
    this->n = 1.0;
    this->angle = 1.0;
}
double Curve::get_square()
{
    return (pow(this->n, 2)/2);
}
double Curve::get_chord()
{
    return this->n/sqrt(2.0);
}
double Curve::get_center_polar()
{
    return this->n/3.0 * cos(this->angle)*sin(this->angle)/(pow(cos(this->angle),3) + pow(sin(this->angle),3));
}
double Curve::get_Rcurve_top()
{
    return n / (8.0 * sqrt(2));
}
double Curve::get_Rcurve_bottom()
{
    return n / 2.0;
}
double Curve::get_len_of_biggest()
{
    return sqrt(1.5)*n*sqrt(2*sqrt(3) - 3);
}
double Curve::get_len_to_biggest()
{
    return sqrt(0.5)*n;
}