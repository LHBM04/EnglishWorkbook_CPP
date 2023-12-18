#pragma once

static const std::string PROGRAM_NAME		= "English Workbook";
static const std::string PROGRAM_VIRSION	= "1.0";

static void Start(std::function<void()> callback) {
	Console::WriteLine(std::format("{:s} Ver.{:s}", PROGRAM_NAME, PROGRAM_VIRSION));
	Console::Write("EnterŰ�� ������ �������� �Ѿ�ϴ�...");
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (callback != nullptr) {
		callback();
	}
}

static void Quit() {
	SceneManager::GetInstance().UnloadScene();

	Console::Clear();
	Console::Write("���α׷��� �����մϴ�...");
}