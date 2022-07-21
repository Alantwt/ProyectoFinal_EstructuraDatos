#include "../include/wfunciones.h" 
#include "../include/Sfunciones.h"
#include "../include/funciones.h"

//INICIAR COMPONENTES
void initComponents(HWND masterWindow){
    //Predefinir el tamaño de cada elemento del arbol binario
    elementSize.x = 30;
    elementSize.y = 30;
    //Definir la posicion inicial de cada elemento en X
    lastPositionX = 10;
    //Entrada del usuario
    lblUserInput = CreateWindowEx(0,L"static",L"Ingrese la secuencia",WS_VISIBLE|WS_CHILD,20,20,150,25,masterWindow,NULL,NULL,NULL); 
    wUserInput = CreateWindowEx(0,L"edit",L"",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER|ES_MULTILINE|ES_AUTOHSCROLL,170,20,150,25,masterWindow,NULL,NULL,NULL);
    //RadioButtons
    rbtnInOrder = CreateWindowEx(0,L"button",L"InOrder",WS_VISIBLE|WS_CHILD|BS_RADIOBUTTON,20,50,80,25,masterWindow,(HMENU)RBTNinOrder,NULL,NULL);
    rbtnPostOrder = CreateWindowEx(0,L"button",L"PostOrder",WS_VISIBLE|WS_CHILD|BS_RADIOBUTTON,100,50,100,25,masterWindow,(HMENU)RBTNpostOrder,NULL,NULL);;
    rbtnPreOrder = CreateWindowEx(0,L"button",L"PreOrder",WS_VISIBLE|WS_CHILD|BS_RADIOBUTTON,200,50,100,25,masterWindow,(HMENU)RBTNpreOrder,NULL,NULL);
    //BUTTONS
    btnGenerar = CreateWindowEx(0,L"button",L"Generar",WS_VISIBLE|WS_CHILD,340,20,70,25,masterWindow,(HMENU)BTNgenerar,NULL,NULL);
}   

//ACCION DE LOS BOTONES
void generarButtonAction(HWND masterWindow, int heightBT){
    panelBinaryTree = CreateWindowEx(0,L"static",NULL,WS_VISIBLE|WS_CHILD|WS_BORDER,0,80,wSize.x,wSize.y,masterWindow,NULL,NULL,NULL);
    GetWindowTextW(wUserInput,userInput,100);
    lenSequense = splitStringBy(userInput,',',&sequence);
    printf("%dlen\n",lenSequense);
    //BinaryTreeGenerate(&sequence,lenSequense,orderOption);
    painBinaryTree(panelBinaryTree);
    puts(orderOption);
}

void inOrderRbuttonAction(WPARAM wParam,HWND mainWindow){
    if(HIWORD(wParam) == BN_CLICKED){
        if(SendDlgItemMessage(mainWindow,RBTNinOrder,BM_GETCHECK,0,0) == 0){
            SendDlgItemMessage(mainWindow,RBTNinOrder,BM_SETCHECK,1,0);
            SendDlgItemMessage(mainWindow,RBTNpostOrder,BM_SETCHECK,0,0);
            SendDlgItemMessage(mainWindow,RBTNpreOrder,BM_SETCHECK,0,0);
            strcpy(orderOption,"inorder");
        }
    }
}
void preOrderRbuttonAction(WPARAM wParam,HWND mainWindow){
    if(HIWORD(wParam) == BN_CLICKED){
        if(SendDlgItemMessage(mainWindow,RBTNpreOrder,BM_GETCHECK,0,0) == 0){
            SendDlgItemMessage(mainWindow,RBTNinOrder,BM_SETCHECK,0,0);
            SendDlgItemMessage(mainWindow,RBTNpostOrder,BM_SETCHECK,0,0);
            SendDlgItemMessage(mainWindow,RBTNpreOrder,BM_SETCHECK,1,0);
            strcpy(orderOption,"preorder");
        }
    }
}
void postOrderRbtnAction(WPARAM wParam,HWND mainWindow){
    if(HIWORD(wParam) == BN_CLICKED){
        if(SendDlgItemMessage(mainWindow,RBTNpostOrder,BM_GETCHECK,0,0) == 0){
            SendDlgItemMessage(mainWindow,RBTNinOrder,BM_SETCHECK,0,0);
            SendDlgItemMessage(mainWindow,RBTNpostOrder,BM_SETCHECK,1,0);
            SendDlgItemMessage(mainWindow,RBTNpreOrder,BM_SETCHECK,0,0);
            strcpy(orderOption,"postorder");
        }
    }
}

//REDIMENCIONAR PANTALLA
void resizeWindow(){
   MoveWindow(panelBinaryTree,0,80,wSize.x,wSize.y,TRUE); 
}


//GENERAR EL ARBOL
void painBinaryTree(HWND masterWindow){
    int altura = BinaryTreeSrchHeightOf(2);
    initBTSimulacion();
    secuenciaPrueba[0].heigth = 3;
    secuenciaPrueba[0].info = 2;
    
    initPositionX = 400;
    lastPositionX = initPositionX;
    lastPositionElement.x = lastPositionX;
    lastPositionElement.y = (secuenciaPrueba[0].heigth*(elementSize.y+elementSize.y))+secuenciaPrueba[0].heigth;
    swprintf(text,L"%d",secuenciaPrueba[0].info);
    lblElement = CreateWindowEx(
        0,
        L"static",
        text,
        WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,
        lastPositionX+elementSize.x,lastPositionElement.y,
        elementSize.x,elementSize.y,
        masterWindow,
        NULL,
        NULL,
        NULL
    );
   
    for(int i = 0; i <= 10-1; i++){
        lastPositionElement.x = lastPositionElement.x+elementSize.x;
        lastPositionElement.y = (secuenciaPrueba[i].heigth*(elementSize.y+elementSize.y))+secuenciaPrueba[i].heigth;
        swprintf(text,L"%d",secuenciaPrueba[i].info);
        printf("%d-%d\n",lastPositionElement.x,lastPositionElement.y);
        lblElement = CreateWindowEx(
            0,
            L"static",
            text,
            WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,
            lastPositionElement.x,lastPositionElement.y,
            elementSize.x,elementSize.y,
            masterWindow,
            NULL,
            NULL,
            NULL
        );
    }
}

void initBTSimulacion(){
    secuenciaPrueba[0].heigth = 3;
    secuenciaPrueba[0].info = 2;

    secuenciaPrueba[1].heigth = 4;
    secuenciaPrueba[1].info = 6;

    secuenciaPrueba[2].heigth = 2;
    secuenciaPrueba[2].info = 10;

    secuenciaPrueba[3].heigth = 1;
    secuenciaPrueba[3].info = 12;

    secuenciaPrueba[4].heigth = 3;
    secuenciaPrueba[4].info = 13;

    secuenciaPrueba[5].heigth = 4;
    secuenciaPrueba[5].info = 15;

    secuenciaPrueba[6].heigth = 2;
    secuenciaPrueba[6].info = 16;

    secuenciaPrueba[7].heigth = 4;
    secuenciaPrueba[7].info = 4;

    secuenciaPrueba[8].heigth = 3;
    secuenciaPrueba[8].info = 18;
    
    secuenciaPrueba[9].heigth = 4;
    secuenciaPrueba[9].info = 19; 
}

//JAIME

// //DECLARACIONES DE LAS FUNCIONES
// void iterar(int** sequence, int lenSequence);

// void iterar2(int** sequence, int lenSequence);
// //BinaryTreeGenerate
// void iterar(int** sequence, int lenSequence){
//     iterar2(sequence,lenSequence);
// }
// //BinaryTreePreorder
// void iterar2(int** sequence, int lenSequence){
//     int xd;
//     cout<<"iterar2"<<endl;
//     for(int i = 0; i <= lenSequence-1; i++){
//         printf("    %d\n",(*(*sequence+i)));
//         //modificar valores del array
//         *((*sequence)+i) = i;
//         //almacenar datos en una variable
//         xd = *((*sequence)+i);
//     }
//     cout<<"segunda vuelta"<<endl;
//     for(int i = 0; i <= lenSequence-1; i++){
//         printf("    %d\n",(*(*sequence+i)));
//     }
// }