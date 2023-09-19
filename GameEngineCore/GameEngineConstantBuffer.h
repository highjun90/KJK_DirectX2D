#pragma once
#include "GameEngineDirectBuffer.h"
#include "GameEngineShader.h"

// 설명 :
class GameEngineConstantBuffer :
	public GameEngineResources<GameEngineConstantBuffer>, public GameEngineDirectBuffer
{
public:
	// constrcuter destructer
	GameEngineConstantBuffer();
	~GameEngineConstantBuffer();

	// delete Function
	GameEngineConstantBuffer(const GameEngineConstantBuffer& _Other) = delete;
	GameEngineConstantBuffer(GameEngineConstantBuffer&& _Other) noexcept = delete;
	GameEngineConstantBuffer& operator=(const GameEngineConstantBuffer& _Other) = delete;
	GameEngineConstantBuffer& operator=(GameEngineConstantBuffer&& _Other) noexcept = delete;

	static std::shared_ptr<GameEngineConstantBuffer> CreateAndFind(int _Byte, std::string_view _Name, ShaderType _Type = ShaderType::None, int Slot = 0)
	{
		if (ConstantBuffers.end() == ConstantBuffers.find(_Byte))
		{
			// 이 크기의 상수버퍼가 존재하지 않는다.
			ConstantBuffers[_Byte];
		}

		std::map<std::string, std::shared_ptr<GameEngineConstantBuffer>>& Buffers = ConstantBuffers[_Byte];

		std::string UpperName = GameEngineString::ToUpperReturn(_Name.data());

		if (Buffers.end() != Buffers.find(UpperName))
		{
			return ConstantBuffers[_Byte][UpperName];
		}

		std::shared_ptr<GameEngineConstantBuffer> Res = GameEngineResources::CreateRes();
		Res->SetName(UpperName);
		Res->Type = _Type;
		Res->Slot = Slot;
		ConstantBuffers[_Byte][UpperName] = Res;
		Res->ResCreate(_Byte);
		return Res;
	}

	template<typename DataType>
	void ChangeData(const DataType& _Data)
	{
		ChangeData(&_Data, sizeof(DataType));
	}

	// 1바이트 자료형
	void ChangeData(const void* _Data, UINT _Size);

	void Setting(UINT _Slot);

protected:

private:
	ShaderType Type = ShaderType::None;
	int Slot = 0;

	// 자료구조를 Resources랑 다르게 다르게 가지고 있어야 한다.
	//            500byte         transformdata
	static std::map<int, std::map<std::string, std::shared_ptr<GameEngineConstantBuffer>>> ConstantBuffers;

	void ResCreate(int _ByteSize);
};

