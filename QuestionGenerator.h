#pragma once

/// <summary>
/// 문제 생성 유틸리티.
/// </summary>
class QuestionGenerator final {
private:
	/// <summary>
	/// 영단어 문제 폴더 경로.
	/// </summary>
	static const std::wstring DIRECTORY_PATH_WORD;

	/// <summary>
	/// 영문장 문제 폴더 경로.
	/// </summary>
	static const std::wstring DIRECTORY_PATH_SENTENCE;

	/// <summary>
	/// 불규칙 동사 문제 폴더 경로.
	/// </summary>
	static const std::wstring DIRECTORY_PATH_IVERB;

public:
	/// <summary>
	/// 영단어 문제를 생성합니다.
	/// </summary>
	/// <returns>영단어 문제.</returns>
	static const std::shared_ptr<WordQuestion> GenerateWordQuestion();
	static const std::vector<std::shared_ptr<WordQuestion>> GenerateWordQuestions();
};

