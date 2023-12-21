#pragma once

#pragma warning(disable: 4996)  
#pragma warning(disable: 4244)
#pragma warning(disable: 26819)

#define GET_NAME(n) #n

// Standards
#include <algorithm>
#include <chrono>
#include <concepts>
#include <cstdio>
#include <deque>
#include <filesystem>
#include <format>
#include <fstream>
#include <functional>
#include <iostream>
#include <memory>
#include <nlohmann/json.hpp>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <thread>
#include <type_traits>
#include <vector>

#include "Singleton.h"
#include "Console.h"
#include "Menu.h"

#include "Question.h"
#include "WordQuestion.h"
#include "SenteceQuestion.h"
#include "IverbQuestion.h"
#include "WrongQuestion.h"
#include "WorkbookManager.h"

#include "SceneInformation.h"
#include "Scene.h"
#include "SceneManager.h"
#include "MainScene.h"
#include "StudyScene.h"
#include "ReviewScene.h"
