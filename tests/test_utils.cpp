#include "utils/Utils.hpp"
#include <iostream>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;;

void usage(char *argv[]){
    fprintf(stderr, "Usage: %s <testname> [<...>]\n", argv[0]);
    exit(EXIT_FAILURE);
}

bool test_split(){
    string s1 = "Test/1/du/SPLIT";
    vector<string> ret1 = split(s1, "/");
    vector<string> sol1 = {"Test", "1", "du", "SPLIT"};

    string s2 = "AAA@AAA@BBB@BBB@CCC";
    vector<string> ret2 = split(s2, "@");
    vector<string> sol2 = {"AAA", "AAA", "BBB", "BBB", "CCC"};

    string s3 = "AbAAAbDDDbGFGFDSCdbBBBBb";
    vector<string> ret3 = split(s3, "b");
    vector<string> sol3 = {"A", "AAA", "DDD", "GFGFDSCd", "BBBB", ""};


    if (ret1 != sol1){
        fprintf(stderr, "PROBLEM on 1\n");
        return false;
    }

    if (ret2 != sol2){
        fprintf(stderr, "PROBLEM on 2\n");
        return false;
    }

    if (ret3 != sol3){
        displayStringVector(ret3);
        displayStringVector(sol3);
        fprintf(stderr, "PROBLEM on 3\n");
        return false;
    }

    return true;
}

bool test_is_digit(){
    for (int i = 0; i < 10; i++){
        if (!is_digit(i+'0')){
            printf("Problem with digit %c\n", i);
            return false;
        }
    }
    if (is_digit('T') || is_digit('E') || is_digit('S') || is_digit('T')){
        printf("Problem on false digit\n");
        return false;
    }
    return true;
}

bool test_string_position_to_int(){
    struct { const char* s; int expected; } tests[] = {
        {"A1", 56}, {"H1", 63}, {"A8", 0}, {"H8", 7},
        {"C5", 26}, {"F5", 29}
    };

    for (auto& t : tests){
        int got = StringPositionToInt(t.s);
        if (got != t.expected){
            fprintf(stderr, "Error: %s -> got %d, expected %d\n", t.s, got, t.expected);
            return false;
        }
    }
    return true;
}


int main(int argc, char* argv[]){
    if (argc == 1){
        usage(argv);
    }

    fprintf(stderr, "=> Start test \"%s\"\n", argv[1]);
    bool pass = false;

    if (strcmp(argv[1], "split") == 0)
        pass = test_split();
    else if(strcmp(argv[1], "is_digit") == 0)
        pass = test_is_digit();
    else if (strcmp(argv[1], "string_position_to_int") == 0)
        pass = test_string_position_to_int();
    else{
        fprintf(stderr, "Error: test \"%s\" not found !\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if (pass == true){
        fprintf(stderr, "Test \"%s\" finished: SUCCESS\n", argv[1]);
        return EXIT_SUCCESS;
    }else{
        fprintf(stderr, "Test \"%s\" finished: FAILURE\n", argv[1]);
        return EXIT_FAILURE;
    }
}