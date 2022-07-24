#ifndef _FUNCIONES
#define _FUNCIONES

#ifndef UNICODE
#define UNICODE//Esto es para utilizar caracteres latinos mas facil
#endif

//LINRERIAS INCLUIDAS
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
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
void srchFather(BinaryTree** nodo, int element);
void BinaryTreeFill(BinaryTree** nodo, BinaryTree** father, int element, int** sequence);
void BinaryTreeDelete(BinaryTree** nodo);
// int BinaryTreePreorden(int** sequence, int lenSequence, char* option);
///////////////////////////////////////////////////////
void BinaryTreeInorden(int** sequence, int lenSequence);
void inOrden(BinaryTree** nodo, int** sequence);
/////////////////////////////////////////////////////
void BinaryTreePostorden(int** sequence, int lenSequence);
void preOrden(BinaryTree** nodo, int** sequence);
/////////////////////////////////////////////////////
void BinaryTreePreorden(int** sequence, int lenSequence);
void postOrden(BinaryTree** nodo, int** sequence);
 
//
void srcHeigth(BinaryTree** nodo, int element);
//insertar nodo
void BinaryTreeInsertNodo();
//borrar nodo
void BinaryTreeDeleteNodo();
//nodos hoja
void BinaryTreeChilNodo();

//ARBOL BINARIO
BinaryTree* arbolBinario;
//ITERAR ARBOL BINARIO
static int iSequence;
//Secuencia del arbol binario
static int** BTsequence;
static int BTlenSequence;
static int counterHeigth = 0, heigthFound = 0;
bool nodoFound = false;
//INORDER POSTORDER PREORDER
static int counterInOrder = 0, counterPostOrder = 0, counterPreOrder = 0;
int* orderSecuencia;
//BUSCAR PADRE
int fatherElement;
bool fatherFound = false;


#include "../lib/funciones.cpp"

#endif