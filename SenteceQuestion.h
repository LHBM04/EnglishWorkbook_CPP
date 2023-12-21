#pragma once

/// <summary>
/// 영문장 문제.
/// </summary>
class SenteceQuestion final : public Question {
private:
	/// <summary>
	/// 영어 답안지
	/// </summary>
	std::string m_english;

	/// <summary>
	/// 한국어 답안지
	/// </summary>
	std::string m_korean;

public:
	SenteceQuestion(const std::string& english, const std::string& korean);
	~SenteceQuestion();

public:
	// Question을(를) 통해 상속됨
	void Marking(const std::string& answer) override;
};

