#pragma once
#include "GameEngineObject.h"
#include "GameEngineComponent.h"

// 설명 : GameEngineRenderer에게 Order는 랜더링 되는 순서를 의미합니다.
class GameEngineRenderer : public GameEngineComponent
{
	friend class GameEngineCamera;

public:
	// constrcuter destructer
	GameEngineRenderer();
	~GameEngineRenderer();

	// delete Function
	GameEngineRenderer(const GameEngineRenderer& _Other) = delete;
	GameEngineRenderer(GameEngineRenderer&& _Other) noexcept = delete;
	GameEngineRenderer& operator=(const GameEngineRenderer& _Other) = delete;
	GameEngineRenderer& operator=(GameEngineRenderer&& _Other) noexcept = delete;

	// 이걸 좀더 간다면
	// 카메라의 경우에는 
	// 이게 무조건 호출되야 합니다.
	// 하나의 랜더러를 여러개의 여러개의 카메라가 바라볼수 있다.
	// 내가 옴겨다니는 개념이 아니다.
	void SetViewCameraSelect(int _Order);

	// 모든 카메라에서 나를 빼고

	// 나를 봐주는 카메라를 바꾸겠다는 

	// 날바라보던 모든 카메라에서 나를 삭제하고
	// _Order 카메라로 이동하는거.
	// void SetChangeViewCameraAllClear(int _Order);

	void SetRenderOrder(int _Order);

	template <typename EnumType>
	void SetRenderOrder(EnumType _Order)
	{
		SetRenderOrder(static_cast<int>(_Order));
	}


	void SetCameraOrder(int _Order);

protected:
	void Start();
	virtual void Render(class GameEngineCamera* _Camera, float _Delta);

	void ResSetting();
	void Draw();

	// 분명히 자신의 랜더링 순서이다.

	GameEngineTransform* DataTransform;

private:
	class GameEngineCamera* Camera = nullptr;
	std::shared_ptr<class GameEngineInputLayOut> LayOut = nullptr;
	// int CameraOrder = 0;
};

