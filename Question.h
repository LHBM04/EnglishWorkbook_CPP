#pragma once

class Question abstract {
protected: 
	bool m_isRight;

public:
	Question();
	~Question() = default;

public:
	const bool IsRight() const;
	void Marking(const std::function<bool(const Question& question)> answer);
};

