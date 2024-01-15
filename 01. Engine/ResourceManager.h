#pragma once

#include "ResourceBase.h"

namespace Engine
{
	class StaticMesh;
	class SkeletalMesh;
	class Material;
	class Shader;
	class AnimationResource;
	class Texture;
	class Bone;

	class ResourceManager
	{
		SINGLETON(ResourceManager)
	public:
		template <typename T>
		shared_ptr<T> Load( const string& _path, const string& key);

		template <typename T>
		shared_ptr<T> Find(const string& _path, const string& key);

		template <typename T>
		ResourceType GetResourceType();

	private:
		using KeyObjMap = unordered_map<string, vector<shared_ptr<ResourceBase>>>;
		array<KeyObjMap, RESOURCE_TYPE_COUNT> m_ResourceMap;
	};

	template<typename T>
	inline shared_ptr<T> ResourceManager::Load(const string& _path, const string& _key)
	{
		// ���� �ش� Ŭ������ ���ҽ� ���̽� Ŭ������ ��� ���� �ʴ� Ŭ������ ����
		assert(!is_base_of_v<ResourceBase, T>);

		ResourceType resourceType = GetResourceType<T>();
		vector<shared_ptr<T>> resource = Find<T>(_path, _key);

		// ���ҽ��� ã���� ��ȯ
		if (resource != nullptr)
			return resource;

		// ���ҽ��� ã�� ���ϸ� �����ϰ� ����
		resource = make_shared<T>();
		resource->Create(_path);			// FBX Load �� �ؽ��� Load

		auto resourceIter = m_ResourceMap[static_cast<int>(resourceType)].find(_path);

		// �ش� ����� ���ҽ����� ���� ��쿡 �ش� ���Ϳ� Ǫ�� �� �ƴϸ� ���� ���� �Ŀ� �ʿ� ����ֱ�
		if (resourceIter != m_ResourceMap[static_cast<int>(resourceType)].end())
		{
			resourceIter->second.push_back(resource);
		}
		else
		{
			vector<shared_ptr<ResourceBase>> resourceVec;
			resourceVec.push_back(resource);
			m_ResourceMap[static_cast<int>(GetResourceType<T>())].insert(make_pair(_path, resourceVec));
		}

		return resource;
	}

	template<typename T>
	inline shared_ptr<T> ResourceManager::Find(const string& _path, const string& _key)
	{
		// ���� �ش� Ŭ������ ���ҽ� ���̽� Ŭ������ ��� ���� �ʴ� Ŭ������ ����
		assert(!is_base_of_v<ResourceBase, T>());

		ResourceType resourceType = GetResourceType<T>();

		// ���ҽ��� ã���� ��ȯ
		auto resourceIter = m_ResourceMap[static_cast<int>(resourceType)].find(_path);
		
		if (resourceIter != m_ResourceMap[static_cast<int>(resourceType)].end())
		{
			// 
			for (auto resource : resourceIter->second)
			{
				if (resource->GetName() == key)
					return resource;
			}
		}

		// ��ã���� nullptr
		return nullptr;
	}

	template<typename T>
	inline ResourceType ResourceManager::GetResourceType()
	{
		// constexpr�� ���̸� ������ �ܰ迡�� �ϼ������ش�.
		if (is_same_v<T, StaticMesh>)
			return ResourceType::StaticMesh;
		if (is_same_v<T, SkeletalMesh>)
			return ResourceType::SkeletalMesh;
		if (is_same_v<T, Material>)
			return ResourceType::Material;
		if (is_same_v<T, Shader>)
			return ResourceType::Shader;
		if (is_same_v<T, AnimationResource>)
			return ResourceType::Animation;
		if (is_same_v<T, Texture>)
			return ResourceType::Texture;
		if (is_same_v<T, Bone>)
			return ResourceType::Bone;

		assert(false);
		return ResourceType::None;
	}
}

#define RESOURCE Engine::ResourceManager::GetInstance()