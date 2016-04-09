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
	for (int i = 0; i < v.size() - 1; i++)
	{
		for (int j = v.size() - 1; j > i; j--)
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

float sort_holder::selection_sort(vector<int> v)
{
	int temp;
	start = clock();
	for (int i = 0; i < v.size() - 1; i++)
	{
		int low_num = i;
		for (int j = v.size() - 1; j > i; j--)
		{
			if (v[j] < v[low_num])
			{
				low_num = j;
			}
		}
		temp = v[low_num];
		v[low_num] = v[i];
		v[i] = temp;
	}
	finish = clock();
	return ((float)finish - (float)start) / CLOCKS_PER_SEC;
}

float sort_holder::shell_sort(vector<int> v)
{
	start = clock();
	for (int i = v.size() / 2; i > 2; i /= 2)
	{
		for (int j = 0; j < i; j++)
		{
			inssort(v, v.size() - j, i);
		}
	}
	inssort(v, v.size(), 1);
	finish = clock();
	return ((float)finish - (float)start) / CLOCKS_PER_SEC;
}

float sort_holder::run_merge(vector<int> v)
{
	start = clock();
	merge_sort(v);
	finish = clock();
	return ((float)finish - (float)start) / CLOCKS_PER_SEC;
}

vector<int> sort_holder::merge_sort(vector<int> v)
{
	if (v.size() == 1)
	{
		return v;
	}

	vector<int>::iterator middle = v.begin() + (v.size() / 2);

	vector<int> left(v.begin(), middle);
	vector<int> right(middle, v.end());

	left = merge_sort(left);
	right = merge_sort(right);

	return merge(left, right);
}

vector<int> sort_holder::merge(vector<int> left, vector<int> right)
{
	vector<int> return_val;
	int left_pos = 0,
		right_pos = 0;

	while ((left_pos < left.size()) && (right_pos < right.size()))
	{
		if (left[left_pos] < right[right_pos])
		{
			return_val.push_back(left[left_pos]);
			left_pos++;
		}
		else
		{
			return_val.push_back(right[right_pos]);
			right_pos++;
		}
	}

	while (left_pos < left.size())
	{
		return_val.push_back(left[left_pos]);
		left_pos++;
	}

	while (right_pos < right.size())
	{
		return_val.push_back(right[right_pos]);
		right_pos++;
	}

	left.clear();
	right.clear();

	return return_val;
}

void sort_holder::run_quick(vector<int> v, int i, int j)
{
	int holder;

	if (j <= i)
	{
		return;
	}
	int pivot_index = find_pivot(v, i, j);
	
	holder = v[pivot_index];
	v[pivot_index] = v[j];

	int k = partition(v, i - 1, j);

	holder = v[k];
	v[k] = v[j];
	v[j] = holder;

	run_quick(v, i, k - 1);
	run_quick(v, k + 1, j);
}

int sort_holder::find_pivot(vector<int> v, int i, int j)
{
	return (i + j) / 2;
}

int sort_holder::partition(vector<int> v, int l, int r)
{
	int holder = v[r];
	int holder_2;
	do {
		while (v[++l] < holder)
		{
			while (l<r && v[--r] > holder)
			{
				holder_2 = v[l];
				v[l] = v[r];
				v[r] = holder;
			}
		}
	} while (l < r);
	return l;
}

float sort_holder::quick_sort(vector<int> v)
{
	start = clock();
	run_quick(v, 0, v.size() - 1);
	finish = clock();
	return ((float)finish - (float)start) / CLOCKS_PER_SEC;
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

void sort_holder::inssort(vector<int> v, int size, int incr)
{
	int holder;
	for (int i = incr; i < size; i += incr)
	{
		for (int j = i; (j >= incr) &&
			(v[j] > v[j - incr]); j -= incr)
		{
			holder = v[j];
			v[j] = v[j - incr];
			v[j - incr] = holder;
		}
	}
}
