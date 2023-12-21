#include "Header.h"

Menu::Menu(const std::string& name, const std::string& description, const std::function<void()>& event) : m_name(name), m_description(description), m_event(event) {
}

Menu::~Menu() {
}

const std::string& Menu::GetName() const {
	return this->m_name;
}

const std::string& Menu::GetDescription() const {
	return this->m_description;
}

void Menu::Invoke() const {
	if (this->m_event == nullptr) {
		return;
	}

	this->m_event();
}

