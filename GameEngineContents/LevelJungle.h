#pragma once
#include <GameEngineCore/GameEngineLevel.h>

struct CameraLimit
{
	float Right = 0;
	float Left = 0;
	float Up = 0;
	float Down = 0;
};



class LevelJungle : public GameEngineLevel
{
public:
	//constructor destructor
	LevelJungle();
	~LevelJungle();

	//delete Function
	LevelJungle(const LevelJungle& _Other) = delete;
	LevelJungle(LevelJungle&& _Other) noexcept = delete;
	LevelJungle& operator=(const LevelJungle& _Other) = delete;
	LevelJungle&& operator=(LevelJungle&& _Other) noexcept = delete;

	template <typename PlayerType>
	void CreatePlayer()
	{
		MainPlayer = CreateActor<PlayerType>();
		std::dynamic_pointer_cast<PlayerType>(MainPlayer);
	}

protected:
	void Start() override;

	void Update(float _Delta) override;

	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;

private:
	//std::shared_ptr<class PlayMap> MapJungle;
	std::shared_ptr<class GameEngineSpriteRenderer> MainSpriteRenderer;
	std::shared_ptr<GameEngineObject> MainPlayer;
	std::shared_ptr<GameEngineCamera> CurCamera;
	CameraLimit CurCameraLimit = { 0 };

};  