#pragma once

/// <summary>
/// Scene.
/// </summary>
class Scene abstract {
private:
	/// <summary>
	/// 해당 Scene의 이름.
	/// </summary>
	std::string	m_name;

	/// <summary>
	/// 해당 Scene의 설명.
	/// </summary>
	std::string	m_description;

	/// <summary>
	/// 해당 Scene에 진입했는지에 대한 여부.
	/// </summary>
	bool		m_isEntered;

public:
	Scene(const std::string& name, const std::string& description);
	~Scene() = default;

public:
	/// <summary>
	/// 해당 Scene의 이름을 가져옵니다.
	/// </summary>
	/// <returns>해당 Scene의 이름.</returns>
	const std::string& GetName() const;

	/// <summary>
	/// 해당 Scene의 설명을 가져옵니다.
	/// </summary>
	/// <returns>해당 Scene의 설명,</returns>
	const std::string& GetDescription() const;

	/// <summary>
	/// 해당 Scene에 진입합니다.
	/// </summary>
	void Enter();

	/// <summary>
	/// 해당 Scene에서 빠져나옵니다.
	/// </summary>
	void Exit();

	/// <summary>
	/// 해당 Scene의 이벤트 주기.
	/// </summary>
	virtual void Routine();
};
