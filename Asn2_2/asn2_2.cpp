#include <iostream>
#include <cmath>
#include <random>
#include <fstream>
using namespace std;

int main() {
	long long int v_i, m;
	long double x_i, random_num;
	int c, a, N;
	const int M = 10;

	fstream uniform_file;

	N = (int) pow(10, 5);
	double bins_1[M] = { 0.0 };
	double bins_2[M] = { 0.0 };
	double delta = 1.0 / M;

	v_i = 1;
	m = (long long int) pow(2, 31);
	a = 65539;
	c = 0;

	default_random_engine generator(v_i);
	uniform_real_distribution<double> distribution(0.0, 1.0);

	for (int i = 1; i <= N; i++) {
		v_i = (a * v_i + c) % m;
		x_i = ((long double)v_i) / m;
		random_num = distribution(generator);

		if (x_i <= delta) {
			bins_1[0] += 1.0;
		}
		else if (x_i <= delta * 2.0) {
			bins_1[1] += 1.0;
		}
		else if (x_i <= delta * 3.0) {
			bins_1[2] += 1.0;
		} 
		else if (x_i <= delta * 4.0) {
			bins_1[3] += 1.0;
		}
		else if (x_i <= delta * 5.0) {
			bins_1[4] += 1.0;
		}
		else if (x_i <= delta * 6.0) {
			bins_1[5] += 1.0;
		}
		else if (x_i <= delta * 7.0) {
			bins_1[6] += 1.0;
		}
		else if (x_i <= delta * 8.0) {
			bins_1[7] += 1.0;
		}
		else if (x_i <= delta * 9.0) {
			bins_1[8] += 1.0;
		}
		else {
			bins_1[9] += 1.0;
		}

		if (random_num <= delta) {
			bins_2[0] += 1.0;
		}
		else if (random_num <= delta * 2.0) {
			bins_2[1] += 1.0;
		}
		else if (random_num <= delta * 3.0) {
			bins_2[2] += 1.0;
		}
		else if (random_num <= delta * 4.0) {
			bins_2[3] += 1.0;
		}
		else if (random_num <= delta * 5.0) {
			bins_2[4] += 1.0;
		}
		else if (random_num <= delta * 6.0) {
			bins_2[5] += 1.0;
		}
		else if (random_num <= delta * 7.0) {
			bins_2[6] += 1.0;
		}
		else if (random_num <= delta * 8.0) {
			bins_2[7] += 1.0;
		}
		else if (random_num <= delta * 9.0) {
			bins_2[8] += 1.0;
		}
		else {
			bins_2[9] += 1.0;
		}
	}

	uniform_file.open("uniform_2.csv", ios::out | ios::app);

	for (int i = 0; i < 10; i++) {
		uniform_file << (i + 1) << "," << bins_1[i] << "," << bins_2[i] << "\n";
	}

	uniform_file.close();


	return 0;
}