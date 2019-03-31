CC=g++
CFLAGS = -Wall -Wpedantic -Wextra -lstdc++fs -std=c++17
SRCS = Album.cpp Song.cpp Splice.cpp CsvParse.cpp lib/FFmpegWrapper.cpp lib/YoutubedlWrapper.cpp FFmpegParse.cpp main.cpp
OBJS=$(sbst .cpp,.o,$(SRCS))
vidCutter:
	@echo "Creating objects.."
	$(CC) -c $(SRCS) $(CFLAGS)
	$(CC)  -o vidCutter Album.o Song.o Splice.o FFmpegWrapper.o YoutubedlWrapper.o CsvParse.o FFmpegParse.o main.o $(CFLAGS)
clean:
	@echo "Cleaning up.."
	rm *.o
	rm lib/*.o
