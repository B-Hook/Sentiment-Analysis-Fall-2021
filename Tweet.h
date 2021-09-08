//
// Created by Braiden Hook on 9/7/21.
//

#ifndef MAIN_CPP_TWEET_H
#define MAIN_CPP_TWEET_H
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "DSString.h"
using namespace std;
// Transaction class


class Tweet {

public:
    Tweet(); // Default Constructor
    Tweet(bool&, DSString&); // Whether a tweet is pos or neg and the ID (Test + sentiment)
    Tweet(DSString&, DSString&); // tweet ID and actual tweet (test)
    Tweet(bool&, DSString&, DSString&); // Pos or Neg, ID, and actual tweet (train)
    // Rule of 3
    Tweet(const Tweet &copy);
    Tweet& operator=(const Tweet &copy);
    ~Tweet();
    void display(int);
    // Getters and Setters
    bool getPositive();
    DSString getId();
    DSString getActualTweet();

private:
    bool *positive;
    DSString *id;
    DSString *actualTweet;

};


#endif //MAIN_CPP_TWEET_H
