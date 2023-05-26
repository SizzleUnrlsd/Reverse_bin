CC=gcc
CFLAGS=-c -Wall -g3
LDFLAGS=-lcrypto
SOURCES=ctf2.c tools_ascii_md5.c tools_binary_ascii.c strcat_bit.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=ctf2

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)

# admin
# rootroot
# "EPICTF{adminrootroot}"