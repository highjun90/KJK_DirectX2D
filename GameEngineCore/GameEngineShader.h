#pragma once

enum class ShaderType
{
	None = 0, // 맨앞에 None를 넣어주는 사람은 에러를 체크하려는 사람들이 많이 쓴다.
	Vertex, // 필수
	Hull,
	Tessellator,
	Domain,
	Geometry,
	Pixel, // 필수
	Max, // max는 for문돌리거나 할때 필요하니까.
};

// 설명 :
class GameEngineShader
{
public:
	static bool AutoCompile(GameEngineFile& _File);

	// constrcuter destructer
	GameEngineShader();
	~GameEngineShader();

	// delete Function
	GameEngineShader(const GameEngineShader& _Other) = delete;
	GameEngineShader(GameEngineShader&& _Other) noexcept = delete;
	GameEngineShader& operator=(const GameEngineShader& _Other) = delete;
	GameEngineShader& operator=(GameEngineShader&& _Other) noexcept = delete;


	
protected:
	void CreateVersion(ShaderType _Type, UINT _VersionHigh, UINT _VersionLow);
	std::string Version;

	// 쉐이더의 바이너리 코드에 대한 포인터
	// 쉐이더 코드를 관리하기 위한 컴파일 포인터이다.
	ID3DBlob* BinaryCode = nullptr;

private:
	ShaderType ShaderTypeValue = ShaderType::None;
};

