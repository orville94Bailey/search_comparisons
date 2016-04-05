#pragma once
#include <vector>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class heap
{
public:
	heap();
	int left(int position);
	int right(int position);
	int parent(int position);
	void min_insert(int data);
	void max_insert(int data);
	int top();
	void min_delete();
	void max_delete();
	//BINARY TREE TRAVERSALS
	void preorder(int local);
	void inorder(int local);
	void postorder(int local);
	~heap();
private:
	std::vector<int> storage;
	int compare_children(bool is_max, int parent_local);
};

