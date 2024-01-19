#include "pch.h"
#include "Helper.h"

#include "AnimationResource.h"
#include "SkeletonResource.h"
#include "Node.h"
#include "StaticMeshResource.h"

namespace Engine
{
	void NodeSetting(shared_ptr<AnimationResource> _animationResource, shared_ptr<SkeletonResource> _skeletonResource, vector<shared_ptr<Node>>& _nodeVec, shared_ptr<Node>& _rootNode)
	{
		// ��忡 �ִϸ��̼ǳ��, ��, �θ� ����
		for (auto currentNode : _nodeVec)
		{
			// �ִϸ��̼� �� �� ��忡 ����
			shared_ptr<AnimationNode> animationNode = _animationResource->FindAnimationNode(currentNode->GetNodaData().m_Name);
			shared_ptr<Bone> bone = _skeletonResource->FindBone(currentNode->GetNodaData().m_Name);

			if (animationNode != nullptr)
				currentNode->SetAnimationNode(animationNode);
			if (bone != nullptr)
				currentNode->SetBone(bone);

			// ��� �������� ����
			for (auto parentNode : _nodeVec)
			{
				if (currentNode->GetNodaData().m_ParentName.empty())
				{
					_rootNode = currentNode;
				}

				if (parentNode->GetNodaData().m_Name == currentNode->GetNodaData().m_ParentName)
				{
					currentNode->SetParent(parentNode);
					break;
				}
			}
		}
	}
	void NodeSetting(shared_ptr<AnimationResource> _animationResource, vector<shared_ptr<Node>>& _nodeVec, shared_ptr<Node>& _rootNode)
	{
		// ��忡 �ִϸ��̼ǳ��, ��, �θ� ����
		for (auto currentNode : _nodeVec)
		{
			// �ִϸ��̼� �� �� ��忡 ����
			if (_animationResource != nullptr)
			{
				shared_ptr<AnimationNode> animationNode = _animationResource->FindAnimationNode(currentNode->GetNodaData().m_Name);

				if (animationNode != nullptr)
					currentNode->SetAnimationNode(animationNode);
			}

			// ��� �������� ����
			for (auto parentNode : _nodeVec)
			{
				if (currentNode->GetNodaData().m_ParentName.empty())
				{
					_rootNode = currentNode;
				}

				if (parentNode->GetNodaData().m_Name == currentNode->GetNodaData().m_ParentName)
				{
					currentNode->SetParent(parentNode);
					break;
				}
			}
		}
	}
	void aiMatrixToMatrix(const aiMatrix4x4& _aiMatrix, Matrix& _matrix)
	{
		_matrix = DirectX::SimpleMath::Matrix(
			_aiMatrix.a1, _aiMatrix.b1, _aiMatrix.c1, _aiMatrix.d1,
			_aiMatrix.a2, _aiMatrix.b2, _aiMatrix.c2, _aiMatrix.d2,
			_aiMatrix.a3, _aiMatrix.b3, _aiMatrix.c3, _aiMatrix.d3,
			_aiMatrix.a4, _aiMatrix.b4, _aiMatrix.c4, _aiMatrix.d4
		);
	}
}
