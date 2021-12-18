#include "pch.h"
#include "CppUnitTest.h"

#include <iostream>
#include <sstream> 
#include "../Yahtzee/De.cpp"
#include "../Yahtzee/Lancer.cpp"
#include "../Yahtzee/Joueur.cpp"
#include "../Yahtzee/Yahtzee_game.cpp"

#include "../Yahtzee/Figures/Figure.cpp"
#include "../Yahtzee/Figures/brelan.cpp"
#include "../Yahtzee/Figures/carre.cpp"
#include "../Yahtzee/Figures/chance.cpp"
#include "../Yahtzee/Figures/Full.cpp"
#include "../Yahtzee/Figures/Grande_suite.cpp"
#include "../Yahtzee/Figures/Petite_suite.cpp"
#include "../Yahtzee/Figures/Yahtzee.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testJoueur
{
	TEST_CLASS(testJoueur)
	{
	public:
		
		TEST_METHOD(TestConstructeur)
		{
			std::string noms_joueurs[2] = { "Abel", "Jean" };
			Yahtzee_game *yahtzee_game = new Yahtzee_game(2, noms_joueurs, 3);
			Joueur j = Joueur(yahtzee_game, noms_joueurs[0]);
			Joueur j2 = Joueur(yahtzee_game, noms_joueurs[0]);

			Assert::AreEqual(j.get_nom(), noms_joueurs[0]);
			Assert::AreEqual(j.get_total_score(), 0);
			
			bool same = false;
			if (&j == &j2)
				same = true;
			Assert::AreEqual(same, false);
		}
		TEST_METHOD(constructeurCopie)
		{
			std::string noms_joueurs[2] = { "Abel", "Jean" };
			Yahtzee_game yahtzee_game(2, noms_joueurs, 3);
			Joueur j = Joueur(&yahtzee_game, noms_joueurs[0]);

			Joueur j2 = Joueur(j);
			Assert::AreEqual(j.get_nom(), j2.get_nom());
			Assert::AreEqual(j.get_total_score(), j2.get_total_score());
			
			bool same = false;
			if (&j == &j2)
				same = true;
			Assert::AreEqual(same, false);
		}
		TEST_METHOD(operatorEqual)
		{
			std::string noms_joueurs[2] = { "Abel", "Jean" };
			Yahtzee_game yahtzee_game(2, noms_joueurs, 3);
			Joueur j = Joueur(&yahtzee_game, noms_joueurs[0]);

			Joueur j2 = j;

			Assert::AreEqual(j.get_nom(), j2.get_nom());
			Assert::AreEqual(j.get_total_score(), j2.get_total_score());

			bool same = false;
			if (&j == &j2)
				same = true;
			Assert::AreEqual(same, false);
		}

		TEST_METHOD(totalScore)
		{
			//On initialise notre environnement (pas possible dans un before ALL) ? 
			std::string noms_joueurs[2] = { "Abel", "Jean" };
			Yahtzee_game yahtzee_game(2, noms_joueurs, 3);
			Joueur j = Joueur(&yahtzee_game, noms_joueurs[0]);
			Joueur j2 = Joueur(&yahtzee_game, noms_joueurs[1]);

			Lancer *l = new Lancer(5);
			int des[5] = { 1, 2, 3, 4, 5 };
			int recap[6];

			// 0 == 0
			Assert::AreEqual(j.get_total_score(), j2.get_total_score());

			//On lance les dés et on ajoute la chance au 0 car toujours en 0 au début de la partie
			l->lance(des, 5);
			j.get_recapitulatif(l->get_des(), recap);
			j.ajouter_inferieurs(recap, 0);//on ajoute le 0

			//qqchose == 0
			Assert::AreNotEqual(j.get_total_score(), j2.get_total_score());
		}
		TEST_METHOD(TestFiguresRestantesEtFiguresAjout)
		{
			//On initialise notre environnement (pas possible dans un before ALL) ? 
			std::string noms_joueurs[2] = { "Abel", "Jean" };
			Yahtzee_game yahtzee_game(2, noms_joueurs, 3);
			Joueur j = Joueur(&yahtzee_game, noms_joueurs[0]);
			Joueur j2 = Joueur(&yahtzee_game, noms_joueurs[1]);
			std::vector<int> inferieurs_possible1, inferieurs_impossible1, superieurs_restant1;
			std::vector<int> inferieurs_possible2, inferieurs_impossible2, superieurs_restant2;
			Lancer* l = new Lancer(5);
			int des[5] = { 1, 2, 3, 4, 5 };
			int recap[6];

			//On lance les dés 
			l->lance(des, 5);
			j.get_recapitulatif(l->get_des(), recap);

			//on obtiens nos tableaux
			j.superieurs_restante(&superieurs_restant1);
			j.inferieurs_restante(&inferieurs_possible1, &inferieurs_impossible1,recap);
			j2.superieurs_restante(&superieurs_restant2);
			j2.inferieurs_restante(&inferieurs_possible2, &inferieurs_impossible2,recap);
			Assert::AreEqual(superieurs_restant1.size(), superieurs_restant2.size());
			Assert::AreEqual(inferieurs_possible1.size(), inferieurs_possible2.size());
			Assert::AreEqual(inferieurs_impossible1.size(), inferieurs_impossible2.size());

			//les inferieurs impossibles
			recap[0] = 5;
			for (int i = 1; i < 5; i++)
				recap[i] = 0;
			j.ajouter_inferieurs(recap, 1);//on ajoute le brelan
			j.inferieurs_restante(&inferieurs_possible1, &inferieurs_impossible1, recap);
			recap[0] = 3;
			recap[1] = 2;
			j2.inferieurs_restante(&inferieurs_possible2, &inferieurs_impossible2, recap);
			Assert::AreNotEqual(inferieurs_impossible1.size(), inferieurs_impossible2.size());

			//les inferieurs restants
			j.ajouter_inferieurs(recap, 0);//on ajoute le 0 (la chance)
			inferieurs_possible1.clear();
			j.inferieurs_restante(&inferieurs_possible1, &inferieurs_impossible1, recap);
			Assert::AreNotEqual(inferieurs_possible1.size(), inferieurs_possible2.size());

			//superieurs
			j2.ajouter_superieurs(recap, 0);//on ajoute le 0 (la chance)
			superieurs_restant2.clear();
			j2.superieurs_restante(&superieurs_restant2);
			Assert::AreNotEqual(superieurs_restant1.size(), superieurs_restant2.size());
		}
		TEST_METHOD(getNom)
		{
			std::string noms_joueurs[2] = { "Abel", "Jean" };
			Yahtzee_game yahtzee_game(2, noms_joueurs, 3);
			Joueur j = Joueur(&yahtzee_game, noms_joueurs[0]);

			Assert::AreEqual(j.get_nom(), noms_joueurs[0]);
			Assert::AreNotEqual(j.get_nom(), noms_joueurs[1]);
		}
		TEST_METHOD(choixCorrect)
		{
			std::string noms_joueurs[2] = { "Abel", "Jean" };
			Yahtzee_game yahtzee_game(2, noms_joueurs, 3);
			Joueur j = Joueur(&yahtzee_game, noms_joueurs[0]);
			//int Joueur::choix_correct(std::string selected, int max)
			std::string selected;

			//une lettre
			selected = "bed";
			Assert::AreEqual(j.choix_correct(selected, 10), -1);

			//un int trop grand
			selected = "11";
			Assert::AreEqual(j.choix_correct(selected, 10), -1);

			//un int trop petit
			selected = "0";
			Assert::AreEqual(j.choix_correct(selected, 10), -1);

			selected = "5";
			Assert::AreEqual(j.choix_correct(selected, 10), 5);
		}

		// test de dés > 5, de lettres et de doublons
		TEST_METHOD(TestDesRelance)
		{
			std::string noms_joueurs[2] = { "Abel", "Jean" };
			Yahtzee_game yahtzee_game(2, noms_joueurs, 3);
			Joueur j = Joueur(&yahtzee_game, noms_joueurs[0]);
			bool same = true;
			int* verif = nullptr;

			// nb_des > 5
			if (j.des_relance("1234567") != verif)
				same = false;
			Assert::AreEqual(same, true); //ici nullptr

			// une lettre
			if (j.des_relance("a") != verif)
				same = false;
			Assert::AreEqual(same, true); //ici nullptr

			//des doublons
			if (j.des_relance("11") != verif)
				same = false;
			Assert::AreEqual(same, true); //ici nullptr

			int* trueverif = new int[5];
			for (int i = 1; i < 6; i++)
				trueverif[i - 1] = i;

			int* result = j.des_relance("12345");
			for (int i = 0; i < 5; i++)
				if (result[i] != trueverif[i])
					same = false;
			Assert::AreEqual(same, true); //ici egal
		}


		TEST_METHOD(getRecapitulatif)
		{

			std::string noms_joueurs[2] = { "Abel", "Jean" };
			Yahtzee_game yahtzee_game(2, noms_joueurs, 3);
			Joueur j = Joueur(&yahtzee_game, noms_joueurs[0]);
			bool same = true;
			int vals[6];
			Lancer *l = new Lancer(5);
			int des[5] = { 1, 2, 3, 4, 5 };
			int recap[6];

			for (int i = 0; i < 5; i++)
				vals[i] = 0;
			l->lance(des, 5);
			for (int i = 0; i < 5; i++)
			{
				if ((l->get_des()[i]->get_val()) == 1)
					vals[0]++;
				else if ((l->get_des()[i]->get_val()) == 2)
					vals[1]++;
				else if ((l->get_des()[i]->get_val()) == 3)
					vals[2]++;
				else if ((l->get_des()[i]->get_val()) == 4)
					vals[3]++;
				else if ((l->get_des()[i]->get_val()) == 5)
					vals[4]++;
				else if ((l->get_des()[i]->get_val()) == 6)
					vals[5]++;
			}

			j.get_recapitulatif(l->get_des(), recap);
			for (int i = 0; i < 5; i++)
				if (vals[i] != recap[i])
					same = false;
			Assert::AreEqual(same, true);
		}
		
	};
}
