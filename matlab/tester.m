sim1 = readtable("../data/sim1_4.csv");
simN = readtable("../data/simN_4.csv");

semilogy(simN{:, 1}, simN{:, 2}, "LineWidth", 1.2)
hold on
y = 200 .* exp(-0.01 .* simN{:, 1});
semilogy(simN{:, 1}, y, "LineWidth", 1.2)


