#pragma once

/// <summary>
/// ���� ���� ��ƿ��Ƽ.
/// </summary>
class QuestionGenerator final {
private:
	/// <summary>
	/// ���ܾ� ���� ���� ���.
	/// </summary>
	static const std::wstring DIRECTORY_PATH_WORD;

	/// <summary>
	/// ������ ���� ���� ���.
	/// </summary>
	static const std::wstring DIRECTORY_PATH_SENTENCE;

	/// <summary>
	/// �ұ�Ģ ���� ���� ���� ���.
	/// </summary>
	static const std::wstring DIRECTORY_PATH_IVERB;

public:
	/// <summary>
	/// ���ܾ� ������ �����մϴ�.
	/// </summary>
	/// <returns>���ܾ� ����.</returns>
	static const std::shared_ptr<WordQuestion> GenerateWordQuestion();
	static const std::vector<std::shared_ptr<WordQuestion>> GenerateWordQuestions();
};

