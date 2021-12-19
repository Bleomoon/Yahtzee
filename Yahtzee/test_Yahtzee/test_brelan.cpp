#include "pch.h"
#include "CppUnitTest.h"

#include <iostream>
#include <sstream> 

#include "../Yahtzee/Figures/brelan.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace testBrelan
{
	// initialisations des récaps
	int recap1[6] = { 0, 1, 1, 1, 1, 1 };
	int recap2[6] = { 0, 0, 3, 1, 1, 0 };
	int recap3[6] = { 0, 1, 1, 3, 0, 0 };

	// les combinaisons
	Brelan brelan;
	Brelan brelan2;
	Brelan brelan3;

	TEST_CLASS(testBrelan)
	{
	public:
		TEST_METHOD(est_figure)
		{
			Assert::IsFalse(brelan.est_figure(recap1));
			Assert::IsTrue(brelan.est_figure(recap2));
			Assert::IsTrue(brelan.est_figure(recap3));
		}
		TEST_METHOD(score_possible)
		{
			Assert::IsTrue(brelan.score_possible(recap1) == 0);
			Assert::IsTrue(brelan.score_possible(recap2) == 18);
			Assert::IsTrue(brelan.score_possible(recap3) == 17);
		}
		TEST_METHOD(avoir_nom)
		{
			Assert::IsTrue(std::strcmp(brelan.avoir_nom().c_str(), "Brelan") == 0);
		}
		TEST_METHOD(valider_figure)
		{
			Assert::IsFalse(brelan.valider_figure(recap1));
			Assert::IsTrue(brelan2.valider_figure(recap2));
			Assert::IsTrue(brelan3.valider_figure(recap3));
		}
		TEST_METHOD(avoir_score)
		{
			brelan.valider_figure(recap1);
			Assert::IsTrue(brelan.avoir_score() == 0);
			brelan2.valider_figure(recap2);
			Assert::IsTrue(brelan2.avoir_score() == 18);
			brelan3.valider_figure(recap3);
			Assert::IsTrue(brelan3.avoir_score() == 17);
		}
	};
}