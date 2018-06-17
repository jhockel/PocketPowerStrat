# Specify compiler
CC=gcc
  
# Specify linker
LINK=gcc

OBJ="main.o character.o"
SOURCE="main.cpp character.cpp"
  
.PHONY : all
all : app
  
# Link the object files into a binary
app : main.o
	$(LINK) -o app $(OBJ) -lstdc++
  
# Compile the source files into object files
main.o : main.cpp
	$(CC) -c $(SOURCE) -o $(OBJ)
  
# Clean target
.PHONY : clean
clean :
	rm main.o app 