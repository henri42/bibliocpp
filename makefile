#nom de l'executable
NAMEPROG=bibliotheque 

#parametres
CXX=g++
CPPFLAGS=-std=c++11 -g
LDFLAGS= -g
LDLIBS=

#sources et objets
SRCS=main.cpp user.cpp admin.cpp mediatheque.cpp media.cpp livre.cpp vhs.cpp revue.cpp cd_dvd.cpp ressource_num.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: $(NAMEPROG)

$(NAMEPROG): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(NAMEPROG) $^ $(LDLIBS)

main.o: $(SRCS)

mediatheque.o: mediatheque.cpp mediatheque.hpp

admin.o: admin.cpp admin.hpp

user.o: user.cpp user.hpp

media.o: media.cpp media.hpp

livre.o: livre.cpp livre.hpp

VHS.o: vhs.cpp vhs.hpp

revue.o: revue.cpp revue.hpp

cd_dvd.o: cd_dvd.cpp cd_dvd.hpp

ressource_num.o: ressource_num.cpp ressource_num.hpp

clean:
	rm -f $(OBJS)

distclean: clean
	rm -f tool