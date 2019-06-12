#include "pch.h"

#include "functions.h"

void LogSDLError(const std::string &msg)
{
	std::cout << msg << std::endl << " SDL error: " << SDL_GetError() << std::endl;
}

void LogIMGError(const std::string &msg)
{
	std::cout << msg << std::endl << " IMG error: " << IMG_GetError() << std::endl;
}

SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren)
{
	SDL_Texture *texture = nullptr;
	SDL_Surface *loadedImage = IMG_Load(file.c_str());

	if (loadedImage != nullptr)
	{
		texture = SDL_CreateTextureFromSurface(ren, loadedImage);
		SDL_FreeSurface(loadedImage);

		if (texture == nullptr)
			LogSDLError("CreateTextureFromSurface");
	}
	else LogIMGError("LoadBMP");

	return texture;
}

void SetupRect(SDL_Rect*rect, int x, int y, int w, int h)
{
	rect->x = x;
	rect->y = y;
	rect->w = w;
	rect->h = h;
}