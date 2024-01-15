#pragma once
#include "ResourceBase.h"

namespace Engine
{
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
        void Create(string _path) override;

    private:
        unordered_map<string, Bone> m_Bones;
    };
}