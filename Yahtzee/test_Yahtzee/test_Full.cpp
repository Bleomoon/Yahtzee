#include "pch.h"
#include "CppUnitTest.h"

#include <iostream>
#include <sstream> 

#include "../Yahtzee/Figures/Full.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace testFull
{
	// initialisations des récaps
	int recap1[6] = { 0, 1, 1, 0, 0, 3 };
	int recap2[6] = { 0, 2, 0, 3, 0, 0 };
	int recap3[6] = { 0, 0, 3, 0, 2, 0 };

	// les combinaisons
	Full full;
	Full full2;
	Full full3;

	TEST_CLASS(testFull)
	{
	public:
		TEST_METHOD(is_figure)
		{
			Assert::IsFalse(full.is_figure(recap1));
			Assert::IsTrue(full.is_figure(recap2));
			Assert::IsTrue(full.is_figure(recap3));
		}
		TEST_METHOD(score_possible)
		{
			Assert::IsTrue(full.score_possible(recap1) == 0);
			Assert::IsTrue(full.score_possible(recap2) == 25);
			Assert::IsTrue(full.score_possible(recap3) == 25);
		}
		TEST_METHOD(get_name)
		{
			Assert::IsTrue(std::strcmp(full.get_name().c_str(), "Full") == 0);
		}
		TEST_METHOD(set_figure)
		{
			Assert::IsFalse(full.set_figure(recap1));
			Assert::IsTrue(full2.set_figure(recap2));
			Assert::IsTrue(full3.set_figure(recap3));
		}
		TEST_METHOD(get_score)
		{
			full.set_figure(recap1);
			Assert::IsTrue(full.get_score() == 0);
			full2.set_figure(recap2);
			Assert::IsTrue(full2.get_score() == 25);
			full3.set_figure(recap3);
			Assert::IsTrue(full3.get_score() == 25);
		}
	};
}