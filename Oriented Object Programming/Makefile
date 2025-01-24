CXX= g++
CXXFLAGS= -Wall -lgtest -lpthread
OBJS= Arquivo.o Labirinto.o Personagem.o Fantasma.o Pacman.o Partida.o

all: $(OBJS)
	$(CXX) -o ep4 ep4.cpp $(OBJS) $(CXXFLAGS)

Arquivo.o: Arquivo.cpp Arquivo.h
	$(CXX) -c -o $@ $< $(CXXFLAGS)

Labirinto.o: Labirinto.cpp Labirinto.h
	$(CXX) -c -o $@ $< $(CXXFLAGS)

Personagem.o: Personagem.cpp Personagem.h
	$(CXX) -c -o $@ $< $(CXXFLAGS)

Fantasma.o: Fantasma.cpp Fantasma.h
	$(CXX) -c -o $@ $< $(CXXFLAGS)

Pacman.o: Pacman.cpp Pacman.h
	$(CXX) -c -o $@ $< $(CXXFLAGS)

Partida.o: Partida.cpp Partida.h
	$(CXX) -c -o $@ $< $(CXXFLAGS)

tests: $(OBJS)
	echo "*******" > gtest.txt
	echo "   F  *" >> gtest.txt
	echo "*... F*" >> gtest.txt
	echo "*     *" >> gtest.txt
	echo "      *" >> gtest.txt
	echo "   *  *" >> gtest.txt
	echo "      *" >> gtest.txt
	echo "      *" >> gtest.txt
	echo "*******" >> gtest.txt
	[ -z $(tail -c1 gtest.txt) ] && truncate -s-1 gtest.txt
	$(CXX) -o ep4 ep4.cpp $(OBJS) $(CXXFLAGS) -DTESTS

doc:
	doxygen Doxyfile

clean:
	@rm -rf gtest.txt *.o html