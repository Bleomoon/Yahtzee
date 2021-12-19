#include "pch.h"
#include "CppUnitTest.h"

#include <iostream>
#include <sstream> 

#include "../Yahtzee/Figures/Yahtzee.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace testYahtzee
{
	// initialisations des récaps
	int recap1[6] = { 0, 1, 1, 1, 1, 1 };
	int recap2[6] = { 0, 5, 0, 0, 0, 0 };
	int recap3[6] = { 0, 0, 0, 0, 5, 0 };

	// les combinaisons
	Yahtzee yahtzee;
	Yahtzee yahtzee2;
	Yahtzee yahtzee3;

	TEST_CLASS(testYahtzee)
	{
	public:
		TEST_METHOD(is_figure)
		{
			Assert::IsFalse(yahtzee.est_figure(recap1));
			Assert::IsTrue(yahtzee.est_figure(recap2));
			Assert::IsTrue(yahtzee.est_figure(recap3));
		}
		TEST_METHOD(score_possible)
		{
			Assert::IsTrue(yahtzee.score_possible(recap1) == 0);
			Assert::IsTrue(yahtzee.score_possible(recap2) == 50);
			Assert::IsTrue(yahtzee.score_possible(recap3) == 50);
		}
		TEST_METHOD(avoir_nom)
		{
			Assert::IsTrue(std::strcmp(yahtzee.avoir_nom().c_str(), "Yahtzee") == 0);
		}
		TEST_METHOD(set_figure)
		{
			Assert::IsFalse(yahtzee.valider_figure(recap1));
			Assert::IsTrue(yahtzee2.valider_figure(recap2));
			Assert::IsTrue(yahtzee3.valider_figure(recap3));
		}
		TEST_METHOD(avoir_score)
		{
			yahtzee.valider_figure(recap1);
			Assert::IsTrue(yahtzee.avoir_score() == 0);
			yahtzee2.valider_figure(recap2);
			Assert::IsTrue(yahtzee2.avoir_score() == 50);
			yahtzee3.valider_figure(recap3);
			Assert::IsTrue(yahtzee3.avoir_score() == 50);
		}
	};
}