//#pragma once
//#include <GameEngineCore/GameEngineObject.h>
//#include <GameEngineCore/GameEngineCore.h>
//
//// 설명 :
//class ContentsCore : public GameEngineObject
//{
//public:
//	static std::string GetWindowTitle()
//	{
//		return "MegamanX5";
//	}
//
//	static float4 GetStartWindowSize()
//	{
//		return { 1280, 720 };
//	}
//
//	static float4 GetStartWindowPos()
//	{
//		return { 200, 200 };
//	}
//
//	// constrcuter destructer
//	ContentsCore();
//	~ContentsCore();
//
//	// delete Function
//	ContentsCore(const ContentsCore& _Other) = delete;
//	ContentsCore(ContentsCore&& _Other) noexcept = delete;
//	ContentsCore& operator=(const ContentsCore& _Other) = delete;
//	ContentsCore& operator=(ContentsCore&& _Other) noexcept = delete;
//
//protected:
//	void Start() override;
//	void Update(float _Delta) override;
//	void Release() override;
//
//
//private:
//
//};

#pragma once
#include <GameEngineCore/GameEngineObject.h>
#include <GameEngineCore/GameEngineCore.h>

// 설명 :
class ContentsCore : public GameEngineObject
{
public:
	static std::string GetWindowTitle()
	{
		return "Megaman X5";
	}

	static float4 GetStartWindowSize()
	{
		return { 960, 720 };
	}

	static float4 GetStartWindowPos()
	{
		return { 0, 0 };
	}

	// constrcuter destructer
	ContentsCore();
	~ContentsCore();

	// delete Function
	ContentsCore(const ContentsCore& _Other) = delete;
	ContentsCore(ContentsCore&& _Other) noexcept = delete;
	ContentsCore& operator=(const ContentsCore& _Other) = delete;
	ContentsCore& operator=(ContentsCore&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;
	void Release() override;


private:

};



