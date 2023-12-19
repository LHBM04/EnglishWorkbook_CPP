#include "Header.h"

SceneManager::SceneManager() {
    this->m_scenes.reserve(3);
    this->m_scenes.push_back(std::make_shared<MainScene>());
    this->m_scenes.push_back(std::make_shared<StudyScene>());
    this->m_scenes.push_back(std::make_shared<ReviewScene>());
}

SceneManager::~SceneManager() {
}

void SceneManager::AddScene(const std::shared_ptr<Scene>& scene) {
    this->m_scenes.push_back(scene);
}

void SceneManager::LoadScene(const unsigned int sceneIndex) {
    auto predicate = [sceneIndex](const std::shared_ptr<Scene>& scene) { return scene->GetBuildIndex() == sceneIndex; };
    auto nextScene = std::find_if(this->m_scenes.begin(), this->m_scenes.end(), predicate);

    if (nextScene == this->m_scenes.end()) {
        return;
    }

    Console::Clear();
    if (!this->m_previousScenes.empty()) {
        this->m_previousScenes.top()->Exit();
    }

    this->m_previousScenes.push(*nextScene);
    this->m_previousScenes.top()->Enter();
}

void SceneManager::LoadScene(const std::string& sceneName) {
    auto predicate = [&sceneName](const std::shared_ptr<Scene>& scene) { return scene->GetName() == sceneName; };
    auto nextScene = std::find_if(this->m_scenes.begin(), this->m_scenes.end(), predicate);

    if (nextScene == this->m_scenes.end()) {
        return;
    }

    Console::Clear();
    if (this->m_previousScenes.size() != 0) {
        this->m_previousScenes.top()->Exit();
    }

    this->m_previousScenes.push(*nextScene);
    this->m_previousScenes.top()->Enter();
}

void SceneManager::UnloadScene() {
    if (this->m_previousScenes.empty()) {
        return;
    }

    Console::Clear();
    this->m_previousScenes.top()->Exit();
    this->m_previousScenes.pop();

    if (!this->m_previousScenes.empty()) {
        this->m_previousScenes.top()->Enter();
    }
}