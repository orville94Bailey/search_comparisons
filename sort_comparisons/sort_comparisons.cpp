// sort_comparisons.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "sort_holder.h"
#include <time.h>
#include <iostream>
#include <random>

using std::cin;
using std::cout;
using std::endl;

vector<int> v;
sort_holder sort;

void seed_v(int num);

const int seed_num = 1000000;

int main()
{
	std::srand(time(NULL));

	//seed_v(seed_num);
	//cout << "bubble sort time: " << sort.bubble_sort(v) << endl;

	seed_v(seed_num);
	cout << "heap sort time: " << sort.heap_sort(v) << endl;

	seed_v(seed_num);
	cout << "insertion sort time: " << sort.insertion_sort(v) << endl;

	cin.sync();
	cin.get();

    return 0;
}

void seed_v(int num)
{
	v.clear();
	for (int i = 0; i < num; i++)
	{
		v.push_back(rand() % 10000);
	}
}