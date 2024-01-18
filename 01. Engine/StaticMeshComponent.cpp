#include "pch.h"
#include "StaticMeshComponent.h"

#include "ResourceManager.h"
#include "StaticMeshResource.h"
#include "Shader.h"

namespace Engine
{
	StaticMeshComponent::StaticMeshComponent()
	{
	}
	StaticMeshComponent::~StaticMeshComponent()
	{
	}
	void StaticMeshComponent::Setting(StaticMeshComponentInfo _info)
	{
		__super::Setting(_info.m_RenderComponentInfo);

		m_FilePath = _info.m_FilePath;
	}

	void StaticMeshComponent::Init()
	{
		__super::Init();

		// ���ҽ��Ŵ������� ���ҽ��� ã��
		m_pStaticMeshes = RESOURCE->Find<StaticMeshSceneResource>(m_FilePath);
		m_pShader = RESOURCE->Find<Shader>("StaticMeshShader");
	}

	void StaticMeshComponent::Update()
	{
		__super::Update();


	}

	void StaticMeshComponent::Render()
	{
		__super::Render();

	}
}

