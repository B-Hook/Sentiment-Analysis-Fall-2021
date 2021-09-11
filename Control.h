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
    //Control();
    void controlCenter (char* filePassed, char* oFilePassed, int type);
    vector <map<DSString, int>> getVectorOfMap ();

private:
    //DSString word;
    //int count;
    //map<DSString, int> negative;
    vector <map<DSString, int>> maps;
};


#endif //MAIN_CPP_CONTROL_H
