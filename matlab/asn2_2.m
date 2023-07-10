uniform_data = readtable("uniform_2.csv");
Y = uniform_data{:, 2:3};

subplot(2, 1, 1);
histogram("BinEdges", 0:0.1:1, "BinCounts", Y(:, 1), "Normalization", "probability")
title("Q1 LCG Pseudo-Random Number Generator")
ylim([0, 0.15])
ylabel("$$\frac{N(i)}{Z}$$", "interpreter", "latex")

subplot(2, 1, 2);
histogram("BinEdges", 0:0.1:1, "BinCounts", Y(:, 2), "Normalization", "probability")
title("C++ Pseudo-Random Number Generator")
ylim([0, 0.15])
ylabel("$$\frac{N(i)}{Z}$$", "interpreter", "latex")
