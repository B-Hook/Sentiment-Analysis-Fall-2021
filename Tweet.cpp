//
// Created by Braiden Hook on 9/7/21.
//

#include "Tweet.h"

Tweet::Tweet() {
    this->sVal = nullptr;
    this->id = nullptr;
    this->actualTweet = nullptr;
}

Tweet::Tweet(DSString &val1 , DSString &val2) {

    if (val1.getLength() == 1) {
        this->sVal = new DSString(val1);
        this->id = nullptr;
        this->actualTweet = nullptr;
    }
    else if (val1.getLength() == 10) {
        this->id = new DSString(val1);
        this->sVal = nullptr;
        this->actualTweet = nullptr;
    }
    else {
        this->actualTweet = new DSString (val1);
        this->sVal = nullptr;
        this->id = nullptr;
    }
    if (val2.getLength() == 1)
        this-> sVal = new DSString (val2);
    else if (val2.getLength() == 10)
        this->id = new DSString (val2);
    else {
        this->actualTweet = new DSString (val2);
    }

}

/*Tweet::Tweet(DSString &id, DSString &actualTweet) {

    this->sVal = nullptr;
    this->id =  new DSString (id);
    this->actualTweet = new DSString (actualTweet);

}

Tweet::Tweet(DSString &positive, DSString &id, DSString &actualTweet) {

    this->sVal = new bool (positive);
    this->id =  new DSString (id);
    this->actualTweet = new DSString (actualTweet);

}*/

Tweet::Tweet(const Tweet &copy) {

    this->sVal = new DSString();
    *sVal = *(copy.sVal);

    this->id = new DSString();
    *id = *(copy.id);

    this->actualTweet = new DSString();
    *actualTweet = *(copy.actualTweet);

}

Tweet &Tweet::operator=(const Tweet &copy) {
    if (this != &copy){

        delete sVal;
        delete id;
        delete actualTweet;

        this->sVal = new DSString();
        *sVal = *(copy.sVal);

        this->id = new DSString();
        *id = *(copy.id);

        this->actualTweet = new DSString();
        *actualTweet = *(copy.actualTweet);
    }
}

Tweet::~Tweet() {
    delete sVal;
    delete id;
    delete actualTweet;

}

void Tweet::setSVal(DSString &sVal) {
    this->sVal = new DSString(sVal);
}

DSString Tweet::getSVal() {
    return *sVal;
}

void Tweet::setId(DSString &id) {
    this->id = new DSString(id);
}

DSString Tweet::getId() {
    return *id;
}

void Tweet::setActualTweet(DSString &actualTweet) {
    this->actualTweet = new DSString(actualTweet);
}

DSString Tweet::getActualTweet() {
    return *actualTweet;
}