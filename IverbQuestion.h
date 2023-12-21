#pragma once

class IverbQuestion final : public Question {
private:
	/// <summary>
	/// ���� ���.
	/// </summary>
	std::vector<std::string>	m_english;

	/// <summary>
	/// �ѱ��� ���.
	/// </summary>
	std::string					m_korean;

public:
	IverbQuestion(const std::vector<std::string>& english, const std::string& korean);
	~IverbQuestion();

public:
	// Question��(��) ���� ��ӵ�
	void Marking(const std::string& answer) override;
};

