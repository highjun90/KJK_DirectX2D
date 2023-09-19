#include "PreCompile.h"
#include "GameEngineCollision.h"
#include "GameEngineActor.h"
#include "GameEngineLevel.h"
#include "GameEngineCollisionGroup.h"

GameEngineCollision::GameEngineCollision() 
{
}

GameEngineCollision::~GameEngineCollision() 
{
}

void GameEngineCollision::Start()
{
	GetActor()->GetLevel()->PushCollision(GetDynamic_Cast_This<GameEngineCollision>());
}

bool GameEngineCollision::Collision(int _Order)
{
	if (false == GetLevel()->Collisions.contains(_Order))
	{
		return false;
	}
	std::shared_ptr<GameEngineCollisionGroup> OtherGroup = GetLevel()->Collisions[_Order];
	return OtherGroup->Collision(GetDynamic_Cast_This<GameEngineCollision>());
}

bool GameEngineCollision::Collision(int _Order, const float4& _NextPos)
{
	if (false == GetLevel()->Collisions.contains(_Order))
	{
		return false;
	}
	std::shared_ptr<GameEngineCollisionGroup> OtherGroup = GetLevel()->Collisions[_Order];
	return OtherGroup->Collision(GetDynamic_Cast_This<GameEngineCollision>(), _NextPos);
}

bool GameEngineCollision::Collision(int _Order, std::function<void(std::vector<std::shared_ptr<GameEngineCollision>>& _Collisions)> _Collision)
{
	if (false == GetLevel()->Collisions.contains(_Order))
	{
		return false;
	}
	std::shared_ptr<GameEngineCollisionGroup> OtherGroup = GetLevel()->Collisions[_Order];
	return OtherGroup->Collision(GetDynamic_Cast_This<GameEngineCollision>(), _Collision);
}

bool GameEngineCollision::Collision(int _Order, const float4& _Next, std::function<void(std::vector<std::shared_ptr<GameEngineCollision>>& _Collisions)> _Collision)
{
	if (false == GetLevel()->Collisions.contains(_Order))
	{
		return false;
	}
	std::shared_ptr<GameEngineCollisionGroup> OtherGroup = GetLevel()->Collisions[_Order];
	return OtherGroup->Collision(GetDynamic_Cast_This<GameEngineCollision>(), _Next, _Collision);
}

bool GameEngineCollision::CollisionEvent(int _Order, const EventParameter& _Event)
{
	if (false == GetLevel()->Collisions.contains(_Order))
	{
		return false;
	}
	std::shared_ptr<GameEngineCollisionGroup> OtherGroup = GetLevel()->Collisions[_Order];

	std::set<std::shared_ptr<GameEngineCollision>>::iterator Start = Others.begin();
	std::set<std::shared_ptr<GameEngineCollision>>::iterator End = Others.end();

	for (; Start != End; )
	{
		std::shared_ptr<GameEngineCollision> OtherCol = *Start;

		// 여기서 터질것이다.
		if (false == OtherCol->IsDeath())
		{
			++Start;
			continue;
		}

		Start = Others.erase(Start);
	}


	return OtherGroup->CollisionEvent(GetDynamic_Cast_This<GameEngineCollision>(), _Event);
}

void GameEngineCollision::Release()
{
	// 내가 지금 사라질것인데. 예전에 나랑 충돌했던 충돌체들에게
	// 내가 죽으니 날 굳이 들고 있을 필요가 없다.
	//for (std::shared_ptr<GameEngineCollision> Collision : Others)
	//{
	//	Collision->Others.erase(GetDynamic_Cast_This<GameEngineCollision>());
	//}
}