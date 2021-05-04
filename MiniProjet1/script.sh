#! /bin/bash

echo ".........................Exercice 1.........................";echo

echo "Exercice 1 partie 1:"
gcc -o exo1p1 tme1_exo1p1.c
echo ; ./exo1p1 
echo "  - Segfault :    Erreur d'indice dans le tableau"; echo;echo

echo  "Exercice 1 partie 2"
gcc -o exo1p2 tme1_exo1p2.c
echo ; ./exo1p2 
echo "  - Segfault :    On n'alloue pas de mémoire à new->rue"; echo;echo

echo  "Exercice 1 partie 3"
gcc -o exo1p3 tme1_exo1p3.c
echo ; ./exo1p3 
echo "  - Leaks :    On ne libere pas la mémoire de t->tab"; echo;echo

rm exo1p{1..3}

echo ".........................Exercice 2.........................";echo

echo "Exercice 2 partie 1:"
gcc -o exo2p1 tme1_exo2p1_voir_resultat_somme.c
echo ; ./exo2p1 
echo "  -  Modifier TAILLE/BORNE : Pour modifier la taille du tableau et les bornes de ses valeurs "; echo

echo "Décommenter prochaine ligne pour afficher les courbes de vitesses d'execution de l'algo 1 et 2 (dispo en .png dans ./courbeFile)" ; echo;echo
# gnuplot  -e "set terminal dumb size 120 30; plot './dataFile/courbe_Exercice2_somme.txt'  using 1:2 with lines notitle; replot './dataFile/courbe_Exercice2_somme.txt'  using 1:3 with lines notitle"

echo  "Exercice 2 partie 2";echo

echo "Question 5 : tous_diff"
gcc -o exo2p2_5 tme1_exo2p2.c tme1_exo2p2_5_voir_matrice.c 
echo ; ./exo2p2_5 
echo "Si return = 1 alors toutes les valeurs de la matrice sont différentes"; echo

echo "Décommenter prochaine ligne pour afficher les courbes de vitesses d'execution de l'algo 1 et 2 (dispo en .png dans ./courbeFile)"; echo;echo
# gnuplot  -e "set terminal dumb size 120 30; plot './dataFile/dataTousDiff.txt'  using 1:2 with lines notitle; replot './dataFile/dataTousDiff.txt'  using 1:3 with lines notitle"
# gnuplot  -e "set terminal dumb size 120 30; plot './dataFile/dataTousDiff2.txt'  using 1:2 with lines notitle; replot './dataFile/dataTousDiff2.txt'  using 1:3 with lines notitle"

echo "Question 6 : produit_matrice"
gcc -o exo2p2_6 tme1_exo2p2.c tme1_exo2p2_6_voir_produit.c 
echo ; ./exo2p2_6 

echo "Décommenter prochaine ligne pour afficher les courbes de vitesses d'execution de l'algo 1 et 2 (dispo en .png dans ./courbeFile)"; echo;echo
# gnuplot  -e "set terminal dumb size 120 30; plot './dataFile/dataProduit.txt'  using 1:2 with lines notitle; replot './dataFile/dataProduit.txt'  using 1:3 with lines notitle"

rm exo2p1 exo2p2_{5,6} 