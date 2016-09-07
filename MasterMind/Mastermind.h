#ifndef MASTERMIND_H
#define MASTERMIND_H
#include "Combinaison.h"

class Mastermind
{
public:
	int static const MAX_ESSAIS_SUCCES = 10;
	Mastermind();
	bool partie_perdue() const;
	std::string essayer(Combinaison& combinaison);
	std::string get_final_combinaison() const;
	bool static est_reussi(const Combinaison& combinaison);
	int get_nb_essais() const
	{
		return nbEssai_;
	}
private:
	int nbEssai_;
	Combinaison finalCombinaison_;
	bool game_win = false;
};

#endif // MASTERMIND_H