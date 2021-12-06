#include <iostream>
#include <ctime>
#include "SortingAlgoritms.h"

int main()
{
    //example of work
    int example_array[5] = { 0,8,3,6,3 };
    std::cout << "We have an array of 5 elements: \n";
    for (int i = 0; i < 5; i++) {
        std::cout << example_array[i] << ' ';
    }
    std::cout << '\n';
    bubble_sort(example_array, 5);
    std::cout << "Array after bubble sort: \n";
    for (int i = 0; i < 5; i++) {
        std::cout << example_array[i] << ' ';
    }
    std::cout << '\n';

    example_array[0] = 0;
    example_array[1] = 8;
    example_array[2] = 3;
    example_array[3] = 6;
    example_array[4] = 3;
    quick_sort(example_array, 5);
    std::cout << "Array after return to original state and quick sort: \n";
    for (int i = 0; i < 5; i++) {
        std::cout << example_array[i] << ' ';
    }
    std::cout << '\n';

    example_array[0] = 0;
    example_array[1] = 8;
    example_array[2] = 3;
    example_array[3] = 6;
    example_array[4] = 3;
    bogo_sort(example_array, 5);
    std::cout << "Array after return to original state and bogo sort: \n";
    for (int i = 0; i < 5; i++) {
        std::cout << example_array[i] << ' ';
    }
    std::cout << '\n';

    std::cout << "Finding index of 6 with binary search: \n";
    std::cout << binary_search(example_array, 5, 6) << '\n';

    char example_char_array[10] = { 'a','a','a','b','c','c','b','a','c','d' };
    std::cout << "Random char array: \n";
    for (int i = 0; i < 10; i++) {
        std::cout << example_char_array[i] << ' ';
    }
    std::cout << '\n';
    counting_sort(example_char_array, 10);
    std::cout << "Random char array after counting sort: \n";
    for (int i = 0; i < 10; i++) {
        std::cout << example_char_array[i] << ' ';
    }
    std::cout << '\n';

    std::cout << "Comparison of the speed of algorithms \"Bubble sort\" and \"Quick sort\": \n";
    srand(time(NULL));
    //bubble sort
    for (int degree = 1; degree <= 4; degree++) {
        long double spended_time = 0;
        for (int i = 0; i < 10; i++) {
            int* Array = new int[pow(10, degree)];
            for (int i = 0; i < pow(10, degree); i++) {
                Array[i] = rand() % 1000;
            }
            clock_t start = clock();
            bubble_sort(Array, pow(10, degree));
            clock_t finish = clock();
            spended_time += (long double)(finish - start) / CLOCKS_PER_SEC;
            delete[] Array;
        }
        spended_time /= 10;
        std::cout << "Bubble sort spend " << spended_time << " seconds to sort " << pow(10, degree) << " elements" << '\n';
    }
    //quick sort
    for (int degree = 1; degree <= 5; degree++) {
        long double spended_time = 0;
        for (int i = 0; i < 10; i++) {
            int* Array = new int[pow(10, degree)];
            for (int i = 0; i < pow(10, degree); i++) {
                Array[i] = rand() % 1000;
            }
            clock_t start = clock();
            quick_sort(Array, pow(10, degree));
            clock_t finish = clock();
            spended_time += (long double)(finish - start) / CLOCKS_PER_SEC;
            delete[] Array;
        }
        spended_time /= 10;
        std::cout << "Quick sort spend " << spended_time << " seconds to sort " << pow(10, degree) << " elements" << '\n';
    }

    std::cout << '\n';
}