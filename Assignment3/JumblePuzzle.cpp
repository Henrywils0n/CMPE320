#include <string>
#include <utility>
#include "JumblePuzzle.h"

using namespace std;

JumblePuzzle::JumblePuzzle(const string& word, const string& difficulty) {
    if (word.length()<3 || word.length()>10){
        throw BadJumbleException("Word is not of valid length");
    }
    if (difficulty != "easy" && difficulty != "medium" && difficulty != "hard"){
        throw BadJumbleException("Difficulty is invalid");
    }
    for(char c :word) {
        if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
            continue;
        }
        throw BadJumbleException("Your word must only conatin a-z characters (or A-Z for testing)");
    }

    srand(time(nullptr));

    hiddenWord = word;
    int sideLength = (int)hiddenWord.length();
    if (difficulty == "easy") {
        size = sideLength * 2;
    }
    else if (difficulty == "medium") {
        size = sideLength * 3;
    }
    else {
        size = sideLength * 4;
    }

    InitalizeRandomTable();

    rowPos = rand() % size;
    colPos = rand() % size;
    string directions = "nesw";
    bool valid = false;
    do {
        direction = directions.at(rand() % 4);
        switch(direction){
            case 'n':
                if (rowPos + 1 - sideLength >= 0) {
                    valid = true;
                    for (int i=0; i<hiddenWord.length(); i++){
                        jumblePuzzle[rowPos - i][colPos] = hiddenWord.at(i);
                    }
                }
                break;
            case 'e':
                if (colPos + sideLength <= size) {
                    valid = true;
                    for (int i=0; i<hiddenWord.length(); i++){
                        jumblePuzzle[rowPos][colPos + i] = hiddenWord.at(i);
                    }
                }
                break;
            case 's':
                if (rowPos + sideLength <= size) {
                    valid = true;
                    for (int i=0; i<hiddenWord.length(); i++){
                        jumblePuzzle[rowPos + i][colPos] = hiddenWord.at(i);
                    }
                }
                break;
            case 'w':
                if (colPos + 1 - sideLength >= 0) {
                    valid = true;
                    for (int i=0; i<hiddenWord.length(); i++){
                        jumblePuzzle[rowPos][colPos-i] = hiddenWord.at(i);
                    }
                }
                break;
        }
    } while(!valid);
}

JumblePuzzle::JumblePuzzle(const JumblePuzzle &copy) {
    hiddenWord = copy.hiddenWord;
    size = copy.size;
    direction = copy.direction;
    rowPos = copy.rowPos;
    colPos = copy.rowPos;

    jumblePuzzle = new charArrayPtr[size];
    for (int i = 0; i < size; i++) {
        jumblePuzzle[i] = new char[size];
        for (int j = 0; j < size; j++) {
            jumblePuzzle[i][j] = copy.jumblePuzzle[i][j];
        }
    }
}

JumblePuzzle& JumblePuzzle::operator=(const JumblePuzzle& compare ) {
    if (this == &compare) {
        return *this;
    }

    for (int i = 0; i < size; i++) {
        charArrayPtr row = this->jumblePuzzle[i];
        delete[] row;
    }
    delete[] this->jumblePuzzle;

    direction = compare.direction;
    size = compare.size;
    rowPos = compare.rowPos;
    colPos = compare.colPos;
    hiddenWord = compare.hiddenWord;

    jumblePuzzle = new charArrayPtr[size];
    for (int i = 0; i < size; i++) {
        jumblePuzzle[i] = new char[size];
        for (int j = 0; j < size; j++) {
            jumblePuzzle[i][j] = compare.jumblePuzzle[i][j];
        }
    }

    return *this;
}


JumblePuzzle::~JumblePuzzle() {
    for (int i = 0; i < size; i++) {
        delete[] this->jumblePuzzle[i];
    }
    delete[] this->jumblePuzzle;
}


void JumblePuzzle::InitalizeRandomTable() {
    jumblePuzzle = new charArrayPtr[size];
    char random;
    for (int i=0; i<size; i++){
        jumblePuzzle[i] = new char[size];
        for (int j=0; j<size; j++){
            random = rand()%26;
            jumblePuzzle[i][j] = (char)('a' + random);
        }
    }
}

int JumblePuzzle::getSize() const {return size;}

int JumblePuzzle::getColPos() const {return colPos;}

int JumblePuzzle::getRowPos() const {return rowPos;}

char JumblePuzzle::getDirection() const {return direction;}

charArrayPtr* JumblePuzzle::getJumble() const {
    auto* copyPuzzle = new charArrayPtr[size];
    for (int i=0; i<size; i++){
        copyPuzzle[i] = new char[size];
        for (int j=0; j<size; j++){
            copyPuzzle[i][j] = jumblePuzzle[i][j];
        }
    }
    return copyPuzzle;
}

BadJumbleException::BadJumbleException(string message): message(std::move(message)) {}
string& BadJumbleException::what() { return message; }