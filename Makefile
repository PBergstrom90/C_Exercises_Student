PROG = main.exe
SRC = main.c safeinput.c studentregister.c
CFLAGS = -g -Wall -Wextra -Wundef -pedantic -Werror
LIBS = 
all: $(PROG)

$(PROG): $(SRC)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(SRC) $(LIBS)

clean: 
	rm -f $(PROG)

.PHONY: all clean