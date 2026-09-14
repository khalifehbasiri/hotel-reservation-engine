CXX ?= g++
CXXFLAGS ?= -std=c++11 -Wall -Wextra -pedantic
SOURCES := $(wildcard *.cc)
TARGET := build/hotel-demo

all: $(TARGET)

$(TARGET): $(SOURCES) $(wildcard *.h)
	mkdir -p build
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

run: all
	./$(TARGET)

.PHONY: all run
