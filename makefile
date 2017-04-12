# Nom de l'exÃ©cutable
TARGET=game

CXX=g++
RM=rm -f
CPPFLAGS=-std=c++11 -g
LDFLAGS= -g
LDLIBS=

SRCS=main.cpp mediatheque.cpp media.cpp livre.cpp revue.cpp

# Objets
OBJS=$(subst .cpp,.o,$(SRCS))

$(TARGET): $(OBJS)

# Injecte les dependences si presentes
-include *.d

clean:
	$(RM) $(TARGET) tool

distclean: clean
	$(RM) tool

depends: $(OBJS:.o=.cpp)
	$(CC) -MMD $(CFLAGS) $^
clean-deps: clean
	rm -f *.d





