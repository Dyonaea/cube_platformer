UNAME_S := $(shell uname -s)

CC := g++
CFLAGS = -std=c++17 -g -Wall -Wextra -Wpedantic -Wstrict-aliasing
CFLAGS += -Ilib/SFML/include
LDFLAGS = lib/SFML/build/lib/libsfml-graphics-s.a lib/SFML/build/lib/libsfml-window-s.a lib/SFML/build/lib/libsfml-system-s.a lib/SFML/build/lib/libsfml-audio-s.a -lX11 -lXrandr -lXxf86vm -lXcursor -lXi -pthread -ludev -lfreetype
SRC := $(wildcard src/*.cpp) $(wildcard src/**/*.cpp)
OBJ := $(SRC:.cpp=.o)
BIN := bin

SFML_BUILD_DIR = lib/SFML/build
SFML_LIB_GRAPHICS = $(SFML_BUILD_DIR)/lib/libsfml-graphics-s.a
SFML_LIB_WINDOW = $(SFML_BUILD_DIR)/lib/libsfml-window-s.a
SFML_LIB_SYSTEM = $(SFML_BUILD_DIR)/lib/libsfml-system-s.a
SFML_LIB_AUDIO = $(SFML_BUILD_DIR)/lib/libsfml-audio-s.a

.PHONY: all clean run dirs libs game

all: dirs libs game

dirs:
	mkdir -p $(BIN)

libs: $(SFML_LIB_GRAPHICS) $(SFML_LIB_WINDOW) $(SFML_LIB_SYSTEM) $(SFML_LIB_AUDIO)

$(SFML_LIB_GRAPHICS): $(SFML_LIB_AUDIO)
$(SFML_LIB_WINDOW): $(SFML_LIB_GRAPHICS)
$(SFML_LIB_SYSTEM): $(SFML_LIB_WINDOW)

$(SFML_LIB_AUDIO):
	if [ ! -f $@ ]; then \
		cd lib/SFML && mkdir -p build && cd build && cmake -DBUILD_SHARED_LIBS=OFF .. && make; \
	fi

game: $(OBJ)
	$(CC) -o $(BIN)/game $^ $(LDFLAGS)

run: all
	$(BIN)/game

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(BIN) $(OBJ) $(SFML_BUILD_DIR)