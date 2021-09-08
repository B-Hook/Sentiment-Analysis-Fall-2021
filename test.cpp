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
    DSString i = DSString("                    ");
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
        //CHECK(str == g);
        str = DSString("\n");
        CHECK(str == h);
    }
    SECTION("Addition operator DSString"){
        CHECK(DSString("1Ten Char10") == a + b);
        CHECK(g + g == "");
        CHECK(g + h == DSString("\n"));
        CHECK(a + b + c == "1Ten Char10Multiple words/Actual Tweet");
    }

    SECTION("Greater than operator DSString"){
        CHECK(b > a);
        CHECK(e > f);
        CHECK(c > g);
        CHECK(b > g);
    }
    SECTION("[] Operator"){
        CHECK(b[1] == 'e');
        CHECK(c[8] == ' ');
        CHECK(g[0] == 0);
    }
    SECTION("getLength function"){
        CHECK(d.getLength() == 10);
        CHECK(g.getLength() == 0);
        CHECK(i.getLength() == 20);
        CHECK(e.getLength() == 9);
    }
    SECTION("Substring function") {
        CHECK(a.substring(0, 1) == "1");
        CHECK(f.substring(0, 5) == "upperc");
        CHECK(f.substring(1, 6) == "pperca");
    }
    SECTION("c_str function"){
        CHECK(strcmp(b.c_str(), "Ten Char10") == 0);
        CHECK(strcmp(d.c_str(), b.c_str()) == 0);
        CHECK(strcmp(g.c_str(), "") == 0);
    }
}
