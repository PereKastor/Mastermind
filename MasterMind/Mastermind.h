#ifndef MASTERMIND_H
#define MASTERMIND_H
#include "Combinaison.h"

class Mastermind
{
public:
	int static const MAX_ESSAIS_SUCCES = 4;
	Mastermind()
		: nbEssai_{}
	{
	}
private:
	int nbEssai_;
	Combinaison finalCombinaison_;
	Combinaison currentCombinaison_;
};

#endif // MASTERMIND_H