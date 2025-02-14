#pragma once
#include "List.h"


template<typename T>
class ObjectPool
{
public:
	ObjectPool(int size);
	~ObjectPool() = default;

	int CountActive();
	int CountInactive();
	void Enable();
	void Disable();

	void Release();

	void RemoveObject(T* value);

	List<T*> GetActive();
	List<T*> GetInactive();

private:
	//active and inactive list 
	List<T*> m_enabled;
	List<T*> m_disabled;

};

template<typename T>
inline ObjectPool<T>::ObjectPool(int size)
{
	
}

template<typename T>
inline int ObjectPool<T>::CountActive()
{
	
}



template<typename T>
inline void ObjectPool<T>::RemoveObject(T* value)
{

}

template<typename T>
inline List<T*> ObjectPool<T>::GetActive()
{
	return m_disabled;
}

template<typename T>
inline List<T*> ObjectPool<T>::GetInactive()
{
	return m_disabled;
}
