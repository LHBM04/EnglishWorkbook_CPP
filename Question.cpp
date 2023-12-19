#include "Header.h"

Question::Question() : m_isRight(false) {
}

Question::~Question() {
}

const bool Question::IsRight() const {
	return this->m_isRight;
}
