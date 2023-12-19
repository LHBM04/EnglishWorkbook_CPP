#pragma once

class Question abstract {
protected: 
	bool m_isRight;

public:
	Question();
	~Question();

public:
	const bool IsRight() const;
	virtual void Marking(const std::string& answer) = 0;
};

