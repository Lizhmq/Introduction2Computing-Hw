#include <iostream>
#include <cstring>
using namespace std;

int array[200000];		// 本题不要求掌握，有兴趣的同学可以自学堆
int asize = 0;

void up(int array[], int size, int idx)
{
	while (idx > 0) {
		int parent = (idx - 1) / 2;
		if (array[parent] > array[idx]) {
			swap(array[parent], array[idx]);
			idx = parent;
		} else {
			break;
		}
	}
}

void down(int array[], int size, int idx)
{
	int leftidx = idx * 2 + 1;
	int rightidx = idx * 2 + 2;
	while (leftidx < size) {
		int minidx = rightidx;
		if (rightidx >= size || array[leftidx] < array[rightidx])
			minidx = leftidx;
		if (array[minidx] < array[idx]) {
			swap(array[minidx], array[idx]);
			idx = minidx;
			leftidx = idx * 2 + 1;
			rightidx = idx * 2 + 2;
		} else {
			break;
		}
	}
}

int extract(int array[], int &size)
{
	swap(array[0], array[size - 1]);
	size--;
	down(array, size, 0);
	return array[size];
}

void insert(int array[], int &size, int val)
{
	array[size++] = val;
	up(array, size, size - 1);
	return;
}


void heapify(int array[], int size)
{
	for (int i = (size - 1) / 2; i >= 0; --i)
		down(array, size, i);
	return;
}

int main()
{
	cin >> asize;
	for (int i = 0; i < asize; ++i)
		cin >> array[i];
	heapify(array, asize);
	int k, val;
	char ope[100];
	cin >> k;
	while (k--) {
		cin >> ope;
		if (ope[0] == 'A') {
			cin >> val;
			insert(array, asize, val);
		} else {
			if (asize == 0)
				cout << "NULL" << endl;
			else
				cout << extract(array, asize) << endl;
		}		
	}
	return 0;
}