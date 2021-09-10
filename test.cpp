//
// Created by Braiden Hook on 9/8/21.
//

#include "catch.hpp"
#include "DSString.h"

TEST_CASE("Testing DSString")
{
    DSString a = "1";
    DSString b = "Ten Char10";
    DSString c = "Multiple words/Actual Tweet";
    DSString d = "Ten Char10";
    DSString e = "UPPERCASE";
    DSString f = "uppercase";
    DSString g = "";
    DSString h = "\n";
    DSString i = "                    ";
    DSString j = "aaaa";
    DSString k = "bbbb";
    char char1 = 'y';
    char char2 = 'n';
    char char3 = ' ';
    char char4 = '\n';
    char char5 = e[0];
    char char6 = 'y';
    char char7 = 'Y';
    char char9 = '1';
    char char10 = '9';


    SECTION("Equality operators DSString"){
        CHECK(a == DSString("1"));
        CHECK(b == d);
        CHECK(c == "Multiple words/Actual Tweet");
        CHECK(!(e == f));
    }
    SECTION("Equality operators Char"){
        CHECK(char1 == 'y');
        CHECK(char1 == char6);
        CHECK(char2 == b[2]);
        CHECK(char3 == i[1]);
        CHECK(char4 == h[0]);
        CHECK(!(char5 == f[0]));
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
    SECTION("Assignment operators Char"){
        char char8;
        char8 = '1';
        CHECK(char8 == a[0]);
        char8 = char('a');
        CHECK(char8 == j[0]);
        char8 = ' ';
        CHECK(char8 == i[2]);
        char8 = 'a';
        CHECK(char8 == 'a');
        char8 = '\n';
        CHECK(char8 == char4);
    }
    SECTION("Addition operator DSString"){
        CHECK(DSString("1Ten Char10") == a + b);
        CHECK(g + g == "");
        CHECK(g + h == DSString("\n"));
        CHECK(a + b + c == "1Ten Char10Multiple words/Actual Tweet");
    }

    SECTION("Greater than operator DSString"){
        CHECK(b > a);
        CHECK(f > e);
        CHECK(k > j);
        CHECK(c > g);
        CHECK(b > g);
    }
    SECTION("Greater than operator DSString"){
        CHECK(a < b);
        CHECK(e < f);
        CHECK(j < k);
        CHECK(g < c);
        CHECK(g < b);
    }
    SECTION("Greater than operator Char"){
        CHECK(char1 > char2);
        CHECK(char6 > char7);
        CHECK(char2 > char7);
        CHECK(char10 > char9);
    }
    SECTION("[] Operator"){
        CHECK(b[1] == 'e');
        CHECK(c[8] == ' ');
        CHECK(g[0] == 0);
    }
    SECTION("Set DSString data"){
        DSString str;
        str.setData("Hello");
        str.c_str() == "Hello";
        str.setData("123");
        str.c_str() == "123";
    }
    SECTION("getLength function"){
        CHECK(d.getLength() == 10);
        CHECK(g.getLength() == 0);
        CHECK(i.getLength() == 20);
        CHECK(e.getLength() == 9);
    }
    SECTION("Substring function") {
        CHECK(a.substring(0, 1) == "1");
        CHECK(f.substring(0, 5) == "upper");
        CHECK(f.substring(1, 6) == "pperca");
    }
    SECTION("c_str function"){
        CHECK(strcmp(b.c_str(), "Ten Char10") == 0);
        CHECK(strcmp(d.c_str(), b.c_str()) == 0);
        CHECK(strcmp(g.c_str(), "") == 0);
    }
}
