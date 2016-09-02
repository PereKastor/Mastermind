#ifndef PINOUCHE_H
#define PINOUCHE_H
#include <string>

class Pinouche
{
public:
	enum Couleurs
	{
		Blue = 0, Green = 1, Red = 2, Yellow = 3, White = 4, Orange = 5, Purple = 6
	};
	Pinouche(Couleurs c)
		: color_(c)
	{
	}
	std::string static couleurs_possibles()
	{
		return "Blue (B), Green (G), Red (R), Yellow (Y), White (W), Orange (O) and Purple (P)";
	};
private :
	Couleurs color_;
};

#endif // PINOUCHE_H