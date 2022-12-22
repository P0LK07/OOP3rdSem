#include <gtest/gtest.h>
#include "curve.hpp"

namespace{
    TEST(Curve, DefautConstructor)
    {
        Curve c;
        EXPECT_EQ(1.0, c.get_n());
        EXPECT_EQ(1.0, c.get_angle());
    }
    TEST(Curve, Setters)
    {
        Curve c;
        EXPECT_EQ(1.0, c.get_n());
        EXPECT_EQ(1.0, c.get_angle());
        c.set_n(2.3);
        c.set_angle(-9.3);
        EXPECT_EQ(2.3, c.get_n());
        EXPECT_EQ(-9.3, c.get_angle());
    }
    TEST(Curve, Functions)
    {
        Curve c;
        c.set_n(100);
        c.set_angle(6.0);
        bool done = (double)(c.get_center_polar() * c.get_chord() * c.get_len_of_biggest() * c.get_len_to_biggest() * c.get_Rcurve_bottom() * c.get_Rcurve_top() * c.get_square()) != (double)0.0;
        EXPECT_EQ(1, done);
    }
}
int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
