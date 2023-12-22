#pragma once

/// <summary>
/// 오답 노트 Scene
/// </summary>
class WrongNoteScene final : public Scene {
private:
	MenuSelector m_menuSelector;

public:
	WrongNoteScene();

public:
	virtual void Routine() override;
};

