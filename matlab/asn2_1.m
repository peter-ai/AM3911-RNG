randu_data = readtable("randu_1.csv");
X = randu_data{:, 1};
Y = randu_data{:, 2};
Z = randu_data{:, 3};
scatter3(X, Y, Z, 10, "b", "LineWidth", 0.25);