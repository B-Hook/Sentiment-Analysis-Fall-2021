#include <iostream>
#include <fstream>
#include "DSString.h"
#include "LinkedList.h"
#include "Tweet.h"
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

        //char char2[1000];
        //DSString obj1;


        //file1.getline(char2, 1000,'\n');

        //DSString obj1(char2);
        //char* a = new char (1);
        //*a = '4';

        //if(obj1.substring(0, 1) == a);
          //  cout << "comparing ID works this way" << endl;

        DSString obj2(char3);

        //Tweet tweet1(obj1, obj2);

        //cout << tweet1.getActualTweet() << endl;

        /*cout << obj1.c_str()<< endl;

        obj1 = obj2;

        cout << endl;

        cout << obj1.c_str()<< endl;

        DSString obj3 (char3);

        obj3 = obj1 + obj3;

        cout << obj3.c_str() << endl;*/

    }

    return 0;
}

void controlCenter (ifstream file, int type){
    LinkedList negative;
    LinkedList positive;
    char char1[281];
    char charS[2];
    char charId[11];
    int count = 0;

    file.getline(char1, 281, '\n');
    //LinkedList list; //new LinkedList object is made
    memset(char1, 0, strlen(char1));

    //while (!file.eof()) {
    while (count < 17){
        count++;
        file.getline(charS, 1, ',');
        DSString sVal(charS);
        file.getline(charId, 10, ',');
        DSString id(charId);
        file.getline(char1, 281, ',');
        memset(char1, 0, strlen(char1)); //wiping date
        file.getline(char1, 281, ',');
        memset(char1, 0, strlen(char1)); //wiping query
        file.getline(char1, 281, ',');
        memset(char1, 0, strlen(char1)); //wiping username
        file.getline(char1, 281, ',');
        DSString actualTweet(char1);

        Tweet tweet;

        if (1 == type) {
            tweet.setSVal(sVal);
            tweet.setActualTweet(actualTweet);
        }

        if (*charS == '0')
            negative.append(tweet);
        if (*charS == '4')
            positive.append(tweet);
    }
    cout << "Negative" << "\n \n \n" << endl;
    negative.display();
    cout << "Positive" << "\n \n \n" << endl;
    positive.display();
}
