#include "Combinaison.h"
#include <ctime>
#include <cstdlib>
#include "Pinouche.h"
#include <iostream>

Combinaison::Init Combinaison::bidon;

Combinaison::Init::Init()
{
	srand(static_cast<unsigned int>(time(nullptr)));
}

bool operator==(Combinaison const& a, Combinaison const& b)
{
	return a.is_same_combi(b);
}

Combinaison::Combinaison()
{
}

bool Combinaison::is_same_combi(Combinaison const& a) const
{
	return !(this->combi_[ 0 ] != a.combi_[ 0 ]
		|| this->combi_[ 1 ] != a.combi_[ 1 ]
		|| this->combi_[ 2 ] != a.combi_[ 2 ]
		|| this->combi_[ 3 ] != a.combi_[ 3 ]);
}

void Combinaison::create_combinaison(Pinouche::Couleurs one, Pinouche::Couleurs two, Pinouche::Couleurs three, Pinouche::Couleurs four)
{
	this->combi_[ 0 ].set_color(one);
	this->combi_[ 1 ].set_color(two);
	this->combi_[ 2 ].set_color(three);
	this->combi_[ 3 ].set_color(four);
}

void Combinaison::generate_random_combi()
{
	this->combi_[ 0 ].set_color(static_cast<Pinouche::Couleurs>(get_rand()));
	this->combi_[ 1 ].set_color(static_cast<Pinouche::Couleurs>(get_rand()));
	this->combi_[ 2 ].set_color(static_cast<Pinouche::Couleurs>(get_rand()));
	this->combi_[ 3 ].set_color(static_cast<Pinouche::Couleurs>(get_rand()));
}

int compare_index(const Pinouche& p, const Pinouche combi[ 4 ], int index)
{
	return p.get_color() == combi[ index ].get_color();
}

std::string Combinaison::compare_combi(const Combinaison& combi) const
{
	int gcp = 0;
	int gcnp = 0;
	int locked_index[ 4 ]{ 0 };
	for(int i = 0; i < NB_PINOUCHES; i++)
	{
		if(this->combi_[ i ].get_color() == combi.combi_[ i ].get_color())
		{
			gcp++;
			locked_index[ i ] = 1;
		}
	}

	for(int j = 0; j < NB_PINOUCHES; j++)
	{
		if(locked_index[ j ] != 1)
		{
			for(int k = 0; k < NB_PINOUCHES; k++)
			{
				if(locked_index[ k ] != 1)
				{
					if(this->combi_[ j ].get_color() == combi.combi_[ k ].get_color())
					{
						gcnp++;
					}
				}
			}
		}
	}
	return "Tu as actullement " + std::to_string(gcp) + " pinouches bien placees et de la bonne couleur,\n " + std::to_string(gcnp) + " pinouches de la bonne couleur mais pas au bon endroit";
}

std::string Combinaison::get_combi_to_display() const
{
	std::string result = Pinouche::ctos(static_cast<Pinouche::Couleurs>(combi_[0].get_color()));
	result += " " + Pinouche::ctos(static_cast<Pinouche::Couleurs>(combi_[ 1 ].get_color()));
	result += " " + Pinouche::ctos(static_cast<Pinouche::Couleurs>(combi_[ 2 ].get_color()));
	result += " " + Pinouche::ctos(static_cast<Pinouche::Couleurs>(combi_[ 3 ].get_color()));
	return result;
}


int Combinaison::get_rand()
{
	return rand() % (Pinouche::NB_COLORS - 1);
}

std::istream& operator >> (std::istream& flux, Combinaison& combi)
{
	char temp1;
	char temp2;
	char temp3;
	char temp4;
	flux >> temp1;
	flux >> temp2;
	flux >> temp3;
	flux >> temp4;

	combi.create_combinaison(Pinouche::stoc(temp1), Pinouche::stoc(temp2), Pinouche::stoc(temp3), Pinouche::stoc(temp4));

	return flux;
}