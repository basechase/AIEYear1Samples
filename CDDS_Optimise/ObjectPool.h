#pragma once
#include "List.h"


template<typename T>
class ObjectPool
{
public:
	ObjectPool<T>();

	void Add(T& item, int index);
	void Enable(int index);
	void Disabke(T& item);
	
	List <T*>& getEnable() { return m_enabled; }
	List <T*>& getDisable() { return m_disabled; }

private:
	//active and inactive list 
	List<T*> m_enabled;
	List<T*> m_disabled;

};

