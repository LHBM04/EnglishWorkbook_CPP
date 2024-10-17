#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "Console.h"
#include "MainScene.h"
#include "Scene.h"

#include "nlohmann/json.hpp"

typedef struct _Question {
public:
	std::string question;
	std::vector<std::string> answers;
} Question;

std::vector<Question> questions;

int main() {
	for (const auto& path : std::filesystem::directory_iterator("Resources/StudyFile/Word")) {
		std::ifstream inputStream{ path.path(), std::ios::in };
		if (not inputStream) {
			std::cerr << "Error!" << std::endl;
		}

		nlohmann::json	jsonFile{};
		inputStream >> jsonFile;

		Question question;
		for (const auto& iter : jsonFile["m_english"]) {
			question.question = iter.get<std::string>();
		}

		for (const auto& iter : jsonFile["m_korean"]) {
			question.answers.push_back(iter.get<std::string>());
		}

		questions.push_back(question);
	}
	
	for (const auto& iter : questions) {
		std::cout << iter.question << std::endl;
		std::cout << iter.answers[0] << std::endl;
		std::cout << "=====================================" << std::endl;
	}

}