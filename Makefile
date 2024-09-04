# Makefile for building the lit version control system on Linux

CC = gcc
CFLAGS = -Wall -std=c99
OBJDIR = obj
BINDIR = bin
LIBDIR = lib

SRCS = src/lit.c src/file_handeling.c src/commit.c src/main.c
OBJS = $(OBJDIR)/lit.o $(OBJDIR)/file_handeling.o $(OBJDIR)/commit.o $(OBJDIR)/main.o

# creates a executable file in binary folder
$(BINDIR)/lit: $(OBJS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $(BINDIR)/lit $(OBJS)

# compile the each source file into object files in object folder
$(OBJDIR)/lit.o: src/lit.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c src/lit.c -o $(OBJDIR)/lit.o

$(OBJDIR)/file_handeling.o: src/file_handeling.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c src/file_handeling.c -o $(OBJDIR)/file_handeling.o

$(OBJDIR)/commit.o: src/commit.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c src/commit.c -o $(OBJDIR)/commit.o

$(OBJDIR)/main.o: src/main.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c src/main.c -o $(OBJDIR)/main.o

# clean the these build directories
clean:
	rm -rf $(OBJDIR) $(BINDIR)
