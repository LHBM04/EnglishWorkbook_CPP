#include "Header.h"

const std::filesystem::path WorkbookManager::DIRECTORY_PATH_WORD		= "StudyFile/Word";
const std::filesystem::path WorkbookManager::DIRECTORY_PATH_SENTENCE	= "StudyFile/Sentence";
const std::filesystem::path WorkbookManager::DIRECTORY_PATH_IVERB		= "StudyFile/Iverb";

void WorkbookManager::CreateWordWorkbook() {
	for (const auto& jsonFile : std::filesystem::directory_iterator(this->DIRECTORY_PATH_WORD)) {
		this->m_jsonReader = std::ifstream(jsonFile.path());
		this->m_jsonReader >> this->m_jsonCashe;

		const auto newQuestion = std::make_shared<const WordQuestion>(this->m_jsonCashe.at("m_english").get<std::string>(),
																	  this->m_jsonCashe.at("m_korean").get<std::vector<std::string>>());

		this->m_wordWorkBook.push_back(newQuestion);
	}
}

void WorkbookManager::CreateSentenceWorkbook() {
	for (const auto& jsonFile : std::filesystem::directory_iterator(this->DIRECTORY_PATH_SENTENCE)) {
		this->m_jsonReader = std::ifstream(jsonFile.path());
		this->m_jsonReader >> this->m_jsonCashe;

		const auto newQuestion = std::make_shared<const SenteceQuestion>(this->m_jsonCashe.at("m_english").get<std::string>(),
																	     this->m_jsonCashe.at("m_korean").get<std::string>());

		this->m_sentenceWorkbook.push_back(newQuestion);
	}
}

void WorkbookManager::CreateIverbWorkbook() {
	for (const auto& jsonFile : std::filesystem::directory_iterator(this->DIRECTORY_PATH_IVERB)) {
		this->m_jsonReader = std::ifstream(jsonFile.path());
		this->m_jsonReader >> this->m_jsonCashe;

		const auto newQuestion = std::make_shared<const IverbQuestion>(this->m_jsonCashe.at("m_english").get<std::vector<std::string>>(),
																	   this->m_jsonCashe.at("m_korean").get<std::string>());

		this->m_iverbWorkbook.push_back(newQuestion);
	}
}

WorkbookManager::WorkbookManager() {
	// Workbook วาด็.
	CreateWordWorkbook();
	CreateSentenceWorkbook();
	CreateIverbWorkbook();
}

WorkbookManager::~WorkbookManager() {
}

const std::vector<std::shared_ptr<const WordQuestion>>& WorkbookManager::GetWordWorkbook() const {
	return this->m_wordWorkBook;
}
