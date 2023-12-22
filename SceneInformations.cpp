#include "Header.h"

const std::string SCENE_NAME_MAINMENU{ "메인 메뉴" };
const std::string SCENE_DESC_MAINMENU{ std::format("\'{:s}\'와 \'{:s}\'중 하나를 선택할 수 있어요.", SCENE_NAME_STUDY, SCENE_NAME_REVIEW) };

const std::string SCENE_NAME_STUDY{ "공부하기" };
const std::string SCENE_DESC_STUDY{ std::format("\'영단어\', \'영문장\', 또는 \'불규칙 동사\'를 공부할 수 있어요.") };

const std::string SCENE_NAME_STUDYWORD{ "영단어 공부" };
const std::string SCENE_DESC_STUDYWORD{ std::format("저장된 영단어 {:d}를 공부할 수 있어요.", WorkbookManager::GetInstance().GetWordWorkbook().size()) };

const std::string SCENE_NAME_STUDYSENTENCE{ "영문장 공부" };
const std::string SCENE_DESC_STUDYSENTENCE{ "" };

const std::string SCENE_NAME_STUDYIVERB{"불규칙 동사 공부"};
const std::string SCENE_DESC_STUDYIVERB;

const std::string SCENE_NAME_REVIEW{ "복습하기" };
const std::string SCENE_DESC_REVIEW{ std::format("\'{:s}\'를 확인하거나, 틀렸던 문제들을 다시 풀어볼 수 있어요.", SCENE_NAME_WRONGNOTE) };

const std::string SCENE_NAME_WRONGNOTE{ "오답노트" };
const std::string SCENE_DESC_WRONGNOTE{ "틀렸던 \'영단어\', \'영문장\', \'불규칙 동사\'들을 확인할 수 있어요." };