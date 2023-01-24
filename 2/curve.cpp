#include "curve.hpp"
Curve::Curve()
{
    this->n = 1.0;
}
double Curve::get_square() const
{
    return (pow(this->n, 2)/2);
}
double Curve::get_chord() const
{
    return this->n/sqrt(2.0);
}
double Curve::get_center_polar(double angle) const
{
    return this->n/3.0 * cos(angle)*sin(angle)/(pow(cos(angle),3) + pow(sin(angle),3));
}
double Curve::get_Rcurve_top() const
{
    return n / (8.0 * sqrt(2));
}
double Curve::get_Rcurve_bottom() const
{
    return n / 2.0;
}
double Curve::get_len_of_biggest() const
{
    return sqrt(1.5)*n*sqrt(2*sqrt(3) - 3);
}
double Curve::get_len_to_biggest() const
{
    return sqrt(0.5)*n;
}