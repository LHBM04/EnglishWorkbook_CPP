#pragma once

class IverbQuestion final : public Question {
private:
	/// <summary>
	/// 영어 답안.
	/// </summary>
	std::vector<std::string>	m_english;

	/// <summary>
	/// 한국어 답안.
	/// </summary>
	std::string					m_korean;

public:
	IverbQuestion(const std::vector<std::string>& english, const std::string& korean);
	~IverbQuestion();

public:
	// Question을(를) 통해 상속됨
	void Marking(const std::string& answer) override;
};

