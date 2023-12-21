#include "Header.h"

WrongScene::WrongScene() : Scene(SCENE_NAME_WRONG, SCENE_DESC_WRONG), m_menuSelector(5) {
	this->m_menuSelector.AddMenu(std::make_shared<Menu>("오답노트", "틀렸던 영단어를 확인합니다.", nullptr));
	this->m_menuSelector.AddMenu(std::make_shared<Menu>("영단어 복습", "틀렸던 영문장을 확인합니다.", nullptr));
	this->m_menuSelector.AddMenu(std::make_shared<Menu>("문장 복습", "틀렸던 불규칙 동사를 확인합니다.", nullptr));
	this->m_menuSelector.AddMenu(std::make_shared<Menu>("뒤로 가기", std::format("\'{:s}\'로 돌아갑니다.", SCENE_DESC_REVIEW), []() { SceneManager::GetInstance().UnloadScene(); }));
}

void WrongScene::Routine() {
	Scene::Routine();
	this->m_menuSelector.Display();
	this->m_menuSelector.Select();
}

