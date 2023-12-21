#pragma once

using WrongWordQuestion		= std::pair<WordQuestion, size_t>;
using WrongSentenceQuestion = std::pair<SentenceQuestion, size_t>;
using WrongIverbQuestion	= std::pair<IverbQuestion, size_t>;

/// <summary>
/// 문제집 관리 유틸리티.
/// </summary>
class WorkbookManager final : public Singleton<WorkbookManager> {
private:
	/// <summary>
	/// 영단어 문제집 데이터 폴더 경로.
	/// </summary>
	static const std::filesystem::path DIRECTORY_PATH_WORD;

	/// <summary>
	/// 영문장 문제집 데이터 폴더 경로.
	/// </summary>
	static const std::filesystem::path DIRECTORY_PATH_SENTENCE;

	/// <summary>
	/// 불규칙 동사 문제집 데이터 폴더 경로.
	/// </summary>
	static const std::filesystem::path DIRECTORY_PATH_IVERB;

private:
	/// <summary>
	/// 영단어 문제집.
	/// </summary>
	std::vector<std::shared_ptr<const WordQuestion>>		m_wordWorkBook;

	/// <summary>
	/// 영문장 문제집.
	/// </summary>
	std::vector<std::shared_ptr<const SentenceQuestion>>	m_sentenceWorkbook;

	/// <summary>
	/// 불규칙 동사 문제집.
	/// </summary>
	std::vector<std::shared_ptr<const IverbQuestion>>		m_iverbWorkbook;

	/// <summary>
	/// 틀린 영단어 수집기.
	/// </summary>
	std::vector<WrongWordQuestion>			m_wrongWordWorkbook;

	/// <summary>
	/// 틀린 영문장 수집기.
	/// </summary>
	std::vector<WrongSentenceQuestion>		m_wrongSentenceWorkbook;

	/// <summary>
	/// 틀린 불규칙 동사 수집기.
	/// </summary>
	std::vector<WrongIverbQuestion>			m_wrongIverbQuestion;

private:
	/// <summary>
	/// JSON 파일 읽기용 인스턴스.
	/// </summary>
	std::ifstream	m_jsonReader;

	/// <summary>
	/// JSON 파일 캐시.
	/// </summary>
	nlohmann::json	m_jsonCashe;

private:
	/// <summary>
	/// 영단어 문제집을 만듭니다.
	/// </summary>
	void CreateWordWorkbook();

	/// <summary>
	/// 영문장 문제집을 만듭니다.
	/// </summary>
	void CreateSentenceWorkbook();

	/// <summary>
	/// 불규칙 동사 문제집을 만듭니다.
	/// </summary>
	void CreateIverbWorkbook();

public:
	WorkbookManager();
	~WorkbookManager() = delete;

public:
	const std::vector<std::shared_ptr<const WordQuestion>>& GetWordWorkbook() const;
	const std::vector<std::shared_ptr<const SentenceQuestion>>& GetSentenceWorkbook() const;
	const std::vector<std::shared_ptr<const IverbQuestion>>& GetIverbWorkbook() const;

	const std::vector<WrongWordQuestion>& GetWrongWordbook() const;
	const std::vector<WrongSentenceQuestion>& GetWrongSentenceQuestion() const;
	const std::vector<WrongIverbQuestion>& GetWrongIverbQuestion() const;
};

