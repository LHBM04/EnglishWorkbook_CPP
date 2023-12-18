#pragma once

class ReviewScene final : public Scene {
private:
	MenuSelector m_menuSelector;

public:
	ReviewScene();
	~ReviewScene();

public:
	virtual void Routine() override;
};

