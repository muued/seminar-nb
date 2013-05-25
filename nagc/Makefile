CC = icc
CFLAGS += $(FLAGS_NAG_INCLUDE)
LDFLAGS += $(FLAGS_NAG_LINKER) -lpthread

all: g08cbce g08cgce

g08cbce: g08cbce.o
g08cbce.o: g08cbce.c

g08cgce: g08cgce.o
g08cgce.o: g08cgce.c

