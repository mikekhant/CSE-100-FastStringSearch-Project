#include <string>
#include <vector>
#include "SuffixArray.h"
#include <iostream>
using namespace std;

vector<unsigned int> array;
vector<string> suffixes;

void nextSuffix(int num, string suffix) {
    if(suffixes[0] > suffix) {
        array.insert(array.begin(), num);
        suffixes.insert(suffixes.begin(), suffix);
        return;
    }
    for(unsigned int i=0; i<array.size()-1; i++) {
        if(suffixes[i] < suffix && suffixes[i+1] > suffix) {
            vector<string>::iterator stringit = suffixes.begin() + i + 1;
            suffixes.insert(stringit, suffix);
            vector<unsigned int>::iterator intit = array.begin() + i + 1;
            array.insert(intit, num);
            return;
        }
    }
    suffixes.push_back(suffix);
    array.push_back(num);
}

/**
 * Implement suffix_array() correctly
 */
vector<unsigned int> suffix_array(const string & s) {
    array.push_back(0);
    suffixes.push_back(s);
    string suffix = s.substr(1, s.length()-1);
    if(s > suffix) {
        array.insert(array.begin(), 1);
        suffixes.insert(suffixes.begin(), suffix);
    }
    else {
        array.push_back(1);
        suffixes.push_back(suffix);
    }
    
    for(unsigned int i=2; i<s.length(); i++) {
        string suffix = s.substr(i, s.length()-i);
        nextSuffix(i, suffix);
    }
    return array;
}


