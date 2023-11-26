CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRCS = main.c funciones.c
OBJS = $(SRCS:.c=.o)
EXE = programa

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.s: %.c
	$(CC) $(CFLAGS) -S $< -o $@

%.o: %.s
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXE) *.s
