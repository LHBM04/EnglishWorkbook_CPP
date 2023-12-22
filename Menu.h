#pragma once

/// <summary>
/// �޴� ��ƿ��Ƽ.
/// </summary>
class Menu final {
private:
	struct Information {
		std::string name;
		std::string description;
	};

	/// <summary>
	/// �ش� �޴��� �̸�.
	/// </summary>
	Menu::Information		m_information;
	/// <summary>
	/// �ش� �޴��� �̺�Ʈ.
	/// </summary>
	std::function<void()>	m_event;

public:
	Menu(const nlohmann::json& jsonFile, const std::function<void()>& event);
	~Menu() = default;

public:
	/// <summary>
	/// �ش� �޴� �̸��� �����ɴϴ�.
	/// </summary>
	/// <returns>�ش� �޴� �̸�.</returns>
	const std::string& GetName() const;

	/// <summary>
	/// �ش� �޴� ������ �����ɴϴ�.
	/// </summary>
	/// <returns></returns>
	const std::string& GetDescription() const;

	/// <summary>
	/// �ش� �޴��� �̺�Ʈ�� �߻���ŵ�ϴ�.
	/// </summary>
	void Invoke() const;

};