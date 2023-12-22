#include "Header.h"

MainScene::MainScene() : Scene(SCENE_NAME_MAINMENU, SCENE_DESC_MAINMENU), m_menuSelector(MenuSelector(3)) {
}

void MainScene::Routine() {
	Scene::Routine();
	this->m_menuSelector.Display();
	this->m_menuSelector.Select();
}
