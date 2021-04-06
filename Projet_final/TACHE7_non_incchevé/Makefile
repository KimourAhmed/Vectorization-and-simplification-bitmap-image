#############################################################################
# Fichier Makefile 
# UE MAP401 - DLST - UGA - 2019/2020
#############################################################################
# utilisation des variables internes $< $@ $*
# $@ : correspond au nom de la cible
# $< : correspond au nom de la premiere dependance
# $^ : correspond \E0 toutes les d\E9pendances
# $* : correspond au nom du fichier sans extension 
#       (dans les regles generiques uniquement)
#############################################################################
# information sur la regle executee avec la commande @echo
# (une commande commancant par @ n'est pas affichee a l'ecran)
#############################################################################


#############################################################################
# definition des variables locales
#############################################################################

# compilateur C
CC = clang

# chemin d'acces aux librairies (interfaces)
INCDIR = .

# chemin d'acces aux librairies (binaires)
LIBDIR = .

# options pour l'\E9dition des liens
LDOPTS = -L$(LIBDIR) -lm

# options pour la recherche des fichiers .o et .h
INCLUDEOPTS = -I$(INCDIR)

# options de compilation
COMPILOPTS = -g -Wall $(INCLUDEOPTS)

# liste des executables
EXECUTABLES = test_plus_contour 

#############################################################################
# definition des regles
#############################################################################

########################################################
# la r\E8gle par d\E9faut
all : $(EXECUTABLES)

########################################################
# regle generique : 
#  remplace les regles de compilation separee de la forme
#	module.o : module.c module.h
#		$(CC) -c $(COMPILOPTS) module.c
%.o : %.c %.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module "$*
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

########################################################
# regles explicites de compilation separee de modules
# n'ayant pas de fichier .h ET/OU dependant d'autres modules
image.o : image.c image.h types_macros.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module image"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

geom2d.o : geom2d.c geom2d.h 
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module geom2d"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

calcul_contour.o: calcul_contour.c calcul_contour.h types_macros.h image.h geom2d.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module calcul_contour"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

structure_Beziers.o: structure_Beziers.c structure_Beziers.h calcul_contour.h types_macros.h image.h geom2d.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module structure_Beziers"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<
	
simplification_contours.o: simplification_contours.c simplification_contours.h calcul_contour.h geom2d.h structure_Beziers.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module simplification_contours"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

converttoeps.o: converttoeps.c converttoeps.h plus_contours.h calcul_contour.h  types_macros.h image.h structure_Beziers.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module converttopes"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

plus_contours.o: plus_contours.c plus_contours.h calcul_contour.h types_macros.h image.h geom2d.h simplification_contours.h structure_Beziers.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module plus_contours"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<
		
test_plus_contour.o: test_plus_contour.c plus_contours.h converttoeps.h calcul_contour.h image.h types_macros.h simplification_contours.h geom2d.h structure_Beziers.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_converttoeps"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

########################################################
# regles explicites de creation des executables

test_plus_contour: test_plus_contour.o plus_contours.o calcul_contour.o image.o simplification_contours.o geom2d.o structure_Beziers.o converttoeps.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@


 

# regle pour "nettoyer" le r\E9pertoire
clean:
	rm -fR $(EXECUTABLES) *.o 
