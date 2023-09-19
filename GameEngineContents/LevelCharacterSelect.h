#pragma once
#include <GameEngineCore/GameEngineLevel.h>

class LevelCharacterSelect : public GameEngineLevel
{
public:
	//constructor destructor
	LevelCharacterSelect();
	~LevelCharacterSelect();

	//delete Function
	LevelCharacterSelect(const LevelCharacterSelect& _Other) = delete;
	LevelCharacterSelect(LevelCharacterSelect&& _Other) noexcept = delete;
	LevelCharacterSelect& operator=(const LevelCharacterSelect& _Other) = delete;
	LevelCharacterSelect&& operator=(LevelCharacterSelect&& _Other) noexcept = delete;

protected:
	void Start() override;

	void Update(float _Delta) override;

	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;

private:

};  