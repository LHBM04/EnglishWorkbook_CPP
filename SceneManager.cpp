#include "Header.h"

SceneManager::SceneManager() {
    AddScene(SCENE_NAME_MAINMENU,       std::make_shared<MainScene>());
    AddScene(SCENE_NAME_MAINMENU,      std::make_shared<StudyScene>());
    AddScene(SCENE_NAME_MAINMENU,     std::make_shared<ReviewScene>());
    AddScene(SCENE_NAME_MAINMENU,  std::make_shared<WrongNoteScene>());
}

void SceneManager::AddScene(const std::string& sceneName, const std::shared_ptr<Scene>& scene) {
    if (this->m_scenes.find(sceneName) != this->m_scenes.end()) {
        this->m_scenes.erase(sceneName);
    }

    this->m_scenes.insert(std::make_pair(sceneName, scene));
}

void SceneManager::LoadScene(const std::string& sceneName) {
    auto nextScene = this->m_scenes.find(sceneName);
    if (nextScene != this->m_scenes.end()) {
        Console::Clear();
        if (!this->m_previousScenes.empty()) {
            this->m_previousScenes.top()->Exit();
        }

        this->m_previousScenes.push(nextScene->second);
        this->m_previousScenes.top()->Enter();
    }
}

void SceneManager::UnloadScene() {
    if (!this->m_previousScenes.empty()) {
        Console::Clear();
        this->m_previousScenes.top()->Exit();
        this->m_previousScenes.pop();

        if (!this->m_previousScenes.empty()) {
            this->m_previousScenes.top()->Enter();
        }
    }
}