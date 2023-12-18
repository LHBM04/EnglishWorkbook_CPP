#include "Header.h"


int main() {
	Start([]() { SceneManager::GetInstance().LoadScene(SCENE_NAME_MAINMENU); });
}