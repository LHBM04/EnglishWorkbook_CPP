#include "Header.h"

SenteceQuestion::SenteceQuestion(const std::string& english, const std::string& korean) : Question(), m_english(english), m_korean(korean) {
}

SenteceQuestion::~SenteceQuestion() {
}

void SenteceQuestion::Marking(const std::string& answer) {
	this->m_isRight = this->m_korean == answer;
}
