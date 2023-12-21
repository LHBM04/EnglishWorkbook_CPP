#pragma once

/// <summary>
/// ������ ����.
/// </summary>
class SenteceQuestion final : public Question {
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
	SenteceQuestion(const std::string& english, const std::string& korean);
	~SenteceQuestion();

public:
	// Question��(��) ���� ��ӵ�
	void Marking(const std::string& answer) override;
};

