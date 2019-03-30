CC=g++
CFLAGS = -Wall -Wpedantic -Wextra -lstdc++fs
vidCutter: main.cpp
	$(CC) -std=c++17 -o vidCutter main.cpp $(CFLAGS)
