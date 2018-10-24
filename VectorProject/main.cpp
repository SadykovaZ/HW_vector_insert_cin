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
	system("pause");
}