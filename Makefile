SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -w -g  -I$(INC) -c
#CPPFLAGS = -Wall -g  -I$(INC) -c

all: $(BIN)/testdiccionario

$(BIN)/testdiccionario: $(SRC)/testdiccionario.cpp $(INC)/ArbolGeneral.h $(INC)/ArbolGeneral.cpp $(INC)/Diccionario.h $(SRC)/Diccionario.cpp
	$(CXX) $(SRC)/testdiccionario.cpp -I./$(INC) -g -o $(BIN)/testdiccionario.cpp 

#$(BIN)/testdiccionario : $(OBJ)/testdiccionario.o $(OBJ)/diccionario.o
#	$(CXX) -o $(BIN)/testdiccionario $(OBJ)/testdiccionario.o -I./$(INC)

#$(OBJ)/testdiccionario.o :  $(SRC)/testdiccionario.cpp $(INC)/diccionario.h
#	$(CXX) $(CPPFLAGS)  -o $(OBJ)/testdiccionario.o $(SRC)/testdiccionario.cpp -I./$(INC)

#$(OBJ)/diccionario.o : $(SRC)/diccionario.cpp $(INC)/diccionario.h $(INC)/ArbolGeneral.h
#	$(CXX) $(CPPFLAGS)  -o $(OBJ)/diccionario.o $(SRC)/diccionario.cpp -I./$(INC)

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
