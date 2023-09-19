#include "PreCompile.h"
#include "MapImageJungle.h"

MapImageJungle::MapImageJungle()
{
}

MapImageJungle::~MapImageJungle()
{
}

void MapImageJungle::Start()
{
	
	//타이틀이미지 컴포넌트
	//{

	{
	    //SpriteRenderer0 = CreateComponent<GameEngineSpriteRenderer>(20);

		//MainSpriteRenderer->SetSprite("PlayerSelectImage0.PNG");
	    //SpriteRenderer0 ->SetSprite("Jungle0.PNG");
		//MainSpriteRenderer->SetSprite("Testmap.PNG");
		//MainSpriteRenderer->CreateAnimation("TitleImageAnimation", "TitleImage", 0.6f, -1, -1, true);
		//MainSpriteRenderer->ChangeAnimation("TitleImageAnimation");
		//SpriteRenderer0->SetSamplerState(SamplerOption::POINT);
		//SpriteRenderer0->Transform.SetLocalPosition({ 0.0f, 0.0f, 0.0f });

		//SpriteRenderer0->SetImageScale({ 960.0f, 720.0f, 5.0f });
		//SpriteRenderer0->Transform.SetLocalScale({ 960.0f, 720.0f, 5.0f });
	}

	//float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	//Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, -500.0f });
}



void MapImageJungle::Update(float _Delta)
{

	//EventParameter Event;

	//Event.Enter = [](GameEngineCollision* Col)
	//{
	//	int a = 0;
	//};

	//Event.Stay = [](GameEngineCollision* Col)
	//{
	//	int a = 0;
	//};


	//Event.Exit = [](GameEngineCollision* Col)
	//{
	//	Col->GetActor()->Death();

	//	int a = 0;
	//};

	//Col->CollisionEvent(ContentsCollisionType::Monster, Event);

	//Col->Collision(ContentsCollisionType::Monster, {100.0f, 0.0f, 0.0f}, [](std::vector<std::shared_ptr<GameEngineCollision>>& _Collision)
	//	{
	//		for (size_t i = 0; i < _Collision.size(); i++)
	//		{
	//			_Collision[i]->GetActor()->Death();
	//		}
	//	});

	//if (xxxx 상황이 되면)
	//{
	//	MainSpriteRenderer->Death();
	//	MainSpriteRenderer = nullptr;
	//}

	// 충돌했냐 안했냐만 보면

	//std::list<std::shared_ptr<Monster>> MonsterList = 
	//	GetLevel()->GetObjectGroupConvert<Monster>(ContentsObjectType::Monster);

	//for (std::shared_ptr<Monster> MonsterPtr : MonsterList)
	//{
	//	// 랜더러로 하는 이유 => 액터로도 할수있는데
	//	// 보통 액터는 위치와 기준을 잡아주는 용도로 사용됩니다.
	//	// MainSpriteRenderer->Transform.Collision(MonsterPtr->Renderer->Transform);

	//	GameEngineTransform& Left = TestCollision->Transform;
	//	GameEngineTransform& Right = MonsterPtr->Renderer->Transform;
	//	Right.AddLocalRotation({ 0.0f, 0.0f, 360.0f * _Delta });

	//	// 콜리전 파라미터를 사용한 이유가. 
	//	if (GameEngineTransform::Collision({ Left , Right, ColType::OBBBOX2D }))
	//	{
	//		MonsterPtr->Death();
	//		int a = 0;
	//		// 충돌했다.
	//	}
	//}


	//float Speed = 100.0f;


	//if (GameEngineInput::IsPress('A'))
	//{
	//	Transform.AddLocalPosition(float4::LEFT * _Delta * Speed);
	//}

	//if (GameEngineInput::IsPress('D'))
	//{
	//	Transform.AddLocalPosition(float4::RIGHT * _Delta * Speed);
	//}

	//if (GameEngineInput::IsPress('W'))
	//{
	//	Transform.AddLocalPosition(float4::UP * _Delta * Speed);
	//}

	//if (GameEngineInput::IsPress('S'))
	//{
	//	Transform.AddLocalPosition(float4::DOWN * _Delta * Speed);
	//}

	//if (GameEngineInput::IsPress('Q'))
	//{
	//	Transform.AddLocalRotation({ 0.0f, 0.0f, 360.0f * _Delta });
	//}

	//if (GameEngineInput::IsPress('E'))
	//{
	//	Transform.AddLocalRotation({ 0.0f, 0.0f, -360.0f * _Delta });
	//}

	//GameEngineColor Color = PlayMap::MainMap->GetColor(Transform.GetWorldPosition(), GameEngineColor::RED);

	//if (GameEngineColor::RED != Color)
	//{
	//	GrivityForce.Y -= _Delta * 100.0f;
	//	Transform.AddLocalPosition(GrivityForce * _Delta);
	//}
	//else 
	//{
	//	GrivityForce = 0.0f;
	//}
	// 땅에 딱붙게하고 싶다면 while돌려서 올려주세요.


	// float4 Color = GetColor(Transform.GetWorldPosition());
}