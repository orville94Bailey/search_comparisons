#include "stdafx.h"
#include "heap.h"


heap::heap()
{
}

int heap::left(int position)
{
	if (position * 2 + 1 < storage.size())
	{
		return storage[position * 2 + 1];
	}
}

int heap::right(int position)
{
	if (position * 2 + 2 < storage.size())
	{
		return storage[position * 2 + 2];
	}
}

int heap::parent(int position)
{
	if (position > 0)
	{
		return storage[(position - 1) / 2];
	}
}

void heap::min_insert(int data)
{
	if (storage.size() == 0)
	{
		storage.push_back(data);
		return;
	}

	int to_insert_local = storage.size();
	int parent = (to_insert_local - 1) / 2;
	int holder;
	storage.push_back(data);

	while (data < storage[parent])
	{
		holder = storage[parent];
		storage[parent] = storage[to_insert_local];
		storage[to_insert_local] = holder;
		to_insert_local = parent;
		parent = (parent - 1) / 2;
	}
}

void heap::max_insert(int data)
{
	if (storage.size() == 0)
	{
		storage.push_back(data);
		return;
	}

	int to_insert_local = storage.size();
	int parent = (to_insert_local - 1) / 2;
	int holder;
	storage.push_back(data);

	while (data > storage[parent])
	{
		holder = storage[parent];
		storage[parent] = storage[to_insert_local];
		storage[to_insert_local] = holder;
		to_insert_local = parent;
		parent = (parent - 1) / 2;
	}
}

int heap::top()
{
	if (storage.size() > 0)
	{
		return storage[0];
	}
}

int heap::compare_children(bool is_max, int parent_local)
{
	if (is_max)
	{
		if (left(parent_local) > right(parent_local))
		{
			if (left(parent_local) > storage[parent_local])
			{
				return parent_local * 2 + 1;
			}
			else
			{
				return -1;
			}
		}
		else
		{
			if (right(parent_local) > storage[parent_local])
			{
				return parent_local * 2 + 2;
			}
			else
			{
				return -1;
			}
		}
	}
	else
	{
		if (left(parent_local) < right(parent_local))
		{
			if (left(parent_local) < storage[parent_local])
			{
				return parent_local * 2 + 1;
			}
			else
			{
				return -1;
			}
		}
		else
		{
			if (right(parent_local) < storage[parent_local])
			{
				return parent_local * 2 + 2;
			}
			else
			{
				return -1;
			}
		}
	}
	return 0;
}

void heap::min_delete()
{
	if (storage.size() > 2)
	{
		storage[0] = storage[storage.size() - 1];
		storage.pop_back();

		int swap_local,
			sub_tree_start = 0,
			holder;

		swap_local = compare_children(false, sub_tree_start);

		while (swap_local < storage.size() - 1 && swap_local > -1)
		{
			holder = storage[sub_tree_start];
			storage[sub_tree_start] = storage[swap_local];
			storage[swap_local] = holder;
			sub_tree_start = swap_local;
			swap_local = compare_children(false, sub_tree_start);
		}
	}
	else if (storage.size() == 2)
	{
		storage[0] = storage[storage.size() - 1];
		storage.pop_back();
	}
	else if (storage.size() == 1)
	{
		storage.pop_back();
	}
	else
	{
		return;
	}
}

void heap::max_delete()
{
	if (storage.size() > 2)
	{
		storage[0] = storage[storage.size() - 1];
		storage.pop_back();

		int swap_local,
			sub_tree_start = 0,
			holder;

		swap_local = compare_children(true, sub_tree_start);

		while (swap_local < storage.size() - 1 && swap_local > -1)
		{
			holder = storage[sub_tree_start];
			storage[sub_tree_start] = storage[swap_local];
			storage[swap_local] = holder;
			sub_tree_start = swap_local;
			swap_local = compare_children(true, sub_tree_start);
		} 
	}
	else if (storage.size() == 2)
	{
		storage[0] = storage[storage.size() - 1];
		storage.pop_back();
	}
	else if (storage.size() == 1)
	{
		storage.pop_back();
	}
	else
	{
		return;
	}
}


void heap::preorder(int local)
{
	if (local > storage.size() - 1)
	{
		return;
	}
	else
	{
		cout << storage[local] << ", ";
		preorder(local * 2 + 1);
		preorder(local * 2 + 2);
	}
}

void heap::inorder(int local)
{
	if (local > storage.size() - 1)
	{
		return;
	}
	else
	{
		inorder(local * 2 + 1);
		cout << storage[local] << ", ";
		inorder(local * 2 + 2);
	}
}

void heap::postorder(int local)
{
	if (local > storage.size() - 1)
	{
		return;
	}
	else
	{
		postorder(local * 2 + 1);
		postorder(local * 2 + 2);
		cout << storage[local] << ", ";
	}
}

heap::~heap()
{
}
