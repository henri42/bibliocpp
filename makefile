CXX=g++
RM=rm -f
CPPFLAGS=-std=c++11 -g
LDFLAGS= -g
LDLIBS=

SRCS=main.cpp personne.cpp extpersonne.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: main

main: $(OBJS)
	$(CXX) $(LDFLAGS) -o pers $(OBJS) $(LDLIBS) 

main.o: main.cpp personne.h extpersonne.h

extpersonne.o: extpersonne.cpp extpersonne.h personne.h

personne.o: personne.cpp personne.h

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) tool