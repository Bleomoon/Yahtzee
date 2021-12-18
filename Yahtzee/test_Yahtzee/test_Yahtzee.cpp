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
			Assert::IsFalse(yahtzee.is_figure(recap1));
			Assert::IsTrue(yahtzee.is_figure(recap2));
			Assert::IsTrue(yahtzee.is_figure(recap3));
		}
		TEST_METHOD(score_possible)
		{
			Assert::IsTrue(yahtzee.score_possible(recap1) == 0);
			Assert::IsTrue(yahtzee.score_possible(recap2) == 50);
			Assert::IsTrue(yahtzee.score_possible(recap3) == 50);
		}
		TEST_METHOD(get_name)
		{
			Assert::IsTrue(std::strcmp(yahtzee.get_name().c_str(), "Yahtzee") == 0);
		}
		TEST_METHOD(set_figure)
		{
			Assert::IsFalse(yahtzee.set_figure(recap1));
			Assert::IsTrue(yahtzee2.set_figure(recap2));
			Assert::IsTrue(yahtzee3.set_figure(recap3));
		}
		TEST_METHOD(get_score)
		{
			yahtzee.set_figure(recap1);
			Assert::IsTrue(yahtzee.get_score() == 0);
			yahtzee2.set_figure(recap2);
			Assert::IsTrue(yahtzee2.get_score() == 50);
			yahtzee3.set_figure(recap3);
			Assert::IsTrue(yahtzee3.get_score() == 50);
		}
	};
}