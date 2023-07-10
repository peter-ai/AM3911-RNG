#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main() {
	long long int v_i, m;
	long double x_i;
	int c, a;
	fstream randu_file;
	
	
	v_i = 1;
	m = (long long int) pow(2, 31);
	a = 65539;
	c = 0;
	randu_file.open("randu.csv", ios::out | ios::app)
		;
	for (int i = 1; i <= 120000; i++) {
		v_i = (a * v_i + c) % m;
		x_i = ((long double)v_i) / m;

		
		if (i % 3 == 0) {
			randu_file << x_i << "\n";
		}
		else {
			randu_file << x_i << ",";
		}
	}
	randu_file.close();

	return 0;
}