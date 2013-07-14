samples <- c(14.6, 15.4, 15.2, 15.8, 17.3, 18.0, 18.7, 19.5, 19.7, 19.9, 20.1, 21.1, 21.7, 22.6, 23.1, 23.2, 24.4, 24.7, 24.8, 25.3);

m <- 20;
v <- 11;
paul_counts <- hist(samples, breaks=c(-9999, m-sqrt(v)*0.6745, m, m+sqrt(v)*0.6745, 9999), plot=FALSE)$counts;
	cat("Paul's hypothesis is ");
if (qchisq(0.9, 3) > chisq.test(paul_counts)$statistic) {
	cat("not ");
}
cat("rejected!\n");

m <- mean(samples);
v <- var(samples);
franz_counts <- hist(samples, breaks=c(-9999, m-sqrt(v)*0.6745, m, m+sqrt(v)*0.6745, 9999), plot=FALSE)$counts;
cat("Franz's hypothesis is ");
if (qchisq(0.9, 1) > chisq.test(franz_counts)$statistic) {
	cat("not ");
}
cat("rejected!\n");
