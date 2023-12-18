#include "Header.h"

StudyScene::StudyScene() : Scene(SCENE_NAME_STUDY, SCENE_DESC_STUDY), m_menuSelector(5) {
	 this->m_menuSelector.AddMenu(std::make_shared<Menu>("단어 공부", "등록해둔 단어들을 공부합니다.", nullptr));
	 this->m_menuSelector.AddMenu(std::make_shared<Menu>("문장 공부", "등록해둔 문장들을 공부합니다.", nullptr));
	 this->m_menuSelector.AddMenu(std::make_shared<Menu>("불규칙 동사 공부", "등록해둔 불규칙 동사들을 공부합니다.", nullptr));
	 this->m_menuSelector.AddMenu(std::make_shared<Menu>("문제 대난투", "등록해둔 모든 것들이 랜덤으로 출제됩니다.", nullptr));
	 this->m_menuSelector.AddMenu(std::make_shared<Menu>("뒤로 가기", std::format("{:s}로 돌아갑니다.", SCENE_NAME_MAINMENU), []() { SceneManager::GetInstance().UnloadScene(); }));
}

StudyScene::~StudyScene()
{
}

void StudyScene::Routine() {
	Scene::Routine();
	this->m_menuSelector.Display();
	this->m_menuSelector.Select();
}
