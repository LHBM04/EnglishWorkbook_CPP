#pragma once

/// <summary>
/// 메뉴 유틸리티.
/// </summary>
class Menu final {
private:
	/// <summary>
	/// 메뉴 이름.
	/// </summary>
	std::string				m_name;
	/// <summary>
	/// 메뉴 설명.
	/// </summary>
	std::string				m_description;
	/// <summary>
	/// 메뉴 이벤트.
	/// </summary>
	std::function<void()>	m_event;

public:
	Menu(const std::string& name, const std::string& description, const std::function<void()>& event);
	~Menu();

public:
	/// <summary>
	/// 해당 메뉴 이름을 가져옵니다.
	/// </summary>
	/// <returns>해당 메뉴 이름.</returns>
	const std::string& GetName() const;
	/// <summary>
	/// 해당 메뉴 설명을 가져옵니다.
	/// </summary>
	/// <returns></returns>
	const std::string& GetDescription() const;
	/// <summary>
	/// 해당 메뉴의 이벤트를 발생시킵니다.
	/// </summary>
	void Invoke() const;

};

/// <summary>
/// 메뉴 셀렉터.
/// </summary>
class MenuSelector final {
private:
	/// <summary>
	/// 관리하는 메뉴들.
	/// </summary>
	std::vector<std::shared_ptr<const Menu>> m_menus;

public:
	MenuSelector(const size_t size);
	~MenuSelector();

public:
	void AddMenu(const std::shared_ptr<const Menu>& menu);
	void Display() const;
	void Select() const;
	void Update() const;
};

