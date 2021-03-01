#include "gtest/gtest.h"
#include "../header/factory.hpp"
#include <string>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wwrite-strings"

TEST(FACTORY, MULT_OPS){
        char* test_val[6] = {"","3","+","7","*","2"};
        Factory* f =new Factory();
        Base* test = f->parse(test_val, 6);
        EXPECT_EQ("((3.000000+7.000000)*2.000000)",test->stringify());
        EXPECT_EQ(20, test->evaluate());
	delete f;
}

TEST(FACTORY, ALL_OPS){
        char* test_val[12] = {"","3","+","7","*","2","/","1","**","2","-","1"};
        Factory* f =new Factory();
        Base* test = f->parse(test_val, 12);
        EXPECT_EQ("(((((3.000000+7.000000)*2.000000)/1.000000)**2.000000)-1.000000)",test->stringify());
        EXPECT_EQ(399, test->evaluate());
	delete f;
}


TEST(FACTORY, EX){
        char *test_val[4] = {"", "3", "+", "7"};
        Factory* f =new Factory();
        Base* test = f->parse(test_val, 4);
        EXPECT_EQ("(3.000000+7.000000)",test->stringify());
        EXPECT_EQ(10, test->evaluate());
	delete f;
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

#pragma GCC diagnostic pop
