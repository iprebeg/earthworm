CC = cc 
CFLAGS = -Wall 
LDFLAGS = 
PROJECT = magic
OBJECTS = magic.o 
SOURCE = magic.c 

$(PROJECT) : $(OBJECTS)
	$(CC) $(LDFLAGS) $(LIBRARY) $(OBJECTS) -o $(PROJECT) 

$(OBJECTS) : $(SOURCE) $(HEADERS)
	$(CC) -c $(CFLAGS) $(SOURCE) $(INCLUDE)

clean:
	-rm -f $(PROJECT) $(OBJECTS) *~ *core
