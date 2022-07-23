#ifndef _FUNCIONES
#define _FUNCIONES

#ifndef UNICODE
#define UNICODE//Esto es para utilizar caracteres latinos mas facil
#endif

//LINRERIAS INCLUIDAS
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
//STRUCTS
struct BinaryTree {    
    int info;
    struct BinaryTree *izquierdo;
    struct BinaryTree *derecho;
};

//DECLARACIONES
void BinaryTreeGenerate(int** sequence, int lenSequence, char* option);
int BinaryTreeSrchHeightOf(int element);
void srchHeigth(BinaryTree** nodo, int element);
int BinaryTreeSrchFather(int element);
void BinaryTreeFill(BinaryTree** nodo, BinaryTree** father, int element, int** sequence);
// int BinaryTreePreorden(int** sequence, int lenSequence, char* option);
// int BinaryTreeInorden(int** sequence, int lenSequence, char* option);
int BinaryTreePostorden(int** sequence, int lenSequence);

//ARBOL BINARIO
BinaryTree* arbolBinario;
//ITERAR ARBOL BINARIO
static int iSequence;
//Secuencia del arbol binario
static int** BTsequence;
static int BTlenSequence;
static int counterHeigth = 0, heigthFound = 0;
bool nodoFound = false;


#include "../lib/funciones.cpp"

#endif