#include "vector_.h"
#include <iostream>
using namespace std;

void main() {
	vector_ v(10,7);
	//cin >> v;
	cout << v<<" ";
	cout << endl;	
	v.insert(3,5);
	cout << v;
	cout << endl;
	v.erase(4);
	cout << v;

	vector_ v2(3,111);
	v2 += v;
	vector_ v3;
	v3 = v2 + v;
	cout << v3;

	system("pause");
}