#include <iostream>
#include <cmath>
#include <random>
#include <fstream>
using namespace std;

int main() {
	long long int v_i, m;
	long double x_i, random_num;
	int c, a;

	const int N = 50000;

	double rand_LCG[N] = { 0.0 };
	double rand_cpp[N] = { 0.0 };

	
	double x_i_avg = 0.0;
	double random_num_avg = 0.0;
	double x_i_2 = 0.0;
	double random_num_2 = 0.0;

	v_i = 1;
	m = 6075;
	a = 106;
	c = 1283;

	fstream autocor_file("random_correlation_3.csv", ios::out | ios::app);
	default_random_engine generator(v_i);
	uniform_real_distribution<double> distribution(0.0, 1.0);

	for (int i = 0; i < N; i++) {
		v_i = (a * v_i + c) % m;
		x_i = ((long double)v_i) / m;
		random_num = distribution(generator);
		
		x_i_avg += x_i;
		random_num_avg += random_num;

		x_i_2 += x_i * x_i;
		random_num_2 += random_num * random_num;

		rand_LCG[i] = x_i;
		rand_cpp[i] = random_num;
	}

	x_i_avg = pow(x_i_avg / N, 2);
	x_i_2 = x_i_2 / N;
	random_num_avg = pow(random_num_avg / N, 2);
	random_num_2 = random_num_2 / N;

	for (int k = 0; k <= 350; k++) {
		double lagsum1 = 0.0;
		double lagsum2 = 0.0;


		for (int i = 0, index = k; index < N; i++, index++) {
			lagsum1 += rand_LCG[index] * rand_LCG[i];
			lagsum2 += rand_cpp[index] * rand_cpp[i];
		}
		lagsum1 /= N;
		lagsum2 /= N;

		double c_k_LCG = (lagsum1 - x_i_avg) / (x_i_2 - x_i_avg);
		double c_k_cpp = (lagsum2 - random_num_avg) / (random_num_2 - random_num_avg);

		autocor_file << k << "," << c_k_LCG << "," << c_k_cpp << "\n";
	}

	return 0;
}