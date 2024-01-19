#pragma once
#include "RenderComponent.h"

namespace Engine
{
    // Ŭ���� ����
    class StaticMeshSceneResource;
    class StaticMesh;
    class Material;
    class Shader;
    class StaticMeshInstance;

    // ���̷�Ż�޽� ������Ʈ ���� ����ü
    struct StaticMeshComponentInfo
    {
        RenderComponentInfo m_RenderComponentInfo;
        string m_FilePath;
    };

    // ����ƽ �޽� ������Ʈ Ŭ����
    class StaticMeshComponent : public RenderComponent
    {
    public:
        StaticMeshComponent();
        virtual ~StaticMeshComponent();

    public:
        void Setting(StaticMeshComponentInfo _info);

    public:
        virtual void Init() override;
        virtual void Update() override;
        virtual void Render() override;

    private:
        string m_FilePath;

        shared_ptr<StaticMeshSceneResource> m_pStaticMesheScene;
        shared_ptr<Shader> m_pShader;

        vector<shared_ptr<StaticMeshInstance>> m_pStaticMeshInstanceVec;
    };
}