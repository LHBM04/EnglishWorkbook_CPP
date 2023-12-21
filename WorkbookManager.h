#pragma once

using WrongWordQuestion		= std::pair<WordQuestion, size_t>;
using WrongSentenceQuestion = std::pair<SentenceQuestion, size_t>;
using WrongIverbQuestion	= std::pair<IverbQuestion, size_t>;

/// <summary>
/// ������ ���� ��ƿ��Ƽ.
/// </summary>
class WorkbookManager final : public Singleton<WorkbookManager> {
private:
	/// <summary>
	/// ���ܾ� ������ ������ ���� ���.
	/// </summary>
	static const std::filesystem::path DIRECTORY_PATH_WORD;

	/// <summary>
	/// ������ ������ ������ ���� ���.
	/// </summary>
	static const std::filesystem::path DIRECTORY_PATH_SENTENCE;

	/// <summary>
	/// �ұ�Ģ ���� ������ ������ ���� ���.
	/// </summary>
	static const std::filesystem::path DIRECTORY_PATH_IVERB;

private:
	/// <summary>
	/// ���ܾ� ������.
	/// </summary>
	std::vector<std::shared_ptr<const WordQuestion>>		m_wordWorkBook;

	/// <summary>
	/// ������ ������.
	/// </summary>
	std::vector<std::shared_ptr<const SentenceQuestion>>	m_sentenceWorkbook;

	/// <summary>
	/// �ұ�Ģ ���� ������.
	/// </summary>
	std::vector<std::shared_ptr<const IverbQuestion>>		m_iverbWorkbook;

	/// <summary>
	/// Ʋ�� ���ܾ� ������.
	/// </summary>
	std::vector<WrongWordQuestion>			m_wrongWordWorkbook;

	/// <summary>
	/// Ʋ�� ������ ������.
	/// </summary>
	std::vector<WrongSentenceQuestion>		m_wrongSentenceWorkbook;

	/// <summary>
	/// Ʋ�� �ұ�Ģ ���� ������.
	/// </summary>
	std::vector<WrongIverbQuestion>			m_wrongIverbQuestion;

private:
	/// <summary>
	/// JSON ���� �б�� �ν��Ͻ�.
	/// </summary>
	std::ifstream	m_jsonReader;

	/// <summary>
	/// JSON ���� ĳ��.
	/// </summary>
	nlohmann::json	m_jsonCashe;

private:
	/// <summary>
	/// ���ܾ� �������� ����ϴ�.
	/// </summary>
	void CreateWordWorkbook();

	/// <summary>
	/// ������ �������� ����ϴ�.
	/// </summary>
	void CreateSentenceWorkbook();

	/// <summary>
	/// �ұ�Ģ ���� �������� ����ϴ�.
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

