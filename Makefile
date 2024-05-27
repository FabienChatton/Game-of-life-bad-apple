CC=g++
CFLAGS=
SRC=src
OBJ=obj
SRCS=$(wildcard $(SRC)/*.cpp)
OBJS=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))
LIBS=-lncursesw

BINDIR=bin
BIN_DEV=$(BINDIR)/main_dev
BIN_PROD=$(BINDIR)/main_prod

ifeq ($(OS),Windows_NT)
    RM = del /Q /F
    RM_FILES = $(BINDIR) $(OBJ)
else
    RM_FILES = $(BINDIR)/* $(OBJ)/*
endif

all: dev

dev: CFLAGS += -g -Wall
dev: $(BIN_DEV)

prod: CFLAGS += -O3
prod: $(BIN_PROD)

$(BIN_DEV): $(OBJS) | $(BINDIR)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBS)

$(BIN_PROD): $(OBJS) | $(BINDIR)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBS)

$(OBJ)/%.o: $(SRC)/%.cpp | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(BINDIR):
	mkdir -p $@

$(OBJ):
	mkdir -p $@

clean:
	$(RM) $(RM_FILES)