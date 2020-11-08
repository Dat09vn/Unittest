#include <iostream>
#include <vector>
#include "gtest/gtest.h"
#include "gmock/gmock.h"


using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::NiceMock;
using ::testing::_;
using ::testing::ReturnPointee;

/*Lesson 1
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


/*Lesson2
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

/*lesson3
class MyClass{
    int baseValue;
    string myStr;
public:
    MyClass(int x,string s){
        baseValue = x;
        myStr = s;
    }
    void Increment(int byValue){
        baseValue += byValue;
    }
    void Decrement(int byValue){
        baseValue -= byValue;
    }
    void setString(string str){
        this->myStr = str;
    }
    string getString(){
        return this->myStr;
    }
    int getValue(){
        return baseValue;
    }
};

struct MyClassTest : public testing::Test{
    MyClass *mc;
    void SetUp(){
        cout<<"SetUp mc"<<endl;
        mc = new MyClass(10,"dat");
    }
    void TearDown(){
        cout<<"Delete mc"<<endl;
        delete mc;
    }
};
//test_F through classTest
TEST_F(MyClassTest,Increment){
    mc->Increment(50);
    EXPECT_EQ(mc->getValue(),60);
}


TEST_F(MyClassTest,Decreament){
    mc->Decrement(5);
    EXPECT_EQ(mc->getValue(),5);
}

TEST_F(MyClassTest,get){
    EXPECT_STREQ(mc->getString().c_str(),"dat");
}

//test through create new in this scope
TEST(MyClass,up){
    MyClass* mcc = new MyClass(10,"tien dat");
    EXPECT_EQ(mcc->getValue(),10);
}

TEST(MyClass1,up1){
    MyClass* mcc = new MyClass(10,"tien dat");
    EXPECT_EQ(mcc->getValue(),10);
}

//test without create new
TEST(MyClass2,up1){
    MyClass mcc(10,"dat09");
    EXPECT_EQ(mcc.getValue(),10);
}
*/



//lesson4
    class Stack{
        vector<int> vstack = {};
    public:
        void push(int value){vstack.push_back(value);}
        int pop(){
            if(vstack.size()>0){
                int value = vstack.back();
                vstack.pop_back();
                return value;
            }
            else {
                return -1;
            }
        }
        int size(){return vstack.size();}
    };

    struct stackTest : public testing::Test{
        Stack s1;       //need to create an instance in here not in void SetUp because of scope
        void SetUp() {
            int value[] = {1,2,3,4,5};
            for(auto &val:value){
                s1.push(val);
            }
        }
        void TeaDown(){}
    };

    TEST_F(stackTest,PopTest){
        int lastPoppedValue = 5;
        while (lastPoppedValue != 1)
            EXPECT_EQ(s1.pop(),lastPoppedValue--);
    }

    TEST_F(stackTest,SizeValue){
        int index = s1.size();
        for(index;index>0;index--)
            EXPECT_NE(s1.pop(),-1);
    }


    int main(int argc, char ** argv)
    {
        std::cout<<"Running main() from "<<__FILE__<<std::endl;
        testing::InitGoogleTest(&argc, argv);

        return RUN_ALL_TESTS();
    }






















