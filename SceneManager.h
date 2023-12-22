#pragma once

/// <summary>
/// Scene 관리자.
/// </summary>
class SceneManager final : public Singleton<SceneManager> {
private:
	/// <summary>
	/// 관리하고 있는 Scene들.
	/// </summary>
	std::map<std::string, std::shared_ptr<Scene>>	m_scenes;

	/// <summary>
	/// 이전 Scene들.
	/// </summary>
	std::stack<std::shared_ptr<Scene>>				m_previousScenes;

public:
	SceneManager();

	~SceneManager() = default;

public:
	/// <summary>
	/// Scene을 추가합니다.
	/// </summary>
	/// <param name="scene">추가할 Scene.</param>
	void AddScene(const std::string& name, const std::shared_ptr<Scene>& scene);

	/// <summary>
	/// Scene을 로드합니다.
	/// </summary>
	/// <param name="sceneName">로드할 Scene의 이름.</param>
	void LoadScene(const std::string& sceneName);

	/// <summary>
	/// Scene을 언로드합니다.
	/// </summary>
	void UnloadScene();
};



