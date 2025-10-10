#include "gui/WindowManager.hpp"
#include "gui/MenuWindow.hpp"
#include "gui/PlayerGameWindow.hpp"

#include <iostream>

using namespace std;

WindowManager::WindowManager(SDL_Renderer* renderer)
    : renderer(renderer), currentWindow(nullptr) {}

WindowManager::~WindowManager() = default;

void WindowManager::handleEvent(const SDL_Event& event) {
    if (currentWindow)
        currentWindow->handleEvent(event);
}

void WindowManager::render() {
    if (currentWindow)
        currentWindow->render(renderer);
}

void WindowManager::update() {
    if (currentWindow)
        currentWindow->update();
}

unique_ptr<Window> WindowManager::createWindow(const string& name) {
    if (name == "menu") {
        return make_unique<MenuWindow>(this, renderer);
    } else if (name == "player_game") {
        return make_unique<PlayerGameWindow>(this, renderer);
    } else {
        cerr << "❌ Unknown window name: " << name << endl;
        return nullptr;
    }
}

void WindowManager::switchTo(const string& windowName) {
    // 🧠 Mise en cache ou suppression selon le type de fenêtre
    if (currentWindow) {
        if (currentName == "menu") {
            cache[currentName] = move(currentWindow);
        } else {
            currentWindow.reset();
        }
    }

    // 🔄 Restauration si déjà en cache
    auto it = cache.find(windowName);
    if (it != cache.end()) {
        currentWindow = move(it->second);
        cout << "✅ Restored cached window: " << windowName << endl;
    } else {
        currentWindow = createWindow(windowName);
        cout << "🆕 Created new window: " << windowName << endl;
    }

    currentName = windowName;
}

Window* WindowManager::getCurrentWindow() {
    return currentWindow.get();
}
