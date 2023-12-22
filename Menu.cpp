#include "Header.h"

Menu::Menu(const nlohmann::json& jsonFile, const std::function<void()>& event) : m_event(event) {
	this->m_information.name		= jsonFile.at("name").get<std::string>();
	this->m_information.description = jsonFile.at("name").get<std::string>();
}

const std::string& Menu::GetName() const {
	return this->m_information.name;
}

const std::string& Menu::GetDescription() const {
	return this->m_information.description;
}

void Menu::Invoke() const {
	if (this->m_event == nullptr) {
		return;
	}

	this->m_event();
}

