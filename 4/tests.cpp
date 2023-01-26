#include <gtest/gtest.h>
#include "deposit.hpp"
#include "table.hpp"
#include "casual.hpp"
/*
Deposit:
2. Getters
3. Setters
4. SpecialFunctions
Table:
1. Constructor
2. Insert
3. Delete
5. 
*/
TEST(Deposit, Getters_Setters) {
    const Date a(12,12,1234), b(10, 10, 1235);
    Deposit n(12, 1234.5, 12.3, a);
    n.SetValue(5678.9);
    n.SetLastOperationDate(b);
    EXPECT_EQ(n.GetCode(), 12);
    EXPECT_EQ(n.GetOpenDate(), a);
    EXPECT_EQ(n.GetLastOperationDate(), b);
    EXPECT_EQ(n.GetValue(), 5678.9);
    EXPECT_EQ(n.GetPercent(), 12.3);
}

TEST(Table, Constructors) {
    Table<int, Deposit> tab;
    tab.Insert(std::make_shared<Deposit>(Deposit(1,1,1,Date(1,1,1))));
    Table<int, Deposit> tab1(tab);
    EXPECT_EQ(tab.size(), 1);
    EXPECT_EQ(tab1.size(), 1);
    Table<int, Deposit> tab2(std::move(tab1));
    EXPECT_EQ(tab2.size(), 1);
}
TEST(Table, Insert) {
    int f = 0;
    Table<int, Deposit> tab;
    const Date a(12,12,1234);
    std::shared_ptr<Deposit> n2 = nullptr;
    Deposit n1(12, 1234.5, 12.3, a);
    tab.Insert(std::make_shared<Deposit>(n1));
    EXPECT_EQ(tab.size(), 1);
    try{
    n2 = tab[12];
    }catch(int e) {
        f = 1;
    }
    EXPECT_EQ(f, 0);
    EXPECT_EQ(n1.GetCode(), n2->GetCode());
    EXPECT_EQ(n1.GetValue(), n2->GetValue());
    EXPECT_EQ(n1.GetPercent(), n2->GetPercent());
}
TEST(Table, Delete) {
    int f = 0;
    Table<int, Deposit> tab;
    const Date a(12,12,1234);
    std::shared_ptr<Deposit> n2 = nullptr;
    Deposit n1(12, 1234.5, 12.3, a);
    tab.Insert(std::make_shared<Deposit>(n1));
    tab.DeleteElement(12);
    try{
    n2 = tab[12];
    }catch(int e) {
        f = 1;
    }
    EXPECT_EQ(f, 1);
    EXPECT_EQ(tab.size(), 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}