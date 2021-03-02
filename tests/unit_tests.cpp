#include "gtest/gtest.h"
#include "../header/factory.hpp"
#include <string>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wwrite-strings"

TEST(FACTORY, MULT_OPS){
        char* test_val[6] = {"","3","+","7","*","2"};
        Factory* f =new Factory();
        Base* test = f->parse(test_val, 6);
	EXPECT_EQ(20, test->evaluate());
        EXPECT_EQ("((3.000000+7.000000)*2.000000)",test->stringify());
	delete f;
	delete test;
}

TEST(FACTORY, ALL_OPS){
        char* test_val[12] = {"","3","+","7","*","2","/","1","**","2","-","1"};
        Factory* f =new Factory();
        Base* test = f->parse(test_val, 12);
        EXPECT_EQ("(((((3.000000+7.000000)*2.000000)/1.000000)**2.000000)-1.000000)",test->stringify());
        EXPECT_EQ(399, test->evaluate());
	delete f;
        delete test;
}


TEST(FACTORY, EX){
        char *test_val[4] = {"", "3", "+", "7"};
        Factory* f =new Factory();
        Base* test = f->parse(test_val, 4);
        EXPECT_EQ("(3.000000+7.000000)",test->stringify());
        EXPECT_EQ(10, test->evaluate());
	delete f;
        delete test;
}
TEST(FACTORY, LETTERS){
        char* test_val[6] = {"","a","+","b","*","2"};
        Factory* f =new Factory();
        EXPECT_EQ(nullptr, f->parse(test_val, 6));
	delete f;
}

TEST(FACTORY, OPERATOR_FIRST){
        char* test_val[5] = {"","+","7","*","9"};
        Factory* f =new Factory();
        EXPECT_EQ(nullptr, f->parse(test_val, 5));
	delete f;
}

TEST(FACTORY, ADD){
        char *test_val[4] = {"", "3", "+", "7"};
        Factory* f =new Factory();
        Base* test = f->parse(test_val, 4);
        EXPECT_EQ("(3.000000+7.000000)",test->stringify());
        EXPECT_EQ(10, test->evaluate());
	delete f;
        delete test;
}

TEST(FACTORY, SUB){
        char *test_val[4] = {"", "7", "-", "3"};
        Factory* f =new Factory();
        Base* test = f->parse(test_val, 4);
        EXPECT_EQ("(7.000000-3.000000)",test->stringify());
        EXPECT_EQ(4, test->evaluate());
	delete f;
        delete test;
}

TEST(FACTORY, MULT){
        char *test_val[4] = {"", "7", "*", "3"};
        Factory* f =new Factory();
        Base* test = f->parse(test_val, 4);
        EXPECT_EQ("(7.000000*3.000000)",test->stringify());
        EXPECT_EQ(21, test->evaluate());
	delete f;
        delete test;
}

TEST(FACTORY, DIV){
        char *test_val[4] = {"", "15", "/", "3"};
        Factory* f =new Factory();
        Base* test = f->parse(test_val, 4);
        EXPECT_EQ("(15.000000/3.000000)",test->stringify());
        EXPECT_EQ(5, test->evaluate());
	delete f;
        delete test;
}

TEST(FACTORY, POW){
        char *test_val[4] = {"", "2", "**", "3"};
        Factory* f =new Factory();
        Base* test = f->parse(test_val, 4);
        EXPECT_EQ("(2.000000**3.000000)",test->stringify());
        EXPECT_EQ(8, test->evaluate());
	delete f;
        delete test;
}

TEST(FACTORY, ONLY_ONE_NUM){
        char* test_val[2] = {"","9"};
        Factory* f =new Factory();
	Base* test = f->parse(test_val, 2);
        EXPECT_EQ("9.000000",test->stringify());
        EXPECT_EQ(9, test->evaluate());
	delete f;
        delete test;
}
TEST(FACTORY, MULTI_DIGIT){
        char *test_val[6] = {"", "100", "*", "3","/","20"};
        Factory* f =new Factory();
        Base* test = f->parse(test_val, 6);
        EXPECT_EQ("((100.000000*3.000000)/20.000000)",test->stringify());
        EXPECT_EQ(15, test->evaluate());
	delete f;
        delete test;
}
TEST(FACTORY, OPERATOR_LAST){
        char* test_val[5] = {"","7","*","9","+"};
        Factory* f =new Factory();
        EXPECT_EQ(nullptr, f->parse(test_val, 5));
	delete f;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

#pragma GCC diagnostic pop
