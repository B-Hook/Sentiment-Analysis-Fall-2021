//
// Created by Braiden Hook on 9/10/21.
//

#include "Control.h"

//using namespace std;

Control::Control(char *file1, char *file2, char *file3, char *file4) {
    controlCenter(file1, file4, 1);
    testFile(file2, 2);
    testSVal(file3, file4);
}

void Control::controlCenter (char* filePassed, char* oFilePassed, int type) {

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
    ifstream file(filePassed);

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
    file.getline(charIgnore, 200, '\n');
    cout << charIgnore << endl;
    //DSString test (char1);

    //cout << test << endl;
    //LinkedList list; //new LinkedList object is made
    //memset(char1, 0, strlen(char1));
    while (!file.eof()) {
    //while (count < 200) {
        //vector <DSString> words;
        //count++;
        if (type == 1) {
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
    maps = {negative, positive};
    //negative.remove1(positive);
//        cout << "Negative" << "\n \n \n" << endl;
//        negative.display();
//        cout << "Positive" << "\n \n \n" << endl;
//        positive.display();



    /*negative.remove1(positive);
    cout << "Negative" << "\n \n \n" << endl;
    negative.display();
    cout << "Positive" << "\n \n \n" << endl;
    positive.display();
    //}*/

    //negative.remove1(positive);

    //for (int i = 0; i < negative.getSize(); i++) {



    //}

    //ofstream oFile (oFilePassed);
    //oFile << "Test" << endl;
    //oFile.close();
    file.close();

    //return maps;
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
        if (countS > 0) {
            tweetS.emplace(id, posSVal);
        }
        else{
            tweetS.emplace(id, negSVal);
        }
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
    float amountRight = 0.000;
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

        if (tweetS.at(id) == sVal){
            amountRight++;
        }
        else{
            incorrectTweets.push_back(id);
            amountWrong++;
        }
    }
    ofstream output (oFile);

    output << fixed << setprecision(3) << amountRight/10000 << endl;

    for (int i = 0; i < incorrectTweets.size(); i++){
        output << incorrectTweets.at(i) << " (" << i << ")" << endl;
    }
    cout << amountWrong << endl;
    output.close();
    file.close();

}

