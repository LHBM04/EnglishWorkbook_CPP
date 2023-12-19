#include "Header.h"

unsigned int Scene::DEFAULT_SCENE_BUILD_INDEX = 0;

Scene::Scene(const std::string& name, const std::string& description) : m_buildIndex(Scene::DEFAULT_SCENE_BUILD_INDEX++), m_name(name), m_description(description) {
}

Scene::~Scene() {
}

const unsigned int Scene::GetBuildIndex() const {
	return this->m_buildIndex;
}

const std::string& Scene::GetName() const {
	return this->m_name;
}

const std::string& Scene::GetDescription() const {
	return this->m_description;
}

void Scene::Enter() {
	this->m_isEntered = true;

	while (this->m_isEntered) {
		this->Routine();
	}
}

void Scene::Exit() {
	this->m_isEntered = false;
}

void Scene::Routine() {
	Console::WriteLine(std::format("¡º{:s}¡»", this->GetName()));
	Console::WriteLine(std::format("({:s})", this->GetDescription()));
}

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
	auto pred = [sceneIndex](const std::shared_ptr<Scene>& scene) { return scene->GetBuildIndex() == sceneIndex; };
	auto next = std::find_if(this->m_scenes.begin(), this->m_scenes.end(), pred);

    if (next == this->m_scenes.end()) {
        return;
    }

    Console::Clear();
    if (!this->m_previousScenes.empty()) {
        this->m_previousScenes.top()->Exit();
    }

    this->m_previousScenes.push(*next);
    this->m_previousScenes.top()->Enter();
}

void SceneManager::LoadScene(const std::string& sceneName) {
    auto pred = [&sceneName](const std::shared_ptr<Scene>& scene) { return scene->GetName() == sceneName; };
    auto next = std::find_if(this->m_scenes.begin(), this->m_scenes.end(), pred);

    if (next == this->m_scenes.end()) {
        return;
    }

    Console::Clear();
    if (this->m_previousScenes.size() != 0) {
        this->m_previousScenes.top()->Exit();
    }

    this->m_previousScenes.push(*next);
    this->m_previousScenes.top()->Enter();
}

void SceneManager::UnloadScene() {
    if (this->m_previousScenes.empty()) {
        return;
    }

    this->m_previousScenes.top()->Exit();
    this->m_previousScenes.pop();
    
    if (!this->m_previousScenes.empty()) {
        Console::Clear();
        this->m_previousScenes.top()->Enter();
    }
}
