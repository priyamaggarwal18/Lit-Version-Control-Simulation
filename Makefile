# compiler and flags
CC = gcc
CFLAGS = -Wall -std=c99 -I src
OBJDIR = obj
BINDIR = bin

# source files and objfiles creation in their respective folders
SRCS = src/lit.c src/file_handeling.c src/commit.c
OBJS = $(OBJDIR)/lit.o $(OBJDIR)/file_handeling.o $(OBJDIR)/commit.o

# test files and their obj file creation
TEST_SRCS = test/test_lit.c
TEST_OBJS = $(OBJDIR)/test_lit.o

# main application source and object file
MAIN_SRC = src/main.c
MAIN_OBJ = $(OBJDIR)/main.o

# target for building the lit executable
$(BINDIR)/lit: $(OBJS) $(MAIN_OBJ)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $(BINDIR)/lit $(OBJS) $(MAIN_OBJ)
	@echo "Build successful! lit executable created in bin directory."
	@echo "            %@@@&                                            "
	@echo "         @@@@ @*@@@@                                         "
	@echo "       &@@@ @@@@@ @@@@      @@@@      @@@@ @@@@@@@@@@@        "
	@echo "    &@@@ @@@@&.% @@& @@@&   @@@@      @@@@     @@@&           "
	@echo "   @@@@  @@@  @ @@@@  @@@@  @@@@      @@@@    @@@@@           "
	@echo "     @@@@ @@@@ @&@@@ @@@@    @@@@      @@@@    @@@@@           "
	@echo "        @@ @%&@@ @ &@@@       @@@@@@@@@ @@@@    @@@@@           "
	@echo "          @@@@,@@@@                                         "
	@echo "             &@@                                            "
	@echo "Lit Build is Completed"
	@echo "Lit it Now "

# compile source files into object files
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

# compile the test file into object files (without linking main.o)
$(OBJDIR)/test_lit.o: test/test_lit.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c test/test_lit.c -o $(OBJDIR)/test_lit.o

# single command to build the lit program and run tests
run: $(BINDIR)/lit $(OBJDIR)/test_lit.o $(OBJS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $(BINDIR)/test_lit $(TEST_OBJS) $(OBJS)
	@echo "Running tests in test mode..."
	./$(BINDIR)/test_lit
	@echo "Tests complete."
