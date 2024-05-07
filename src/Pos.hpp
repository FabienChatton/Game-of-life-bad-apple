#ifndef POS_HPP
#define POS_HPP

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

#endif // POS_HPP