#pragma once
#include <vector>
class MapImageJungle : public GameEngineActor
{
public:
	//constructor destructor
	MapImageJungle();
	~MapImageJungle();

	//delete Function
	MapImageJungle(const MapImageJungle& _Other) = delete;
	MapImageJungle(MapImageJungle&& _Other) noexcept = delete;
	MapImageJungle& operator=(const MapImageJungle& _Other) = delete;
	MapImageJungle&& operator=(MapImageJungle&& _Other) noexcept = delete;

	std::shared_ptr<class GameEngineSpriteRenderer> GetSpriteRenderer()
	{
		return SpriteRenderer0;;
	}


protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	const int MapImageCount = 37;
	//std::vector< std::shared_ptr<class GameEngineSpriteRenderer>> SpriteRenderers;
	std::shared_ptr<class GameEngineSpriteRenderer> SpriteRenderer0;

};  