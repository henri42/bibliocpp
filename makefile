#nom de l'executable
NAMEPROG=bibliotheque 

#parametres
CXX=g++
CPPFLAGS=-std=c++11 -g
LDFLAGS= -g
LDLIBS=

#sources et objets
SRCS=main.cpp mediatheque.cpp media.cpp livre.cpp vhs.cpp revue.cpp cd_dvd.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: $(NAMEPROG)

$(NAMEPROG): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(NAMEPROG) $^ $(LDLIBS)

main.o: main.cpp mediatheque.hpp media.hpp livre.hpp vhs.hpp revue.cpp

mediatheque.o: mediatheque.cpp mediatheque.hpp

media.o: media.cpp media.hpp

livre.o: livre.cpp livre.hpp

VHS.o: vhs.cpp vhs.hpp

revue.o: revue.cpp revue.hpp

cd_dvd.o: cd_dvd.cpp cd_dvd.hpp

clean:
	rm -f $(OBJS)

distclean: clean
	rm -f tool