# compiler and flags
CC = gcc
CFLAGS = -Wall -std=c99 -I src
OBJDIR = obj
BINDIR = bin

# source files and objfiles creation in there respective folders
SRCS = src/lit.c src/file_handeling.c src/commit.c src/main.c
OBJS = $(OBJDIR)/lit.o $(OBJDIR)/file_handeling.o $(OBJDIR)/commit.o $(OBJDIR)/main.o

# test files and there obj file creation
TEST_SRCS = test/test_lit.c
TEST_OBJS = $(OBJDIR)/test_lit.o

# target for building the lit executable
$(BINDIR)/lit: $(OBJS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $(BINDIR)/lit $(OBJS)
	@echo "Build successful! lit executable created in bin directory."
	@echo "            %@@@&                                           "
	@echo "         @@@@ @*@@@@                                         "
	@echo "       &@@@ @@@@@ @@@@      @@@@      @@@@ @@@@@@@@@@@        "
	@echo "    &@@@ @@@@&.% @@& @@@&   @@@@      @@@@     @@@&           "
	@echo "   @@@@  @@@  @ @@@@  @@@@  @@@@      @@@@    @@@@@           "
	@echo "     @@@@ @@@@ @&@@@ @@@@    @@@@      @@@@    @@@@@           "
	@echo "        @@ @%&@@ @ &@@@       @@@@@@@@@ @@@@    @@@@@           "
	@echo "          @@@@,@@@@                                         "
	@echo "           &@@                                            "
	@echo " "
	@echo " Lit Build is Completed "
	@echo " Lit it Now 🔥 "

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

# target for building and running the tests
test: $(TEST_OBJS) $(OBJS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $(BINDIR)/test_lit $(TEST_OBJS) $(OBJS)
	@echo "Running tests..."
	./$(BINDIR)/test_lit

# compile the test file into object files
$(OBJDIR)/test_lit.o: test/test_lit.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c test/test_lit.c -o $(OBJDIR)/test_lit.o

# shortcut to clean up all build artifacts (object files and binaries)
clean:
	rm -rf $(OBJDIR) $(BINDIR)
	@echo "Clean up completed."

# shortcut to build and test
run: $(BINDIR)/lit test
	@echo "Run and test complete."
