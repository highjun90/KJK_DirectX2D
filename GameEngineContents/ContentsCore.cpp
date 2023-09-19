//#include "PreCompile.h"
//#include "ContentsCore.h"
//
//#include <GameEngineCore/GameEngineSampler.h>
//#include <GameEngineCore/GameEngineSpriteRenderer.h>
//
//ContentsCore::ContentsCore()
//{
//}
//
//ContentsCore::~ContentsCore()
//{
//}
//
//void ContentsCore::Start()
//{
//
//
//}
//
//void ContentsCore::Update(float _Delta)
//{
//
//}
//
//void ContentsCore::Release()
//{
//
//}

#include "PreCompile.h"
#include "ContentsCore.h"
#include "LevelTitle.h"
#include "LevelcharacterSelect.h"
#include "LevelJungle.h"

ContentsCore::ContentsCore()
{
}

ContentsCore::~ContentsCore()
{
}

void ContentsCore::Start()
{
	GameEngineCore::CreateLevel<LevelTitle>("LevelTitle");
	GameEngineCore::CreateLevel<LevelCharacterSelect>("LevelCharacterSelect");
	GameEngineCore::CreateLevel<LevelJungle>("LevelJungle");
	GameEngineCore::ChangeLevel("LevelTitle");
}

void ContentsCore::Update(float _Delta)
{

}

void ContentsCore::Release()
{

}