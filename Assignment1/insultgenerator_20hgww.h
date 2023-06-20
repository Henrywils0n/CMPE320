#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <cmath>
#include <sstream>
#include <set>

using namespace std;
//#ifndef ASSIGNMENT1_INSULTGENERATOR_H
//#define ASSIGNMENT1_INSULTGENERATOR_H
//
//#endif //ASSIGNMENT1_INSULTGENERATOR_H

class InsultGenerator {

    public:
        void initialize();      // read source file and store contents
        string talkToMe();      // generate a single insult
        void generateAndSave(const string& fileName, int num);  // Save insults a file
        vector<string> generate(int num);   // generate a vector of insults size num

    private:
        string adjective1[50];  // hold the first adjective
        string adjective2[50];  // hold the second adjective
        string noun[50];        // hold the noun

};

class FileException {
public:
    FileException(const string& message);
    string& what();
private:
    string message;
};

//This class is used when you request an invalid number of insults
class NumInsultsOutOfBounds {
public:
    NumInsultsOutOfBounds(const string& message);
    string& what();
private:
    string message;
};

