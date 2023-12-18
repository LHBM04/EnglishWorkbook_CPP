#include "Header.h"

Menu::Menu(const std::string& name, const std::string& description, const std::function<void()>& event) : m_name(name), m_description(description), m_event(event) {
}

Menu::~Menu()
{
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

MenuSelector::MenuSelector(const size_t size) {
	this->m_menus.reserve(size);
}

MenuSelector::~MenuSelector() {
}

void MenuSelector::AddMenu(const std::shared_ptr<const Menu>& menu) {
	this->m_menus.push_back(menu);
}

void MenuSelector::Display() const {
	int index = 0;
	for (const std::shared_ptr<const Menu> menu : this->m_menus) {
		Console::WriteLine(std::format("[{:d}]. 「{:s}」", ++index, menu->GetName()));
	}
}

void MenuSelector::Select() const {
	Console::Write("메뉴를 선택해주세요. : ");
	while (true) {
		int index = Console::Read(size_t(1), this->m_menus.size(), []() { Console::Write("올바른 메뉴를 선택해주세요. : "); }) - 1;
		if (this->m_menus.at(index) != nullptr) {
			this->m_menus.at(index)->Invoke();
			return;
		}
	}
}

void MenuSelector::Update() const {
	while (true) {
		this->Display();
		this->Select();
	}
}
