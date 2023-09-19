#include "PreCompile.h"
#include "LevelTitle.h"
#include "TitleImage.h"




LevelTitle::LevelTitle()
{
}

LevelTitle::~LevelTitle()
{
}


void LevelTitle::Start()
{


	//타이틀 리소스 (애니메이션)가져오기
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("MegamanX5Resources");
		Dir.MoveChild("MegamanX5Resources");
		Dir.MoveChild("BackGround");
		Dir.MoveChild("TitleImage");

		GameEngineSprite::CreateFolder(Dir.GetStringPath());
	}

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	GetMainCamera()->Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);
	{
		std::shared_ptr<TitleImage> Object0 = CreateActor<TitleImage>(ContentsObjectType::Player);
	}

}

void LevelTitle::Update(float _Delta)
{
	//레벨바꾸기
	if (GameEngineInput::IsPress(VK_F12))
	{
		GameEngineCore::ChangeLevel("PlayLevel");
	}
	if (GameEngineInput::IsPress(VK_F2))
	{
		GameEngineCore::ChangeLevel("LevelCharacterSelect");
	}
	/*if (GameEngineInput::IsPress(VK_F3))
	{
		GameEngineCore::ChangeLevel("LevelJungle");
	}*/
}

void LevelTitle::LevelStart(GameEngineLevel* _PrevLevel)
{
}

void LevelTitle::LevelEnd(GameEngineLevel* _NextLevel)
{
}