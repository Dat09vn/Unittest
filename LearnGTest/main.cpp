#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::NiceMock;
using ::testing::_;
using ::testing::ReturnPointee;

/*
//UNITTEST
TEST(TestName1,Subtestt_1){
    //arrange:
    int x=10;
    int y=20;

    //act:
    x=x+y;

    //assert:
    ASSERT_EQ(x,30);

}
TEST(TestName2,Subtestt_2){
    //arrange:
    int x=10;
    int y=50;

    //act:
    x=x+y;

    //assert:
    ASSERT_EQ(x,60);
}
*/

/*
class MyClass{
    public:
    int baseValue;
    MyClass(int x){
        baseValue=x;
    }
    void Increment(int byValue){
        baseValue += byValue;
    }
    int getValue(){
        return baseValue;
    }
};

TEST(ClassTest,subtest){
    //arrange
    MyClass mc(10);

    //act
    mc.Increment(5);


    //assert
    EXPECT_EQ(mc.getValue(),15);
}

TEST(ClassTest,subtest1){
    //arrange
    MyClass mc(11);

    //act
    mc.Increment(5);


    //assert
    EXPECT_EQ(mc.getValue(),16);
}
*/


class MyClass{
    int baseValue;
public:
    MyClass(int x){
        baseValue = x;
    }
    void Increment(int byValue){
        baseValue += byValue;
    }
    void Decrement(int byValue){
        baseValue -= byValue;
    }
    int getValue(){
        return baseValue;
    }
};

struct MyClassTest : public testing::Test{
    MyClass *mc;
    void SetUp(){
        cout<<"SetUp mc"<<endl;
        mc = new MyClass(10);
    }
    void TearDown(){
        cout<<"Delete mc"<<endl;
        delete mc;
    }
};

TEST_F(MyClassTest,Increment){
    mc->Increment(50);
    EXPECT_EQ(mc->getValue(),70);
}

TEST_F(MyClassTest,Decreament){
    mc->Decrement(5);
    EXPECT_EQ(mc->getValue(),5);
}

int main(int argc, char ** argv)
{
    std::cout<<"Running main() from "<<__FILE__<<std::endl;
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
