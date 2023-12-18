#pragma once

class MainScene final : public Scene {
private:
	MenuSelector m_menuSelector;

public:
	MainScene();
	~MainScene();

public:
	virtual void Routine() override;
};

