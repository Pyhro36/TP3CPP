#makefile de analog

EXE = analog
COMP = g++
RM = rm
EDL = g++
ECHO = @echo
INTF = Date.h Fichier.h Log.h Pages.h Util.h
REAL = $(INTF:.h=.cpp) $(EXE).cpp
OBJ = $(REAL:.cpp=.o)
OUTPUT = -o
RMFLAGS = -f
CPPFLAGS = #-Wall -FMAP
EDLFALGS =
LIBS =
LIBPATH =
INPATH =
CLEAN = clean
SOS = backup

$(EXE) : $(OBJ)
	$(ECHO) "Edition des liens"
	$(EDL) $(OUTPUT) $(EXE) $(EDLFLAGS) $(LIBPATH) $(OBJ) $(LIBS)

$(EXE).o : $(EXE).cpp Collection.h
Collection.o : Collection.cpp Collection.h

%.o : %.cpp
	$(ECHO) "Compilation de <$<>"
	$(COMP) $(CPPFLAGGS) $(INPATH) -c $<

$(CLEAN) :
	$(ECHO) "Nettoyage des fichiers crees !"
	$(RM) $(RMFLAGS) $(EXE) $(OBJ) #core

#$(SOS)
