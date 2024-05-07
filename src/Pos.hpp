#ifndef POS_HPP
#define POS_HPP

#include <cstddef>

class Pos {
public:
	Pos(int x, int y);
	
	long int ToLong() const;
	static long int ToLong(int x, int y);
	int GetX() const;
	int GetY() const;
	
	bool operator==(const Pos &other) const;
	long int operator[](const Pos &p) const;

private:

	int x;
	int y;
	
};

struct PosHash {
	size_t operator()(const long int &k) const;
};

#endif // POS_HPP