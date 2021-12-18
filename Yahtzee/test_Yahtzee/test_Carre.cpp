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
		TEST_METHOD(is_figure)
		{
			Assert::IsFalse(carre.is_figure(recap1));
			Assert::IsTrue(carre.is_figure(recap2));
			Assert::IsTrue(carre.is_figure(recap3));
		}
		TEST_METHOD(score_possible)
		{
			Assert::IsTrue(carre.score_possible(recap1) == 0);
			Assert::IsTrue(carre.score_possible(recap2) == 12);
			Assert::IsTrue(carre.score_possible(recap3) == 25);
		}
		TEST_METHOD(get_name)
		{
			Assert::IsTrue(std::strcmp(carre.get_name().c_str(), "Carre") == 0);
		}
		TEST_METHOD(set_figure)
		{
			Assert::IsFalse(carre.set_figure(recap1));
			Assert::IsTrue(carre2.set_figure(recap2));
			Assert::IsTrue(carre3.set_figure(recap3));
		}
		TEST_METHOD(get_score)
		{
			carre.set_figure(recap1);
			Assert::IsTrue(carre.get_score() == 0);
			carre2.set_figure(recap2);
			Assert::IsTrue(carre2.get_score() == 12);
			carre3.set_figure(recap3);
			Assert::IsTrue(carre3.get_score() == 25);
		}
	};
}