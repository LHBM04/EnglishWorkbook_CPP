#pragma once

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
	std::vector< std::shared_ptr<const SenteceQuestion>>	m_sentenceWorkbook;

	/// <summary>
	/// �ұ�Ģ ���� ������.
	/// </summary>
	std::vector< std::shared_ptr<const IverbQuestion>>		m_iverbWorkbook;

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
	~WorkbookManager();

public:
	const std::vector<std::shared_ptr<const WordQuestion>>& GetWordWorkbook() const;
};

