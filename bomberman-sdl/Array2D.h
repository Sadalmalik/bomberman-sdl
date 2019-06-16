#pragma once

#include "pch.h"

template<typename T>
class Array2D
{
protected:
	T*data_;
	int32_t _length;
	int32_t _xSize;
	int32_t _ySize;
public:
	Array2D(int32_t sx, int32_t sy);
	Array2D(int32_t sx, int32_t sy, T fill);
	~Array2D();

	void Resize(int32_t sx, int32_t sy);
	void Fill(T fill);

	bool ValidIndex(int32_t idx) const;
	bool ValidIndex(int32_t x, int32_t y) const;

	int32_t Length() const;
	int32_t XSize() const;
	int32_t YSize() const;

	T& Get(int32_t idx) const;
	T& Get(int32_t x, int32_t y) const;

	void Set(int32_t idx, T value);
	void Set(int32_t x, int32_t y, T value);
};

//================================================================================//

template<typename T>
Array2D<T>::Array2D(int32_t sx, int32_t sy) :
	_xSize(sx), _ySize(sy), _length(sx*sy)
{
	data_ = new T[_length];
}

template<typename T>
Array2D<T>::Array2D(int32_t sx, int32_t sy, T fill) :
	_xSize(sx), _ySize(sy), _length(sx*sy)
{
	data_ = new T[_length];
	for (int i = 0; i < _length; i++)
		data_[i] = fill;
}

template<typename T>
Array2D<T>::~Array2D()
{
	delete[] data_;
	data_ = nullptr;
}

template<typename T>
void Array2D<T>::Resize(int32_t sx, int32_t sy)
{
	_xSize = sx;
	_ySize = sy;
	_length = sx * sy;
	if (data_) delete[] data_;
	data_ = new T[_length];
}

template<typename T>
void Array2D<T>::Fill(T fill)
{
	for (int i = 0; i < _length; i++)
		data_[i] = fill;
}

//================================================================================//

template<typename T>
bool Array2D<T>::ValidIndex(int32_t idx) const
{
	return data_ && (0 <= idx && idx < _length);
}

template<typename T>
bool Array2D<T>::ValidIndex(int32_t x, int32_t y) const
{
	return data_ && (
		0 <= x && x < _xSize &&
		0 <= y && y < _ySize );
}

template<typename T>
int32_t Array2D<T>::Length() const
{
	return _length;
}

template<typename T>
int32_t Array2D<T>::XSize() const
{
	return _xSize;
}

template<typename T>
int32_t Array2D<T>::YSize() const
{
	return _ySize;
}

//================================================================================//

template<typename T>
T& Array2D<T>::Get(const int32_t idx) const
{
	if (ValidIndex(idx))
		return data_[idx];
	throw std::out_of_range("2D Array index out of range!");
}

template<typename T>
T& Array2D<T>::Get(int32_t x, int32_t y)	const
{
	if (ValidIndex(x, y))
		return Get(x + _xSize * y);
	throw std::out_of_range("2D Array x, y out of range!");
}

template<typename T>
void Array2D<T>::Set(const int32_t idx, T value)
{
	assert(ValidIndex(idx));
	data_[idx] = value;
}

template<typename T>
void Array2D<T>::Set(int32_t x, int32_t y, T value)
{
	assert(ValidIndex(x, y));
	data_[x + _xSize * y] = value;
}