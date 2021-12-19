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
		TEST_METHOD(is_figure)
		{
			Assert::IsFalse(brelan.is_figure(recap1));
			Assert::IsTrue(brelan.is_figure(recap2));
			Assert::IsTrue(brelan.is_figure(recap3));
		}
		TEST_METHOD(score_possible)
		{
			Assert::IsTrue(brelan.score_possible(recap1) == 0);
			Assert::IsTrue(brelan.score_possible(recap2) == 18);
			Assert::IsTrue(brelan.score_possible(recap3) == 17);
		}
		TEST_METHOD(get_name)
		{
			Assert::IsTrue(std::strcmp(brelan.get_name().c_str(), "Brelan") == 0);
		}
		TEST_METHOD(set_figure)
		{
			Assert::IsFalse(brelan.set_figure(recap1));
			Assert::IsTrue(brelan2.set_figure(recap2));
			Assert::IsTrue(brelan3.set_figure(recap3));
		}
		TEST_METHOD(get_score)
		{
			brelan.set_figure(recap1);
			Assert::IsTrue(brelan.get_score() == 0);
			brelan2.set_figure(recap2);
			Assert::IsTrue(brelan2.get_score() == 18);
			brelan3.set_figure(recap3);
			Assert::IsTrue(brelan3.get_score() == 17);
		}
	};
}