
# Compiler settings
CC = g++
CXXFLAGS = -std=c++11 -Wall

# Source files
SRCS = main.cpp LEDTV.cpp SmartTV.cpp TV3D.cpp
OBJS = $(SRCS:.cpp=.o)

# Executable name
APPNAME = myapp

# Default target
all: $(APPNAME)

# Linking
$(APPNAME): $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $^

# Compiling
%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

# Cleaning rules
.PHONY: clean
clean:
	rm -f $(OBJS) $(APPNAME)
