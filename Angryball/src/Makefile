CXX = g++
CXXFLAGS = -std=c++11
TARGET = angryball
SRCS = BallCollision.cpp BrickGenerator.cpp HigestScore.cpp \
       main.cpp Menu.cpp PowerDown.cpp \
       PowerUp.cpp ScoreBoard.cpp
INCLUDES = -Iinclude -I../ncurses/include/ncursesw -I../ncurses/include
LIBS = -L../ncurses/lib -lncursesw

# Default target
all: $(TARGET)

# Build the target
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(INCLUDES) $(LIBS)

# Clean up build files
clean:
	rm -f $(TARGET)