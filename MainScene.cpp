#include "Header.h"

MainScene::MainScene() : Scene(SCENE_NAME_MAINMENU, SCENE_DESC_MAINMENU), m_menuSelector(MenuSelector(3)) {
	this->m_menuSelector.AddMenu(std::make_shared<Menu>("�����ϱ�", "����ص� �������� ������ �� �ֽ��ϴ�.", []() { SceneManager::GetInstance().LoadScene(SCENE_NAME_STUDY); }));
	this->m_menuSelector.AddMenu(std::make_shared<Menu>("�����ϱ�", "Ʋ�� �������� Ȯ���ϰ� ������ �� �ֽ��ϴ�.", []() { SceneManager::GetInstance().LoadScene(SCENE_NAME_REVIEW); }));
	this->m_menuSelector.AddMenu(std::make_shared<Menu>("�����ϱ�", "���� �� ���α׷��� �����մϴ�.", []() { SceneManager::GetInstance().UnloadScene(); }));
}

void MainScene::Routine() {
	Scene::Routine();
	this->m_menuSelector.Display();
	this->m_menuSelector.Select();
}
