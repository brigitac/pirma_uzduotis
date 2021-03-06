CC = clang++
CXXFLAGS = -c -Wall -Weverything -Wno-c++98-compat -std=c++11

all: main_v.o galbalas.o ivedimas.o sukurimas.o
	$(CC) $^
main_v.o: main_v.cpp galbalas.h ivedimas.h failai.h struktura.h sukurimas.h
	$(CC) $(CXXFLAGS) $<
galbalas.o: galbalas.cpp galbalas.h
	$(CC) $(CXXFLAGS) $<
ivedimas.o: ivedimas.cpp ivedimas.h galbalas.h
	$(CC) $(CXXFLAGS) $<
sukurimas.o: sukurimas.cpp sukurimas.h
	$(CC) $(CXXFLAGS) $<
clean:
	rm -f *.o $@
