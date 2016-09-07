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
	std::string compare_combi(const Combinaison& combi) const;
	bool is_good() const
	{
		return good_combi_;
	}
	void set_is_good(bool b)
	{
		good_combi_ = b;
	}
	std::string get_combi_to_display() const;
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