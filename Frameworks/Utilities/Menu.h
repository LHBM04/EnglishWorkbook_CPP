#pragma once

#include <string>
#include <functional>

#include "MenuManager.h";
class MenuManager;
class Menu {
	friend MenuManager;
private:
	std::string m_name{ "???" };
	std::string m_description{"???"};
	std::function<void()> m_event{ nullptr };

public:
	Menu() = delete;
	Menu(const Menu&) = delete;
	Menu(const char* const, const char* const, void(*)());
	Menu(const std::string&, const std::string&, std::function<void()>);
	~Menu();

public:
	const std::string& GetName() const;
	const std::string& GetDescription() const;

	void Invoke() const;
};

