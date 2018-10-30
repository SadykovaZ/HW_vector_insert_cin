#pragma once
//#include <vector>
#include <iostream>
using namespace std;
class vector_
{
	int* arr;
	int size;
public:
	vector_();
	~vector_();
	vector_(const vector_&v);	
	vector_(int size, int element=0);
	
	bool empty() const;
	int getSize() const;
	void clear();
	void push_back(int number);
	void pop_back();
	void erase(int index);
	void insert(int index, int number);
	int& operator[](int index) const;
	vector_&operator=(const vector_&obj);
	//перемещение
	vector_(vector_&&v);
	vector_& operator=(vector_ &&v);
	vector_& operator+=(const vector_&v);
};
ostream &operator<<(ostream &os, const vector_ & v);
istream& operator>>(istream&is, vector_&d);
vector_ operator + (const vector_&a, const  vector_ &b);
//void f() {
//	std::vector<int> v;
//}