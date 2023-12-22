#include "Header.h"

const std::filesystem::path WorkbookManager::DIRECTORY_PATH_WORD		= "StudyFile/Word";
const std::filesystem::path WorkbookManager::DIRECTORY_PATH_SENTENCE	= "StudyFile/Sentence";
const std::filesystem::path WorkbookManager::DIRECTORY_PATH_IVERB		= "StudyFile/Iverb";

WorkbookManager::WorkbookManager() {
	std::ifstream	jsonReader;	// 파일 입력 인스턴스.
	nlohmann::json	jsonCashe;	// JSON 파일 캐시.
	
	// 영단어
	for (const auto& jsonFile : std::filesystem::directory_iterator(this->DIRECTORY_PATH_WORD)) {
		jsonReader = std::ifstream(jsonFile.path());
		jsonReader >> jsonCashe;

		const auto newQuestion = std::make_shared<const WordQuestion>(jsonCashe.at("m_english").get<std::string>(),
																	  jsonCashe.at("m_korean").get<std::vector<std::string>>());

		this->m_wordWorkBook.push_back(newQuestion);
	}
	// 영문장
	for (const auto& jsonFile : std::filesystem::directory_iterator(this->DIRECTORY_PATH_SENTENCE)) {
		jsonReader = std::ifstream(jsonFile.path());
		jsonReader >> jsonCashe;

		const auto newQuestion = std::make_shared<const SentenceQuestion>(jsonCashe.at("m_english").get<std::string>(),
																		  jsonCashe.at("m_korean").get<std::string>());

		this->m_sentenceWorkbook.push_back(newQuestion);
	}
	// 불규칙 동사.
	for (const auto& jsonFile : std::filesystem::directory_iterator(this->DIRECTORY_PATH_IVERB)) {
		jsonReader = std::ifstream(jsonFile.path());
		jsonReader >> jsonCashe;

		const auto newQuestion = std::make_shared<const IverbQuestion>(jsonCashe.at("m_english").get<std::vector<std::string>>(),
																	   jsonCashe.at("m_korean").get<std::string>());

		this->m_iverbWorkbook.push_back(newQuestion);
	}
}

const std::vector<std::shared_ptr<const WordQuestion>>& WorkbookManager::GetWordWorkbook() const {
	return this->m_wordWorkBook;
}

const std::vector<std::shared_ptr<const SentenceQuestion>>& WorkbookManager::GetSentenceWorkbook() const {
	return this->m_sentenceWorkbook;
}

const std::vector<std::shared_ptr<const IverbQuestion>>& WorkbookManager::GetIverbWorkbook() const {
	return this->m_iverbWorkbook;
}

const std::vector<WrongWordQuestion>& WorkbookManager::GetWrongWordbook() const {
	return this->m_wrongWordWorkbook;
}

const std::vector<WrongSentenceQuestion>& WorkbookManager::GetWrongSentenceQuestion() const {
	return this->m_wrongSentenceWorkbook;
}

const std::vector<WrongIverbQuestion>& WorkbookManager::GetWrongIverbQuestion() const {
	return this->m_wrongIverbQuestion;
}
