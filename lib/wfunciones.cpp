#include "../include/wfunciones.h" 
#include "../include/Sfunciones.h"
#include "../include/funciones.h"


//INICIAR COMPONENTES
void initComponents(HWND masterWindow){
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

void BinaryTreePanelCreate(HWND masterWindow){
    panelBinaryTree = CreateWindowEx(0,L"static",NULL,WS_VISIBLE|WS_CHILD|WS_BORDER,0,80,wSize.x,wSize.y,masterWindow,NULL,NULL,NULL);
}

//ACCION DE LOS BOTONES
void generarButtonAction(HWND masterWindow){
    resetWindow();
    printf("iniciar: %d-%d\n",wSize.x,wSize.y);
    //BinaryTreePanelCreate(masterWindow);
    panelBinaryTree = CreateWindowEx(0,L"static",NULL,WS_VISIBLE|WS_CHILD|WS_BORDER,0,80,wSize.x,wSize.y,masterWindow,NULL,NULL,NULL);
    GetWindowTextW(wUserInput,userInput,200);
    lenSequense = splitStringBy(L"12,16,18,10,13,19,15,17,2,6",',',&sequence);
    printf("%dlen\n",lenSequense);
    BinaryTreeGenerate(&sequence,lenSequense,orderOption);
    paintBinaryTree(panelBinaryTree,lenSequense);
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
//RESETEAR VENTANA
void resetWindow(){
    DestroyWindow(panelBinaryTree);
}


//GENERAR EL ARBOL
void paintBinaryTree(HWND masterWindow, int lenSequence){
    lenSequence = 10;
    //DAR ESPACIO EN MEMORIA PARA TODAS LAS POCIIONES DE LOS ELEMENTOS

    //FUNCION PARA LLENAR UN ARBOL BINARIO DE PRUEBA
    initBTSimulacion();
    //Predefinir el tamaño de cada elemento del arbol binario
    nodoSize.x = 30;
    nodoSize.y = 30;
    //Definir la posicion inicial del primer nodo en X
    initXposition = 300;
    //formula para saber la posicion en y del nodo: (altura * (2*tamaño del rectangulo del nodo)+altura del nodo)
    printf("\nAltura buscada: %d\n",BinaryTreeSrchHeightOf(12));
    nodoPosition.y =  (secuenciaPrueba[0].heigth*(2*nodoSize.y))+secuenciaPrueba[0].heigth;
    nodoPosition.x = initXposition;
    lastPosition = nodoPosition;
    //convertir el valor del nodo en wchar_t para ponerlo en la ventana
    swprintf(nodoText,L"%d",secuenciaPrueba[0].info);
    //crear la ventana donde va el valor del nodo
    //lblElement = CreateWindowEx(0,L"static",nodoText,WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,nodoPosition.x,nodoPosition.y,nodoSize.x,nodoSize.y,masterWindow,NULL,NULL,NULL);
    lblElement = CreateWindowEx(0,L"static",L"2",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,nodoPosition.x,nodoPosition.y,30,30,masterWindow,NULL,NULL,NULL);
    secuenciaPrueba[0].fPosition = nodoPosition;

    //Automatizar el procedimiento para los demas nodos
    for(int i = 1; i <= lenSequence-1; i++){
        nodoPosition.x = lastPosition.x+nodoSize.x;
        nodoPosition.y =  (secuenciaPrueba[i].heigth*(2*nodoSize.y))+secuenciaPrueba[i].heigth;;
        //printf("%d-%d\n",nodoPosition.x,nodoPosition.y);
        swprintf(nodoText,L"%d",secuenciaPrueba[i].info);
        lblElement = CreateWindowEx(0,L"static",nodoText,WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,nodoPosition.x,nodoPosition.y,nodoSize.x,nodoSize.y,masterWindow,NULL,NULL,NULL);
        lastPosition = nodoPosition;
        secuenciaPrueba[i].fPosition = nodoPosition;
    }

    // printf("posiciones guardadas");
    // for(int i = 0; i <= lenSequence-1; i++){
    //     printf("%d-%d\n",secuenciaPrueba[i].fPosition.x,secuenciaPrueba[i].fPosition.y);
    // }

}

// void paintBinaryTreeConections(){
//     hDC = BeginPaint(panelBinaryTree,&ps);
//     for(int i = 0; i <= 10-1; i++){
//         int j = buscarIndice(secuenciaPrueba[i].father);
//         if(j != -1){
//             printf("%d-%d/%d-%d/%d/%d\n",secuenciaPrueba[i].fPosition.x,secuenciaPrueba[i].fPosition.y,secuenciaPrueba[j].fPosition.x,secuenciaPrueba[j].fPosition.y,j,secuenciaPrueba[i].father);
            
//             MoveToEx(hDC,secuenciaPrueba[i].fPosition.x+15,secuenciaPrueba[i].fPosition.y+15,NULL);
//             int j = buscarIndice(secuenciaPrueba[i].father);
//             LineTo(hDC,secuenciaPrueba[j].fPosition.x+15,secuenciaPrueba[j].fPosition.y+15); 
            
//         }
//     }
//     EndPaint(panelBinaryTree,&ps);
// }

int buscarIndice(int nodo){
    printf("buscar\n");
    for(int i = 0; i <= 10-1; i++){
        if(secuenciaPrueba[i].info == nodo){
            return i;
        };
    }
    return -1;
}   


void initBTSimulacion(){
    secuenciaPrueba[0].heigth = 3;
    secuenciaPrueba[0].info = 2;
    secuenciaPrueba[0].father = 10;

    secuenciaPrueba[1].heigth = 4;
    secuenciaPrueba[1].info = 6;
    secuenciaPrueba[1].father = 2;

    secuenciaPrueba[2].heigth = 2;
    secuenciaPrueba[2].info = 10;
    secuenciaPrueba[2].father = 12;

    secuenciaPrueba[3].heigth = 1;
    secuenciaPrueba[3].info = 12;
    secuenciaPrueba[3].father = 0;

    secuenciaPrueba[4].heigth = 3;
    secuenciaPrueba[4].info = 13;
    secuenciaPrueba[4].father = 16;

    secuenciaPrueba[5].heigth = 4;
    secuenciaPrueba[5].info = 15;
    secuenciaPrueba[5].father = 13;


    secuenciaPrueba[6].heigth = 2;
    secuenciaPrueba[6].info = 16;
    secuenciaPrueba[6].father = 12;

    secuenciaPrueba[7].heigth = 4;
    secuenciaPrueba[7].info = 17;
    secuenciaPrueba[7].father = 18;

    secuenciaPrueba[8].heigth = 3;
    secuenciaPrueba[8].info = 18;
    secuenciaPrueba[8].father = 16;
    
    secuenciaPrueba[9].heigth = 4;
    secuenciaPrueba[9].info = 19;
    secuenciaPrueba[9].father = 18; 
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