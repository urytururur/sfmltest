CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -g -I$(INCLUDE)

INCLUDE = /usr/include	#headerfile-includes
LDFLAGS = -L/usr/lib/arm-linux-gnueabihf/libsfml-audio.so /usr/lib/arm-linux-gnueabihf/libsfml-graphics.so /usr/lib/arm-linux-gnueabihf/libsfml-network.so /usr/lib/arm-linux-gnueabihf/libsfml-system.so /usr/lib/arm-linux-gnueabihf/libsfml-window.so	#library-includes

#object files (.o)
OBJ = client.o

client: $(OBJ)
	$(CXX) $(OBJ) $(LDFLAGS) -o client

client.o: client.cc
	$(CXX) -c client.cc $(LDFLAGS)