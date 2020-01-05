#ifndef UT_TEST
#define UT_TEST

#include <gtest/gtest.h>
#include "../src/database.h"

TEST (FirstTest, FirstTest)
{
    ASSERT_TRUE(true);
}

TEST (readFileTest, fail)
{
    ASSERT_NO_THROW(db::Parser p);
}

TEST (readFileTest, succeed)
{
    db::Parser p;
}

#endif