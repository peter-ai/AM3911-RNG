#include <iostream>
#include <random>
#include <fstream>
using namespace std;

int main() {
	// Define monte carlo parameters
	const int ntrials = 20;
	const int tmax = 200;
	const int N_0 = 200;
	const double p = 0.01;
	int t, unstable_nuclei;

	// Define array to store monte carlo ensemble average
	double nuclei[tmax + 1] = { 0.0 };

	// Define data files
	fstream sim1_file, simN_file;
	sim1_file.open("sim1_4.csv", ios::out | ios::app);
	simN_file.open("simN_4.csv", ios::out | ios::app);


	// Define the system uniform random number generator
	default_random_engine generator;
	uniform_real_distribution<double> distribution(0.0, 1.0);

	// Simulate nuclear decay for ntrials (20)
	for (int iter = 0; iter < ntrials; iter++) {
		unstable_nuclei = N_0;
		nuclei[0] += unstable_nuclei;

		// Run computations at each time step
		for (t = 1; t <= tmax; t++) {
			// Compute probability of decay for each unstable nuclei
			for (int i = 0; i < unstable_nuclei; i++) {
				if (distribution(generator) <= p) {
					unstable_nuclei -= 1;
				}
			}

			// The number of unstable nuclei remaining at the beginning of the t+1 time step
			nuclei[t] += unstable_nuclei;

			// Save the nuclear decay data from the first simulation
			if (iter == 0) {
				if (t == 1) {
					sim1_file << (t - 1) << "," << nuclei[t - 1] << "\n";
				}
				sim1_file << t << "," << nuclei[t] << "\n";
			}
		}
	}

	// Compute ensemble average for monte carlo
	// Save nuclear decay data from monte carlo
	for (t = 0; t <= tmax; t++) {
		nuclei[t] /= ntrials;
		simN_file << t << "," << nuclei[t] << "\n";
	}

	// Close files
	sim1_file.close();
	simN_file.close();
	return 0;
}