#include <string>

using namespace std;

#ifndef ASSIGNMENT3_JUMBLEPUZZLE_H
#define ASSIGNMENT3_JUMBLEPUZZLE_H


#endif //ASSIGNMENT3_JUMBLEPUZZLE_H

typedef char* charArrayPtr;

class JumblePuzzle{
public:
    // main contsructor. Input the word you are looking for followed by difficulty
    JumblePuzzle(const string& word, const string& diff);

    // copy constructor
    JumblePuzzle(const JumblePuzzle& copy);

    // destructor
    ~JumblePuzzle();

    // overwrite of equals operator
    JumblePuzzle& operator=(const JumblePuzzle&);

    // accessors
    int getSize() const;
    int getRowPos() const;
    int getColPos() const;
    char getDirection() const;
    charArrayPtr* getJumble() const;

private:
    // initializes the jumble puzzle to a table of random lower case letters
    void InitalizeRandomTable();

    // private variables
    charArrayPtr* jumblePuzzle;
    string hiddenWord;
    int size;
    int rowPos;
    int colPos;
    char direction;
};

// Exception class thrown by JumblePuzzle class
class BadJumbleException{
public:
    BadJumbleException(string  message);
    string& what();
private:
    string message;
};

