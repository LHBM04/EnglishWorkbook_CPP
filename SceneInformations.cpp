#include "Header.h"

const std::string SCENE_NAME_MAINMENU{ "���� �޴�" };
const std::string SCENE_DESC_MAINMENU{ std::format("\'{:s}\'�� \'{:s}\'�� �ϳ��� ������ �� �־��.", SCENE_NAME_STUDY, SCENE_NAME_REVIEW) };

const std::string SCENE_NAME_STUDY{ "�����ϱ�" };
const std::string SCENE_DESC_STUDY{ std::format("\'���ܾ�\', \'������\', �Ǵ� \'�ұ�Ģ ����\'�� ������ �� �־��.") };

const std::string SCENE_NAME_STUDYWORD{ "���ܾ� ����" };
const std::string SCENE_DESC_STUDYWORD{ std::format("����� ���ܾ� {:d}�� ������ �� �־��.", WorkbookManager::GetInstance().GetWordWorkbook().size()) };

const std::string SCENE_NAME_STUDYSENTENCE{ "������ ����" };
const std::string SCENE_DESC_STUDYSENTENCE{ "" };

const std::string SCENE_NAME_STUDYIVERB{"�ұ�Ģ ���� ����"};
const std::string SCENE_DESC_STUDYIVERB;

const std::string SCENE_NAME_REVIEW{ "�����ϱ�" };
const std::string SCENE_DESC_REVIEW{ std::format("\'{:s}\'�� Ȯ���ϰų�, Ʋ�ȴ� �������� �ٽ� Ǯ� �� �־��.", SCENE_NAME_WRONGNOTE) };

const std::string SCENE_NAME_WRONGNOTE{ "�����Ʈ" };
const std::string SCENE_DESC_WRONGNOTE{ "Ʋ�ȴ� \'���ܾ�\', \'������\', \'�ұ�Ģ ����\'���� Ȯ���� �� �־��." };