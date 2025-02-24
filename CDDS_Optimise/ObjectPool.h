#pragma once
#include "List.h"

template<typename T>
class ObjectPool
{
public:
	ObjectPool<T>(int size);
	~ObjectPool<T>();



	void Release(T* element);
	void Clear();
	T* Get();

	int CountActive();
	int CountInactive();
	int CountAll();

private:
	List<T*> m_enabled;
	List<T*> m_disabled;

};



template<typename T>
inline ObjectPool<T>::ObjectPool(int size)
{
	for (int i = 0; i < size; i++)
	{
		m_enabled.pushFront(new T());
	}
}

template<typename T>
inline ObjectPool<T>::~ObjectPool()
{
	m_disabled.destroy();
	m_disabled.destroy();
}

template<typename T>
inline void ObjectPool<T>::Release(T* element)
{
	m_enabled.pushFront(element);
	m_disabled.Remove(element);
	
}

template<typename T>
inline void ObjectPool<T>::Clear()
{
	m_disabled.destroy();
	m_disabled.destroy();
}

template<typename T>
inline T* ObjectPool<T>::Get()
{
	m_enabled.pushFront(m_disabled.first());
	m_disabled.popFront();
	return m_disabled.first();
}

template<typename T>
inline int ObjectPool<T>::CountActive()
{
	return m_enabled.getLength();
}

template<typename T>
inline int ObjectPool<T>::CountInactive()
{
	return m_disabled.getLength();
}

template<typename T>
inline int ObjectPool<T>::CountAll()
{
	return (CountActive() + CountInactive());
}
