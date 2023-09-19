#include "PreCompile.h"
#include "GameEngineCore.h"
#include "GameEngineDirectBuffer.h"

GameEngineDirectBuffer::GameEngineDirectBuffer() 
{
}

GameEngineDirectBuffer::~GameEngineDirectBuffer() 
{
	if (nullptr != Buffer)
	{
		Buffer->Release();
		Buffer = nullptr;
	}
}

