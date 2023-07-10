auto_cor = readtable("random_correlation_3.csv");
k = auto_cor{:, 1};
lcg = auto_cor{:, 2};
cpp = auto_cor{:, 3};

plot(k, lcg, "LineWidth", 1)
title("LCG RNG", "interpreter", "latex")
xlabel("Lag (\textit{k})", "interpreter", "latex")
ylabel("Auto-correlation [\textit{C(k)}]", "interpreter", "latex")

figure 

plot(k, cpp, "LineWidth", 1)
title("C++ RNG", "interpreter", "latex")
xlabel("Lag (\textit{k})", "interpreter", "latex")
ylabel("Auto-correlation [\textit{C(k)}]", "interpreter", "latex")
