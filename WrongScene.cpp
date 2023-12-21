#include "Header.h"

WrongScene::WrongScene() : Scene(SCENE_NAME_WRONG, SCENE_DESC_WRONG), m_menuSelector(5) {
	this->m_menuSelector.AddMenu(std::make_shared<Menu>("�����Ʈ", "Ʋ�ȴ� ���ܾ Ȯ���մϴ�.", nullptr));
	this->m_menuSelector.AddMenu(std::make_shared<Menu>("���ܾ� ����", "Ʋ�ȴ� �������� Ȯ���մϴ�.", nullptr));
	this->m_menuSelector.AddMenu(std::make_shared<Menu>("���� ����", "Ʋ�ȴ� �ұ�Ģ ���縦 Ȯ���մϴ�.", nullptr));
	this->m_menuSelector.AddMenu(std::make_shared<Menu>("�ڷ� ����", std::format("\'{:s}\'�� ���ư��ϴ�.", SCENE_DESC_REVIEW), []() { SceneManager::GetInstance().UnloadScene(); }));
}

void WrongScene::Routine() {
	Scene::Routine();
	this->m_menuSelector.Display();
	this->m_menuSelector.Select();
}

