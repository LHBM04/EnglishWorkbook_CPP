#pragma once

/// <summary>
/// 영문장 문제.
/// </summary>
class SentenceQuestion final : public Question {
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
	SentenceQuestion(const std::string& english, const std::string& korean);

public:
	const std::string& GetEnglish() const;
	const std::string& GetKorean() const;
 };

