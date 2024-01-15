#pragma once
#include "ResourceBase.h"

namespace Engine
{
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
    class StaticMeshResource 
    {
    public:
        StaticMeshResource();
        virtual ~StaticMeshResource();

    public:
        void Create(aiMesh* _mesh);

    private:
        vector<Vertex> m_Vertices;
        vector<UINT> m_Indices;

        ID3D11Buffer* m_pVertexBuffer = nullptr;
        ID3D11Buffer* m_pIndexBuffer = nullptr;
    };


    // ����ƽ �޽��� ������ ���� ���ҽ� Ŭ����
    class StaticMeshSceneResource : public ResourceBase
    {
    public:
        StaticMeshSceneResource();
        virtual ~StaticMeshSceneResource();

    public:
        void Create(string _path);

    private:
        vector<StaticMeshResource> m_StaticMeshResources;
        vector<Material> m_Materials;

        Vector3 m_AABBmin;
        Vector3 m_AABBmax;
    };
}