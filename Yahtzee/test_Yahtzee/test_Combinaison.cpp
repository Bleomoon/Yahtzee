#include "pch.h"
#include "CppUnitTest.h"

#include <iostream>
#include <sstream> 

#include "../Yahtzee/Figures/Combinaison.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace testCombinaison
{
	// initialisations des récaps
	int recap1_1[6] = { 0, 1, 1, 1, 1, 1 };
	int recap1_2[6] = { 5, 0, 0, 0, 0, 0 };
	int recap2_1[6] = { 1, 0, 1, 1, 1, 1 };
	int recap2_2[6] = { 0, 5, 0, 0, 0, 0 };
	int recap3_1[6] = { 1, 1, 0, 1, 1, 1 };
	int recap3_2[6] = { 0, 0, 5, 0, 0, 0 };
	int recap4_1[6] = { 1, 1, 1, 0, 1, 1 };
	int recap4_2[6] = { 0, 0, 0, 5, 0, 0 };
	int recap5_1[6] = { 1, 1, 1, 1, 0, 1 };
	int recap5_2[6] = { 0, 0, 0, 0, 5, 0 };
	int recap6_1[6] = { 1, 1, 1, 1, 1, 0 };
	int recap6_2[6] = { 0, 0, 0, 0, 0, 5 };

	// les combinaisons
	Combinaison<1> comb1;
	Combinaison<2> comb2;
	Combinaison<3> comb3;
	Combinaison<4> comb4;
	Combinaison<5> comb5;
	Combinaison<6> comb6;

	TEST_CLASS(testCombinaison)
	{
	public:
		TEST_METHOD(is_figure_un)
		{
			Assert::AreEqual(comb1.is_figure(recap1_1), true);
			Assert::AreEqual(comb1.is_figure(recap1_2), true);
		}
		TEST_METHOD(is_figure_deux)
		{
			Assert::AreEqual(comb2.is_figure(recap2_1), true);
			Assert::AreEqual(comb2.is_figure(recap2_2), true);
		}
		TEST_METHOD(is_figure_trois)
		{
			Assert::AreEqual(comb3.is_figure(recap3_1), true);
			Assert::AreEqual(comb3.is_figure(recap3_2), true);
		}
		TEST_METHOD(is_figure_quatre)
		{
			Assert::AreEqual(comb4.is_figure(recap4_1), true);
			Assert::AreEqual(comb4.is_figure(recap4_2), true);
		}
		TEST_METHOD(is_figure_cinq)
		{
			Assert::AreEqual(comb5.is_figure(recap5_1), true);
			Assert::AreEqual(comb5.is_figure(recap5_2), true);
		}
		TEST_METHOD(is_figure_six)
		{
			Assert::AreEqual(comb6.is_figure(recap6_1), true);
			Assert::AreEqual(comb6.is_figure(recap6_2), true);
		}
		TEST_METHOD(score_possible_zero)
		{
			Assert::IsTrue(comb1.score_possible(recap1_1) == 0);
			Assert::IsTrue(comb2.score_possible(recap2_1) == 0);
			Assert::IsTrue(comb3.score_possible(recap3_1) == 0);
			Assert::IsTrue(comb4.score_possible(recap4_1) == 0);
			Assert::IsTrue(comb5.score_possible(recap5_1) == 0);
			Assert::IsTrue(comb6.score_possible(recap6_1) == 0);
		}
		TEST_METHOD(score_possible_cinq)
		{
			Assert::IsTrue(comb1.score_possible(recap1_2) == 5);
			Assert::IsTrue(comb2.score_possible(recap2_2) == 10);
			Assert::IsTrue(comb3.score_possible(recap3_2) == 15);
			Assert::IsTrue(comb4.score_possible(recap4_2) == 20);
			Assert::IsTrue(comb5.score_possible(recap5_2) == 25);
			Assert::IsTrue(comb6.score_possible(recap6_2) == 30);
		}
		TEST_METHOD(get_name)
		{
			Assert::IsTrue(std::strcmp(comb1.get_name().c_str(), "un")== 0);
			Assert::IsTrue(std::strcmp(comb2.get_name().c_str(), "deux") == 0);
			Assert::IsTrue(std::strcmp(comb3.get_name().c_str(), "trois") == 0);
			Assert::IsTrue(std::strcmp(comb4.get_name().c_str(), "quatre") == 0);
			Assert::IsTrue(std::strcmp(comb5.get_name().c_str(), "cinq") == 0);
			Assert::IsTrue(std::strcmp(comb6.get_name().c_str(), "six") == 0);
		}
		TEST_METHOD(set_figure_zero)
		{
			Assert::IsTrue(comb1.set_figure(recap1_1));
			Assert::IsTrue(comb2.set_figure(recap2_1));
			Assert::IsTrue(comb3.set_figure(recap3_1));
			Assert::IsTrue(comb4.set_figure(recap4_1));
			Assert::IsTrue(comb5.set_figure(recap5_1));
			Assert::IsTrue(comb6.set_figure(recap6_1));
		}
		TEST_METHOD(set_figure_cinq)
		{
			Assert::IsTrue(comb1.set_figure(recap1_2));
			Assert::IsTrue(comb2.set_figure(recap2_2));
			Assert::IsTrue(comb3.set_figure(recap3_2));
			Assert::IsTrue(comb4.set_figure(recap4_2));
			Assert::IsTrue(comb5.set_figure(recap5_2));
			Assert::IsTrue(comb6.set_figure(recap6_2));
		}
		TEST_METHOD(get_score_zero)
		{
			comb1.set_figure(recap1_1);
			Assert::IsTrue(comb1.get_score() == 0);
			comb2.set_figure(recap2_1);
			Assert::IsTrue(comb2.get_score() == 0);
			comb3.set_figure(recap3_1);
			Assert::IsTrue(comb3.get_score() == 0);
			comb4.set_figure(recap4_1);
			Assert::IsTrue(comb4.get_score() == 0);
			comb5.set_figure(recap5_1);
			Assert::IsTrue(comb5.get_score() == 0);
			comb6.set_figure(recap6_1);
			Assert::IsTrue(comb6.get_score() == 0);
		}
		TEST_METHOD(get_score_cinq)
		{
			comb1.set_figure(recap1_2);
			Assert::IsTrue(comb1.get_score() == 5);
			comb2.set_figure(recap2_2);
			Assert::IsTrue(comb2.get_score() == 10);
			comb3.set_figure(recap3_2);
			Assert::IsTrue(comb3.get_score() == 15);
			comb4.set_figure(recap4_2);
			Assert::IsTrue(comb4.get_score() == 20);
			comb5.set_figure(recap5_2);
			Assert::IsTrue(comb5.get_score() == 25);
			comb6.set_figure(recap6_2);
			Assert::IsTrue(comb6.get_score() == 30);
		}
	};
}