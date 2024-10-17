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

int main() {
	std::ifstream file{ "Resources/StudyFile/Word/Question_Word_0.json", std::ios::in };
	if (not file) {
		std::cerr << "Error!" << std::endl;
	}

	nlohmann::json jsonFile;
	file >> jsonFile;

	Question question;
	for (const auto& iter : jsonFile["m_english"]) {
		question.question = iter.get<std::string>();
	}

	for (const auto& iter : jsonFile["m_korean"]) {
		question.answers.push_back(iter.get<std::string>());
	}

	std::cout << question.question << std::endl;
	std::cout << question.answers[0] << std::endl;
}