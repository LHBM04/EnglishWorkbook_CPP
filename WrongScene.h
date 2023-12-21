#pragma once

class WrongScene final : public Scene {
private:
	MenuSelector m_menuSelector;

public:
	WrongScene();

public:
	virtual void Routine() override;
};

