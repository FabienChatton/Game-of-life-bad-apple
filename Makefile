CC=g++
CFLAGS=-g -Wall
SRC=src
OBJ=obj
SRCS=$(wildcard $(SRC)/*.cpp)
OBJS=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))
LIBS=-lncursesw

BINDIR=bin
BIN=$(BINDIR)/main

ifeq ($(OS),Windows_NT) 
	RM = del /Q /F
	RM_FILES = $(BINDIR) $(OBJ)
else
	RM_FILES = $(BINDIR)/* $(OBJ)/*
endif

all: $(BIN)

$(BIN): $(OBJS) | $(BINDIR)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBS)

$(OBJ)/%.o: $(SRC)/%.cpp | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(BINDIR):
	mkdir $@

$(OBJ):
	mkdir $@

clean:
	$(RM) $(RM_FILES)
