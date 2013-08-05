# Standardnormalverteilung leer
x <- seq(-4,4,length=100)
hx <- dnorm(x)
plot(x, hx, typ="l", xlab="X", ylab="Dichte", main="Standardnormalverteilung")
