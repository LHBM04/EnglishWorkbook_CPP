#include "Header.h"

static const std::string PROGRAM_NAME = "English Workbook";
static const std::string PROGRAM_VIRSION = "1.0";

int main() {
	//Console::WriteLine(std::format("{:s} Ver.{:s}", PROGRAM_NAME, PROGRAM_VIRSION));
	//system("pause");
	//SceneManager::GetInstance().LoadScene(0);
	
	for (const auto& iter : WorkbookManager::GetInstance().GetWordWorkbook()) {
		std::cout << iter->GetEnglish() << " " << iter->GetKorean().at(0) << std::endl;
	}
}