#pragma once

/// <summary>
/// Scene.
/// </summary>
class Scene abstract {
private:
	/// <summary>
	/// �ش� Scene�� �̸�.
	/// </summary>
	std::string	m_name;

	/// <summary>
	/// �ش� Scene�� ����.
	/// </summary>
	std::string	m_description;

	/// <summary>
	/// �ش� Scene�� �����ߴ����� ���� ����.
	/// </summary>
	bool		m_isEntered;

public:
	Scene(const std::string& name, const std::string& description);
	~Scene() = default;

public:
	/// <summary>
	/// �ش� Scene�� �̸��� �����ɴϴ�.
	/// </summary>
	/// <returns>�ش� Scene�� �̸�.</returns>
	const std::string& GetName() const;

	/// <summary>
	/// �ش� Scene�� ������ �����ɴϴ�.
	/// </summary>
	/// <returns>�ش� Scene�� ����,</returns>
	const std::string& GetDescription() const;

	/// <summary>
	/// �ش� Scene�� �����մϴ�.
	/// </summary>
	void Enter();

	/// <summary>
	/// �ش� Scene���� �������ɴϴ�.
	/// </summary>
	void Exit();

	/// <summary>
	/// �ش� Scene�� �̺�Ʈ �ֱ�.
	/// </summary>
	virtual void Routine();
};
