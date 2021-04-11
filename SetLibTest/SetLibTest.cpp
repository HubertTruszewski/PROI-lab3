#include "CppUnitTest.h"
#include "../SetLib/SetLib.h"
#include <iostream>
#include <stdexcept>
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace SetLibTest
{
	TEST_CLASS(SetLibTest)
	{
	public:
		
		TEST_METHOD(TestDefaultConstructor)
		{
			Set<int>testSet;
			Assert::AreEqual(testSet.count(), (size_t)0);
			Assert::IsTrue(testSet.isEmpty());
			Assert::IsFalse(testSet.isInSet(5));
			Assert::IsFalse(testSet.isInSet(0));
		}
		TEST_METHOD(TestVectorArgumentConstructor1)
		{
			std::vector<int> numbers = { 1, 2, 3, 4 };
			Set<int>testSet(numbers);
			Assert::AreEqual(testSet.count(), (size_t)4);
			Assert::IsTrue(testSet.isInSet(1));
			Assert::IsTrue(testSet.isInSet(4));
			Assert::IsFalse(testSet.isInSet(10));
			Assert::IsFalse(testSet.isEmpty());
		}
		TEST_METHOD(TestVectorArgumentConstructor2)
		{
			std::vector<int> numbers = { 1, 2, 3, 4, 3, 6, 2, 5, 4, 9, 1 };
			Set<int>testSet(numbers);
			Assert::AreEqual(testSet.count(), (size_t)7);
			Assert::IsTrue(testSet.isInSet(1));
			Assert::IsTrue(testSet.isInSet(4));
			Assert::IsTrue(testSet.isInSet(9));
			Assert::IsFalse(testSet.isEmpty());
			Assert::IsFalse(testSet.isInSet(8));
		}
		TEST_METHOD(TestVectorArgumentConstructor3)
		{
			std::vector<int> numbers = {};
			Set<int>testSet(numbers);
			Assert::AreEqual(testSet.count(), (size_t)0);
			Assert::IsTrue(testSet.isEmpty());
			Assert::IsFalse(testSet.isInSet(5));
			Assert::IsFalse(testSet.isInSet(0));
		}
		TEST_METHOD(TestSetArgumentConstructor1)
		{
			Set<int>emptySet;
			Set<int>testSet(emptySet);
			Assert::AreEqual(testSet.count(), (size_t)0);
			Assert::IsTrue(testSet.isEmpty());
			Assert::IsFalse(testSet.isInSet(5));
			Assert::IsFalse(testSet.isInSet(0));
		}
		TEST_METHOD(TestSetArgumentConstructor2)
		{
			std::vector<int> numbers = { 1, 2 , 3, 4 };
			Set<int>sourceSet(numbers);
			Set<int>testSet(sourceSet);
			Assert::AreEqual(testSet.count(), (size_t)4);
			Assert::IsTrue(testSet.isInSet(2));
			Assert::IsTrue(testSet.isInSet(4));
			Assert::IsFalse(testSet.isInSet(8));
			Assert::IsFalse(testSet.isEmpty());
		}
		TEST_METHOD(TestGetElementsEmpty)
		{
			std::vector<int> numbers = {};
			Set<int>testSet(numbers);
			auto result = testSet.getElements();
			Assert::AreEqual(result.size(), (size_t)0);
			Assert::IsTrue(result.empty());
		}
		TEST_METHOD(TestGetElementsNormal)
		{
			std::vector<int> numbers = {1, 2, 3, 4, 5};
			Set<int>testSet(numbers);
			auto result = testSet.getElements();
			Assert::AreEqual(result.size(), (size_t)5);
			Assert::IsFalse(result.empty());
		}
		TEST_METHOD(TestGetElementsNotUniqueNums)
		{
			std::vector<int> numbers = {2, 4, 7, 2, 4, 0, 6, 4, 7};
			Set<int>testSet(numbers);
			auto result = testSet.getElements();
			Assert::AreEqual(result.size(), (size_t)5);
			Assert::IsFalse(result.empty());
		}
		TEST_METHOD(TestOperatorPlusWithSetUniqueNums)
		{
			std::vector<int> numbers1 = { 1, 2, 3, 4, 5 };
			Set<int>set1(numbers1);
			std::vector<int> numbers2 = { 6, 7, 9 };
			Set<int>set2(numbers2);
			Set<int>set3 = set1 + set2;
			Assert::AreEqual(set3.count(), (size_t)8);
			Assert::IsTrue(set3.isInSet(3));
			Assert::IsTrue(set3.isInSet(7));
			Assert::IsFalse(set3.isInSet(8));
			Assert::IsFalse(set3.isEmpty());
		}
		TEST_METHOD(TestOperatorPlusWithSetNotUniqueNums)
		{
			std::vector<int> numbers1 = { 1, 2, 3, 4, 5, 8, 9 };
			Set<int>set1(numbers1);
			std::vector<int> numbers2 = { 5, 6, 7, 9 };
			Set<int>set2(numbers2);
			Set<int>set3 = set1 + set2;
			Assert::AreEqual(set3.count(), (size_t)9);
			Assert::IsTrue(set3.isInSet(3));
			Assert::IsTrue(set3.isInSet(7));
			Assert::IsTrue(set3.isInSet(8));
			Assert::IsFalse(set3.isEmpty());
			Assert::IsFalse(set3.isInSet(0));
		}
		TEST_METHOD(TestOperatorPlusWithSetEmpty)
		{
			std::vector<int> numbers = { 1, 2, 3, 4, 5, 8, 9 };
			Set<int>set1(numbers);
			Set<int>set2;
			Set<int>set3 = set1 + set2;
			Assert::AreEqual(set3.count(), (size_t)7);
			Assert::IsTrue(set3.isInSet(3));
			Assert::IsFalse(set3.isInSet(7));
			Assert::IsTrue(set3.isInSet(8));
			Assert::IsFalse(set3.isEmpty());
			Assert::IsFalse(set3.isInSet(0));
		}
		TEST_METHOD(TestOperatorMinusWithSetNormal)
		{
			std::vector<int> numbers1 = { 1, 2, 3, 4, 5, 8, 9 };
			Set<int>set1(numbers1);
			std::vector<int> numbers2 = { 3, 4, 9 };
			Set<int>set2(numbers2);
			Set<int>set3 = set1 - set2;
			Assert::AreEqual(set3.count(), (size_t)4);
			Assert::IsTrue(set3.isInSet(5));
			Assert::IsFalse(set3.isInSet(7));
			Assert::IsTrue(set3.isInSet(8));
			Assert::IsFalse(set3.isEmpty());
			Assert::IsFalse(set3.isInSet(0));
		}
		TEST_METHOD(TestOperatorMinusWithSetNoCommon)
		{
			std::vector<int> numbers1 = { 1, 2, 3, 4, 5, 8, 9 };
			Set<int>set1(numbers1);
			std::vector<int> numbers2 = { 10, 13 };
			Set<int>set2(numbers2);
			Set<int>set3 = set1 - set2;
			Assert::AreEqual(set3.count(), (size_t)7);
			Assert::IsFalse(set3.isEmpty());
			Assert::IsTrue(set3.isInSet(9));
			Assert::IsFalse(set3.isInSet(10));
		}
		TEST_METHOD(TestOperatorMinusWithEmptySet)
		{
			std::vector<int> numbers1 = { 1, 2, 3, 4, 5, 8, 9 };
			Set<int>set1(numbers1);
			Set<int>set2;
			Set<int>set3 = set1 - set2;
			Assert::AreEqual(set3.count(), (size_t)7);
			Assert::IsFalse(set3.isEmpty());
			Assert::IsTrue(set3.isInSet(3));
			Assert::IsTrue(set3.isInSet(9));
			Assert::IsFalse(set3.isInSet(7));
		}
		TEST_METHOD(TestOperatorPlusWithInteger)
		{
			std::vector<int> numbers1 = { 1, 2, 3, 4, 5, 8, 9 };
			Set<int>set1(numbers1);
			Set<int>set2 = set1 + 6;
			Assert::AreEqual(set2.count(), (size_t)8);
			Assert::IsFalse(set2.isEmpty());
			Assert::IsTrue(set2.isInSet(5));
			Assert::IsTrue(set2.isInSet(6));
			Assert::IsFalse(set2.isInSet(7));
		}
		TEST_METHOD(TestOperatorPlusWithIntegerInSet)
		{
			std::vector<int> numbers1 = { 1, 2, 3, 4, 5, 8, 9 };
			Set<int>set1(numbers1);
			Set<int>set2 = set1 + 9;
			Assert::AreEqual(set2.count(), (size_t)7);
			Assert::IsFalse(set2.isEmpty());
			Assert::IsTrue(set2.isInSet(5));
			Assert::IsTrue(set2.isInSet(9));
			Assert::IsFalse(set2.isInSet(7));
		}
		TEST_METHOD(TestOperatorMinusWithIntegerInSet)
		{
			std::vector<int> numbers1 = { 1, 2, 3, 4, 5, 8, 9 };
			Set<int>set1(numbers1);
			Set<int>set2 = set1 - 5;
			Assert::AreEqual(set2.count(), (size_t)6);
			Assert::IsFalse(set2.isEmpty());
			Assert::IsTrue(set2.isInSet(8));
			Assert::IsFalse(set2.isInSet(5));
		}
		TEST_METHOD(TestOperatorMinusWithIntegerNotInSet)
		{
			std::vector<int> numbers1 = { 1, 2, 3, 4, 5, 8, 9 };
			Set<int>set1(numbers1);
			Set<int>set2 = set1 - 6;
			Assert::AreEqual(set2.count(), (size_t)7);
			Assert::IsFalse(set2.isEmpty());
			Assert::IsTrue(set2.isInSet(8));
			Assert::IsFalse(set2.isInSet(6));
		}
		TEST_METHOD(TestOperatorAdditionAssignmentWithSetNormal)
		{
			std::vector<int> numbers1 = { 1, 2, 3, 4, 5, 8, 9 };
			Set<int>set1(numbers1);
			std::vector<int> numbers2 = { 6, 7 };
			Set<int>set2(numbers2);
			set1 += set2;
			Assert::AreEqual(set1.count(), (size_t)9);
			Assert::IsTrue(set1.isInSet(3));
			Assert::IsTrue(set1.isInSet(6));
			Assert::IsFalse(set1.isEmpty());
		}
		TEST_METHOD(TestOperatorAdditionAssignmentWithSetCommonElements)
		{
			std::vector<int> numbers1 = { 1, 2, 3, 4, 5, 8, 9 };
			Set<int>set1(numbers1);
			std::vector<int> numbers2 = { 1, 3, 5 };
			Set<int>set2(numbers2);
			set1 += set2;
			Assert::AreEqual(set1.count(), (size_t)7);
			Assert::IsTrue(set1.isInSet(3));
			Assert::IsTrue(set1.isInSet(5));
			Assert::IsFalse(set1.isInSet(6));
			Assert::IsFalse(set1.isEmpty());
		}
		TEST_METHOD(TestOperatorAdditionAssignmentWithSetNotUniqueElements)
		{
			std::vector<int> numbers1 = { 1, 2, 3, 4, 5, 8, 9 };
			Set<int>set1(numbers1);
			std::vector<int> numbers2 = { 1, 3, 5, 6, 7 };
			Set<int>set2(numbers2);
			set1 += set2;
			Assert::AreEqual(set1.count(), (size_t)9);
			Assert::IsTrue(set1.isInSet(3));
			Assert::IsTrue(set1.isInSet(5));
			Assert::IsTrue(set1.isInSet(6));
			Assert::IsFalse(set1.isEmpty());
		}
		TEST_METHOD(TestOperatorAdditionAssignmentWithEmptySet)
		{
			std::vector<int> numbers1 = { 1, 2, 3, 4, 5, 8, 9 };
			Set<int>set1(numbers1);
			Set<int>set2;
			set1 += set2;
			Assert::AreEqual(set1.count(), (size_t)7);
			Assert::IsTrue(set1.isInSet(3));
			Assert::IsTrue(set1.isInSet(5));
			Assert::IsFalse(set1.isInSet(6));
			Assert::IsFalse(set1.isEmpty());
		}
		TEST_METHOD(TestOperatorSubstractionAssignmentNormal)
		{
			std::vector<int> numbers1 = { 1, 2, 3, 4, 5, 8, 9 };
			Set<int>set1(numbers1);
			std::vector<int> numbers2 = { 1, 3, 5 };
			Set<int>set2(numbers2);
			set1 -= set2;
			Assert::AreEqual(set1.count(), (size_t)4);
			Assert::IsTrue(set1.isInSet(2));
			Assert::IsTrue(set1.isInSet(9));
			Assert::IsFalse(set1.isInSet(1));
			Assert::IsFalse(set1.isInSet(3));
			Assert::IsFalse(set1.isInSet(5));
		}
		TEST_METHOD(TestOperatorSubstractionAssignmentWithCommonElements)
		{
			std::vector<int> numbers1 = { 1, 2, 3, 4, 5, 8, 9 };
			Set<int>set1(numbers1);
			std::vector<int> numbers2 = { 1, 3, 5, 6, 7 };
			Set<int>set2(numbers2);
			set1 -= set2;
			Assert::AreEqual(set1.count(), (size_t)4);
			Assert::IsTrue(set1.isInSet(2));
			Assert::IsTrue(set1.isInSet(9));
			Assert::IsFalse(set1.isInSet(1));
			Assert::IsFalse(set1.isInSet(3));
			Assert::IsFalse(set1.isInSet(5));
			Assert::IsFalse(set1.isInSet(6));
			Assert::IsFalse(set1.isInSet(7));
		}
		TEST_METHOD(TestOperatorSubstractionAssignmentWithEmptySet)
		{
			std::vector<int> numbers1 = { 1, 2, 3, 4 };
			Set<int>set1(numbers1);
			Set<int>set2;
			set1 -= set2;
			Assert::AreEqual(set1.count(), (size_t)4);
			Assert::IsTrue(set1.isInSet(1));
			Assert::IsTrue(set1.isInSet(2));
			Assert::IsTrue(set1.isInSet(3));
			Assert::IsTrue(set1.isInSet(4));
			Assert::IsFalse(set1.isInSet(5));
			Assert::IsFalse(set1.isInSet(6));
			Assert::IsFalse(set1.isInSet(7));
		}
		TEST_METHOD(TestOperatorSubstractionAssignmentWithNotCommon)
		{
			std::vector<int> numbers1 = { 1, 2, 3, 4 };
			Set<int>set1(numbers1);
			std::vector<int> numbers2 = { 5, 7, 9 };
			Set<int>set2(numbers2);
			set1 -= set2;
			Assert::AreEqual(set1.count(), (size_t)4);
			Assert::IsTrue(set1.isInSet(1));
			Assert::IsTrue(set1.isInSet(2));
			Assert::IsTrue(set1.isInSet(3));
			Assert::IsTrue(set1.isInSet(4));
			Assert::IsFalse(set1.isInSet(5));
			Assert::IsFalse(set1.isInSet(6));
			Assert::IsFalse(set1.isInSet(7));
		}
		TEST_METHOD(TestOperatorSubstractionAssignmentWithPresentIneger)
		{
			std::vector<int> numbers1 = { 1, 2, 3, 4 };
			Set<int>set1(numbers1);
			set1 -= 4;
			Assert::AreEqual(set1.count(), (size_t)3);
			Assert::IsTrue(set1.isInSet(1));
			Assert::IsTrue(set1.isInSet(2));
			Assert::IsTrue(set1.isInSet(3));
			Assert::IsFalse(set1.isInSet(4));
			Assert::IsFalse(set1.isInSet(5));
			Assert::IsFalse(set1.isInSet(6));
		}
		TEST_METHOD(TestOperatorSubstractionAssignmentWithNotPresentInteger)
		{
			std::vector<int> numbers1 = { 1, 2, 3, 4 };
			Set<int>set1(numbers1);
			set1 -= 6;
			Assert::AreEqual(set1.count(), (size_t)4);
			Assert::IsTrue(set1.isInSet(1));
			Assert::IsTrue(set1.isInSet(2));
			Assert::IsTrue(set1.isInSet(3));
			Assert::IsTrue(set1.isInSet(4));
			Assert::IsFalse(set1.isInSet(5));
			Assert::IsFalse(set1.isInSet(6));
		}
		TEST_METHOD(TestIntersectionNormal)
		{
			std::vector<int> numbers1 = { 1, 2, 3, 4, 7, 9 };
			Set<int>set1(numbers1);
			std::vector<int> numbers2 = { 1, 5, 8, 9 };
			Set<int>set2(numbers2);
			Set<int>set3 = set1 * set2;
			Assert::AreEqual(set3.count(), (size_t)2);
			Assert::IsFalse(set3.isEmpty());
			Assert::IsTrue(set3.isInSet(1));
			Assert::IsTrue(set3.isInSet(9));
			Assert::IsFalse(set3.isInSet(3));
			Assert::IsFalse(set3.isInSet(8));
		}
		TEST_METHOD(TestIntersectionEmptySet)
		{
			std::vector<int> numbers1 = { 1, 2, 3, 4, 7, 9 };
			Set<int>set1(numbers1);
			Set<int>set2;
			Set<int>set3 = set1 * set2;
			Assert::AreEqual(set3.count(), (size_t)0);
			Assert::IsTrue(set3.isEmpty());
			Assert::IsFalse(set3.isInSet(1));
			Assert::IsFalse(set3.isInSet(9));
			Assert::IsFalse(set3.isInSet(3));
			Assert::IsFalse(set3.isInSet(8));
		}
		TEST_METHOD(TestIntersectionEmptySets)
		{
			Set<int>set1;
			Set<int>set2;
			Set<int>set3 = set1 * set2;
			Assert::AreEqual(set3.count(), (size_t)0);
			Assert::IsTrue(set3.isEmpty());
			Assert::IsFalse(set3.isInSet(1));
			Assert::IsFalse(set3.isInSet(9));
			Assert::IsFalse(set3.isInSet(3));
			Assert::IsFalse(set3.isInSet(8));
		}

		TEST_METHOD(TestIsInSetTrue)
		{
			Set<int>testSet;
			testSet += 5;
			testSet += 7;
			Assert::IsTrue(testSet.isInSet(5));
			Assert::IsTrue(testSet.isInSet(7));
		}
		TEST_METHOD(TestIsInSetFalse)
		{
			Set<int>testSet;
			testSet += 5;
			testSet += 7;
			Assert::IsFalse(testSet.isInSet(9));
			Assert::IsFalse(testSet.isInSet(8));
		}
		TEST_METHOD(TestIsEmptyTrue)
		{
			Set<int>testSet;
			Assert::IsTrue(testSet.isEmpty());
		}
		TEST_METHOD(TestIsEmptyFalse)
		{
			Set<int>testSet;
			testSet += 9;
			Assert::IsFalse(testSet.isEmpty());
		}
		TEST_METHOD(TestCountEmptySet)
		{
			Set<int>set1;
			Assert::AreEqual(set1.count(), (size_t)0);
		}
		TEST_METHOD(TestCountNotEmptySet)
		{
			Set<int>set1;
			set1 += 6;
			set1 += 9;
			Assert::AreEqual(set1.count(), (size_t)2);
		}
		TEST_METHOD(TestInsertionOperatorEmptySet)
		{
			std::stringstream out;
			Set<int>testSet;
			out << testSet;
			Assert::AreEqual(out.str(), (std::string)"{}");
		}
		TEST_METHOD(TestInsertionOperatorNotEmpty)
		{
			std::vector<int> numbers = { 1, 2, 19 };
			Set<int>set1(numbers);
			std::stringstream out;
			out << set1;
			Assert::AreEqual(out.str().length(), (size_t)10);
		}
		TEST_METHOD(TestComplementSetNormal)
		{
			std::vector<int> numbers1 = { 1, 2, 3, 4 };
			Set<int> set1(numbers1);
			std::vector<int> numbers2 = { 1, 2, 3, 4, 6, 7, 8 };
			Set<int> set2(numbers2);
			Set<int> resultSet = set1.complement(set2);
			Assert::AreEqual(resultSet.count(), (size_t)3);
			Assert::IsTrue(resultSet.isInSet(6));
			Assert::IsTrue(resultSet.isInSet(7));
			Assert::IsTrue(resultSet.isInSet(8));
			Assert::IsFalse(resultSet.isEmpty());
		}
		TEST_METHOD(TestComplementNotSuperset)
		{
			std::vector<int> numbers1 = { 1, 2, 3, 4 };
			Set<int> set1(numbers1);
			std::vector<int> numbers2 = { 1, 2, 3, 4, 6, 7, 8 };
			Set<int> set2(numbers2);
			try
			{
				set2.complement(set1);
				Assert::Fail();
			}
			catch (std::domain_error)
			{
				Assert::IsTrue(true);
			}
		}
	};
}
