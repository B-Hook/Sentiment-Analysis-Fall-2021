//
// Created by Braiden Hook on 9/8/21.
//

#include "catch.hpp"
#include "DSString.h"

TEST_CASE("Testing DSString")
{
    DSString a = DSString("1");
    DSString b = DSString("Ten Char10");
    DSString c = DSString("Multiple words/Actual Tweet");
    DSString d = DSString("Ten Char10");
    DSString e = DSString("UPPERCASE");
    DSString f = DSString("uppercase");
    DSString g = DSString("");
    DSString h = DSString("\n");
    //char y = 'y';


    SECTION("Equality operators DSString"){
        CHECK(a == DSString("1"));
        CHECK(b == d);
        CHECK(c == "Multiple words/Actual Tweet");
        CHECK(!(e == f));
    }
    SECTION("Assignment operators DSString"){
        DSString str;
        str = "1";
        CHECK(str == a);
        str = DSString("Ten Char10");
        CHECK(str == b);
        str = "";
        CHECK(str == g);
        str = DSString("\n");
        CHECK(str == h);
    }
    SECTION("Addition operator DSString"){
        REQUIRE(DSString("1Ten Char10") == a + b);
        REQUIRE(g + g == "");
        REQUIRE(g + h == DSString("\n"));
        REQUIRE(a + b + c == "1Ten Char10Multiple words/Actual Tweet");
    }

}
