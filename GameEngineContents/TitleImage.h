#pragma once

class TitleImage : public GameEngineActor
{
public:
	//constructor destructor
	TitleImage();
	~TitleImage();

	//delete Function
	TitleImage(const TitleImage& _Other) = delete;
	TitleImage(TitleImage&& _Other) noexcept = delete;
	TitleImage& operator=(const TitleImage& _Other) = delete;
	TitleImage&& operator=(TitleImage&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> MainSpriteRenderer;
};  