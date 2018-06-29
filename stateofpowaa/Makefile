# File: Makefile
# Author: John Hockel
# Guys this was my first Windows makefile that I ever made for myself and I was very proud of it
# Even though it kinda cheats and gcc's the source files, compiling AND linking in 1 step, which is kinda cheating
# Also I didnt use any fancy options. Just compiles. Oh well. 

# Specify compiler
CC=g++
  
# Specify linker
LINK=g++

INC_DIR=lib/include_cpp
LIB=xl

# OBJ="main.o character.o"
SOURCE=main.cpp character.cpp backbone.cpp excelio.cpp
OBJS=$(SOURCE:.cpp=.o)
  
.PHONY : all
all : app
  
# Link the object files into a binary
app : $(OBJS)
	$(LINK) $^ -L. -l$(LIB) -lstdc++ -o sop.exe
  
# Compile the source files into object files
$(OBJS) : $(SOURCE)
	$(CC) -Wall -o $@ -c $*.cpp -I$(INC_DIR)
  
# Clean target
.PHONY : clean
clean :
	rm -f $(OBJS) sop.exe