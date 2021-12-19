#include "pch.h"
#include "CppUnitTest.h"

#include <iostream>
#include <sstream> 

#include "../Yahtzee/Figures/Petite_suite.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace testPetiteSuite
{
	// initialisations des récaps
	int recap1[6] = { 0, 1, 1, 1, 0, 2 };
	int recap2[6] = { 1, 1, 1, 1, 0, 1 };
	int recap3[6] = { 1, 1, 1, 1, 1, 0 };

	// les combinaisons
	Petite_suite petite_suite;
	Petite_suite petite_suite2;
	Petite_suite petite_suite3;

	TEST_CLASS(testPetiteSuite)
	{
	public:
		TEST_METHOD(is_figure)
		{
			Assert::IsFalse(petite_suite.est_figure(recap1));
			Assert::IsTrue(petite_suite.est_figure(recap2));
			Assert::IsTrue(petite_suite.est_figure(recap3));
		}
		TEST_METHOD(score_possible)
		{
			Assert::IsTrue(petite_suite.score_possible(recap1) == 0);
			Assert::IsTrue(petite_suite.score_possible(recap2) == 30);
			Assert::IsTrue(petite_suite.score_possible(recap3) == 30);
		}
		TEST_METHOD(avoir_nom)
		{
			Assert::IsTrue(std::strcmp(petite_suite.avoir_nom().c_str(), "Petite Suite") == 0);
		}
		TEST_METHOD(set_figure)
		{
			Assert::IsFalse(petite_suite.valider_figure(recap1));
			Assert::IsTrue(petite_suite2.valider_figure(recap2));
			Assert::IsTrue(petite_suite3.valider_figure(recap3));
		}
		TEST_METHOD(avoir_score)
		{
			petite_suite.valider_figure(recap1);
			Assert::IsTrue(petite_suite.avoir_score() == 0);
			petite_suite2.valider_figure(recap2);
			Assert::IsTrue(petite_suite2.avoir_score() == 30);
			petite_suite3.valider_figure(recap3);
			Assert::IsTrue(petite_suite3.avoir_score() == 30);
		}
	};
}