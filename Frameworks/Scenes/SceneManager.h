#pragma once

#include <iterator>
#include <memory>
#include <optional>
#include <stack>
#include <vector>
#include <unordered_map>

#include "Scene.h"
#include "Singleton.h"

class Scene;
class SceneManager : public Singleton<SceneManager> {
	friend Scene;
private:
	std::unordered_map<std::string, std::shared_ptr<Scene>> m_scenes;

};