#include "Header.h"

MainScene::MainScene() : Scene(SCENE_NAME_MAINMENU, SCENE_DESC_MAINMENU), m_menuSelector(MenuSelector(3)) {
	this->m_menuSelector.AddMenu(std::make_shared<Menu>("공부하기", "등록해둔 문제들을 공부할 수 있습니다.", []() { SceneManager::GetInstance().LoadScene(SCENE_NAME_STUDY); }));
	this->m_menuSelector.AddMenu(std::make_shared<Menu>("복습하기", "틀린 문제들을 확인하고 복습할 수 있습니다.", []() { SceneManager::GetInstance().LoadScene(SCENE_NAME_REVIEW); }));
	this->m_menuSelector.AddMenu(std::make_shared<Menu>("종료하기", "저장 후 프로그램을 종료합니다.", []() { SceneManager::GetInstance().UnloadScene(); }));
}

void MainScene::Routine() {
	Scene::Routine();
	this->m_menuSelector.Display();
	this->m_menuSelector.Select();
}
