op <- options(warn = -1);
cat("Values :\n");
x <- c(1, 1.1, 1.2, 1.6, 1.7, 2.1, 2.1, 2.4, 2.4, 2.5, 2.6, 2.6, 2.6, 2.7, 2.8, 3, 3.3, 3.5, 3.8, 4.2);
cat(x,"\n")
y <- "pnorm";
mean <- 3.5;
sd <- 1;
cat("Franz' values:\n");
result_franz <-ks.test(x,y,mean,sd,alternative="two.sided");
cat("statistic ",result_franz$statistic," p-value: ",result_franz$p.value,"\n");
mean <- 3;
sd <-0.7;
cat("Pauls values:\n");
result_paul <- ks.test(x,y,mean,sd,alternative="two.sided")
cat("statistic ",result_paul$statistic," p-value: ",result_paul$p.value,"\n");
options(op);