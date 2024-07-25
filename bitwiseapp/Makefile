CC = gcc

CFLAGS = -Wall -Wextra -Iinclude

LDFLAGS = 

SRCDIR = src
OBJDIR = obj
BINDIR = output

SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, %(SOURCES))
EXECUTABLE = $(BINDIR)/output

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
    $(CC) $(LDFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
    $(CC) $(CFLAGS) -o $< -o $@

clean:
    rm -rf $(OBJDIR)/*.o $(EXECUTABLE)/exe

