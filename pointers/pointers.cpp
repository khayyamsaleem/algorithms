#include <iostream>
#include <sstream>

using namespace std;

void display_array(int array[], const int length){
	cout << "[";
	for (int i = 0; i < length; i++){
		if (i != 0) {
		 cout << ", ";
		}
		cout << array[i]; 
	}
	cout << "]" << endl;
}

void display_array_ptr(int array[], const int length) {
	cout << "[";
	for (int *ptr = array, *end = array + length; ptr < end; ptr++){
		if (ptr != array) {
			cout << ", ";
		}
		cout << *ptr;
	}
	cout << "]" << endl;
}

void pass_by_value(int x){
	x = 10;
}

void pass_by_pointer(int *x){
	*x = 20;
}

void pass_by_reference(int &x){
	x = 30;
}

int main() {
	int x = 5, y =6;
	cout << y << endl;
	int *z;
	z = &x;
	cout << z << endl;
	cout << *z << endl;
	cout << "x = " << x << ", y = " << y << endl;
	*z = 7;
	cout << "x = " << x << ", y = " << y << endl;
	z = &y;
	*z = 7;
	cout << "x = " << x << ", y = " << y << endl;
	cout << z << endl;
	// char = 1 byte;
	// bool = 1 byte;
	// short = 2 bytes;
	// int = 4 bytes;
	// float = 4 bytes;
	// double = 8 bytes;
	int *values = new int[y];
	for (int i = 0; i < y; i++) {
		values[i] = i;
	}
	display_array(values, y);
	delete [] values;

	x = 5;
	pass_by_value(x);
	cout << x << endl;

	x = 5;
	pass_by_pointer(&x);
	cout << x << endl;

	x = 5;
	pass_by_reference(x);
	cout << x << endl;
}

