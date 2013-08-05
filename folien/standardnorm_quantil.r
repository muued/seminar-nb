# Standardnormalverteilung
ub <- qnorm(0.75)
x <- seq(-4,4,length=100)
hx <- dnorm(x)
i <- x <= ub
plot(x, hx, typ="l", xlab="X", ylab="Dichte", main="Standardnormalverteilung")
lines(x,rep(0,100))
polygon(c(ub, x[i]), c(0,hx[i]), col="red")
mtext(paste("P(X <=",signif(ub,3),") =",signif(pnorm(ub),3)))
