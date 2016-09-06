#include "Mastermind.h";

Mastermind::Mastermind()
  : nbEssai_{}
{
	finalCombinaison_.generate_random_combi();
}

std::string Mastermind::essayer(const Combinaison& combinaison)
{
	if(combinaison == finalCombinaison_)
	{
		game_win = true;
		return "Congrats";
	}


	return "You fail";
}

bool Mastermind::partie_perdue() const
{
	return nbEssai_ >= MAX_ESSAIS_SUCCES;
}

bool Mastermind::est_reussi(const Combinaison& combinaison)
{
	return combinaison.is_good();
}