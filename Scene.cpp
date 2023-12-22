#include "Header.h"

Scene::Scene(const std::string& name, const std::string& description) : m_name(name), m_description(description), m_isEntered(false) {
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