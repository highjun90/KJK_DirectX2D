#pragma once

class Zero : public GameEngineActor
{
public:
	//constructor destructor
	Zero();
	~Zero();

	//delete Function
	Zero(const Zero& _Other) = delete;
	Zero(Zero&& _Other) noexcept = delete;
	Zero& operator=(const Zero& _Other) = delete;
	Zero&& operator=(Zero&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> MainSpriteRenderer;
};  