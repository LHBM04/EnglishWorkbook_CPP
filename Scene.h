#pragma once

/// <summary>
/// Scene.
/// </summary>
class Scene abstract {
private:
	/// <summary>
	/// �⺻ ���� �ε���.
	/// </summary>
	static unsigned int DEFAULT_SCENE_BUILD_INDEX;

private:
	/// <summary>
	/// �ش� Scene�� �Ϸ� ��ȣ.
	/// </summary>
	unsigned int	m_buildIndex	= DEFAULT_SCENE_BUILD_INDEX;

	/// <summary>
	/// �ش� Scene�� �̸�.
	/// </summary>
	std::string		m_name			= SCENE_NAME_DEFAULT;

	/// <summary>
	/// �ش� Scene�� ����.
	/// </summary>
	std::string		m_description	= SCENE_DESC_DEFAULT;

	/// <summary>
	/// �ش� Scene�� �����ߴ����� ���� ����.
	/// </summary>
	bool			m_isEntered		= false;

public:
	Scene(const std::string& name, const std::string& description);
	~Scene();

public:
	/// <summary>
	/// �ش� Scene�� �Ϸ� ��ȣ�� �����ɴϴ�.
	/// </summary>
	/// <returns></returns>
	const unsigned int GetBuildIndex() const;

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

/// <summary>
/// Scene ������.
/// </summary>
class SceneManager final : public Singleton<SceneManager> {
private:
	/// <summary>
	/// �����ϰ� �ִ� Scene��.
	/// </summary>
	std::vector<std::shared_ptr<Scene>>	m_scenes;

	/// <summary>
	/// ���� Scene��.
	/// </summary>
	std::stack<std::shared_ptr<Scene>>	m_previousScenes;

public:
	SceneManager();
	~SceneManager();

public:
	/// <summary>
	/// Scene�� �߰��մϴ�.
	/// </summary>
	/// <param name="scene">�߰��� Scene.</param>
	void AddScene(const std::shared_ptr<Scene>& scene);

	/// <summary>
	/// Scene�� �ε��մϴ�.
	/// </summary>
	/// <param name="sceneIndex">�ε��� Scene�� �Ϸ� ��ȣ.</param>
	void LoadScene(const unsigned int sceneIndex);

	/// <summary>
	/// Scene�� �ε��մϴ�.
	/// </summary>
	/// <param name="sceneName">�ε��� Scene�� �̸�.</param>
	void LoadScene(const std::string& sceneName);

	/// <summary>
	/// Scene�� ��ε��մϴ�.
	/// </summary>
	void UnloadScene();
};

