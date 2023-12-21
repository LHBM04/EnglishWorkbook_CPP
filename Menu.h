#pragma once

/// <summary>
/// �޴� ��ƿ��Ƽ.
/// </summary>
class Menu final {
private:
	/// <summary>
	/// �޴� �̸�.
	/// </summary>
	std::string				m_name;
	/// <summary>
	/// �޴� ����.
	/// </summary>
	std::string				m_description;
	/// <summary>
	/// �޴� �̺�Ʈ.
	/// </summary>
	std::function<void()>	m_event;

public:
	Menu(const std::string& name, const std::string& description, const std::function<void()>& event);
	~Menu();

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