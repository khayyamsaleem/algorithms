#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class MyPoint {

public:
	//constructor that uses an initializer list
	MyPoint(int x, int y, float z) : x_(x), y_(y), z_(z) { }

	//methods that do not modify member variables should be declared const
	void print_coords() const {
		cout << "(x, y, z) = (" << x_ << ", " << y_ << ", " << fixed << setprecision(2) << z_ << ")" << endl;

	}
	
	//mutator
	void set_x(int x) {
		x_ = x;
	}
	
	//accessor
	int get_x() const {
		return x_;
	}

private: 
	//Member variables (fields). Use the trailing _ for these variables.
	int x_, y_;
	float z_;

};

void display_points(vector<MyPoint> &points) {
	for (vector<MyPoint>::const_iterator it = points.begin(); it != points.end(); ++it) {
		it->print_coords();
	}
}

int main() {
	int x, y;

	MyPoint point1(5, 7, 1.9823412);
	MyPoint point2(1, 2, 3);
	MyPoint point3(4, 5, 6);

	vector<MyPoint> points;
	points.push_back(point1);
	points.push_back(point2);
	points.push_back(point3);

	vector<MyPoint> points_above_two;
	for (vector<MyPoint>::const_iterator it = points.begin(); it != points.end(); ++it) {
		if (it->get_x() > 2) {
			points_above_two.push_back(*it);
		}
	}

	display_points(points_above_two);
	
	cout << "Input x: ";
	cin >> x;

	cout << "Input y: ";
	cin >> y;

	MyPoint somePoint(x, y, 7);
	somePoint.print_coords();
}
