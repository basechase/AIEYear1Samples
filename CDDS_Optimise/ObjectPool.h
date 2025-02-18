#pragma once
#include "List.h"


template<typename T>
class ObjectPool
{
public:
	ObjectPool<T>();
	~ObjectPool<T>() = default;

	void Add(T& item, int index);
	void Enable(int index);
	void Disable(T& item);



	//active and inactive list 
	List<T*> m_enabled;
	List<T*> m_disabled;

};

template<typename T>
inline ObjectPool<T>::ObjectPool()
{
}

template<typename T>
inline ObjectPool<T>::~ObjectPool()
{
}

template<typename T>
inline void ObjectPool<T>::Add(T& item, int index)
{
	m_enabled.insert(&item, index);
}

template<typename T>
inline void ObjectPool<T>::Enable(int index)
{
	
	m_enabled.insert(m_disabled.popFront(), index);
}

template<typename T>
inline void ObjectPool<T>::Disable(T& item)
{
	m_disabled.pushBack(&item);
	m_enabled.remove(&item);
}
