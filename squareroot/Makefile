CC=g++

OBJDIR=obj
SRCDIR=src
BINDIR=bin

_OBJS = main.o
OBJS = $(patsubst %,$(OBJDIR)/%,$(_OBJS))

PROGNAME=$(BINDIR)/squareroot

$(OBJDIR)/%.o: $(SRCDIR)/%.cc
	mkdir -p $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(PROGNAME): $(OBJS)
	mkdir -p $(BINDIR)
	g++ -o $(PROGNAME) $(OBJS)

.PHONY: clean

clean:
	rm -f $(OBJDIR)/*.o $(PROGNAME)