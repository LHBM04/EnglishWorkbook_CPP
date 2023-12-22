#include "Header.h"

StudyScene::StudyScene() : Scene(SCENE_NAME_MAINMENU, SCENE_DESC_MAINMENU), m_menuSelector(5) {
	
}

void StudyScene::Routine() {
	Scene::Routine();
	this->m_menuSelector.Display();
	this->m_menuSelector.Select();
}
