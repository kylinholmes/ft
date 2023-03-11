#include "gtest/gtest.h"
#include <cstdint>
#include "ipv4.cpp"

// OK 
TEST(test_ipv4, test_ok_0) {
  EXPECT_EQ(f( "172.168.5.1"s ).first, 2896692481);
}

TEST(test_ipv4, test_ok_1) {
  EXPECT_EQ(f( " 172.168.5.1 "s ).first, 2896692481);
}

TEST(test_ipv4, test_ok_2) {
  EXPECT_EQ(f( "172 .168 . 5. 1"s ).first, 2896692481);
}

TEST(test_ipv4, test_ok_3) {
  EXPECT_EQ(f( "129.0.0.1"s ).first, 2164260865);
}

TEST(test_ipv4, test_ok_4) {
  EXPECT_EQ(f( "0.0.0.0"s ).first, 0);
}

TEST(test_ipv4, test_ok_5) {
  EXPECT_EQ(f( "123.45.67.89"s ).first, 2066563929);
}

TEST(test_ipv4, test_ok_6) {
  EXPECT_EQ(f( "255.255.255.255"s ).first, UINT32_MAX);
}

// Err
TEST(test_ipv4, test_err_0) {
  EXPECT_NE(f( "1 7 2 .1 6 8 . 5. 1"s ).second, 0);
}

TEST(test_ipv4, test_err_1) {
  EXPECT_NE(f( "abc.def.hij.klm"s ).second, 0);
}

TEST(test_ipv4, test_err_2) {
  EXPECT_NE(f( "-127.def.hij.klm"s ).second, 0);
}

TEST(test_ipv4, test_err_3) {
  EXPECT_NE(f( "abc.d.e.f.g.h.i"s ).second, 0);
}

TEST(test_ipv4, test_err_4) {
  EXPECT_NE(f( "17221.16985.0.0"s ).second, 0);
}

TEST(test_ipv4, test_err_5) {
  EXPECT_NE(f( "256.256.256.256"s ).second, 0);
}

TEST(test_ipv4, test_err_6) {
  EXPECT_NE(f( "4294967296.4294967297.4294967298.4294967299"s ).second, 0);
}

TEST(test_ipv4, test_err_7) {
  EXPECT_NE(f( "4294967300.4294967297.4294967298.4294967299"s ).second, 0);
}