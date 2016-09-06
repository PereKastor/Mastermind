#ifndef MASTERMIND_H
#define MASTERMIND_H
#include "Combinaison.h"

class Mastermind
{
public:
	int static const MAX_ESSAIS_SUCCES = 10;
	Mastermind();
	bool partie_perdue() const;
	std::string essayer(const Combinaison& combinaison);
	bool static est_reussi(const Combinaison& combinaison);
private:
	int nbEssai_;
	Combinaison finalCombinaison_;
	bool game_win = false;
};

#endif // MASTERMIND_H