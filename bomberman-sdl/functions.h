#pragma once

const float PI = 3.1415926535f;
const float Deg2Rad = PI / 180;
const float Rad2Deg = 180 / PI;

void LogSDLError(const std::string &msg);
void LogIMGError(const std::string &msg);

SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren);

void SetupRect(SDL_Rect*rect, int x, int y, int w, int h);

template<class T>
constexpr const T& clamp(const T& v, const T& lo, const T& hi)
{
	return v < lo ? lo : (hi < v ? hi : v);
}

float Random();

template<typename T>
float RandomRange(T min, T max)
{
	return min + (T)((max-min) * Random());
}