#include "Header.h"

WordQuestion::WordQuestion(const std::string& english, const std::vector<std::string>& korean) : Question(), m_english(english), m_korean(korean) {
}

const std::string WordQuestion::GetEnglish() const {
	return this->m_english;
}

const std::vector<std::string> WordQuestion::GetKorean() const {
	return this->m_korean;
}
