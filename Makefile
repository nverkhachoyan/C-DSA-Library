CC=gcc
CFLAGS=-Iinclude -Wall
SRCDIR=src
OBJDIR=obj
BINDIR=bin
SOURCES=$(wildcard $(SRCDIR)/**/*.c $(SRCDIR)/*.c)
OBJECTS=$(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
TARGET=$(BINDIR)/main

all: $(TARGET)

$(TARGET): $(OBJECTS)
	mkdir -p $(@D)
	$(CC) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(TARGET)

.PHONY: all clean
