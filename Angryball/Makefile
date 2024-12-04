CXX = g++
CXXFLAGS = -std=c++11
TARGET = angryball
SRCS = src/BallCollision.cpp src/BrickGenerator.cpp src/HigestScore.cpp \
       src/main.cpp src/Menu.cpp src/PowerBar.cpp src/PowerDown.cpp \
       src/PowerUp.cpp src/ScoreBoard.cpp
INCLUDES = -Iinclude -I./ncurses/include/ncursesw -I./ncurses/include
LIBS = -L./ncurses/lib -lncursesw

# Default target
all: $(TARGET)

# Build the target
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(INCLUDES) $(LIBS)

# Clean up build files
clean:
	rm -f $(TARGET)
