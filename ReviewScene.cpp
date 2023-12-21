#include "Header.h"

ReviewScene::ReviewScene() : Scene(SCENE_NAME_REVIEW, SCENE_DESC_REVIEW), m_menuSelector(5) {
	this->m_menuSelector.AddMenu(std::make_shared<Menu>("오답노트", "틀렸던 문제들을 확인합니다.", []() { SceneManager::GetInstance().LoadScene(SCENE_NAME_WRONG); }));
	this->m_menuSelector.AddMenu(std::make_shared<Menu>("영단어 복습", "틀렸던 영단어들을 복습합니다.", nullptr));
	this->m_menuSelector.AddMenu(std::make_shared<Menu>("문장 복습", "틀렸던 문장들을 복습합니다.", nullptr));
	this->m_menuSelector.AddMenu(std::make_shared<Menu>("불규칙 동사 복습", "틀렸던 불규칙 동사들을 복습합니다.", nullptr));
	this->m_menuSelector.AddMenu(std::make_shared<Menu>("뒤로 가기", std::format("{:s}로 돌아갑니다.", SCENE_NAME_MAINMENU), []() { SceneManager::GetInstance().UnloadScene(); }));
}

void ReviewScene::Routine() {
	Scene::Routine();
	this->m_menuSelector.Display();
	this->m_menuSelector.Select();
}
