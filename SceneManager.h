#pragma once

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
	~SceneManager() = default;

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



