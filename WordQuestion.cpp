#include "Header.h"

WordQuestion::WordQuestion(const std::string& english, const std::vector<std::string>& korean) : Question(), m_english(english), m_korean(korean) {
}

WordQuestion::~WordQuestion() {
}

void WordQuestion::Marking(const std::string& answer) {
	auto predicate	= [&answer](const std::string& string) { return string == answer; };
	auto result		= std::find_if(this->m_korean.begin(), this->m_korean.end(), predicate);

	this->m_isRight = (result == this->m_korean.end());
}

const std::string WordQuestion::GetEnglish() const {
	return this->m_english;
}

const std::vector<std::string> WordQuestion::GetKorean() const {
	return this->m_korean;
}
