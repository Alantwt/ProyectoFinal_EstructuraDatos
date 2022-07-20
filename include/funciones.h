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
void BinaryTreeGenerate(int* sequence, int lenSequence, char* option);
int BinaryTreeSrchHeightOf(int element, int BinaryTreeHeight);

//ARBOL BINARIO
BinaryTree* arbolBinario;


#include "../lib/funciones.cpp"

#endif