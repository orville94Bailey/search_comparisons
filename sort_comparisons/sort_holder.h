#pragma once
#include <vector>
#include "heap.h"
#include <time.h>

using std::vector;

class sort_holder
{
public:
	sort_holder();
	~sort_holder();
	float insertion_sort(vector<int>);
	float bubble_sort(vector<int>);
	float selection_sort(vector<int>);
	float shell_sort(vector<int>);
	float merge_sort(vector<int>);
	float quick_sort(vector<int>);
	float heap_sort(vector<int>);
private:
	clock_t start,
		finish;
};

