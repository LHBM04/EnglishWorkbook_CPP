#pragma once

/// <summary>
/// ���� ��Ʈ Scene
/// </summary>
class WrongNoteScene final : public Scene {
private:
	MenuSelector m_menuSelector;

public:
	WrongNoteScene();

public:
	virtual void Routine() override;
};

