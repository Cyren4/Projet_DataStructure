CFLAGS  =	-Wall -Wextra -Werror

CC      =	gcc

EXEC    =	projet


all     :	$(EXEC)

OBJS	=	${SRCS:.c=.o}

SRCS	=	gestionChaine.c gestionReseau.c\
			Chaine.c        Reseau.c\
			mesureChaine.c  mesureReseau.c\
			SVGwriter.c\
			Hachage.c\
			ArbreQuat.c gestionArbreQuat.c\
			Graphe.c\
			ReconstitueReseau.c
			# TimeMain.c
			# ChaineMain.c
			# ReseauMain.c

projet :	$(OBJS)
			$(CC) -o $@ $(CFLAGS) $^ 

%.o		:	%.c %.h
			$(CC)  $(GCC_FLAGS) -c  $< 

clean	:
			rm -f *.o

fclean	:	clean
			rm $(EXEC)

re		:	clean all

.PHONY  :   all clean