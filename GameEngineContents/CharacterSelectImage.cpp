#include "PreCompile.h"
#include "CharacterSelectImage.h"

CharacterSelectImage::CharacterSelectImage()
{
}

CharacterSelectImage::~CharacterSelectImage()
{
}


void CharacterSelectImage::Start()
{
	{


		MainSpriteRenderer = CreateComponent<GameEngineSpriteRenderer>(20);


		MainSpriteRenderer->CreateAnimation("ZeroSelectAnimation", "ZeroSelect", 0.01f, -1, -1, true);
		MainSpriteRenderer->CreateAnimation("XSelectAnimation", "XSelect", 0.01f, -1, -1, true);

		MainSpriteRenderer->ChangeAnimation("ZeroSelectAnimation"); //제로 먼저 화면에 띄우기
		


		MainSpriteRenderer->SetSamplerState(SamplerOption::POINT);
		MainSpriteRenderer->Transform.SetLocalPosition({ 0.0f, 0.0f, 0.0f });
		MainSpriteRenderer->Transform.SetLocalScale({ 960.0f, 720.0f, 1.0f });
	}


	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, -500.0f });

}


void CharacterSelectImage::Update(float _Delta)
{
	if (SelectedPlayer == PlayerSelectState::Zero && true == GameEngineInput::IsPress(VK_LEFT))
	{
		MainSpriteRenderer->ChangeAnimation("XSelectAnimation");
		SelectedPlayer = PlayerSelectState::X;
	}
	else if (SelectedPlayer == PlayerSelectState::X && true == GameEngineInput::IsPress(VK_RIGHT))
	{
		MainSpriteRenderer->ChangeAnimation("ZeroSelectAnimation");
		SelectedPlayer = PlayerSelectState::Zero;
	}

}