#include "pch.h"
#include "CppUnitTest.h"

#include <iostream>
#include <sstream> 

#include "../Yahtzee/Figures/Chance.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace testChance
{
	// initialisations des récaps
	int recap1[6] = { 0, 1, 1, 1, 1, 1 };
	int recap2[6] = { 0, 0, 5, 0, 0, 0 };
	int recap3[6] = { 0, 0, 2, 0, 2, 1 };

	// les combinaisons
	Chance chance;
	Chance chance2;
	Chance chance3;

	TEST_CLASS(testChance)
	{
	public:
		TEST_METHOD(is_figure)
		{
			Assert::IsTrue(chance.is_figure(recap1));
			Assert::IsTrue(chance.is_figure(recap2));
			Assert::IsTrue(chance.is_figure(recap3));
		}
		TEST_METHOD(score_possible)
		{
			Assert::IsTrue(chance.score_possible(recap1) == 20);
			Assert::IsTrue(chance.score_possible(recap2) == 15);
			Assert::IsTrue(chance.score_possible(recap3) == 22);
		}
		TEST_METHOD(get_name)
		{
			Assert::IsTrue(std::strcmp(chance.get_name().c_str(), "Chance") == 0);
		}
		TEST_METHOD(set_figure)
		{
			Assert::IsTrue(chance.set_figure(recap1));
			Assert::IsTrue(chance2.set_figure(recap2));
			Assert::IsTrue(chance3.set_figure(recap3));
		}
		TEST_METHOD(get_score)
		{
			chance.set_figure(recap1);
			Assert::IsTrue(chance.get_score() == 20);
			chance2.set_figure(recap2);
			Assert::IsTrue(chance2.get_score() == 15);
			chance3.set_figure(recap3);
			Assert::IsTrue(chance3.get_score() == 22);
		}
	};
}