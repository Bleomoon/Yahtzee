#include "pch.h"
#include "CppUnitTest.h"

#include <iostream>
#include <sstream> 

#include "../Yahtzee/Figures/Yahtzee.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace testCarre
{
	// initialisations des récaps
	int recap1[6] = { 0, 1, 1, 0, 0, 3 };
	int recap2[6] = { 0, 4, 0, 1, 0, 0 };
	int recap3[6] = { 0, 0, 0, 0, 5, 0 };

	// les combinaisons
	Carre carre;
	Carre carre2;
	Carre carre3;

	TEST_CLASS(testCarre)
	{
	public:
		TEST_METHOD(est_figure)
		{
			Assert::IsFalse(carre.est_figure(recap1));
			Assert::IsTrue(carre.est_figure(recap2));
			Assert::IsTrue(carre.est_figure(recap3));
		}
		TEST_METHOD(score_possible)
		{
			Assert::IsTrue(carre.score_possible(recap1) == 0);
			Assert::IsTrue(carre.score_possible(recap2) == 12);
			Assert::IsTrue(carre.score_possible(recap3) == 25);
		}
		TEST_METHOD(avoir_nom)
		{
			Assert::IsTrue(std::strcmp(carre.avoir_nom().c_str(), "Carre") == 0);
		}
		TEST_METHOD(valider_figure)
		{
			Assert::IsFalse(carre.valider_figure(recap1));
			Assert::IsTrue(carre2.valider_figure(recap2));
			Assert::IsTrue(carre3.valider_figure(recap3));
		}
		TEST_METHOD(avoir_score)
		{
			carre.valider_figure(recap1);
			Assert::IsTrue(carre.avoir_score() == 0);
			carre2.valider_figure(recap2);
			Assert::IsTrue(carre2.avoir_score() == 12);
			carre3.valider_figure(recap3);
			Assert::IsTrue(carre3.avoir_score() == 25);
		}
	};
}