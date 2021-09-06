#include <iostream>
#include <fstream>
#include "DSString.h"
using namespace std;
int main(int argc, char** argv) {

    for(int i = 0; i < argc; i++){
        cout <<"argv["<< i << "]: " << argv[i] << endl;
    }

    ifstream file1 (argv[1]);

    if (file1.is_open()){
        char char1[500];
        //char char2[1000];
        char char3[1000];

        file1.getline(char1, 500, '\n');
        //file1.getline(char2, 1000, '\n');
        file1.getline(char3, 1000, '\n');

        char char2[1000];
        //DSString obj1;


        file1.getline(char2, 1000,'\n');

        DSString obj1(char2);

        cout << endl;

        cout << obj1 << endl;

    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
