#include "utils/utils.hpp"

using namespace std;; 

vector<string> split(const string& text, const string& delimiter) {
    vector<string> res;
    size_t start = 0, end = 0;
    while ((end = text.find(delimiter, start)) != string::npos) {
        res.push_back(text.substr(start, end - start));
        start = end + delimiter.length();
    }
    res.push_back(text.substr(start));
    return res;
}

bool is_digit(int c){
    return (c >= '0' && c <= '9');
}