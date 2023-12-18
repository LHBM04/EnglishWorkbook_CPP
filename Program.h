#pragma once

static const std::string PROGRAM_NAME		= "English Workbook";
static const std::string PROGRAM_VIRSION	= "1.0";

static void Start(std::function<void()> callback) {
	Console::WriteLine(std::format("{:s} Ver.{:s}", PROGRAM_NAME, PROGRAM_VIRSION));
	Console::Write("Enter키를 누르면 다음으로 넘어갑니다...");
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (callback != nullptr) {
		callback();
	}
}

static void Quit() {
	SceneManager::GetInstance().UnloadScene();

	Console::Clear();
	Console::Write("프로그램을 종료합니다...");
}