#include "Menu.h"

Menu::Menu(const char* const _name, const char* const _description, void(*_event)()) :
	m_name(_name),
	m_description(_description),
	m_event(_event) {
}

Menu::Menu(const std::string& _name, const std::string& _description, std::function<void()> _event) :
	m_name(_name),
	m_description(_description),
	m_event(_event) {
}

const std::string& Menu::GetName() const {
	return this->m_name;
}

const std::string& Menu::GetDescription() const
{
	return this->m_description;
}

void Menu::Invoke() const {
	if (this->m_event == nullptr) {
		return;
	}

	this->m_event();
}
