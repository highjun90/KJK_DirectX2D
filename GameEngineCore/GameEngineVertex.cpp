#include "PreCompile.h"
#include "GameEngineVertex.h"


GameEngineInputLayOutInfo GameEngineVertex2D::VertexInfo;

class GameEngineVertex2DStart 
{
public:
	GameEngineVertex2DStart() 
	{
		GameEngineVertex2D::VertexInfo.AddInputLayOutDesc("POSITION", DXGI_FORMAT_R32G32B32A32_FLOAT);
		GameEngineVertex2D::VertexInfo.AddInputLayOutDesc("TEXCOORD", DXGI_FORMAT_R32G32B32A32_FLOAT);
	}
};

GameEngineVertex2DStart GameEngineVertex2DInit;