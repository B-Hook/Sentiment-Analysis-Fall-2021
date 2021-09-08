//
// Created by Braiden Hook on 9/7/21.
//

#include "Tweet.h"

Tweet::Tweet() {

}

Tweet::Tweet(bool &positive , DSString &id) {

    this->positive = new bool (positive);
    this->id =  new DSString (id);
    this->actualTweet = nullptr;

}

Tweet::Tweet(DSString &id, DSString &actualTweet) {

    this->positive = nullptr;
    this->id =  new DSString (id);
    this->actualTweet = new DSString (actualTweet);

}

Tweet::Tweet(bool &positive, DSString &id, DSString &actualTweet) {

    this->positive = new bool (positive);
    this->id =  new DSString (id);
    this->actualTweet = new DSString (actualTweet);

}

Tweet::Tweet(const Tweet &copy) {

    this->positive = new bool();
    *positive = *(copy.positive);

    this->id = new DSString();
    *id = *(copy.id);

    this->actualTweet = new DSString();
    *actualTweet = *(copy.actualTweet);

}

Tweet &Tweet::operator=(const Tweet &copy) {
    if (this != &copy){

        delete positive;
        delete id;
        delete actualTweet;

        this->positive = new bool();
        *positive = *(copy.positive);

        this->id = new DSString();
        *id = *(copy.id);

        this->actualTweet = new DSString();
        *actualTweet = *(copy.actualTweet);
    }
}

Tweet::~Tweet() {
    delete positive;
    delete id;
    delete actualTweet;

}

bool Tweet::getPositive() {
    return positive;
}

DSString Tweet::getId() {
    return *id;
}

DSString Tweet::getActualTweet() {
    return *actualTweet;
}
