#ifndef PINOUCHE_H
#define PINOUCHE_H
#include <string>

class Pinouche
{
public:
	int static const NB_COLORS = 7;
	enum Couleurs
	{
		Blue = 0, Green = 1, Red = 2, Yellow = 3, White = 4, Orange = 5, Purple = 6
	};
	void set_color(Couleurs c)
	{
		color_ = c;
	}
	Pinouche()
		: color_(static_cast<Couleurs>(0))
	{
	}
	Pinouche(Couleurs c)
		: color_(c)
	{
	}
	std::string static couleurs_possibles()
	{
		return "Blue (B), Green (G), Red (R), Yellow (Y), White (W), Orange (O) and Purple (P)";
	};
	int get_color() const
	{
		return color_;
	}
	Couleurs static stoc(char c)
	{
		switch (c)
		{
		case 'B':
			return Blue;
		case 'G':
			return Green;
		case 'R':
			return Red;
		case 'Y':
			return Yellow;
		case 'W':
			return White;
		case 'O':
			return Orange;
		case 'P':
			return Purple;
		default:
			return Blue;
		}
	}
private :
	Couleurs color_;
};

inline bool operator!=(Pinouche const& a, Pinouche const& b)
{
	return !(a.get_color() == b.get_color());
}

#endif // PINOUCHE_H
