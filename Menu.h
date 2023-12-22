#pragma once

/// <summary>
/// 메뉴 유틸리티.
/// </summary>
class Menu final {
private:
	struct Information {
		std::string name;
		std::string description;
	};

	/// <summary>
	/// 해당 메뉴의 이름.
	/// </summary>
	Menu::Information		m_information;
	/// <summary>
	/// 해당 메뉴의 이벤트.
	/// </summary>
	std::function<void()>	m_event;

public:
	Menu(const nlohmann::json& jsonFile, const std::function<void()>& event);
	~Menu() = default;

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