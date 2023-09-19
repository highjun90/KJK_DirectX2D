#pragma once
#include <GameEngineCore/GameEngineLevel.h>


class LevelTitle : public GameEngineLevel
{
public:
	//constructor destructor
	LevelTitle();
	~LevelTitle();

	//delete Function
	LevelTitle(const LevelTitle& _Other) = delete;
	LevelTitle(LevelTitle&& _Other) noexcept = delete;
	LevelTitle& operator=(const LevelTitle& _Other) = delete;
	LevelTitle&& operator=(LevelTitle&& _Other) noexcept = delete;

protected:
	void Start() override;

	void Update(float _Delta) override;

	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;

private:
	
};  