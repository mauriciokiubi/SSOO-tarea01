#
# Seccion 1
#
# Esta seccion se puede modificar segun
# los requerimientos de su proyecto

CC=cc
SRC=hora.c
CFLAGS=-W -std=c17 
#LIBS=-ldl

TARGET=../hora

BIN=hora
#
# Seccion 2 (NO MODIFICAR!!!)
#
OBJ=$(SRC:.c=.o)

INCLUDES=-I./include -I/opt/local/include
LDFLAGS=-L/usr/local/lib 
LDLIBS=-lpthread

CXXFLAGS=-std=c++17 -Wall -O2

DIR_OBJ=objs

SRCS=$(wildcard *.cc)

OBJS=$(patsubst %.cc,$(DIR_OBJ)/%.o,$(SRCS))



all:  $(TARGET)
	@echo Made [ $? ] OK :\)

$(BIN): $(OBJ)
	$(CC) $(LIBS) $(OBJ) -o $(@)
	@rm -f $(OBJ)
	@rm -f *~

$(TARGET): $(OBJ)
	@echo Linking [$@]
	@$(CXX) -o $@ $^ $(CXXFLAGS) $(LDLIBS) $(LDFLAGS) 

$(DIR_OBJ)/%.o: %.cc
	@echo Compiling [$@]
	@mkdir -p $(DIR_OBJ)
	@$(CXX) -c -o $@ $< $(CXXFLAGS) $(INCLUDES)	
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@rm -f *~
	@rm -f $(BIN)
	
