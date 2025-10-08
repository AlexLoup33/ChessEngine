#ifndef __WINDOWMANAGER_HPP__
#define __WINDOWMANAGER_HPP__

#pragma once

#include <memory>
#include <unordered_map>
#include <string>
#include "gui/Window.hpp"

class WindowManager {
public:
    void addWindow(const std::string& name, std::shared_ptr<Window> window) {
        windows[name] = window;
    }

    void switchTo(const std::string& name) {
        if (windows.count(name))
            current = windows[name];
    }

    std::shared_ptr<Window> getCurrent() const { return current; }

private:
    std::unordered_map<std::string, std::shared_ptr<Window>> windows;
    std::shared_ptr<Window> current;
};

#endif // __WINDOWMANAGER_HPP__
