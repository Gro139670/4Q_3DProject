#include "pch.h"
#include "AnimationResource.h"

namespace Engine
{
	AnimationResource::AnimationResource()
	{
		m_ResourceType = ResourceType::Animation;
	}

	AnimationResource::~AnimationResource()
	{
	}

	void AnimationResource::Create(string _path)
	{
		Assimp::Importer importer;

		importer.SetPropertyBool(AI_CONFIG_IMPORT_FBX_PRESERVE_PIVOTS, 0);	// $assimp_fbx$ ��� ��������
		unsigned int importFlags = aiProcess_ConvertToLeftHanded;	// �޼� ��ǥ��� ��ȯ
		const aiScene* scene = importer.ReadFile(_path, importFlags);

		if (scene->HasAnimations())
		{

		}
	}
}
