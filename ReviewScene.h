#pragma once

class ReviewScene final : public Scene {
private:
	MenuSelector m_menuSelector;

public:
	ReviewScene();

public:
	virtual void Routine() override;
};

