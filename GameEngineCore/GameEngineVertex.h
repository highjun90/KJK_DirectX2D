#pragma once
#include "GameEngineInputLayOut.h"
// Input LayOut이란 점 1개의 구조에요.

// 설명 : 애가 제일 잘알고 있어야 합니다.
class GameEngineVertex2D
{
public:
	static GameEngineInputLayOutInfo VertexInfo;

	// 내가 얼마든지 바꿀수 있다.
public:
	float4 POSITION;
	float4 TEXCOORD;
};

//struct Vertex
//{
//    float4 Pos0 : POSITION0;
//    float4 Pos1 : POSITION1;
//    float4 COLOR : COLOR;
//    float4 COLOR : TEXCOORD;
//};

class GameEngine3DVertex
{
public:
	static GameEngineInputLayOutInfo VertexInfo;

public:
	float4 POSITION;
	float4 TEXCOORD;
	float4 COLOR;
	float4 NORMAL;
	float4 BINORMAL;
	float4 TANGENT;
	float4 WEIGHT;
	int BLENDINDICES[4];
};