SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -w -g  -I$(INC) -c
#CPPFLAGS = -Wall -g  -I$(INC) -c

#all: $(BIN)/testdiccionario

all: $(BIN)/letras

#$(BIN)/testdiccionario: $(SRC)/testdiccionario.cpp $(INC)/ArbolGeneral.h $(INC)/ArbolGeneral.cpp $(INC)/Diccionario.h $(INC)/Diccionario.cpp
#	$(CXX) $(SRC)/testdiccionario.cpp -I$(INC) -g -o $(BIN)/testdiccionario

$(BIN)/letras: $(SRC)/letras.cpp $(INC)/ArbolGeneral.h $(INC)/ArbolGeneral.cpp $(INC)/Diccionario.h $(INC)/Diccionario.cpp $(INC)/bolsa_letras.h $(INC)/Conjunto_letras.h	
	$(CXX) $(SRC)/letras.cpp -I$(INC) -g -o $(BIN)/letras

#$(BIN)/testdiccionario: $(SRC)/testdiccionario.cpp $(INC)/ArbolGeneral.h $(INC)/ArbolGeneral.cpp $(INC)/Diccionario.h $(SRC)/Diccionario.cpp
#	$(CXX) $(SRC)/testdiccionario.cpp -I./$(INC) -g -o $(BIN)/testdiccionario.cpp 

#$(BIN)/testdiccionario: $(OBJ)/testdiccionario.o $(OBJ)/ArbolGeneral.o $(OBJ)/Diccionario.o
#	$(CXX) -o $(BIN)/testdiccionario $(OBJ)/testdiccionario.o -I./$(INC)

#$(OBJ)/testdiccionario.o :  $(SRC)/testdiccionario.cpp $(INC)/Diccionario.h
#	$(CXX) $(CPPFLAGS)  -o $(OBJ)/testdiccionario.o $(SRC)/testdiccionario.cpp -I./$(INC)

#$(OBJ)/ArbolGeneral.o : $(INC)/ArbolGeneral.h $(INC)/ArbolGeneral.cpp
#	$(CXX) $(CPPFLAGS)  -o $(OBJ)/ArbolGeneral.o $(INC)/ArbolGeneral.h -I./$(INC)

#$(OBJ)/Diccionario.o : $(SRC)/Diccionario.cpp $(INC)/Diccionario.h $(INC)/ArbolGeneral.h
#s	$(CXX) $(CPPFLAGS)  -o $(OBJ)/diccionario.o $(SRC)/Diccionario.cpp -I./$(INC)

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
