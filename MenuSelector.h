#pragma once

/// <summary>
/// �޴� ������.
/// </summary>
class MenuSelector final {
private:
	/// <summary>
	/// �����ϴ� �޴���.
	/// </summary>
	std::vector<std::shared_ptr<const Menu>> m_menus;

public:
	MenuSelector(const size_t size);
	~MenuSelector() = default;

public:
	void AddMenu(const std::shared_ptr<const Menu>& menu);
	void Display() const;
	void Select() const;
	void Update() const;
};

