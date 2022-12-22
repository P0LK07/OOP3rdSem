#include <gtest/gtest.h>
#include "binvec.hpp"

namespace
{
    TEST(BinVec, DefaultConstructor)
    {
        BinVec a;
        EXPECT_EQ(0, a.len());
    }
    TEST(BinVec, CopyConstructor)
    {
        BinVec a(12);
        BinVec b(a);
        EXPECT_EQ(a.len(), b.len());
        EXPECT_EQ(a[0], a[0]);
    }
    TEST(BinVec, intConstructor)
    {
        BinVec a(12);
        EXPECT_EQ(4, a.len());
        EXPECT_EQ(1, a[0]);
        EXPECT_EQ(1, a[1]);
    }
    TEST(BinVec, Operator_equal)
    {
        BinVec a(12),b;
        b = a;
        EXPECT_EQ(a.len(), b.len());
        EXPECT_EQ(a[0], b[0]);
        b = 3;
        EXPECT_EQ(b.len(), 2);
        EXPECT_EQ(a[0], 1);
    }
    TEST(BinVec, Operator_square_braces)
    {
        BinVec a(10);
        a[1] = 1;
        EXPECT_EQ(a[1], 1);
        EXPECT_EQ(a[3], 0);
    }
    TEST(BinVec, BinaryOperators)
    {
        BinVec a(1), b(1);
        BinVec Xor = a ^ b, And = a & b,Or = a | b;
        EXPECT_EQ(Xor[0], 0);
        EXPECT_EQ(Or[0], 1);
        EXPECT_EQ(And[0], 1);
        EXPECT_EQ(a[0], 1);
        EXPECT_EQ(b[0], 1);
    }
    TEST(BinVec, shrink)
    {
        BinVec a(10),b(10);
        a[0] = 0;
        b[2] = 0;
        a.shrink();
        b.shrink();
        EXPECT_EQ(a.len(), b.len());
        EXPECT_EQ(a[0], b[0]);
    }

}
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}