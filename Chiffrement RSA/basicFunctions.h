#ifndef BASICFUNCTIONS_H_INCLUDED
#define BASICFUNCTIONS_H_INCLUDED

#define SIZECELL 3

// Un grand nombre est constitué de plusieurs tableaux d'entiers à sizeCell chiffres
// Le pointeur de pointeur est en fait un pointeur de tableau, il sert à modifier un grand nombre


int getNumber(unsigned int **number, char numberName);
/*
permet d'obtenir des nombres à entrer, ici P et Q
prend la taille d'une case, un pointeur sur un grand nombre et le nom du nombre à obtenir
On effectue un calloc avec **number. renvoie la taille du tableau d'entiers
JE L'AI FAIT

*/

int rearrangeNumber(unsigned int **number, int size);
/*
permet de réarranger un nombre pour qu'il ait la bonne taille et les bonnes valeurs
peut ajouter une case au tableau si la valeur obtenue est trop grande
prend la taille d'une case, un pointeur sur un grand nombre et sa taille en nombre de cases
renvoie la taille du tableau
JE L'AI FAIT

*/

void allocateNumber(unsigned int **number, int size);
/*
permet d'allouer un nouveau nombre dans la mémoire avec la taille correspondante, le nombre n'étant PAS ENCORE UTILISE
prend la taille d'une case, un pointeur sur un grand nombre et sa taille en nombre de cases
renvoie la taille du tableau alloué
JE L'AI FAIT

*/

void freeNumber(unsigned int **number, int size);

int addNumber(unsigned int *numberA, int sizeA, unsigned int *numberB, int sizeB, unsigned int **numberC);
/*
permet d'ajouter 2 grands nombres. Les opérations se font à l'intérieur d'une case : (123) (456) (789) + (987) (654) = (123) (456 + 987) (789 + 654)
la taille du grand nombre C est la taille du plus grand nombre entre A et B
on réarrange le nombre correctement avec rearrangeNumber
un grand nombre et sa taille, un autre grand nombre et sa taille, et un grand nombre pour le résultat
renvoie la taille du tableau final

*/

int mulNumber(unsigned int *numberA, int sizeA, unsigned int *numberB, int sizeB, unsigned int **numberC);
/*
permet de multiplier 2 grands nombres. Les opérations sont découpés comme ceci : (a + b + c + d) * (e + f + g + h) = ae + (af + be) + (ag + bf + ce) + (ah + bg + cf + de) + (bh + cg + df) + (ch + dg) + dh
(123) (456) (789) * (987) (654) = (123 * 987) (123 * 654 + 456 * 987) (456 * 654 + 789 * 987) (789 * 654)
la taille du grand nombre C est la taille de A multipliée par la taille de B
on réarrange le nombre correctement avec rearrangeNumber
prend la taille d'une case, un grand nombre et sa taille, un autre grand nombre et sa taille, et un grand nombre pour le résultat
renvoie la taille du tableau final

*/

#endif // BASICFUNCTIONS_H_INCLUDED
