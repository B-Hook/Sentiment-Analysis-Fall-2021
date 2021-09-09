#include <iostream>
#include <fstream>
#include "DSString.h"
#include "LinkedList.h"
#include "Tweet.h"
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

using namespace std;

void controlCenter (char*, char*, int);

int main(int argc, char** argv) {

    for(int i = 0; i < argc; i++){
        cout <<"argv["<< i << "]: " << argv[i] << endl;
    }

    //ifstream file1 (argv[1]);

    //if (file1.is_open()){
        controlCenter (argv[1], argv[4], 1);
        /*char char1[500];
        char char2[1000];
        char char3[1000];

        file1.getline(char1, 500, '\n');
        file1.getline(char2, 1000, '\n');
        file1.getline(char3, 1000, '\n');

        //char char2[1000];
        //DSString obj1;


        //file1.getline(char2, 1000,'\n');

        DSString obj1(char2);
        //char* a = new char (1);
        //*a = '4';

        //if(obj1.substring(0, 1) == a);
          //  cout << "comparing ID works this way" << endl;

        DSString obj2(char3);

        LinkedList testList;

        Tweet tweet1(obj1, obj2);
        /** There is something wrong when appending the tweet.
         *  Could have to do with the copy constructor in tweet.
         **/
        //testList.append(tweet1);

        //cout << tweet1.getActualTweet() << endl;

        //testList.display();

        /*cout << obj1.c_str()<< endl;

        obj1 = obj2;

        cout << endl;

        cout << obj1.c_str()<< endl;

        DSString obj3 (char3);

        obj3 = obj1 + obj3;

        cout << obj3.c_str() << endl;

    }*/

    return 0;
}

void controlCenter (char* filePassed, char* oFilePassed, int type){
    Catch::Session().run();
    LinkedList negative;
    LinkedList positive;
    char char1[281];
    char charS[2];
    char charId[11];
    char charIgnore[200];
    int count = 0;
    ifstream file (filePassed);

    if (file.is_open()) {

        file.getline(charIgnore, 281, ',');
        cout << charIgnore << endl;
        file.getline(charIgnore, 281, ',');
        cout << charIgnore << endl;
        file.getline(charIgnore, 281, ',');
        cout << charIgnore << endl;
        file.getline(charIgnore, 281, ',');
        cout << charIgnore << endl;
        file.getline(charIgnore, 281, ',');
        cout << charIgnore << endl;
        file.getline(charIgnore, 281, '\n');
        cout << charIgnore << endl;
        //DSString test (char1);

        //cout << test << endl;
        //LinkedList list; //new LinkedList object is made
        //memset(char1, 0, strlen(char1));

        //while (!file.eof()) {
        while (count < 17) {
            count++;
            file.getline(charS, 2, ',');
            DSString sVal(charS);
            file.getline(charId, 11, ',');
            DSString id(charId);
            file.getline(charIgnore, 200, ',');
            //memset(char1, 0, strlen(char1)); //wiping date
            file.getline(charIgnore, 200, ',');
            //memset(char1, 0, strlen(char1)); //wiping query
            file.getline(charIgnore, 200, ',');
            //memset(char1, 0, strlen(char1)); //wiping username
            file.getline(char1, 281, '\n');
            DSString actualTweet(char1);
            Tweet tweet;
            //Tweet tweet (sVal, actualTweet);


            tweet.setSVal(sVal);
            tweet.setId(id);
            tweet.setActualTweet(actualTweet);


            if (charS[0] == '0')
                negative.append(tweet);
            if (charS[0] == '4')
                positive.append(tweet);

            //memset(char1, 0, strlen(char1));
            //memset(charS, 0, strlen(charS));
            //memset(charId, 0, strlen(charId));
        }
        cout << "Negative" << "\n \n \n" << endl;
        negative.display();
        cout << "Positive" << "\n \n \n" << endl;
        positive.display();
    }
    ofstream oFile (oFilePassed);
    oFile << "Test" << endl;
    oFile.close();
}
