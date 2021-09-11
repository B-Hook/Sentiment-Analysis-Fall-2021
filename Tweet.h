//
// Created by Braiden Hook on 9/7/21.
//
/*
#ifndef MAIN_CPP_TWEET_H
#define MAIN_CPP_TWEET_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "DSString.h"
using namespace std;
// Transaction class


class Tweet {

public:
    Tweet(); // Default Constructor
    Tweet(DSString&, int);
    //Tweet(DSString&, DSString&); // Whether a tweet is pos or neg and the ID (Test + sentiment)
    //Tweet(DSString&, DSString&, vector<DSString>&); // Pos or Neg, ID, and actual tweet (train)
    // Rule of 3
    Tweet(const Tweet &copy);
    Tweet& operator=(const Tweet &copy);
    //bool operator==(const Tweet &copy);
    ~Tweet();
    void display(int);
    // Getters and Setters
    void setSVal(DSString&);
    DSString getSVal();
    void setId(DSString&);
    DSString getId();
    void setActualTweet(vector<DSString>&);
    vector <DSString> getActualTweet();
    void setWord(DSString&);
    DSString getWord();
    void setCount(int);
    int getCount();

private:
    //DSString *sVal;
    //DSString *id;
    DSString *word;
    int *count;
    //vector <DSString> actualTweet;

};


#endif //MAIN_CPP_TWEET_H
*/