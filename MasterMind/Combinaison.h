#ifndef COMBINAISON_H
#define COMBINAISON_H
#include "Pinouche.h"

class Combinaison
{
public:
	Combinaison();
	bool is_same_combi(Combinaison const& a) const;
	void generate_random_combi();
	int static const NB_PINOUCHES = 4;
	void create_combinaison(Pinouche::Couleurs, Pinouche::Couleurs, Pinouche::Couleurs, Pinouche::Couleurs);
	bool is_good() const
	{
		return good_combi_;
	}

	friend std::istream& operator >> (std::istream&, Combinaison& F);
private:
	int static get_rand();
	bool good_combi_ = false;
	Pinouche combi_[ NB_PINOUCHES ];
	struct Init
	{
		Init();
	};
	static Init bidon;
};
bool operator==(Combinaison const& a, Combinaison const& b);

#endif // COMBINAISON_H