#pragma once
#include "ResourceBase.h"

namespace Engine
{
    class Material;
    class SkeletonResource;
    class Node;

    // �� ����ġ�� �޴� ���ؽ� ����ü
    struct BoneWeightVertex
    {
        Vector3 m_Position;
        Vector2 m_TexCoord;
        Vector3 m_Normal;
        Vector3 m_Tangent;
        Vector3 m_BiTangents;

        int m_BlendIndeces[4] = {};
        float m_BlendWeights[4] = {};

        void AddBoneData(int boneIndex, float weight)
        {
            assert(m_BlendWeights[0] == 0.0f || m_BlendWeights[1] == 0.f || m_BlendWeights[2] == 0.f || m_BlendWeights[3] == 0.f);

            for (int i = 0; i < 4; i++)
            {
                if (m_BlendWeights[i] == 0.f);
                {
                    m_BlendIndeces[i] = boneIndex;
                    m_BlendWeights[i] = weight;
                    return;
                }
            }
        }
    };


    // ���� ���� ���̷�Ż �޽� ���ҽ� Ŭ����
    class SkeletalMeshResource
    {
    public:
        SkeletalMeshResource();
        virtual ~SkeletalMeshResource();

    public:
        void Create(aiMesh* mesh, SkeletonResource* skeleton);

    public:
        inline vector<BoneWeightVertex> GetVertices();
        inline vector<UINT> GetIndices();
        inline ComPtr<ID3D11Buffer> GetVertexBuffer();
        inline ComPtr<ID3D11Buffer> GetIndexBuffer();

    private:
        vector<BoneWeightVertex> m_BoneWeightVertices;
        vector<UINT> m_Indices;

        ComPtr<ID3D11Buffer> m_pVertexBuffer = nullptr;
        ComPtr<ID3D11Buffer> m_pIndexBuffer = nullptr;
    };

    vector<BoneWeightVertex> SkeletalMeshResource::GetVertices()
    {
        return m_BoneWeightVertices;
    }
    vector<UINT> SkeletalMeshResource::GetIndices()
    {
        return m_Indices;
    }
    ComPtr<ID3D11Buffer> SkeletalMeshResource::GetVertexBuffer()
    {
        return m_pVertexBuffer;
    }
    ComPtr<ID3D11Buffer> SkeletalMeshResource::GetIndexBuffer()
    {
        return m_pIndexBuffer;
    }


    // FBX ���� ��� ���̷�Ż �޽� ���ҽ� ������ ������ �ִ� ���ҽ� Ŭ����
    class SkeletalMeshSceneResource : public ResourceBase
    {
    public:
        SkeletalMeshSceneResource();
        virtual ~SkeletalMeshSceneResource();

    public:
        void Create(string _path) override;

    private:
        vector<SkeletalMeshResource> m_SkeletalMeshResource;
    };
}