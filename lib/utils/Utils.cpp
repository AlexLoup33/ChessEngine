#include "utils/Utils.hpp"

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

int StringPositionToInt(const char* c){
    int file = c[0] - 'A';         // A=0, B=1, ..., H=7
    if (file < 0 || file > 7)
        throw runtime_error("StringPositionToInt: file out of range (A-H)");

    int rank = c[1] - '1';         // 1=0, 2=1, ..., 8=7
    if (rank < 0 || rank > 7)
        throw runtime_error("StringPositionToInt: rank out of range (1-8)");

    return (7 - rank) * 8 + file;  // inverser la rangée pour que A8=0
}


void displayStringVector(std::vector<std::string> v){
    cout << "[ ";
    for (auto i : v)
        cout << i << ", ";
    cout << "]";
}