#pragma once

/// <summary>
/// Scene.
/// </summary>
class Scene abstract {
private:
	/// <summary>
	/// 기본 빌드 인덱스.
	/// </summary>
	static unsigned int DEFAULT_SCENE_BUILD_INDEX;

private:
	/// <summary>
	/// 해당 Scene의 일련 번호.
	/// </summary>
	unsigned int	m_buildIndex	= DEFAULT_SCENE_BUILD_INDEX;

	/// <summary>
	/// 해당 Scene의 이름.
	/// </summary>
	std::string		m_name			= SCENE_NAME_DEFAULT;

	/// <summary>
	/// 해당 Scene의 설명.
	/// </summary>
	std::string		m_description	= SCENE_DESC_DEFAULT;

	/// <summary>
	/// 해당 Scene에 진입했는지에 대한 여부.
	/// </summary>
	bool			m_isEntered		= false;

public:
	Scene(const std::string& name, const std::string& description);
	~Scene();

public:
	/// <summary>
	/// 해당 Scene의 일련 번호를 가져옵니다.
	/// </summary>
	/// <returns></returns>
	const unsigned int GetBuildIndex() const;

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

/// <summary>
/// Scene 관리자.
/// </summary>
class SceneManager final : public Singleton<SceneManager> {
private:
	/// <summary>
	/// 관리하고 있는 Scene들.
	/// </summary>
	std::vector<std::shared_ptr<Scene>>	m_scenes;

	/// <summary>
	/// 이전 Scene들.
	/// </summary>
	std::stack<std::shared_ptr<Scene>>	m_previousScenes;

public:
	SceneManager();
	~SceneManager();

public:
	/// <summary>
	/// Scene을 추가합니다.
	/// </summary>
	/// <param name="scene">추가할 Scene.</param>
	void AddScene(const std::shared_ptr<Scene>& scene);

	/// <summary>
	/// Scene을 로드합니다.
	/// </summary>
	/// <param name="sceneIndex">로드할 Scene의 일련 번호.</param>
	void LoadScene(const unsigned int sceneIndex);

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

