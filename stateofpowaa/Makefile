# File: Makefile
# Author: John Hockel
# Guys this was my first Windows makefile that I ever made for myself and I was very proud of it
# Even though it kinda cheats and gcc's the source files, compiling AND linking in 1 step, which is kinda cheating
# Also I didnt use any fancy options. Just compiles. Oh well. 

# Specify compiler
CC=gcc
  
# Specify linker
# LINK=gcc

INC_DIR=G:\Code\libxl-3.8.2.0\include_cpp
LIB_DIR=G:\Code\libxl-3.8.2.0\lib
LIB=xl.lib

# OBJ="main.o character.o"
SOURCE="main.cpp character.cpp excelio.cpp"
  
.PHONY : all
all : app
  
# Link the object files into a binary
# app : main.o
#	$(LINK) -o app $(OBJ) -lstdc++
  
# Compile the source files into object files
app : main.cpp
	$(CC) -Wall -I$(INC_DIR) -L$(LIB_DIR) $(SOURCE) -l$(LIB) -o sop.exe
  
# Clean target
.PHONY : clean
clean :
	rm sop.exe