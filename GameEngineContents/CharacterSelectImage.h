#pragma once

enum class PlayerSelectState
{
	X,
	Zero
};

class CharacterSelectImage : public GameEngineActor
{
public:
	//constructor destructor
	CharacterSelectImage();
	~CharacterSelectImage();

	//delete Function
	CharacterSelectImage(const CharacterSelectImage& _Other) = delete;
	CharacterSelectImage(CharacterSelectImage&& _Other) noexcept = delete;
	CharacterSelectImage& operator=(const CharacterSelectImage& _Other) = delete;
	CharacterSelectImage&& operator=(CharacterSelectImage&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> MainSpriteRenderer;
	PlayerSelectState SelectedPlayer = PlayerSelectState::Zero;
};  