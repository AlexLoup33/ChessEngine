#include <stdio.h>
#include <stdint.h>

#include <SDL2/SDL.h>

#include "gui/Application.hpp"

using namespace std;;

int main(int argc, char** argv){
    Application app("Chess Engine", 1280, 720);
    app.run();

    return EXIT_SUCCESS;
}