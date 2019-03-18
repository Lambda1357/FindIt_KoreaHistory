#pragma once
#include "Object.h"

class CHiddenObject :
	public Object
{
protected:
	bool bClicked;
	bool bChecked;
	bool bHinted;
	Object* m_Hint;
public:
	virtual void Update();
	void Render(SDL_Surface* scrSurface);

	SDL_Rect GetRect()
	{
		return scrPosit;
	}

	void SetClicked(bool _OHYEAH)
	{
		bClicked = _OHYEAH;
	}

	void SetChecked(bool _OHYEAH)
	{
		bChecked = _OHYEAH;
	}

	bool GetClicked()
	{
		return bClicked;
	}

	bool GetChecked()
	{
		return bChecked;
	}

	void SetHint(bool _Hint)
	{
		bHinted = _Hint;
	}

	bool GetHint()
	{
		return bHinted;
	}
public:
	CHiddenObject();
	virtual ~CHiddenObject();
};

