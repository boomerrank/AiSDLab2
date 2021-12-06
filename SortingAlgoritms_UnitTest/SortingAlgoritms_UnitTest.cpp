#include "CppUnitTest.h"
#include "../AiSDLab2/SortingAlgoritms.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingAlgoritmsUnitTest
{
	TEST_CLASS(SortingAlgoritmsUnitTest)
	{
	public:
		
		TEST_METHOD(binary_search_Test)
		{
			int test_array[500];
			for (int i = 0; i < 500; i++) {
				test_array[i] = i + 1;
			}
			Assert::IsTrue(binary_search(test_array, 500, 395) == 394);
			Assert::IsTrue(binary_search(test_array, 500, 150) == 149);
			Assert::IsTrue(binary_search(test_array, 500, 500) == 499);
			Assert::IsTrue(binary_search(test_array, 500, 1) == 0);
		}

		TEST_METHOD(bogo_sort_Test) {
			int test_array[5] = { 1,8,3,3,6 };
			bogo_sort(test_array, 5);
			Assert::IsTrue(test_array[0] == 1);
			Assert::IsTrue(test_array[1] == 3);
			Assert::IsTrue(test_array[2] == 3);
			Assert::IsTrue(test_array[3] == 6);
			Assert::IsTrue(test_array[4] == 8);
		}

		TEST_METHOD(bubble_sort_Test) {
			int test_array[5] = { 1,8,3,3,6 };
			bubble_sort(test_array, 5);
			Assert::IsTrue(test_array[0] == 1);
			Assert::IsTrue(test_array[1] == 3);
			Assert::IsTrue(test_array[2] == 3);
			Assert::IsTrue(test_array[3] == 6);
			Assert::IsTrue(test_array[4] == 8);
		}

		TEST_METHOD(counting_sort_Test) {
			char test_array[10] = { 'a','a','a','b','c','c','b','a','c','d' };
			counting_sort(test_array, 10);
			Assert::IsTrue(test_array[0] == 'a');
			Assert::IsTrue(test_array[1] == 'a');
			Assert::IsTrue(test_array[2] == 'a');
			Assert::IsTrue(test_array[3] == 'a');
			Assert::IsTrue(test_array[4] == 'b');
			Assert::IsTrue(test_array[5] == 'b');
			Assert::IsTrue(test_array[6] == 'c');
			Assert::IsTrue(test_array[7] == 'c');
			Assert::IsTrue(test_array[8] == 'c');
			Assert::IsTrue(test_array[9] == 'd');
		}

		TEST_METHOD(quick_sort_Test) {
			int test_array[5] = { 1,8,3,3,6 };
			quick_sort(test_array, 5);
			Assert::IsTrue(test_array[0] == 1);
			Assert::IsTrue(test_array[1] == 3);
			Assert::IsTrue(test_array[2] == 3);
			Assert::IsTrue(test_array[3] == 6);
			Assert::IsTrue(test_array[4] == 8);
		}
	};
}
