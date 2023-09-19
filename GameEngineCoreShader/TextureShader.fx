#include "Transform.fx"

struct GameEngineVertex2D
{
    float4 POSITION : POSITION;
    float4 TEXCOORD : TEXCOORD;
};


struct PixelOutPut
{
    // 픽셀쉐이더에 보내느 ㄴ역
    float4 POSITION : SV_POSITION;
    float4 TEXCOORD : TEXCOORD;
};

cbuffer SpriteData : register(b1)
{
    float Pos2DX;
    float Pos2DY;
    float Scale2DX;
    float Scale2DY;
};


// 파일명과 함수명을 일치시키고 버텍스 쉐이더면 무조건 뒤에 _VS를 붙입니다.
// 의미있는 버텍스 쉐이더이다.
PixelOutPut TextureShader_VS(GameEngineVertex2D _Input) 
{
    // 쉐이더 문법 모두 0인 자료형으로 초기화 하는것
    PixelOutPut Result = (PixelOutPut)0;
    
    // 내가 원하는 값을 이안에 넣어줄수 있어야 한다.
    
    Result.POSITION = mul(_Input.POSITION, WorldViewProjectionMatrix);
    // Result.TEXCOORD = _Input.TEXCOORD;
    
    // 6의 버텍스가 들어올것이다.
    Result.TEXCOORD.x = (_Input.TEXCOORD.x * Scale2DX) + Pos2DX;
    Result.TEXCOORD.y = (_Input.TEXCOORD.y * Scale2DY) + Pos2DY;
    
    // 버텍스 들은 어떻게 되어있나?
    
    
    
    return Result;
}

// b버퍼 14
// t텍스처 
// s샘플러 
// 둘의 슬롯은 공유되지 않는다.

// 보통 샘플러와 텍스처는 1쌍으로 사용되기 때문에
// 샘플러는 텍스처의 색상을 가져올때 보간을 해주거나 특수한 공식등을 내부에서
// 사용해주는 용도가 있다.
Texture2D DiffuseTex : register(t0);
SamplerState Sampler : register(s0);

float4 TextureShader_PS(PixelOutPut _Input) : SV_Target0
{
   
    float4 Color = DiffuseTex.Sample(Sampler, _Input.TEXCOORD.xy);
    // 블랜드라는 작업을 해줘야 한다.
    
    if (0.0f >= Color.a)
    {
        clip(-1);
    }
    
    return Color;
}