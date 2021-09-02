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
        char char2[1000];
        char char3[1000];

        file1.getline(char1, 500, '\n');
        file1.getline(char2, 1000, '\n');
        file1.getline(char3, 1000, '\n');


        /**
        This goes into the tweet object!

        DSString data;

        file1.getline(data, 1000, '\n');

         **/


        cout << endl;

        cout << char1 << endl;
        cout << char2 << endl;
        cout << char3 << endl;


        //while (file1.getline(char1, 100)){
        //    file1.getline(char1, 100);
       // }
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
