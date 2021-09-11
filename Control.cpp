#include "Control.h"

Control::Control(char *file1, char *file2, char *file3, char *file4) {
    trainFile(file1); // Calls the train function and sends the train file
    testFile(file2); // Calls the test function and sends the test file
    testSVal(file3, file4); // Calls the test sentiment function and sends the sentiment file
}
// Training the algo by reading in the positive and negative words.
// Goal is to attach the amount of times a word appears in the entire file to said word
void Control::trainFile (char* filePassed) {
    // Creating 2 maps one for positive words and one for negative words
    map<DSString, int> positive;
    map<DSString, int> negative;
    // Allocating memory for c-strings
    char char1[281]; // This is for the actual whole tweet
    char charS[2]; // sentiment value of the tweet
    char charId[11]; // id for the tweet
    char charIgnore[200]; // Buffer
    ifstream file(filePassed); // Opening file
    file.getline(charIgnore, 200, '\n'); // Ignore header
    // Looping through the entire file tweet by tweet
    while (!file.eof()) {

        file.getline(charS, 2, ','); // Getting sentiment from char
        DSString sVal(charS); // Creating DSString object for sentiment
        // Same process but for id
        file.getline(charId, 11, ',');
        DSString id(charId);
        // Ignoring date, no query, and username
        file.getline(charIgnore, 200, ',');
        file.getline(charIgnore, 200, ',');
        file.getline(charIgnore, 200, ',');
        // get tweet from file
        file.getline(char1, 281, '\n');

        char charWords[strlen(char1) + 1]; // Creating c-string to parse each word into
        int j = 0; // index for charWords
        // Looping through the tweet for each char
        for (int i = 0; i < strlen(char1); i++) {
            // Enters if there is a new word indicated by a space
            if (char1[i] == ' ') {
                charWords[j] = '\0'; // Forcibly ending the c-string to avoid any weird outputs
                DSString actualTweet(charWords); // sends the finalized word to a DSString object
                // if the word is greater than 2 characters, it will be placed in the map
                if (actualTweet.getLength() > 2) {
                    // if negative
                    if (sVal[0] == '0') {
                        // Searches to see if the words exists in the map
                        if (negative.count(actualTweet) == 0) {
                            // if it does not then the DDString will be placed in the map with a count of 1
                            negative.emplace(actualTweet, 1);
                        } else {
                            // if it does appear then it will add to the count
                            negative.at(actualTweet)++;
                        }
                    }
                    else { // Enters when positive
                        // Same process as before
                        if (positive.count(actualTweet) == 0) {
                            positive.emplace(actualTweet, 1);
                        } else {
                            positive.at(actualTweet)++;
                        }
                    }
                }
                // This memset below is simply a precaution, not necessary as the charWords
                // already is stopped due to the null allocated above
                memset(charWords, 0, strlen(charWords)); // Resetting the c-string so there is no words left over
                j = 0; // Pointing back to the beginning of the c-string so
                // the new word doesn't start part way through the string

            }
            // if the word is not complete, this will check if it is an alphabetic character
            // This will also cause it to ignore any char that is not alphabetic
            if (isalpha(char1[i])) {
                char1[i] = tolower(char1[i]); // if it is then it will become lowercase
                charWords[j] = char1[i]; // Sends the char to the word
                j++;
            }
        }

    }
    // After we have a list of positive and negative words we put those into a vector
    maps = {negative, positive};
    file.close(); // Close the train file, not sure if necessary but did so anyway
}
// Test the algo by using the count of the words from trainFile().
void Control::testFile(char *filePassed) {
    DSString negSVal = "0";
    DSString posSVal = "4";
    // Same initialization as in train, but without sVal
    char char1[281];
    char charId[11];
    char charIgnore[200];
    ifstream file(filePassed); // Opening file
    file.getline(charIgnore, 200, '\n'); // Ignore header
    // Loop tweet by tweet till end of file
    while (!file.eof()) {
        // This countS will decide whether the tweet is + or -
        int countS = 0;
        file.getline(charId, 11, ','); // Getting id from char
        DSString id(charId); // Creating a DSString for id
        // Ignoring date, no query, and username
        file.getline(charIgnore, 200, ',');
        file.getline(charIgnore, 200, ',');
        file.getline(charIgnore, 200, ',');
        // Get tweet from file
        file.getline(char1, 281, '\n');

        char charWords[strlen(char1) + 1]; // c-string for each word
        int j = 0;
        // loop through tweet for each char
        for (int i = 0; i < strlen(char1); i++) {
            // Enters if there is a new word indicated by a space
            if (char1[i] == ' ') {
                charWords[j] = '\0';
                DSString actualTweet(charWords); // DSString for the completed word
                // if the word exists within the trained map of - words
                if (maps.at(0).count(actualTweet) > 0){
                    // Subtracts from the count which indicates the sentiment
                    countS = countS - maps.at(0).at(actualTweet);
                }
                // if the word exists within the trained map of + words
                if (maps.at(1).count(actualTweet) > 0){
                    // Adds from the count which indicates the sentiment
                    countS = countS + maps.at(1).at(actualTweet);
                }
                // I made it so even if the word is in both lists it will just add and subtract from one another
                memset(charWords, 0, strlen(charWords));
                j = 0;
            }
            // Same processes of converting letters to lowercase
            if (isalpha(char1[i])) {
                char1[i] = tolower(char1[i]);
                charWords[j] = char1[i];
                j++;
            }
        }
        // After iterating through the entire tweet if countS > 0 then the sentiment is +.
        // if it is countS < 0 then the sentiment is -.
        if (countS < 0) {
            tweetS.emplace(id, negSVal); // Places the id and predicted sentiment inside - map
        }
        else{
            tweetS.emplace(id, posSVal); // Places the id and predicted sentiment inside + map
        }
    }
    maps.at(0).clear(); // Clears the map of trained - words as we no longer need them
    maps.at(1).clear(); // Clears the map of trained + words as we no longer need them
    maps.clear(); // Clears the vector of the map
    file.close(); // Closes file just in case
}
// Checks to see if the predicted sentiment for each tweet was correct
void Control::testSVal(char *sFile, char *oFile) {
    // Only need to ignore the header so size allocated is smaller
    char charIgnore[20];
    char charS[2];
    char charId[11];
    int count = 0; // Keeps track of how many tweets there are
    double amountRight = 0.000; // Calculates the amount of predictions right
    vector<DSString> incorrectTweets; // Will contain the tweets predicted incorrectly

    ifstream file(sFile); // Open file

    file.getline(charIgnore, 20, '\n'); // Ignores header
    // Loops through each line until end of the file
    while (!file.eof()){
        count ++;
        file.getline(charS, 2, ','); // Gets sentiment
        DSString sVal(charS); // Creates a DSString for sentiment
        file.getline(charId, 11, '\n'); // Gets id
        DSString id(charId); // Creates a DSString for id
        // Checks the predicted sentiment of the same id inside the map
        // to see if it is the same as the real sentiment
        if (tweetS.at(id) == sVal) {
            amountRight++; // If it is the amount right increases
        }
        // If not the id is placed in the vector of incorrect tweets
        else {
            incorrectTweets.push_back(id);
        }
    }
    ofstream output (oFile); // Opening the output file
    // Prints the accuracy to the output file
    output << fixed << setprecision(3) << amountRight/count << endl;
    // Loops through the vector of incorrect tweets which prints their id to the output file
    for (int i = 0; i < incorrectTweets.size(); i++){
        output << incorrectTweets.at(i) << endl;
        //incorrectTweets.at(i);

    }
    output.close(); // Closes output file
    file.close(); // Closes the file that check the sentiment

}

