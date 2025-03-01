#pragma once
#include "List.h"
#include "Critter.h"
template<typename T>
class ObjectPool
{
public:
	typedef T(*CreateItemSignature)();
	ObjectPool<T>(int size, CreateItemSignature createItemFunction);
	~ObjectPool<T>() = default;
	
	void Disable(T& element);
	void Release(T& element);
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
inline ObjectPool<T>::ObjectPool(int size, CreateItemSignature createItemFunction)
{
	if (size == 0)
	{
		//initialize lists as empty
		m_disabled.pushFront(nullptr);
		m_enabled.pushFront(nullptr);
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			T* item = new T(createItemFunction()) ;  
			m_disabled.pushFront(item);            
		}
	}
}





template<typename T>
inline void ObjectPool<T>::Disable(T& element)
{
	
	

	m_enabled.popFront();
	m_disabled.pushFront(&element);
	
	
}

template<typename T>
inline void ObjectPool<T>::Release(T& element)
{
	
	
	
		m_enabled.remove(&element);
		
	

	// Add to disabled list
	m_disabled.pushBack(&element);
	

	
	
}

template<typename T>
inline void ObjectPool<T>::Clear()
{
	m_disabled.destroy();
	m_enabled.destroy();
}

template<typename T>
inline T* ObjectPool<T>::Get()
{
	if (m_disabled.getLength() == 0) 
		return nullptr; 

	T* obj = m_disabled.first();
	m_disabled.popFront();
	m_enabled.pushFront(obj);

	return obj;
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
	return CountActive() + CountInactive();
}
