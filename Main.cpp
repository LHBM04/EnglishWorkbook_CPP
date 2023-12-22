#include "Header.h"

static const std::string PROGRAM_NAME = "English Workbook";
static const std::string PROGRAM_VIRSION = "1.0";

int main() {
	Console::WriteLine(std::format("{:s} Ver.{:s}", PROGRAM_NAME, PROGRAM_VIRSION));
	system("pause");
	SceneManager::GetInstance().LoadScene(SCENE_NAME_MAINMENU);
}