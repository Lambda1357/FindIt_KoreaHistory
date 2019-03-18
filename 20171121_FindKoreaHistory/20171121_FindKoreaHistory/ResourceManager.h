#pragma once

#include "Singletone.h"
class CResourceManager : public Singletone<CResourceManager>
{
private:
	int _iMaxHp, _iHp;
	int _iMaxHint, _iHint;
public:
	void ResetSource()
	{
		_iHp = 3;
		_iHint = 3;
	}

	void SubHp()
	{
		if (_iHp >= 1)
		{
			_iHp -= 1;
		}
	}

	int GetHp()
	{
		return _iHp;
	}

	void SubHint()
	{
		if (_iHint >= 1)
		{
			_iHint -= 1;
		}
	}

	int GetHint()
	{
		return _iHint;
	}
public:
	CResourceManager();
	virtual ~CResourceManager();
};

#define RESOURCEMANAGER CResourceManager::GetInstance()

