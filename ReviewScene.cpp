#include "Header.h"

ReviewScene::ReviewScene() : Scene(SCENE_NAME_REVIEW, SCENE_DESC_REVIEW), m_menuSelector(5) {
	this->m_menuSelector.AddMenu(std::make_shared<Menu>("�����Ʈ", "Ʋ�ȴ� �������� Ȯ���մϴ�.", nullptr));
	this->m_menuSelector.AddMenu(std::make_shared<Menu>("���ܾ� ����", "Ʋ�ȴ� ���ܾ���� �����մϴ�.", nullptr));
	this->m_menuSelector.AddMenu(std::make_shared<Menu>("���� ����", "Ʋ�ȴ� ������� �����մϴ�.", nullptr));
	this->m_menuSelector.AddMenu(std::make_shared<Menu>("�ұ�Ģ ���� ����", "Ʋ�ȴ� �ұ�Ģ ������� �����մϴ�.", nullptr));
	this->m_menuSelector.AddMenu(std::make_shared<Menu>("�ڷ� ����", std::format("{:s}�� ���ư��ϴ�.", SCENE_NAME_MAINMENU), []() { SceneManager::GetInstance().UnloadScene(); }));
}

ReviewScene::~ReviewScene() {
}

void ReviewScene::Routine() {
	Scene::Routine();
	this->m_menuSelector.Display();
	this->m_menuSelector.Select();
}
