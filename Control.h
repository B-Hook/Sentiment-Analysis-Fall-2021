//
// Created by Braiden Hook on 9/10/21.
//

#ifndef MAIN_CPP_CONTROL_H
#define MAIN_CPP_CONTROL_H


#include "DSString.h"
#include <fstream>
#include <map>
#include <vector>
using namespace std;

class Control {


public:
    Control(char*, char*, char*, char*);
    void controlCenter (char*, char*, int);
    void testFile (char*, int);
    void testSVal (char*, char*);
    vector <map<DSString, int>> getVectorOfMap ();

private:
    //DSString word;
    //int count;
    //map<DSString, int> negative;
    vector <map<DSString, int>> maps;
    map <DSString, DSString> tweetS;
};


#endif //MAIN_CPP_CONTROL_H
