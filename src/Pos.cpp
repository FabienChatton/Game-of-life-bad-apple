#include "Pos.hpp"

Pos::Pos(int x_, int y_): x(x_), y(y_)
{
	
}

long int Pos::ToLong() const
{
	long int l = (long) x << (sizeof(int) * 8);
	l |= y;
	return l;
}

long int Pos::ToLong(int x, int y)
{
	long int l = (long) x << (sizeof(int) * 8);
	l |= y;
	return l;
}

int Pos::GetX() const
{
	return x;
}

int Pos::GetY() const
{
	return y;
}

bool Pos::operator==(const Pos &other) const
{
	return x == other.x && y == other.y;
}

size_t PosHash::operator()(const long int &k) const
{
	return k;
}