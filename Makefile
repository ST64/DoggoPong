CXX=g++
CXXFLAGS=-O3 -std=c++11
LDFLAGS=-lsfml-window -lsfml-system -lsfml-graphics
SRC=doggopong.cpp
all:
	$(CXX) $(SRC) -o doggopong $(CXXFLAGS) $(LDFLAGS)

