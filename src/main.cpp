#include <stdio.h>
#include <stdint.h>

#include "gui/application.hpp"


using namespace std;

int main(int argc, char** argv){
    Application app("Chess Engine", 1280, 720);
    app.run();
    
    return 0;
}