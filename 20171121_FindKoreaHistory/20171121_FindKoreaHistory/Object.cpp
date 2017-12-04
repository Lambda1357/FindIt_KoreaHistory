#include "Object.h"

void Object::Init(char* imgAddr, SDL_Rect posit)
{
	ObjectImage = SDL_LoadBMP(imgAddr);
}

void Object::Destroy()
{
	SDL_FreeSurface(ObjectImage);
}
