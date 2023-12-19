#pragma once

class Question abstract {
protected: 
	bool m_isRight;

public:
	Question();
	~Question();
};

class QuestionGenerator final {
private:
	static const std::string FILE_DIRECTION;
};

class QuestionManager final {
private:

public:
	QuestionManager();
	~QuestionManager();

};

