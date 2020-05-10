#ifndef ADVANCEDFUNCTIONS_INCLUDED
#define ADVANCEDFUNCTIONS_INCLUDED

void distributeAll(unsigned int *nombre, int size, int value);
/*
Enlève value au premiers chiffres du grand nombre et le distribuer aux autres membres
Exemple avec value = 2 : (456) (789) (123) (555) = (456-2) (789+1998) (123+1998) + (555+2000) = (454) (2787) (2121) (2555)
Utile pour faire des soustractions avec des unsigned int
ne renvoie rien. Prend un grand nombre et une valeur(vérifier qu'elle est inférieure à la première valeur du nombre pour empêcher les 19-155 = nombre négatif

*/

int subNumber(unsigned int *numberA, int sizeA, unsigned int *numberB, int sizeB, unsigned int **numberC);
/*
Quasiment la même fonction que addNumber, tu peux partir d'elle. Utilise distributeAll au début et rearrangeNumber à la fin.
Un grand nombre et sa taille, un autre grand nombre et sa taille, et un pointeur sur un grand nombre pour le résultat
renvoie la taille du tableau final
*/

int isModOf(unsigned int *bigNumber, int sizeBigNumber, unsigned int *smallNumber, int sizeSmallNumber, unsigned int **remainder);
/*
Vérifie si le deuxième nombre est un diviseur du premier. renvoie le reste de la division euclidienne
Utilise subNumber et multiplie temporairement smallNumber avant de faire la soustraction
Exemple : 123456789 divisible par 123 ?
123 246 369 - 123 000 000 = 246 369
246 369 - 123 000 = 123 369
123 369 - 123 000 = 369
369 - 123 = 246
246 - 123 = 123
123 - 123 = 0
Donc la fonction renvoie 0
*/

int getPrimeNumber(unsigned int *bigNumber, int sizeBigNumber, unsigned int **primeNumber);
/*
Prend un grand nombre et sa taille, et une adresse d'un nombre plus petit généré aléatoirement, premier avec bigNumber. renvoie la taille
générer aléatoirement chaque partie du nombre avec rand() % 1000
pour vérifier si un nombre est premier avec bigNumber, tu fais la division eclidienne de bigNumber par le nombre que tu as obtenu.
si tu obtiens un autre nombre, tu fais la division euclidienne du nombre obtenu aléatoirement par ce nombre et ainsi de suite
 - Avec une boucle while, tu recommences tant que tu obtiens 0 à un seul des résultats. Si tu trouves un reste de 1, le nombre est bon et primeNumber devient ce nombre
 Exemple :
 64 est bigNumber. Tu cherches si 36 est bon
 64 / 36 = 1 reste 28
 36 / 28 = 1 reste 8
 28 / 8 = 3 reste 4
 8 / 4 = 0

 Tu obtiens 0 donc tu recommences à chercher un autre nombre

*/

#endif // ADVANCEDFUNCTIONS_INCLUDED
