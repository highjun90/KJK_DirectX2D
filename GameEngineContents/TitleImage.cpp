#include "PreCompile.h"
#include "TitleImage.h"

TitleImage::TitleImage()
{
}

TitleImage::~TitleImage()
{
}

void TitleImage::Start()
{
	{


		MainSpriteRenderer = CreateComponent<GameEngineSpriteRenderer>(20);


		MainSpriteRenderer->CreateAnimation("TitleImageAnimation", "TitleImage", 0.6f, -1, -1, true);
		MainSpriteRenderer->ChangeAnimation("TitleImageAnimation");
		MainSpriteRenderer->SetSamplerState(SamplerOption::POINT);
		MainSpriteRenderer->Transform.SetLocalPosition({ 0.0f, 0.0f, 0.0f });
		MainSpriteRenderer->Transform.SetLocalScale({ 960.0f, 720.0f, 5.0f });
	}


	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, -500.0f });

}


void TitleImage::Update(float _Delta)
{
	
}