#pragma once
#include "ResourceBase.h"

namespace Engine
{
    struct BoneWeightVertex;

    // �� ����ü
    struct Bone
    {
        string m_NodeName;
        Matrix m_OffsetMatrix;
    };


    // �� ����ü ������ ���� ���̷��� Ŭ����
    class SkeletonResource : public ResourceBase
    {
    public:
        SkeletonResource();
        virtual ~SkeletonResource();

    public:
        void Create(aiMesh* _aiMesh, vector<BoneWeightVertex>* _vertices);

    private:
        vector<Bone> m_Bones;
    };
}