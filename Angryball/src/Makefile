CXX = g++
CXXFLAGS = -std=c++11
TARGET = angryball
SRCS = BallCollision.cpp BrickGenerator.cpp HigestScore.cpp \
       main.cpp Menu.cpp PowerDown.cpp \
       PowerUp.cpp ScoreBoard.cpp game.cpp
INCLUDES = -Iinclude -I../ncurses/include/ncursesw -I../ncurses/include
LIBS = -L../ncurses/lib -lncursesw

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(INCLUDES) $(LIBS)

clean:
	rm -f $(TARGET)
