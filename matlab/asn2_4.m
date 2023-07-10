sim1 = readtable("../data/sim1_4.csv");
simN = readtable("../data/simN_4.csv");
%lambda = -(log(simN{:, 1} + 1) ./ log(200)) ./ simN{:, 2}

plot(sim1{:, 1}, sim1{:, 2}, "LineWidth", 1.2)
hold on
plot(simN{:, 1}, simN{:, 2}, "LineWidth", 1.2)
title("Monte Carlo Simulation - Nuclear Decay", "interpreter", "latex")
legend("$$\textit{N(t)}$$", "$$<\textit{N(t)}>$$", "interpreter", "latex")
xlabel("$$\textit{t}$$", "interpreter", "latex")
ylabel("Quantity of Unstable Nuclei", "interpreter", "latex")

figure

semilogy(simN{:, 1}, simN{:, 2}, "LineWidth", 1.2)
hold on
semilogy(simN{:, 1}, (200 .* exp(0.0142 .* simN{:, 1})), "LineWidth", 1.2)
title("Semi-Log Plot of $$<\textit{N(t)}>$$ with Least Squares Fit", "interpreter", "latex")
legend("$$<\textit{N(t)}>$$", "Least Squares Fit", "interpreter", "latex")
xlabel("$$\textit{t}$$", "interpreter", "latex")
ylabel("$$\log_{10}$$ of the Quantity of Unstable Nuclei", "interpreter", "latex")


