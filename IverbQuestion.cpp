#include "Header.h"

IverbQuestion::IverbQuestion(const std::vector<std::string>& english, const std::string& korean) : Question(), m_english(english), m_korean(korean) {
}

IverbQuestion::~IverbQuestion() {
}

void IverbQuestion::Marking(const std::string& answer) {
	this->m_isRight = this->m_korean == answer;
}
