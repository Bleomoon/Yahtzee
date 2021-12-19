#include "pch.h"
#include "CppUnitTest.h"

#include <iostream>
#include <sstream> 

#include "../Yahtzee/Figures/Grande_suite.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace testGrandeSuite
{
	// initialisations des récaps
	int recap1[6] = { 1, 1, 1, 1, 0, 1 };
	int recap2[6] = { 1, 1, 1, 1, 1, 0 };
	int recap3[6] = { 0, 1, 1, 1, 1, 1 };

	// les combinaisons
	Grande_suite grande_suite;
	Grande_suite grande_suite2;
	Grande_suite grande_suite3;

	TEST_CLASS(testGrandeSuite)
	{
	public:
		TEST_METHOD(is_figure)
		{
			Assert::IsFalse(grande_suite.est_figure(recap1));
			Assert::IsTrue(grande_suite.est_figure(recap2));
			Assert::IsTrue(grande_suite.est_figure(recap3));
		}
		TEST_METHOD(score_possible)
		{
			Assert::IsTrue(grande_suite.score_possible(recap1) == 0);
			Assert::IsTrue(grande_suite.score_possible(recap2) == 40);
			Assert::IsTrue(grande_suite.score_possible(recap3) == 40);
		}
		TEST_METHOD(avoir_nom)
		{
			Assert::IsTrue(std::strcmp(grande_suite.avoir_nom().c_str(), "Grande Suite") == 0);
		}
		TEST_METHOD(set_figure)
		{
			Assert::IsFalse(grande_suite.valider_figure(recap1));
			Assert::IsTrue(grande_suite2.valider_figure(recap2));
			Assert::IsTrue(grande_suite3.valider_figure(recap3));
		}
		TEST_METHOD(avoir_score)
		{
			grande_suite.valider_figure(recap1);
			Assert::IsTrue(grande_suite.avoir_score() == 0);
			grande_suite2.valider_figure(recap2);
			Assert::IsTrue(grande_suite2.avoir_score() == 40);
			grande_suite3.valider_figure(recap3);
			Assert::IsTrue(grande_suite3.avoir_score() == 40);
		}
	};
}