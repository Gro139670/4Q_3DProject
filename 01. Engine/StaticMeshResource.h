#pragma once
#include "ResourceBase.h"

namespace Engine
{
    // Ŭ���� ����
    class Material;


    // �⺻ ���ؽ� ����ü
    struct Vertex
    {
        Vector3 m_Position;
        Vector2 m_TexCoord;
        Vector3 m_Normal;
        Vector3 m_Tangent;
        Vector3 m_BiTangents;
    };


    // ���ؽ��� ���� ����ƽ �޽� Ŭ����
    class StaticMesh
    {
    public:
        StaticMesh();
        virtual ~StaticMesh();

    public:
        void Create(aiMesh* _aiMesh);

    private:
        void createBuffer();

    private:
        string m_Name;

        vector<Vertex> m_VertexVec;
        vector<UINT> m_IndexVec;

        ComPtr<ID3D11Buffer> m_pVertexBuffer = nullptr;
        ComPtr<ID3D11Buffer> m_pIndexBuffer = nullptr;
    };


    // ����ƽ �޽��� ������ ���� ���ҽ� Ŭ����
    class StaticMeshSceneResource : public ResourceBase
    {
    public:
        StaticMeshSceneResource();
        virtual ~StaticMeshSceneResource();

    public:
        void Create(const aiScene* _aiScene);

    private:
        vector<StaticMesh> m_StaticMeshVec;
        vector<shared_ptr<Material>> m_pMaterialVec;

        Vector3 m_AABBmin;
        Vector3 m_AABBmax;
        BoundingBox m_BoundingBox;
    };
}