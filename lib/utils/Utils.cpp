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
    // Converting the letter into file
    int file = (int)c[0];
    if (file < 65 || file > 72) // A to H
        throw runtime_error("Error: StringPositionToInt: file is out of range (A-H)");
    file -= 65;
    
    // Converting the digit into rank
    int rank = (int)c[1];
    if (rank < 49 || rank > 56) // 1 to 8
        throw runtime_error("Error: StringPositionToInt: rank is out of range (1-8)");
    rank -= 49;

    int pos = file*8+rank;
    if (pos < 0 || pos > 63)
        throw runtime_error("Error: StringPositionToInt: pos is out of range (0-63)");
    return pos;
}

void displayStringVector(std::vector<std::string> v){
    cout << "[ ";
    for (auto i : v)
        cout << i << ", ";
    cout << "]";
}