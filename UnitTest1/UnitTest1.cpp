#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab-7.2.1.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int** arr = new int* [3];
			arr[0] = new int[2]{ 0, 2 };
			arr[1] = new int[2]{ 1, 1 };

			Change(2, 3);
			Assert::AreEqual(0, 1);
		}
	};
}