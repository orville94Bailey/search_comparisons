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
	float run_merge(vector<int> v);
	float quick_sort(vector<int> v);
	float heap_sort(vector<int>);
private:
	clock_t start,
		finish;
	void inssort(vector<int> v, int size, int incr);
	vector<int> merge_sort(vector<int>);
	vector<int> merge(vector<int>, vector<int>);
	void run_quick(vector<int> v, int i, int j);
	int find_pivot(vector<int> v, int i, int j);
	int partition(vector<int> v, int l, int r);
};

