#pragma once

template <typename T>
class Singletone
{
protected:
	Singletone() {};
	virtual ~Singletone() {};

public:
	inline static T* GetInstance()
	{
		if (m_pInstance == NULL)
		{
			m_pInstance = new T;
		}
		return m_pInstance;
	}
	inline static void ReleaseInstance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = NULL;
		}
	}

private:
	static T* m_pInstance;
};

template <typename T> T* Singletone<T>::m_pInstance = NULL;