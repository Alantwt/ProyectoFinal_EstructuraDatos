#ifndef _WFUNCIONES
#define _WFUNCIONES

#include <windows.h>
#include <windef.h>
#include <winuser.h>
#include <wingdi.h>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

//MACROS DE LOS BOTONES
#define BTNgenerar 100
#define RBTNinOrder 101
#define RBTNpostOrder 102
#define RBTNpreOrder 103

//DECLARACION DE STRUCTS
struct XY{
    int x;
    int y;
};
struct binaryTsimulacion{
    int info;
    int heigth;
    int father;
    XY fPosition;
};


//DECLARACION DE FUNCIONES
LRESULT CALLBACK WindowProcedure(HWND mainWindow,UINT messageW,WPARAM wParam,LPARAM lParam) ;
void initComponents(HWND masterWindow);
void BinaryTreePanelCreate(HWND masterWindow);
void resizeWindow();
void resetWindow();
void generarButtonAction(HWND masterWindow);
void inOrderRbuttonAction(WPARAM wParam,HWND mainWindow);
void preOrderRbuttonAction(WPARAM wParam,HWND mainWindow);
void postOrderRbtnAction(WPARAM wParam,HWND mainWindow);
int splitStringBy(const wchar_t* string);
void paintBinaryTree(HWND masterWindow,int lenSequence);
void paintBinaryTreeConections(HWND masterWindow);
int searchIndex(int nodo);


//DECLARACION DE VARIABLES
//Ventana principal
HWND mainW;
static XY wSize;
//Mensajes de la ventana principal
MSG msgW;       
//Estilos de la ventana principal
WNDCLASSEX wClass;   
wchar_t className[] = L"Estilos"; 
//Entrada de datos del usuaio
HWND lblUserInput,wUserInput;
wchar_t userInput[600];
int* sequence;
int lenSequence;
//Buttons
HWND btnGenerar;
//RadioButtons
HWND rbtnInOrder,rbtnPreOrder,rbtnPostOrder;
char orderOption[10] = "postorder";
//Panel del Arbol binario
XY elementSize,lastPositionElement;
int lastPositionX, initPositionX;
wchar_t text[10];
//Elementos del Arbol Binario
int binaryTreeWeight = 1;
//Elementos para pintar el arbol binario
HWND panelBinaryTree, lblElement;
HDC hDC;
PAINTSTRUCT ps;
XY nodoSize, nodoPosition, lastPosition,*nodosPositions;
int initXposition,nodoHeigth;
wchar_t nodoText[10];
int wNodoHeigth = 0;
int wFatherElement = 0;




#include "../lib/wfunciones.cpp"

#endif