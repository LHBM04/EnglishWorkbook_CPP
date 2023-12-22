#include "Header.h"

ReviewScene::ReviewScene() : Scene(SCENE_NAME_MAINMENU, SCENE_DESC_MAINMENU), m_menuSelector(5) {
}

void ReviewScene::Routine() {
	Scene::Routine();
	this->m_menuSelector.Display();
	this->m_menuSelector.Select();
}
