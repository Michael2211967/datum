# Wedit Makefile for project datum
SRCDIR=c:\users\michael\datum\win
CFLAGS=-I"c:\lcc\include"  -g2 
CC=$(LCCROOT)\bin\lcc.exe
LINKER=$(LCCROOT)\bin\lcclnk.exe
OBJS=\
	datum.obj

LIBS=
EXE=datum.exe

$(EXE):	$(OBJS) Makefile
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\datum.exe $(OBJS) $(LIBS)

# Build datum.c
DATUM_C=\

datum.obj: $(DATUM_C) $(SRCDIR)\datum.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\datum.c

link:
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\datum.exe $(OBJS) $(LIBS)

clean:
	del $(OBJS) datum.exe
