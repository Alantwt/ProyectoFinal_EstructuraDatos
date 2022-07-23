#include "../include/wfunciones.h" 
#include "../include/Sfunciones.h"
#include "../include/funciones.h"


//INICIAR COMPONENTES
void initComponents(HWND masterWindow){
    //Entrada del usuario
    lblUserInput = CreateWindowEx(0,L"static",L"Ingrese la secuencia",WS_VISIBLE|WS_CHILD,20,20,150,25,masterWindow,NULL,NULL,NULL); 
    wUserInput = CreateWindowEx(0,L"edit",L"",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER|ES_MULTILINE|ES_AUTOHSCROLL,170,20,200,25,masterWindow,NULL,NULL,NULL);
    //RadioButtons
    rbtnInOrder = CreateWindowEx(0,L"button",L"InOrder",WS_VISIBLE|WS_CHILD|BS_RADIOBUTTON,20,50,80,25,masterWindow,(HMENU)RBTNinOrder,NULL,NULL);
    rbtnPostOrder = CreateWindowEx(0,L"button",L"PostOrder",WS_VISIBLE|WS_CHILD|BS_RADIOBUTTON,100,50,100,25,masterWindow,(HMENU)RBTNpostOrder,NULL,NULL);;
    rbtnPreOrder = CreateWindowEx(0,L"button",L"PreOrder",WS_VISIBLE|WS_CHILD|BS_RADIOBUTTON,200,50,100,25,masterWindow,(HMENU)RBTNpreOrder,NULL,NULL);
    //BUTTONS
    btnGenerar = CreateWindowEx(0,L"button",L"Generar",WS_VISIBLE|WS_CHILD,390,20,70,25,masterWindow,(HMENU)BTNgenerar,NULL,NULL);
}

void BinaryTreePanelCreate(HWND masterWindow){
    panelBinaryTree = CreateWindowEx(0,L"static",NULL,WS_VISIBLE|WS_CHILD|WS_BORDER,0,80,wSize.x,wSize.y,masterWindow,NULL,NULL,NULL);
}

//ACCION DE LOS BOTONES
void generarButtonAction(HWND masterWindow){
    resetWindow();
    //printf("iniciar: %d-%d\n",wSize.x,wSize.y);
    panelBinaryTree = CreateWindowEx(0,L"static",NULL,WS_VISIBLE|WS_CHILD|WS_BORDER,0,100,wSize.x,wSize.y,masterWindow,NULL,NULL,NULL);
    GetWindowTextW(wUserInput,userInput,600);
    lenSequence = splitStringBy(userInput,',',&sequence);
    printf("%dlen\n",lenSequence);
    //VERIFICAR NUMEROS REPETIDOS Y ELIMINARLOS
    int u = 0;
    for(int i = 0; i <= lenSequence-1; i++){
        for(int j = i+1; j <= lenSequence-1; j++){
            if(*(sequence+i) == *(sequence+j)){
                printf("iguales %d-%d/%d-%d\n",i,j,*(sequence +j),*(sequence+(j+1)));
                *(sequence +j) = *(sequence+(j+1));
            }
            else{
                printf("diferentes %d-%d\n",i,j);
            }
        }
    }
    for(int i = 0; i <= lenSequence-1; i++){
        printf("\nsequence %d : %d",i,*(sequence+i));
    }
    BinaryTreeGenerate(&sequence,lenSequence,orderOption);
    paintBinaryTree(panelBinaryTree,lenSequence);
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
    BinaryTreeInorden(&sequence,&lenSequence);
    nodosPositions = (XY*)calloc(lenSequence,sizeof(XY));
    //initBTSimulacion();
    //Predefinir el tamaño de cada elemento del arbol binario
    nodoSize.x = 30;
    nodoSize.y = 30;
    //Definir la posicion inicial del primer nodo en X
    initXposition = 300;
    //formula para saber la posicion en y del nodo: (altura * (2*tamaño del rectangulo del nodo)+altura del nodo)
    printf("\nAltura buscada: %d\n",BinaryTreeSrchHeightOf(sequence[0]));
    wNodoHeigth = BinaryTreeSrchHeightOf(sequence[0]);
    nodoPosition.y =  (wNodoHeigth*(2*nodoSize.y))+wNodoHeigth;
    nodoPosition.x = initXposition;
    lastPosition = nodoPosition;
    //convertir el valor del nodo en wchar_t para ponerlo en la ventana
    swprintf(nodoText,L"%d",sequence[0]);
    //crear la ventana donde va el valor del nodo
    //lblElement = CreateWindowEx(0,L"static",nodoText,WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,nodoPosition.x,nodoPosition.y,nodoSize.x,nodoSize.y,masterWindow,NULL,NULL,NULL);
    lblElement = CreateWindowEx(0,L"static",nodoText,WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,nodoPosition.x,nodoPosition.y,30,30,masterWindow,NULL,NULL,NULL);
    *(nodosPositions+0) = nodoPosition;
    //Automatizar el procedimiento para los demas nodos
    for(int i = 1; i <= lenSequence-1; i++){
        printf("------------------------------------------------\n");
        //printf("\nAltura buscada: %d-%d\n",BinaryTreeSrchHeightOf(*(sequence+i)),*(sequence+i));
        wNodoHeigth = BinaryTreeSrchHeightOf(*(sequence+i));
        nodoPosition.x = lastPosition.x+nodoSize.x;
        nodoPosition.y =  (wNodoHeigth*(2*nodoSize.y))+wNodoHeigth;
        printf("%d-%d\n",nodoPosition.x,nodoPosition.y);
        swprintf(nodoText,L"%d",*(sequence+i));
        _putws(nodoText);
        printf("\n**%d**\n",*(sequence+i));
        lblElement = CreateWindowEx(0,L"static",nodoText,WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,nodoPosition.x,nodoPosition.y,nodoSize.x,nodoSize.y,masterWindow,NULL,NULL,NULL);
        lastPosition = nodoPosition;
        *(nodosPositions+i) = nodoPosition;
        wNodoHeigth = 0;
    }
}

void paintBinaryTreeConections(){
    printf("pintas");
    hDC = BeginPaint(panelBinaryTree,&ps);
    int j = 0;
    for(int i = 0; i <= lenSequence-1; i++){
        fatherElement = BinaryTreeSrchFather(*(sequence+i));
        if(fatherElement != 0){
            printf("Father: %d",fatherElement);
            j = searchIndex(fatherElement);
            if(j != -1){
                printf("%d-%d/%d-%d\n",(nodosPositions+i)->x,(nodosPositions+i)->y,(nodosPositions+j)->x,(nodosPositions+i)->y);
                //MoveToEx(hDC,(nodosPositions+i)->x+nodoSize.x/2,(nodosPositions+i)->y+nodoSize.y/2,NULL);
                //LineTo(hDC,(nodosPositions+j)->x+nodoSize.x/2, (nodosPositions+j)->y+nodoSize.y/2);
           }
        }
    }
    EndPaint(panelBinaryTree,&ps);
    printf("pintas fin");
}

int searchIndex(int element){
    for(int i = 0; i <= lenSequence-1; i++){
        if(*(sequence+i) == element){
            return i;
        }
    }
    return -1;
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