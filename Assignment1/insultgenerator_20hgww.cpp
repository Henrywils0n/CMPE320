
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include "insultgenerator_20hgww.h"

using namespace std;

void InsultGenerator::initialize() {
    string currLine, word;
    ifstream insultsSource ("InsultsSource.txt");

    if (insultsSource.is_open()) {
        int lineNum = 0;
        while (getline(insultsSource, currLine, '\n')) {
            vector<string> words;
            istringstream iss(currLine);
            while (getline(iss, word, '\t')) {
                words.emplace_back(string(word));
            }
            adjective1[lineNum] = words[0];
            adjective2[lineNum] = words[1];
            noun[lineNum] = words[2];
            lineNum++;
        }
        insultsSource.close();
    }
    else{
        throw FileException("Unable to find file");
    }
}

string InsultGenerator::talkToMe() {
    return ("Thou " + adjective1[rand() % 50] + string(" ") + adjective2[rand() % 50]+ string(" ")+ noun[rand() % 50]+ "!");
}

void InsultGenerator::generateAndSave(const string& fileName, int num) {
    ofstream insultsFile(fileName);
    if(insultsFile.is_open()){
        vector<string> insults = InsultGenerator::generate(num);
        for (int i=0;i<num;i++) {
            insultsFile << insults[i] << endl;
        }
        insultsFile.close();
    }
}

vector<string> InsultGenerator::generate(int num) {
    if (num<=0 || num>10000){
        throw NumInsultsOutOfBounds("number of insults is out of allowable bounds");
    }
    set<string> insults;
    for (int i=0; i<num; i++) {
        string insult = InsultGenerator::talkToMe();
        if (!insults.insert(insult).second) {
            i--;
            continue;
        }
    }
    vector<string> sorted_insults;
    set<string> :: iterator it;
    for(it = insults.begin() ; it != insults.end() ; it++) {
        sorted_insults.push_back(*it);
    }
    return sorted_insults;
}

FileException::FileException(const string& message) : message(message) {}
string& FileException::what() {
    return message;
}

NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string& message): message(message) {}
string&  NumInsultsOutOfBounds::what() {
    return message;
}
