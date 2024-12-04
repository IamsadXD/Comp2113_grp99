CXX = g++
CXXFLAGS = -std=c++11
TARGET = angryball
SRCS = src/BallCollision.cpp src/BrickGenerator.cpp src/main.cpp \
	src/Menu.cpp src/PowerDown.cpp src/PowerUp.cpp src/ScoreBoard.cpp src/game.cpp
INCLUDES = -Iinclude -Incurses/include/ncursesw -Incurses/include
LIBS = -Lncurses/lib -lncurses
#Change -lncurses to -lncursesw if needed, the former works in mac

# Default target
all: $(TARGET)

# Build the target
$(TARGET): $(SRCS)
	@$(CXX) $(CXXFLAGS) -o $@ $^ $(INCLUDES) $(LIBS)

# Clean up build files
clean:
	@rm -f $(TARGET)
