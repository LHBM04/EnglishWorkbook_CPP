#include "Header.h"

const std::string SCENE_NAME_WRONGNOTE{ "�����Ʈ" };
const std::string SCENE_DESC_WRONGNOTE{ "Ʋ�ȴ� \'���ܾ�\', \'������\', \'�ұ�Ģ ����\'���� Ȯ���� �� �־��." };

const std::string SCENE_NAME_REVIEW{ "�����ϱ�" };
const std::string SCENE_DESC_REVIEW{ std::format("\'{:s}\'�� Ȯ���ϰų�, Ʋ�ȴ� �������� �ٽ� Ǯ� �� �־��.", SCENE_NAME_WRONGNOTE) };

const std::string SCENE_NAME_STUDY{ "�����ϱ�" };
const std::string SCENE_DESC_STUDY{ "\'���ܾ�\', \'������\', �Ǵ� \'�ұ�Ģ ����\'�� ������ �� �־��." };

const std::string SCENE_NAME_MAINMENU{ "���� �޴�" };
const std::string SCENE_DESC_MAINMENU{ std::format("\'{:s}\'�� \'{:s}\'�� �ϳ��� ������ �� �־��.", SCENE_NAME_STUDY, SCENE_NAME_REVIEW) };