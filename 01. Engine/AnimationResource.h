#pragma once
#include "ResourceBase.h"

namespace Engine
{
	class AnimationResource;

	// Ű������ ����ü
	struct KeyFrameData
	{
		float m_Time;
		Vector3 m_Scale;
		Quaternion m_Rotation;
		Vector3 m_Transtation;
	};


	// �ִϸ��̼� ��� ����ü
	struct AnimationNode
	{
		string m_Name;
		AnimationResource* m_Owner;
		vector<KeyFrameData> m_KeyFrame;
	};


	// �ִϸ��̼� ���ҽ� ����ü
	class AnimationResource : public ResourceBase
	{
	public:
		AnimationResource();
		virtual ~AnimationResource();

	public:
		void Create(aiAnimation* _srcAnimation);

	private:
		AnimationNode ParseAnimationNode(aiNodeAnim* srcNode);

	private:
		unsigned int m_FrameCount;
		float m_FrameRate;
		float m_Duration;
		unordered_map<string, AnimationNode> m_Nodes;
	};
}
