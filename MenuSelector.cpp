#include "Header.h"

MenuSelector::MenuSelector(const size_t size) {
	this->m_menus.reserve(size);
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