#include "CppUnitTest.h"
#include "../SetLib/SetLib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace SetLibTest
{
	TEST_CLASS(SetLibTest)
	{
	public:
		
		TEST_METHOD(TestDefaultConstructor)
		{
			Set testSet;
			Assert::AreEqual(testSet.count(), (size_t) 0);
			Assert::IsTrue(testSet.isEmpty());
			Assert::IsFalse(testSet.isInSet(5));
			Assert::IsFalse(testSet.isInSet(0));
		}
		TEST_METHOD(TestVectorArgumentConstructor1)
		{
			std::vector<int> numbers = { 1, 2, 3, 4 };
			Set testSet(numbers);
			Assert::AreEqual(testSet.count(), (size_t) 4);
			Assert::IsTrue(testSet.isInSet(1));
			Assert::IsTrue(testSet.isInSet(4));
			Assert::IsFalse(testSet.isInSet(10));
			Assert::IsFalse(testSet.isEmpty());
		}
		TEST_METHOD(TestVectorArgumentConstructor2)
		{
			std::vector<int> numbers = { 1, 2, 3, 4, 3, 6, 2, 5, 4, 9, 1 };
			Set testSet(numbers);
			Assert::AreEqual(testSet.count(), (size_t) 7);
			Assert::IsTrue(testSet.isInSet(1));
			Assert::IsTrue(testSet.isInSet(4));
			Assert::IsTrue(testSet.isInSet(9));
			Assert::IsFalse(testSet.isEmpty());
			Assert::IsFalse(testSet.isInSet(8));
		}
		TEST_METHOD(TestVectorArgumentConstructor3)
		{
			std::vector<int> numbers = {};
			Set testSet(numbers);
			Assert::AreEqual(testSet.count(), (size_t) 0);
			Assert::IsTrue(testSet.isEmpty());
			Assert::IsFalse(testSet.isInSet(5));
			Assert::IsFalse(testSet.isInSet(0));
		}
		TEST_METHOD(TestSetArgumentConstructor1)
		{
			Set emptySet;
			Set testSet(emptySet);
			Assert::AreEqual(testSet.count(), (size_t) 0);
			Assert::IsTrue(testSet.isEmpty());
			Assert::IsFalse(testSet.isInSet(5));
			Assert::IsFalse(testSet.isInSet(0));
		}
		TEST_METHOD(TestSetArgumentConstructor2)
		{
			std::vector<int> numbers = { 1, 2 , 3, 4 };
			Set sourceSet(numbers);
			Set testSet(sourceSet);
			Assert::AreEqual(testSet.count(), (size_t) 4);
			Assert::IsTrue(testSet.isInSet(2));
			Assert::IsTrue(testSet.isInSet(4));
			Assert::IsFalse(testSet.isInSet(8));
			Assert::IsFalse(testSet.isEmpty());
		}
		TEST_METHOD(TestGetElementsEmpty)
		{
			std::vector<int> numbers = {};
			Set testSet(numbers);
			auto result = testSet.getElements();
			Assert::AreEqual(result.size(), (size_t) 0);
			Assert::IsTrue(result.empty());
		}
		TEST_METHOD(TestGetElementsNormal)
		{
			std::vector<int> numbers = {1, 2, 3, 4, 5};
			Set testSet(numbers);
			auto result = testSet.getElements();
			Assert::AreEqual(result.size(), (size_t) 5);
			Assert::IsFalse(result.empty());
		}
		TEST_METHOD(TestGetElementsNotUniqueNums)
		{
			std::vector<int> numbers = {2, 4, 7, 2, 4, 0, 6, 4, 7};
			Set testSet(numbers);
			auto result = testSet.getElements();
			Assert::AreEqual(result.size(), (size_t) 5);
			Assert::IsFalse(result.empty());
		}
		TEST_METHOD(TestOperatorPlusWithSetUniqueNums)
		{
			std::vector<int> numbers1 = { 1, 2, 3, 4, 5 };
			Set set1(numbers1);
			std::vector<int> numbers2 = { 6, 7, 9 };
			Set set2(numbers2);
			Set set3 = set1 + set2;
			Assert::AreEqual(set3.count(), (size_t) 8);
			Assert::IsTrue(set3.isInSet(3));
			Assert::IsTrue(set3.isInSet(7));
			Assert::IsFalse(set3.isInSet(8));
			Assert::IsFalse(set3.isEmpty());
		}
		TEST_METHOD(TestOperatorPlusWithSetNotUniqueNums)
		{
			std::vector<int> numbers1 = { 1, 2, 3, 4, 5, 8, 9 };
			Set set1(numbers1);
			std::vector<int> numbers2 = { 5, 6, 7, 9 };
			Set set2(numbers2);
			Set set3 = set1 + set2;
			Assert::AreEqual(set3.count(), (size_t) 9);
			Assert::IsTrue(set3.isInSet(3));
			Assert::IsTrue(set3.isInSet(7));
			Assert::IsTrue(set3.isInSet(8));
			Assert::IsFalse(set3.isEmpty());
			Assert::IsFalse(set3.isInSet(0));
		}
	};
}
