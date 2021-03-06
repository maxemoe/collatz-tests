// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair

#include "gtest/gtest.h"

#include "Collatz.h"

using namespace std;

// ----
// read
// ----

TEST(CollatzFixture, read) {
    istringstream r("1 10\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 1, i);
    ASSERT_EQ(10, j);}

// ----
// eval
// ----

TEST(CollatzFixture, eval_1) {
    const int v = collatz_eval(1, 10);
    ASSERT_EQ(20, v);}

TEST(CollatzFixture, eval_2) {
    const int v = collatz_eval(100, 200);
    ASSERT_EQ(125, v);}

TEST(CollatzFixture, eval_3) {
    const int v = collatz_eval(201, 210);
    ASSERT_EQ(89, v);}

TEST(CollatzFixture, eval_4) {
    const int v = collatz_eval(900, 1000);
    ASSERT_EQ(174, v);}

TEST(CollatzFixture, eval_5) {
    const int v = collatz_eval(6000, 7000);
    ASSERT_EQ(262, v);}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(35043, 75493);
    ASSERT_EQ(340, v);}

TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(24567, 32345);
    ASSERT_EQ(308, v);}

// -----
// init_cache
// -----

TEST(CollatzFixture, init_cache_1) {
    init_cache();
    const int v = cache_val(10);
    ASSERT_EQ(7, v);}

TEST(CollatzFixture, init_cache_2) {
    init_cache();
    const int v = cache_val(20);
    ASSERT_EQ(8, v);}

TEST(CollatzFixture, init_cache_3) {
    init_cache();
    const int v = cache_val(54);
    ASSERT_EQ(113, v);}

TEST(CollatzFixture, init_cache_4) {
    init_cache();
    const int v = cache_val(567);
    ASSERT_EQ(62, v);}

TEST(CollatzFixture, init_cache_5) {
    init_cache();
    const int v = cache_val(248);
    ASSERT_EQ(110, v);}

// -----
// print
// -----

TEST(CollatzFixture, print) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

