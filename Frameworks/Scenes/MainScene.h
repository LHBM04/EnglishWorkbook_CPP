#pragma once
#include "Console.h"
#include "Scene.h"
class MainScene : public Scene {
public:
	MainScene();

public:
	// Scene��(��) ���� ��ӵ�
	void Display() const override;
	void Update() const override;
};