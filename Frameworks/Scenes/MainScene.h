#pragma once
#include "Console.h"
#include "Scene.h"
class MainScene : public Scene {
public:
	MainScene();

public:
	// Scene을(를) 통해 상속됨
	void Display() const override;
	void Update() const override;
};