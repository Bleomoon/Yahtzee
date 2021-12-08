#include "Yahtzee_game.h"

int main(int argc, char** argv) {
	std::string noms_joueurs[2] = { "Remi", "Thibault" };
	Yahtzee_game yahtzee_game(2, noms_joueurs, 3);

	yahtzee_game.jouer();
}