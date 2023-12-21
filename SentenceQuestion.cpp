#include "Header.h"

SentenceQuestion::SentenceQuestion(const std::string& english, const std::string& korean) : Question(), m_english(english), m_korean(korean) {
}

const std::string& SentenceQuestion::GetEnglish() const {
	return this->m_english;
}

const std::string& SentenceQuestion::GetKorean() const {
	return this->m_korean;
}
