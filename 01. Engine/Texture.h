#pragma once
#include "ResourceBase.h"

namespace Engine
{
	// 텍스쳐 타입 열거형
	enum class TextureType
	{
		DIFFUSE = 0,
		NORMAL,
		SPECULAR,
		OPACITY,
		EMISSIVE,
		METALNESS,
		ROUGHNESS,

		END
	};


	// 텍스쳐 클래스
    class Texture : public ResourceBase
    {
    public:
        Texture();
        virtual ~Texture();

	public:
		void LoadTexture(string _path);
		void LoadEmbeddedTexture(const aiTexture* _embeddedTexture);

	public:
		inline ComPtr< ID3D11ShaderResourceView> GetTexture();
		inline void SetTextureType(TextureType _type);
		inline TextureType GetTextureType();

	private:
		ComPtr<ID3D11ShaderResourceView> m_Texture;
		TextureType m_TextureType;
    };


	ComPtr< ID3D11ShaderResourceView> Texture::GetTexture()
	{
		return m_Texture;
	}
	void Texture::SetTextureType(TextureType _type)
	{
		m_TextureType = _type;
	}
	TextureType Engine::Texture::GetTextureType()
	{
		return m_TextureType;
	}
}