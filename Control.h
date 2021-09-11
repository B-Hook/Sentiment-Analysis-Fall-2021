#ifndef MAIN_CPP_CONTROL_H
#define MAIN_CPP_CONTROL_H


#include "DSString.h"
#include <fstream>
#include <iomanip>
#include <map>
#include <vector>
using namespace std;

class Control {
public:
    Control(char*, char*, char*, char*); // Overloaded constructor sending each file to Control
    void trainFile (char*); // Training the algo by reading in + & - words
    void testFile (char*); // Test the algo by using the count of the words from trainFile().
    void testSVal (char*, char*); // Checks to see if the predicted sentiment for each tweet was correct
private:
    // Vector which will contain the maps of + & - words from train.
    // Made as a data member so I could pass the maps to the testFile()
    vector <map<DSString, int>> maps;
    // Map of the tested tweet ids and predicted sentiment
    map <DSString, DSString> tweetS;
};


#endif //MAIN_CPP_CONTROL_H
