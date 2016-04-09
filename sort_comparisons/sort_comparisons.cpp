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
void check_vector(vector<int> v);

const int seed_mil = 1000000;
const int seed_hund_thous = 100000;
const int seed_thous = 1000;
const int seed_hund = 100;
const int seed_ten = 10;

float bubble_ten,
bubble_hund,
bubble_thous;

float heap_ten,
heap_hund,
heap_thous;

float insertion_ten,
insertion_hund,
insertion_thous;

float selection_ten,
selection_hund,
selection_thous;

float shell_ten,
shell_hund,
shell_thous,
shell_hund_thous;

float merge_ten,
merge_hund,
merge_thous,
merge_hund_thous,
merge_mil;

float quick_ten,
quick_hund,
quick_thous,
quick_hund_thous,
quick_mil;

int main()
{
	std::srand(time(NULL));

	seed_v(seed_ten);
	bubble_ten = sort.bubble_sort(v);

	seed_v(seed_hund);
	bubble_hund = sort.bubble_sort(v);

	seed_v(seed_thous);
	bubble_thous = sort.bubble_sort(v);

	seed_v(seed_ten);
	heap_ten = sort.heap_sort(v);

	seed_v(seed_hund);
	heap_hund = sort.heap_sort(v);

	seed_v(seed_thous);
	heap_thous = sort.heap_sort(v);

	seed_v(seed_ten);
	insertion_ten = sort.insertion_sort(v);

	seed_v(seed_hund);
	insertion_hund = sort.insertion_sort(v);

	seed_v(seed_thous);
	insertion_thous = sort.insertion_sort(v);

	seed_v(seed_ten);
	selection_ten = sort.selection_sort(v);

	seed_v(seed_hund);
	selection_hund = sort.selection_sort(v);

	seed_v(seed_thous);
	selection_thous = sort.selection_sort(v);

	seed_v(seed_ten);
	shell_ten = sort.shell_sort(v);

	seed_v(seed_hund);
	shell_hund = sort.shell_sort(v);

	seed_v(seed_thous);
	shell_thous = sort.shell_sort(v);

	seed_v(seed_hund_thous);
	shell_hund_thous = sort.shell_sort(v);

	seed_v(seed_ten);
	merge_ten = sort.run_merge(v);

	seed_v(seed_hund);
	merge_hund = sort.run_merge(v);

	seed_v(seed_thous);
	merge_thous = sort.run_merge(v);

	seed_v(seed_hund_thous);
	merge_hund_thous = sort.run_merge(v);

	seed_v(seed_mil);
	merge_mil = sort.run_merge(v);

	seed_v(seed_ten);
	merge_ten = sort.quick_sort(v);

	seed_v(seed_hund);
	merge_hund = sort.quick_sort(v);

	seed_v(seed_thous);
	merge_thous = sort.quick_sort(v);

	seed_v(seed_hund_thous);
	merge_hund_thous = sort.quick_sort(v);

	seed_v(seed_mil);
	merge_mil = sort.quick_sort(v);

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

void check_vector(vector<int> v)
{
	int prev_num = v[0];
	for (int i = 1; i < v.size(); i++)
	{
		if (!v[i] > prev_num)
		{
			cout << "Sort is Broken" << endl;
			return;
		}
		prev_num = v[i];
	}
	cout << "Sort Passed" << endl;
}