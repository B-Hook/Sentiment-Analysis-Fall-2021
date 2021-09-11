#include <iostream>
#include <fstream>
#include "DSString.h"
//#include "LinkedList.h"
#include <map>
//#include "Tweet.h"
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

using namespace std;

vector <map<DSString, int>>& controlCenter (char*, char*, int);
map <DSString, DSString>& test (vector <map<DSString, int>>&, char*, int);

int main(int argc, char** argv) {

    //for(int i = 0; i < argc; i++){
        //cout <<"argv["<< i << "]: " << argv[i] << endl;
    //}

    //ifstream file1 (argv[1]);

    if (argc == 1){
        Catch::Session().run(); // TODO: Make this into it's own function i.e void runCatch();
    }
    //if (file1.is_open()){
    else {
        vector <map<DSString, int>> maps = controlCenter(argv[1], argv[4], 1);
        map <DSString, DSString> testMap = test(maps, argv[2], 2);

    }
        //controlCenter
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

vector <map<DSString, int>>& controlCenter (char* filePassed, char* oFilePassed, int type){

    map<DSString, int> positive;
    map<DSString, int> negative;
    DSString sVal;
//    vector <map<DSString, int>> maps {negative, positive};
    //map<DSString, int>::iterator it = positive.begin();
    //it->first;
    //LinkedList negative;
    //LinkedList positive;
    //vector <DSString> countWords;
    //vector <Tweet> negative;
    //vector <Tweet> positive;
    char char1[281];
    char charS[2];
    char charId[11];
    char charIgnore[200];
    //char* charType [2]= "4";
    int count = 0;
    ifstream file (filePassed);

    //if (file.is_open()) {

//        file.getline(charIgnore, 281, ',');
//        cout << charIgnore << endl;
//        file.getline(charIgnore, 281, ',');
//        cout << charIgnore << endl;
//        file.getline(charIgnore, 281, ',');
//        cout << charIgnore << endl;
//        file.getline(charIgnore, 281, ',');
//        cout << charIgnore << endl;
//        file.getline(charIgnore, 281, ',');
//        cout << charIgnore << endl;
        file.getline(charIgnore, 281, '\n');
        cout << charIgnore << endl;
        //DSString test (char1);

        //cout << test << endl;
        //LinkedList list; //new LinkedList object is made
        //memset(char1, 0, strlen(char1));
        //while (!file.eof()) {
        while (count < 30) {
            //vector <DSString> words;
            count++;
            if (type == 1){
                file.getline(charS, 2, ',');
                sVal.setData(charS);
            }
            file.getline(charId, 11, ',');
            DSString id(charId);
            file.getline(charIgnore, 200, ',');
            //memset(char1, 0, strlen(char1)); //wiping date
            file.getline(charIgnore, 200, ',');
            //memset(char1, 0, strlen(char1)); //wiping query
            file.getline(charIgnore, 200, ',');
            //memset(char1, 0, strlen(char1)); //wiping username
            file.getline(char1, 281, '\n');

            //while (char1[0] == '\n'){
                //file.getline(char1, 281, ' ');
            char charWords[strlen(char1) + 1];
            int j = 0;

            for (int i = 0; i < strlen(char1); i++) {
                if (char1[i] == ' ') {
                    charWords[j] = '\0'; //forcibly ending the c-string to avoid any weird outputs
                    DSString actualTweet(charWords);
                    //for (int k = 0; k < words.size(); k++)
                        //if (actualTweet.c_str() == words.at(k).c_str()){
                            //break;
                        //}
                        //else if (id == "0"){
                        //}

                    if (actualTweet.getLength() > 1) {

                        if (sVal[0] == '0') {
                            //search - list for current word
                            //if (negative.search(actualTweet)) {}
                            if (negative.count(actualTweet) == 0) {
                                negative.emplace(actualTweet, 1);
                            }
                            else {
                                //Tweet word(actualTweet, 1);
                                //negative.append(word);
                                negative.at(actualTweet)++;
                            }
                            //if cannot find word, make word object with count of 1
                            //if can find word, getCount from existing word, then set by ++
                            //negWords.push_back(actualTweet);
                            //cout << "negative : " << actualTweet << " : " << maps.at(0).at(actualTweet) << endl;
                        } else {
                            //search - list for current word
                            if (positive.count(actualTweet) == 0) {
                                positive.emplace(actualTweet, 1);
                            }
                            else {
                                positive.at(actualTweet)++;
                            }
                            //if cannot find word, make word object with count of 1
                            //if can find word, getCount from existing word, then set by ++
                            //posWords.push_back(actualTweet);
                            //cout << "positive : " << actualTweet << " : " << maps.at(1).at(actualTweet) << endl;
                        }
                    }
                    //words.push_back(actualTweet);
                    //This memset below is simply a precaution, not necessary as the charWords
                    //already is stopped due to the null allocated above
                    memset(charWords, 0, strlen(charWords)); //reseting the c-string so there is no words left over
                    j = 0; // pointing back to the beginning of the c-string so
                        // the new word doesn't start part way through the string


                } //else if (ispunct(char1[i])) {
                //charWords[i] = '0';}
                if (isalpha(char1[i])) {
                    char1[i] = tolower(char1[i]);
                    charWords[j] = char1[i];
                    j++;
                }
            }

            //for (int i = 0; i < words.size(); i++){
              //  cout << words.at(i) << " ";
            //}

            //cout << endl;
            //DSString actualTweet(char1);
            //Tweet tweet;
            //Tweet tweet (sVal, id, words);
            //Tweet tweet (sVal, actualTweet);


            //tweet.setSVal(sVal);
            //tweet.setId(id);
            //tweet.setActualTweet(words);


            //if (charS[0] == '0')
                //negative.append(tweet);
            //if (charS[0] == '4')
                //positive.append(tweet);

            //memset(char1, 0, strlen(char1));
            //memset(charS, 0, strlen(charS));
            //memset(charId, 0, strlen(charId));
            //int f = 0;
        }
    vector <map<DSString, int>> maps {negative, positive};
    //negative.remove1(positive);
//        cout << "Negative" << "\n \n \n" << endl;
//        negative.display();
//        cout << "Positive" << "\n \n \n" << endl;
//        positive.display();



    //negative.remove1(positive);
    /*cout << "Negative" << "\n \n \n" << endl;
    negative.display();
    cout << "Positive" << "\n \n \n" << endl;
    positive.display();
    //}*/

    //negative.remove1(positive);

    //for (int i = 0; i < negative.getSize(); i++) {



    //}

    ofstream oFile (oFilePassed);
    oFile << "Test" << endl;
    oFile.close();

    return maps;
}

map <DSString, DSString>& test (vector <map<DSString, int>>& trainMaps, char* filePassed, int type){





























}
