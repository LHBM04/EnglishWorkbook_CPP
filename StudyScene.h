#pragma once

class StudyScene : public Scene {
private:
	MenuSelector m_menuSelector;

public:
	StudyScene();
	~StudyScene();

public:
	virtual void Routine() override;
};

