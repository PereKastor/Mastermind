#include "Mastermind.h";

Mastermind::Mastermind()
  : nbEssai_{}
{
	finalCombinaison_.generate_random_combi();
}

std::string Mastermind::essayer(Combinaison& combinaison)
{
	++nbEssai_;
	if(combinaison == finalCombinaison_)
	{
		game_win = true;
		combinaison.set_is_good(true);
		return "Congrats";
	}
	else
	{
		return combinaison.compare_combi(finalCombinaison_);
	}
}

std::string Mastermind::get_final_combinaison() const
{
	return finalCombinaison_.get_combi_to_display();
}

bool Mastermind::partie_perdue() const
{
	return nbEssai_ >= MAX_ESSAIS_SUCCES;
}

bool Mastermind::est_reussi(const Combinaison& combinaison)
{
	return combinaison.is_good();
}