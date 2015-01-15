SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -w -g  -I$(INC) -c
#CPPFLAGS = -Wall -g  -I$(INC) -c

all: $(BIN)/main

$(BIN)/main : $(OBJ)/main.o
	$(CXX) -o $(BIN)/main $(OBJ)/main.o -I./$(INC) 

$(OBJ)/main.o :  $(SRC)/main.cpp $(INC)/ArbolGeneral.h
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/main.o $(SRC)/main.cpp -I./$(INC)

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
