#pragma once
#include "ResourceBase.h"

namespace Engine
{
	// �ؽ��� Ÿ�� ������
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


	// �ؽ��� Ŭ����
    class Texture : public ResourceBase
    {
    public:
        Texture();
        virtual ~Texture();

	public:
		void Create(string _path) override;

	public:
		inline void SetTextureType(TextureType _type);
		inline TextureType GetTextureType();

	private:
		ComPtr<ID3D11ShaderResourceView> m_Texture;
		TextureType m_TextureType;
    };

	void Texture::SetTextureType(TextureType _type)
	{
		m_TextureType = _type;
	}
	TextureType Engine::Texture::GetTextureType()
	{
		return m_TextureType;
	}
}