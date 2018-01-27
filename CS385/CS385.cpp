#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(void) {
	int x;
	int y;
	int z;
	puts("Hello World");
	cout << "Enter a number:" << endl;
	cin >> x;
	cout << "Enter another number:" << endl;
	cin >> y;
	cout << "The sum of the numbers is:" << endl;
	z = x + y;
	cout << z << endl;
	for (int i = 1; i <= z; i++){
		cout << i << endl;;
	};
	return EXIT_SUCCESS;
}
