CC=gcc
CFLAGS=-c -Wall
LDFLAGS=-lcrypto
SOURCES=ctf1.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=ctf1

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)

# toto
# azerty
# EPICTF{azertytoto}