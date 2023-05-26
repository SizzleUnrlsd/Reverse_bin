CC=gcc
CFLAGS=-c -Wall -O3 -g3
LDFLAGS=-lcrypto
SOURCES=ctf3.c tools_ascii_md5.c tools_binary_ascii.c strcat_bit.c anti_debug.c tools_defuscate.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=ctf3

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)

#
# "EPICTF{supertoto}"