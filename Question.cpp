#include "Header.h"

Question::Question() : m_isRight(false) {
}

const bool Question::IsRight() const {
	return this->m_isRight;
}

void Question::Marking(const std::function<bool(const Question& question)> answer) {
	this->m_isRight = answer(*this);
}
