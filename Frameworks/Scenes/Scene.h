#pragma once

#include <format>
#include <string>

#include "SceneManager.h"

class SceneManager;
class Scene abstract {
	friend SceneManager;

protected:
	std::string m_name{ "???" };
	std::string m_description{ "???" };

public:
	Scene() = delete;
	Scene(const Scene&) = delete;
	Scene(const char*&, const char*&);
	Scene(const std::string&, const std::string&);
	virtual ~Scene() {};

	void operator = (const Scene&) = delete;

public:
	virtual void Display() const = 0;
	virtual void Update() const = 0;
	
public:
	const std::string& GatName() const;
	const std::string& GetDescription() const;
};

