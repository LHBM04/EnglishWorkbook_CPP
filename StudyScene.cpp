#include "Header.h"

StudyScene::StudyScene() : Scene(SCENE_NAME_STUDY, SCENE_DESC_STUDY), m_menuSelector(5) {
	 this->m_menuSelector.AddMenu(std::make_shared<Menu>("�ܾ� ����", "����ص� �ܾ���� �����մϴ�.", nullptr));
	 this->m_menuSelector.AddMenu(std::make_shared<Menu>("���� ����", "����ص� ������� �����մϴ�.", nullptr));
	 this->m_menuSelector.AddMenu(std::make_shared<Menu>("�ұ�Ģ ���� ����", "����ص� �ұ�Ģ ������� �����մϴ�.", nullptr));
	 this->m_menuSelector.AddMenu(std::make_shared<Menu>("���� �볭��", "����ص� ��� �͵��� �������� �����˴ϴ�.", nullptr));
	 this->m_menuSelector.AddMenu(std::make_shared<Menu>("�ڷ� ����", std::format("{:s}�� ���ư��ϴ�.", SCENE_NAME_MAINMENU), []() { SceneManager::GetInstance().UnloadScene(); }));
}

StudyScene::~StudyScene()
{
}

void StudyScene::Routine() {
	Scene::Routine();
	this->m_menuSelector.Display();
	this->m_menuSelector.Select();
}
