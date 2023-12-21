#pragma once

/// <summary>
/// ������ ����.
/// </summary>
class SentenceQuestion final : public Question {
private:
	/// <summary>
	/// ���� �����
	/// </summary>
	std::string m_english;

	/// <summary>
	/// �ѱ��� �����
	/// </summary>
	std::string m_korean;

public:
	SentenceQuestion(const std::string& english, const std::string& korean);

public:
	const std::string& GetEnglish() const;
	const std::string& GetKorean() const;
 };

