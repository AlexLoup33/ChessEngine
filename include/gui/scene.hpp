#ifndef __SCENE_HPP__
#define __SCENE_HPP__

#pragma once

#include <SDL2/SDL.h>

class Window;

class Scene {
public:
    virtual ~Scene() = default;
    virtual void handleEvent(const SDL_Event& e) = 0;
    virtual void update() = 0;
    virtual void render(Window& window) = 0;
    virtual bool shouldQuit() const = 0;
};

#endif // __SCENE_HPP__