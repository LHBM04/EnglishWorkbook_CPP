#pragma once

class WordQuestion final : public Question {
private:
	std::string					m_english;
	std::vector<std::string>	m_korean;

public:
	WordQuestion(const std::string& english, const std::vector<std::string>& korean);
	~WordQuestion();

public:	
	// Question��(��) ���� ��ӵ�
	virtual void Marking(const std::string& answer) override;
	
	const std::string GetEnglish() const;
	const std::vector<std::string> GetKorean() const;
};

