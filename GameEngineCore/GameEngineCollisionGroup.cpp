#include "PreCompile.h"
#include "GameEngineCollisionGroup.h"
#include "GameEngineCollision.h"

GameEngineCollisionGroup::GameEngineCollisionGroup() 
{
}

GameEngineCollisionGroup::~GameEngineCollisionGroup() 
{
}



void GameEngineCollisionGroup::AllReleaseCheck()
{
	std::list<std::shared_ptr<class GameEngineCollision>>::iterator StartIter = Collisions.begin();
	std::list<std::shared_ptr<class GameEngineCollision>>::iterator EndIter = Collisions.end();

	for ( ; StartIter != EndIter; )
	{
		if (false == (*StartIter)->IsDeath())
		{
			++StartIter;
			continue;
		}

		StartIter = Collisions.erase(StartIter);
	}
}



bool GameEngineCollisionGroup::Collision(std::shared_ptr<GameEngineCollision> _Collision)
{
	for (std::shared_ptr<class GameEngineCollision> Collsion : Collisions)
	{
		if (Collsion == _Collision)
		{
			continue;
		}

		if (true == GameEngineTransform::Collision({ _Collision->Transform.ColData , Collsion->Transform.ColData, _Collision->GetCollisionType(), Collsion->GetCollisionType() }))
		{
			return true;
		}
	}

	return false;
}

bool GameEngineCollisionGroup::Collision(std::shared_ptr<GameEngineCollision> _Collision, const float4& _NextPos)
{
	CollisionData Data = _Collision->Transform.ColData;

	Data.OBB.Center.x += _NextPos.X;
	Data.OBB.Center.y += _NextPos.Y;
	Data.OBB.Center.z += _NextPos.Z;

	for (std::shared_ptr<class GameEngineCollision> Collsion : Collisions)
	{
		if (Collsion == _Collision)
		{
			continue;
		}

		if (true == GameEngineTransform::Collision({ Data , Collsion->Transform.ColData, _Collision->GetCollisionType(), Collsion->GetCollisionType() }))
		{
			return true;
		}
	}

	return false;
}

bool GameEngineCollisionGroup::Collision(std::shared_ptr<GameEngineCollision> _Collision, std::function<void(std::vector<std::shared_ptr<GameEngineCollision>>& _Collisions)> _Function)
{
	// static 지역변수로 만들면
	// std::list Nodes delete를 한다.
	// 쓰레드나 이런것에서 위험하지만
	static std::vector<std::shared_ptr<GameEngineCollision>> ResultCollision;
	ResultCollision.clear();

	for (std::shared_ptr<class GameEngineCollision> Collsion : Collisions)
	{
		if (Collsion == _Collision)
		{
			continue;
		}

		if (true == GameEngineTransform::Collision({ _Collision->Transform.ColData , Collsion->Transform.ColData, _Collision->GetCollisionType(), Collsion->GetCollisionType() }))
		{
			ResultCollision.push_back(Collsion);
		}
	}

	if (0 != ResultCollision.size())
	{
		_Function(ResultCollision);
	}

	return false;

}


bool GameEngineCollisionGroup::Collision(std::shared_ptr<GameEngineCollision> _Collision, const float4& _NextPos, std::function<void(std::vector<std::shared_ptr<GameEngineCollision>>& _Collisions)> _Function)
{
	static std::vector<std::shared_ptr<GameEngineCollision>> ResultCollision;
	ResultCollision.clear();

	CollisionData Data = _Collision->Transform.ColData;

	Data.OBB.Center.x += _NextPos.X;
	Data.OBB.Center.y += _NextPos.Y;
	Data.OBB.Center.z += _NextPos.Z;

	for (std::shared_ptr<class GameEngineCollision> Collsion : Collisions)
	{
		if (Collsion == _Collision)
		{
			continue;
		}

		if (true == GameEngineTransform::Collision({ Data , Collsion->Transform.ColData, _Collision->GetCollisionType(), Collsion->GetCollisionType() }))
		{
			ResultCollision.push_back(Collsion);
		}
	}

	if (0 != ResultCollision.size())
	{
		_Function(ResultCollision);
	}

	return false;
}


bool GameEngineCollisionGroup::CollisionEvent(std::shared_ptr<GameEngineCollision> _Collision, const EventParameter& _Event)
{
	static std::vector<std::shared_ptr<GameEngineCollision>> ResultCollision;
	ResultCollision.clear();

	for (std::shared_ptr<class GameEngineCollision> Collsion : Collisions)
	{
		if (Collsion == _Collision)
		{
			continue;
		}

		if (true == GameEngineTransform::Collision({ _Collision->Transform.ColData , Collsion->Transform.ColData, _Collision->GetCollisionType(), Collsion->GetCollisionType() }))
		{
			ResultCollision.push_back(Collsion);
			continue;
		}

		// 애는 충돌을 나랑 안했네.
		if (true == _Collision->Others.contains(Collsion))
		{
			if (_Event.Exit)
			{
				_Event.Exit(_Collision.get(), Collsion.get());
			}

			_Collision->Others.erase(Collsion);
		}
	}

	if (0 != ResultCollision.size())
	{
		// ResultCollision 나랑 충돌한 애들.
		
		for (size_t i = 0; i < ResultCollision.size(); i++)
		{
			std::shared_ptr<GameEngineCollision> Other = ResultCollision[i];
			if (false == _Collision->Others.contains(Other))
			{
				if (_Event.Enter)
				{
					_Event.Enter(_Collision.get(), Other.get());
				}

				_Collision->Others.insert(Other);
			}
			else 
			{
				if (_Event.Stay)
				{
					_Event.Stay(_Collision.get(), Other.get());
				}
			}
		}
	}

	return false;
}

void GameEngineCollisionGroup::PushCollision(std::shared_ptr<GameEngineCollision> _Collision)
{
	if (nullptr == _Collision)
	{
		MsgBoxAssert("존재하지 않는 콜리전을 사용하려고 했습니다.");
		return;
	}

	Collisions.push_back(_Collision);
}
