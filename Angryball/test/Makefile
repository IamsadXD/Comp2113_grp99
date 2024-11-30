CXX = g++
CXXFLAGS = -std=c++11
TARGET = test
SRCS = test.cpp
INCLUDES = -I../ncurses/include
LIBS = -L../ncurses/lib -lncurses
#Aodfianodfinadofi
# Default target
all: $(TARGET)

# Build the target
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(INCLUDES) $(LIBS)

# Clean up build files
clean:
	rm -f $(TARGET)