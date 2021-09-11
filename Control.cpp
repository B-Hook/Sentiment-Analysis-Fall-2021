//
// Created by Braiden Hook on 9/10/21.
//

#include "Control.h"

Control::Control(char *file1, char *file2, char *file3, char *file4) {
    controlCenter(file1, file4, 1);
    testFile(file2, 2);
    testSVal(file3, file4);
}

void Control::controlCenter (char* filePassed, char* oFilePassed, int type) {

    map<DSString, int> positive;
    map<DSString, int> negative;
    DSString sVal;
    char char1[281];
    char charS[2];
    char charId[11];
    char charIgnore[200];
    int count = 0;
    ifstream file(filePassed);
    file.getline(charIgnore, 200, '\n');
    cout << charIgnore << endl;
    while (!file.eof()) {
        if (type == 1) {
            file.getline(charS, 2, ',');
            sVal.setData(charS);
        }
        file.getline(charId, 11, ',');
        DSString id(charId);
        file.getline(charIgnore, 200, ',');
        file.getline(charIgnore, 200, ',');
        file.getline(charIgnore, 200, ',');
        file.getline(char1, 281, '\n');

        char charWords[strlen(char1) + 1];
        int j = 0;

        for (int i = 0; i < strlen(char1); i++) {
            if (char1[i] == ' ') {
                charWords[j] = '\0'; //forcibly ending the c-string to avoid any weird outputs
                DSString actualTweet(charWords);

                if (actualTweet.getLength() > 2) {
                    if (sVal[0] == '0') {
                        //search - list for current word
                        //if (negative.search(actualTweet)) {}
                        if (negative.count(actualTweet) == 0) {
                            //DSString char3Word = actualTweet.substring(0, 3);
                            negative.emplace(actualTweet, 1);
                        } else {
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
                        } else {
                            positive.at(actualTweet)++;
                        }
                        //if cannot find word, make word object with count of 1
                        //if can find word, getCount from existing word, then set by ++
                        //cout << "positive : " << actualTweet << " : " << maps.at(1).at(actualTweet) << endl;
                    }
                }
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

    }
    maps = {negative, positive};
    file.close();
}

void Control::testFile(char *filePassed, int type) {
    //map<DSString, int> tweetS;
    DSString negSVal = "0";
    DSString posSVal = "4";
    char char1[281];
    char charS[2];
    char charId[11];
    char charIgnore[200];
    int count = 0;
    ifstream file(filePassed);
    file.getline(charIgnore, 200, '\n');
    cout << charIgnore << endl;

    while (!file.eof()) {
        //vector <DSString> words;
        int countS = 0;
        count++;
        /*if (type == 1) {
            file.getline(charS, 2, ',');
            sVal.setData(charS);
        }*/
        file.getline(charId, 11, ',');
        DSString id(charId);
        file.getline(charIgnore, 200, ',');
        file.getline(charIgnore, 200, ',');
        file.getline(charIgnore, 200, ',');
        file.getline(char1, 281, '\n');

        char charWords[strlen(char1) + 1];
        int j = 0;

        for (int i = 0; i < strlen(char1); i++) {
            if (char1[i] == ' ') {
                charWords[j] = '\0'; //forcibly ending the c-string to avoid any weird outputs
                DSString actualTweet(charWords);

                if (maps.at(0).count(actualTweet) > 0){
                    countS = countS - maps.at(0).at(actualTweet);
                }
                if (maps.at(1).count(actualTweet) > 0){
                    countS = countS + maps.at(1).at(actualTweet);
                }
                //This memset below is simply a precaution, not necessary as the charWords
                //already is stopped due to the null allocated above
                memset(charWords, 0, strlen(charWords)); //reseting the c-string so there is no words left over
                j = 0; // pointing back to the beginning of the c-string so
                // the new word doesn't start part way through the string
            }
            if (isalpha(char1[i])) {
                char1[i] = tolower(char1[i]);
                charWords[j] = char1[i];
                j++;
            }
        }
        if (countS < 0) {
            tweetS.emplace(id, negSVal);
        }
        else{
            tweetS.emplace(id, posSVal);
        }
        //cout << countS << endl;
        //cout << id << " : " << tweetS.at(id) << endl;
    }
    maps.at(0).clear();
    maps.at(1).clear();
    maps.clear();
    file.close();
}


vector<map<DSString, int>> Control::getVectorOfMap() {
    return maps;
}

void Control::testSVal(char *sFile, char *oFile) {
    char charIgnore[20];
    char charS[2];
    char charId[11];
    int count = 0;
    double amountRight = 0.000;
    int amountWrong = 0;
    vector<DSString> incorrectTweets;

    ifstream file(sFile);
    file.getline(charIgnore, 20, '\n');
    cout << charIgnore << endl;

    while (!file.eof()){
        count ++;
        file.getline(charS, 2, ',');
        DSString sVal(charS);
        file.getline(charId, 11, '\n');
        DSString id(charId);

        if (tweetS.at(id) == sVal) {
            amountRight++;
        } else {
            incorrectTweets.push_back(id);
            amountWrong++;}
    }
    ofstream output (oFile);

    output << fixed << setprecision(3) << amountRight/10000 << endl;

    for (int i = 0; i < incorrectTweets.size(); i++){
        output << incorrectTweets.at(i) << endl;
        //incorrectTweets.at(i);

    }
    cout << amountWrong << endl;
    output.close();
    file.close();

}

