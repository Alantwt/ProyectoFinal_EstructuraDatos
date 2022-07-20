#ifndef _WFUNCIONES
#define _WFUNCIONES

#include <windows.h>
#include <windef.h>
#include <winuser.h>

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

//DECLARACION DE FUNCIONES
LRESULT CALLBACK WindowProcedure(HWND mainWindow,UINT messageW,WPARAM wParam,LPARAM lParam) ;
void initComponents(HWND masterWindow);
void generarButtonAction(HWND masterWindow);
void inOrderRbuttonAction();
void preOrderRbuttonAction();
void postOrderRbtnAction();

//DECLARACION DE VARIABLES
//Ventana principal
HWND mainW;
//Mensajes de la ventana principal
MSG msgW;       
//Estilos de la ventana principal
WNDCLASSEX wClass;   
wchar_t className[] = L"Estilos"; 
//Entrada de datos del usuaio
HWND lblUserInput,wUserInput;
//RadioButtons
HWND rbtnInOrder,rbtnPreOrder,rbtnPostOrder;
char orderOption[10];
//Panel del Arbol binario
HWND panelBinaryTree, lblElement;
XY elementSize;
int lastPositionX;
//Elementos del Arbol Binario
int binaryTreeWeight = 1;



#include "../lib/wfunciones.cpp"

#endif