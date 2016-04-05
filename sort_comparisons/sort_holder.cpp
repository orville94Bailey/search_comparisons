#include "stdafx.h"
#include "sort_holder.h"


sort_holder::sort_holder()
{
}


sort_holder::~sort_holder()
{
}

float sort_holder::insertion_sort(vector<int> v)
{
	int holder;
	start = clock();
	for (int i = 1; i < v.size(); i++)
	{
		for (int j = i; (j> 0) && (v[j] > v[j - 1]); j--)
		{
			holder = v[j];
			v[j] = v[j - 1];
			v[j - 1] = holder;
		}
	}
	finish = clock();
	return((float)finish - (float)start) / CLOCKS_PER_SEC;
}

float sort_holder::bubble_sort(vector<int> v)
{
	int holder;
	start = clock();
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = v.size() - 1; j > i; j)
		{
			if (v[j] < v[j - 1])
			{
				holder = v[j];
				v[j] = v[j - 1];
				v[j - 1] = holder;
			}
		}
	}
	finish = clock();
	return((float)finish - (float)start) / CLOCKS_PER_SEC;
}

float sort_holder::selection_sort(vector<int>)
{
	return 0;
}

float sort_holder::shell_sort(vector<int>)
{
	return 0;
}

float sort_holder::merge_sort(vector<int>)
{
	return 0;
}

float sort_holder::quick_sort(vector<int>)
{
	return 0;
}

float sort_holder::heap_sort(vector<int> v)
{
	heap h;
	int size = v.size();
	start = clock();
	for (int i = 0; i < size; i++)
	{
		h.min_insert(v.back());
		v.pop_back();
	}

	for (int i = 0; i < size; i++)
	{
		v.push_back(h.top());
		h.min_delete();
	}
	finish = clock();
	return((float)finish - (float)start) / CLOCKS_PER_SEC;
}
