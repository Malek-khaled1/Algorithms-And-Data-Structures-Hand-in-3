#ifndef _INSERTION_SORT_H_
#define _INSERTION_SORT_H_
#include <vector>
#include <functional>
#include <iostream>

using namespace std;

/**
 * Simple insertion sort.
 */
template <typename Comparable>
void insertionSort(vector<Comparable> &a) {
	for (int p = 1; p < a.size(); ++p) {
		Comparable tmp = std::move(a[p]);

		int j;
		for (j = p; j > 0 && tmp < a[j - 1]; --j) {
			a[j] = std::move(a[j - 1]);
		}
		a[j] = std::move(tmp);
	}
}

template<typename Comparable>
void selected_sort(vector<Comparable> &a)
{
	
	for(int i = 0;  i< a.size() - 1; ++i) { // For loop will iterate N - 1 times
		// Assume current position holds
		// the minimum element
		int min_index = i;

		for (int j = i + 1; j < a.size(); ++j)
		{
			if(a[j] < a[min_index]){min_index = j;}
		}
		// Swap minimum element with element a[i]
		Comparable temp = std::move(a[min_index]);
		a[min_index] = std::move(a[i]);
		a[i] = std::move(temp);
	}
}

void printVector(const vector<int>& v) {
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";
}

/*
 * This is the more public version of insertion sort.
 * It requires a pair of iterators and a comparison
 * function object.
 */
template <typename Iterator, typename Comparator>
void insertionSort(const Iterator& begin, const Iterator& end, Comparator less){
	if (begin == end)
		return;

	for (Iterator j, p = begin + 1; p != end; ++p) {
		auto tmp = std::move(*p);
		for (j = p; j != begin && less(tmp, *(j - 1)); --j)
			*j = std::move(*(j - 1));
		*j = std::move(tmp);
	}
}

/*
 * The two-parameter version calls the three parameter version, using C++11.
 */
template <typename Iterator >
void insertionSort(const Iterator& begin, const Iterator& end) {
	insertionSort(begin, end, less<decltype(*begin)> { });
}

#endif
