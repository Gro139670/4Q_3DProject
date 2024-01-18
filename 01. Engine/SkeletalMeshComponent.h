#pragma once
#include "RenderComponent.h"

namespace Engine
{
	// Ŭ���� ����
	class Node;
	class SkeletalMeshSceneResource;
	class Shader;
	class SkeletalMeshInstance;

	// ���̷�Ż�޽� ������Ʈ ���� ����ü
	struct SkeletalMeshComponentInfo
	{
		RenderComponentInfo m_RenderComponentInfo;
		string m_FilePath;
	};

	// ���̷�Ż �޽� ������Ʈ Ŭ����
	class SkeletalMeshComponent : public RenderComponent
	{
	public:
		SkeletalMeshComponent();
		virtual ~SkeletalMeshComponent();

	public:
		void Setting(SkeletalMeshComponentInfo _info);

	public:
		virtual void Init() override;
		virtual void Update() override;
		virtual void Render() override;

	private:
		string m_FilePath;
		float m_CurrentTime = 0.f;

		shared_ptr<Node> m_pRootNode;
		vector<shared_ptr<Node>> m_pNodeVec;
		shared_ptr<SkeletalMeshSceneResource> m_pSkeletalMeshes;
		shared_ptr<Shader> m_pShader;

		vector<shared_ptr<SkeletalMeshInstance>> m_pSkeletalMeshInstanceVec;
	};
}