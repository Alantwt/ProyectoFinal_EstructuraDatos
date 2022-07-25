#include "../include/wfunciones.h" 
#include "../include/Sfunciones.h"
#include "../include/funciones.h"


//INICIAR COMPONENTES
void initComponents(HWND masterWindow){
    //Entrada del usuario
    lblUserInput = CreateWindowEx(0,L"static",L"Ingrese la secuencia",WS_VISIBLE|WS_CHILD,20,20,150,25,masterWindow,NULL,NULL,NULL); 
    wUserInput = CreateWindowEx(0,L"edit",L"",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER|ES_MULTILINE|ES_AUTOHSCROLL,170,20,200,25,masterWindow,NULL,NULL,NULL);
    wUserInputBB = CreateWindowEx(0,L"edit",L"",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER|ES_MULTILINE|ES_AUTOHSCROLL,470,55,100,25,masterWindow,NULL,NULL,NULL);
    //RadioButtons
    rbtnInOrder = CreateWindowEx(0,L"button",L"InOrder",WS_VISIBLE|WS_CHILD|BS_RADIOBUTTON,20,50,80,25,masterWindow,(HMENU)RBTNinOrder,NULL,NULL);
    rbtnPostOrder = CreateWindowEx(0,L"button",L"PostOrder",WS_VISIBLE|WS_CHILD|BS_RADIOBUTTON,100,50,100,25,masterWindow,(HMENU)RBTNpostOrder,NULL,NULL);;
    rbtnPreOrder = CreateWindowEx(0,L"button",L"PreOrder",WS_VISIBLE|WS_CHILD|BS_RADIOBUTTON,200,50,100,25,masterWindow,(HMENU)RBTNpreOrder,NULL,NULL);
    //BUTTONS
    btnGenerar = CreateWindowEx(0,L"button",L"Generar",WS_VISIBLE|WS_CHILD,390,20,70,25,masterWindow,(HMENU)BTNgenerar,NULL,NULL);

    //Boton para insertar nuevo nodo al arbol ya creado.
	btnInsertar = CreateWindowEx(0,L"button",L"Insertar nodo",WS_VISIBLE|WS_CHILD,470,20,120,25,masterWindow,(HMENU)BTNinsertar,NULL,NULL);
	//Busca el valor del nodo y lo elimina del arbol, reorganiza el arbol
	btnBorrar = CreateWindowEx(0,L"button",L"Borrar nodo",WS_VISIBLE|WS_CHILD,600,20,100,25,masterWindow,(HMENU)BTNborrar,NULL,NULL);
	//Muestra los hijos del arbol por consola :)
	btnMostrarHijos = CreateWindowEx(0,L"button",L"Mostrar hijos",WS_VISIBLE|WS_CHILD,710,20,120,25,masterWindow,(HMENU)BTNmostrarHijos,NULL,NULL);
    btnMostrarPadres = CreateWindowEx(0,L"button",L"Mostrar Padres",WS_VISIBLE|WS_CHILD,840,20,120,25,masterWindow,(HMENU)BTNmostrarPadres,NULL,NULL);
    btnBuscarNodo = CreateWindowEx(0,L"button",L"Buscar Nodo",WS_VISIBLE|WS_CHILD,970,20,120,25,masterWindow,(HMENU)BTNbuscarNodo,NULL,NULL);
}

void BinaryTreePanelCreate(HWND masterWindow){
    panelBinaryTree = CreateWindowEx(0,L"static",NULL,WS_VISIBLE|WS_CHILD|WS_BORDER,0,80,wSize.x,wSize.y,masterWindow,NULL,NULL,NULL);
}

void inOrderScreen(HWND masterWindow){
    wchar_t cadenaAux[10];
    int inicial = 10;
    lblOrder = CreateWindowEx(0,L"static",L"InOrder",WS_VISIBLE|WS_CHILD,inicial,5,50,20,masterWindow,NULL,NULL,NULL);
    swprintf(cadenaAux,L"%d,",*(sequence+0)); 
    lblOrder = CreateWindowEx(0,L"static",cadenaAux,WS_VISIBLE|WS_CHILD,inicial,20,20,20,masterWindow,NULL,NULL,NULL);
    for(int i = 1; i <= lenSequence-1; i++){
        inicial = inicial+20+wcslen(cadenaAux);
        swprintf(cadenaAux,L"%d,",*(sequence+i));
        lblOrder = CreateWindowEx(0,L"static",cadenaAux,WS_VISIBLE|WS_CHILD,inicial,20,15,20,masterWindow,NULL,NULL,NULL);
    }  
    lblOrder = CreateWindowEx(0,L"static",L"Peso:",WS_VISIBLE|WS_CHILD,10,120,50,20,masterWindow,NULL,NULL,NULL);
    swprintf(cadenaAux,L"%d",lenSequence);
    lblOrder = CreateWindowEx(0,L"static",cadenaAux,WS_VISIBLE|WS_CHILD,55,120,50,20,masterWindow,NULL,NULL,NULL);
}
void preOrderScreen(HWND masterWindow){
    wchar_t cadenaAux[10];
    int inicial = 10;
    lblOrder = CreateWindowEx(0,L"static",L"PreOrder",WS_VISIBLE|WS_CHILD,inicial,5,70,20,masterWindow,NULL,NULL,NULL);
    swprintf(cadenaAux,L"%d,",*(orderSecuencia+0)); 
    lblOrder = CreateWindowEx(0,L"static",cadenaAux,WS_VISIBLE|WS_CHILD,10,20,20,20,masterWindow,NULL,NULL,NULL);
    for(int i = 1; i <= lenSequence-1; i++){
        inicial = inicial+20+wcslen(cadenaAux);
        swprintf(cadenaAux,L"%d,",*(orderSecuencia+i));
        lblOrder = CreateWindowEx(0,L"static",cadenaAux,WS_VISIBLE|WS_CHILD,inicial,20,20,20,masterWindow,NULL,NULL,NULL);
    }  
    lblOrder = CreateWindowEx(0,L"static",L"Peso:",WS_VISIBLE|WS_CHILD,10,120,50,20,masterWindow,NULL,NULL,NULL);
    swprintf(cadenaAux,L"%d",lenSequence);
    lblOrder = CreateWindowEx(0,L"static",cadenaAux,WS_VISIBLE|WS_CHILD,55,120,50,20,masterWindow,NULL,NULL,NULL);
}
void postOrderScreen(HWND masterWindow){
    wchar_t cadenaAux[10];
    int inicial = 10;
    lblOrder = CreateWindowEx(0,L"static",L"PostOrder",WS_VISIBLE|WS_CHILD,inicial,5,80,20,masterWindow,NULL,NULL,NULL);
    swprintf(cadenaAux,L"%d,",*(orderSecuencia+0)); 
    lblOrder = CreateWindowEx(0,L"static",cadenaAux,WS_VISIBLE|WS_CHILD,10,20,20,20,masterWindow,NULL,NULL,NULL);
    for(int i = 1; i <= lenSequence-1; i++){
        inicial = inicial+20+wcslen(cadenaAux);
        swprintf(cadenaAux,L"%d,",*(orderSecuencia+i));
        lblOrder = CreateWindowEx(0,L"static",cadenaAux,WS_VISIBLE|WS_CHILD,inicial,20,20,20,masterWindow,NULL,NULL,NULL);
    }  
    lblOrder = CreateWindowEx(0,L"static",L"Peso:",WS_VISIBLE|WS_CHILD,10,120,50,20,masterWindow,NULL,NULL,NULL);
    swprintf(cadenaAux,L"%d",lenSequence);
    lblOrder = CreateWindowEx(0,L"static",cadenaAux,WS_VISIBLE|WS_CHILD,55,120,50,20,masterWindow,NULL,NULL,NULL);
}

//ACCION DE LOS BOTONES
void generarButtonAction(HWND masterWindow){
    resetWindow();
    //printf("iniciar: %d-%d\n",wSize.x,wSize.y);
    panelBinaryTree = CreateWindowEx(0,L"static",NULL,WS_VISIBLE|WS_CHILD|WS_BORDER,0,100,wSize.x,wSize.y,masterWindow,NULL,NULL,NULL);
    GetWindowTextW(wUserInput,userInput,600);
    if((wcslen(userInput) > 0)&&(wcscmp(userInput,L"0") == 1)){
        lenSequence = splitStringBy(userInput,',',&sequence);
        if(lenSequence > 0){
            //VERIFICAR NUMEROS REPETIDOS Y ELIMINARLOS
            verificarRepetidos();
            insertSequence = (int*)realloc(insertSequence,lenSequence*sizeof(int));
            for(int i = 0; i <= lenSequence-1; i++){
                *(insertSequence+i) = *(sequence+i);
            }
            BinaryTreeGenerate(&sequence,lenSequence,orderOption);
            paintBinaryTree(panelBinaryTree,lenSequence);
            if(strcmp(orderOption,"inorder") == 0) inOrderScreen(panelBinaryTree);
            else if(strcmp(orderOption,"postorder") == 0) postOrderScreen(panelBinaryTree);
            else if(strcmp(orderOption,"preorder") == 0) preOrderScreen(panelBinaryTree);
        }
    }
    else resetWindow();
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
    BinaryTreeInorden(&sequence,lenSequence);
    nodosPositions = (XY*)calloc(lenSequence,sizeof(XY));
    //initBTSimulacion();
    //Predefinir el tamaño de cada elemento del arbol binario
    nodoSize.x = 50;
    nodoSize.y = 50;
    //Definir la posicion inicial del primer nodo en X
    initXposition = 400;
    //formula para saber la posicion en y del nodo: (altura * (2*tamaño del rectangulo del nodo)+altura del nodo)
    wNodoHeigth = BinaryTreeSrchHeightOf(sequence[0]);
    nodoPosition.y =  (wNodoHeigth*(2*nodoSize.y))+wNodoHeigth;
    nodoPosition.x = initXposition;
    lastPosition = nodoPosition;
    //convertir el valor del nodo en wchar_t para ponerlo en la ventana
    swprintf(nodoText,L"\n%d",sequence[0]);
    //crear la ventana donde va el valor del nodo
    //lblElement = CreateWindowEx(0,L"static",nodoText,WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,nodoPosition.x,nodoPosition.y,nodoSize.x,nodoSize.y,masterWindow,NULL,NULL,NULL);
    lblElement = CreateWindowEx(0,L"static",nodoText,WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,nodoPosition.x,nodoPosition.y,nodoSize.x,nodoSize.y,masterWindow,NULL,NULL,NULL);
    *(nodosPositions+0) = nodoPosition;
    //Automatizar el procedimiento para los demas nodos
    for(int i = 1; i <= lenSequence-1; i++){
        //printf("\nAltura buscada: %d-%d\n",BinaryTreeSrchHeightOf(*(sequence+i)),*(sequence+i));
        wNodoHeigth = BinaryTreeSrchHeightOf(*(sequence+i));
        nodoPosition.x = lastPosition.x+nodoSize.x;
        nodoPosition.y =  (wNodoHeigth*(2*nodoSize.y))+wNodoHeigth;
        swprintf(nodoText,L"\n%d",*(sequence+i));
        _putws(nodoText);
        lblElement = CreateWindowEx(0,L"static",nodoText,WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER,nodoPosition.x,nodoPosition.y,nodoSize.x,nodoSize.y,masterWindow,NULL,NULL,NULL);
        lastPosition = nodoPosition;
        *(nodosPositions+i) = nodoPosition;
        wNodoHeigth = 0;
    }
}

void paintBinaryTreeConections(){
    hDC = BeginPaint(panelBinaryTree,&ps);
    int j = 0;
    for(int i = 0; i <= lenSequence-1; i++){
        fatherElement = BinaryTreeSrchFather(*(sequence+i));
        if(fatherElement != 0){
            j = searchIndex(fatherElement);
            if(j != -1){
                MoveToEx(hDC,(nodosPositions+i)->x+nodoSize.x/2,(nodosPositions+i)->y+nodoSize.y/2,NULL);
                LineTo(hDC,(nodosPositions+j)->x+nodoSize.x/2, (nodosPositions+j)->y+nodoSize.y/2);
           }
        }
    }
    EndPaint(panelBinaryTree,&ps);
}

int searchIndex(int element){
    for(int i = 0; i <= lenSequence-1; i++){
        if(*(sequence+i) == element){
            return i;
        }
    }
    return -1;
}

void insertarButtonAction(HWND masterWindow){
    resetWindow();
    panelBinaryTree = CreateWindowEx(0,L"static",NULL,WS_VISIBLE|WS_CHILD|WS_BORDER,0,100,wSize.x,wSize.y,masterWindow,NULL,NULL,NULL);
    bool isNumer = true;
    GetWindowTextW(wUserInputBB,userInputBB,10);
    for(int i = 0; i <= wcslen(userInputBB)-1; i++){
        if(isdigit(userInputBB[i]) != 1){
            isNumer = false;
            break;
        }
        else isNumer = true;
    }
    
    if((wcscmp(userInputBB,L"") == 1)&&(isNumer == true)&&(lenSequence > 0)){
        lenSequence = lenSequence+1;
        
        sequence = (int*)realloc(sequence,lenSequence*sizeof(int));
        insertSequence = (int*)realloc(insertSequence,lenSequence*sizeof(int));
        *(insertSequence+(lenSequence-1)) = _wtoi(userInputBB);
        
        for(int i = 0; i <= lenSequence-1; i++){
            *(sequence+i) = *(insertSequence+i);
        }
        verificarRepetidos();
        BinaryTreeGenerate(&sequence,lenSequence,orderOption);
        paintBinaryTree(panelBinaryTree,lenSequence);
    }
    if(strcmp(orderOption,"inorder") == 0) inOrderScreen(panelBinaryTree);
    else if(strcmp(orderOption,"postorder") == 0) postOrderScreen(panelBinaryTree);
    else if(strcmp(orderOption,"preorder") == 0) preOrderScreen(panelBinaryTree);
}

void borrarButtonAction(HWND masterWindow){
    resetWindow();
    panelBinaryTree = CreateWindowEx(0,L"static",NULL,WS_VISIBLE|WS_CHILD|WS_BORDER,0,100,wSize.x,wSize.y,masterWindow,NULL,NULL,NULL);
    bool isNumer = true;
    GetWindowTextW(wUserInputBB,userInputBB,10);
    for(int i = 0; i <= wcslen(userInputBB)-1; i++){
        if(isdigit(userInputBB[i]) != 1){
            isNumer = false;
            break;
        }
        else isNumer = true;
    }
    if((wcscmp(userInputBB,L"") == 1)&&(isNumer == true)&&(lenSequence > 0)){
        for(int i = 0; i <= lenSequence-1; i++){
            if(*(insertSequence+i) == _wtoi(userInputBB)){
                *(insertSequence+i) = 0;
            }
        }

        int u = 0;
        for(int i = 0; i <= lenSequence-1; i++){
            for(int j = i+1; j <= lenSequence-1; j++){
                if(*(insertSequence+i) == *(insertSequence+j)){
                    *(insertSequence+j) = 0;
                }
            }
        }
        int c = 0;
        for(int i = 0; i <= lenSequence-1; i++){
            c = i;
            if(*(insertSequence+i) == 0){
                c++;
                for(int j = i; j <= lenSequence-1; j++){
                    *(insertSequence+j) = *(insertSequence+(j+1));
                }
            }
            
        }
        lenSequence = lenSequence-1;
        sequence = (int*)realloc(sequence,lenSequence*sizeof(int));

        for(int i = 0; i <= lenSequence-1; i++){
            *(sequence+i) = *(insertSequence+i);
        }
        insertSequence = (int*)realloc(insertSequence,lenSequence*sizeof(int));
        for(int i = 0; i <= lenSequence-1;i++){
            *(insertSequence+i) = *(sequence+i);
        }   
        BinaryTreeGenerate(&sequence,lenSequence,orderOption);
        paintBinaryTree(panelBinaryTree,lenSequence);
    }
    if(strcmp(orderOption,"inorder") == 0) inOrderScreen(panelBinaryTree);
    else if(strcmp(orderOption,"postorder") == 0) postOrderScreen(panelBinaryTree);
    else if(strcmp(orderOption,"preorder") == 0) preOrderScreen(panelBinaryTree);
}

void mostrarHijosButtonAction(HWND masterWindow){
    DestroyWindow(lblNodosPH);
    if(lenSequence > 0){
        int lenNodosLeaf = BinaryTreeSrchLeafs();
        printf("lenP:%d ",lenNodosLeaf);
        panelNodosPH = CreateWindowEx(0,L"static",L"",WS_VISIBLE|WS_CHILD,0,50,55+((lenNodosLeaf*2)*20),20,panelBinaryTree,NULL,NULL,NULL);
        wchar_t cadenaAux[10];
        lblNodosPH = CreateWindowEx(0,L"static",L"Hoja:",WS_VISIBLE|WS_CHILD,10,0,35,20,panelNodosPH,NULL,NULL,NULL);
        int inicial = 55;
        swprintf(cadenaAux,L"%d,",*(nodosPH+0)); 
        lblOrder = CreateWindowEx(0,L"static",cadenaAux,WS_VISIBLE|WS_CHILD,inicial,0,20,20,panelNodosPH,NULL,NULL,NULL);
        for(int i = 1; i <= lenNodosLeaf-1; i++){
            printf("nodosP:%d ",*(nodosPH+i));
            inicial = inicial+20+wcslen(cadenaAux);
            swprintf(cadenaAux,L"%d,",*(nodosPH+i));
            lblOrder = CreateWindowEx(0,L"static",cadenaAux,WS_VISIBLE|WS_CHILD,inicial,0,20,20,panelNodosPH,NULL,NULL,NULL);
        }  
    }
}

void mostrarPadreButtonAction(HWND masterWindow){
    DestroyWindow(lblNodosPH);
    if(lenSequence > 0){
        int lenNodosPadre = BinaryTreeSrchAllFather(&sequence,lenSequence);

        int u = 0;
        for(int i = 0; i <= lenNodosPadre-1; i++){
            for(int j = i+1; j <= lenNodosPadre-1; j++){
                if(*(nodosPH+i) == *(nodosPH+j)){
                    *(nodosPH +j) = 0;
                }
            }
        }
        int c = 0;
        for(int i = 0; i <= lenNodosPadre-1; i++){
            c = i;
            while((*(nodosPH+i) == 0) && c < lenNodosPadre){
                u++;
                c++;
                for(int j = i; j <= lenNodosPadre-1; j++){
                    *(nodosPH+j) = *(nodosPH+(j+1));
                }
            }  
        }
        lenNodosPadre = lenNodosPadre-u;
        nodosPH = (int*)realloc(nodosPH,lenNodosPadre*sizeof(int));

        printf("lenP:%d ",lenNodosPadre);
        panelNodosPH = CreateWindowEx(0,L"static",L"",WS_VISIBLE|WS_CHILD,0,50,55+((lenNodosPadre*2)*20),20,panelBinaryTree,NULL,NULL,NULL);
        wchar_t cadenaAux[10];
        lblNodosPH = CreateWindowEx(0,L"static",L"Hoja:",WS_VISIBLE|WS_CHILD,10,0,35,20,panelNodosPH,NULL,NULL,NULL);
        int inicial = 55;
        swprintf(cadenaAux,L"%d,",*(nodosPH+0)); 
        lblOrder = CreateWindowEx(0,L"static",cadenaAux,WS_VISIBLE|WS_CHILD,inicial,0,20,20,panelNodosPH,NULL,NULL,NULL);
        for(int i = 1; i <= lenNodosPadre-1; i++){
            printf("nodosP:%d ",*(nodosPH+i));
            inicial = inicial+20+wcslen(cadenaAux);
            swprintf(cadenaAux,L"%d,",*(nodosPH+i));
            lblOrder = CreateWindowEx(0,L"static",cadenaAux,WS_VISIBLE|WS_CHILD,inicial,0,20,20,panelNodosPH,NULL,NULL,NULL);
        }  
    }
}   

void buscarNodoButtonAction(HWND masterWindow){
    DestroyWindow(lblNodosPH);
    if(lenSequence > 0){
        bool isNumer = true;
        GetWindowTextW(wUserInputBB,userInputBB,10);
        for(int i = 0; i <= wcslen(userInputBB)-1; i++){
            if(isdigit(userInputBB[i]) != 1){
                isNumer = false;
                break;
            }
            else isNumer = true;
        }
        if((wcscmp(userInputBB,L"") == 1)&&(isNumer == true)&&(lenSequence > 0)){
            wchar_t cadenaAux[10];
            int lenNodo = BinaryTreeSrchNodo(_wtoi(userInputBB));
            panelNodosPH = CreateWindowEx(0,L"static",L"",WS_VISIBLE|WS_CHILD,0,50,100+((lenNodo*2)*20),20,panelBinaryTree,NULL,NULL,NULL);
            lblNodosPH = CreateWindowEx(0,L"static",L"NodoBuscado:",WS_VISIBLE|WS_CHILD,10,0,100,20,panelNodosPH,NULL,NULL,NULL);
            int inicial = 110;
            swprintf(cadenaAux,L"%d",*(nodosPH+0));
            lblOrder = CreateWindowEx(0,L"static",cadenaAux,WS_VISIBLE|WS_CHILD,120,0,20,20,panelNodosPH,NULL,NULL,NULL);

            for(int i = 1; i <= lenNodo-1; i++){
                printf("nodosP:%d ",*(nodosPH+i));
                inicial = inicial+20+wcslen(cadenaAux)+15;
                swprintf(cadenaAux,L"->%d",*(nodosPH+i));
                lblOrder = CreateWindowEx(0,L"static",cadenaAux,WS_VISIBLE|WS_CHILD,inicial,0,wcslen(cadenaAux)*10,20,panelNodosPH,NULL,NULL,NULL);
            }     

        }
    }
}

bool verificarRepetidos(){
    int u = 0;
    for(int i = 0; i <= lenSequence-1; i++){
        for(int j = i+1; j <= lenSequence-1; j++){
            if(*(sequence+i) == *(sequence+j)){
                *(sequence +j) = 0;
            }
        }
    }
    int c = 0;
    for(int i = 0; i <= lenSequence-1; i++){
        c = i;
        while((*(sequence+i) == 0) && c < lenSequence){
            u++;
            c++;
            for(int j = i; j <= lenSequence-1; j++){
                *(sequence+j) = *(sequence+(j+1));
            }
        }
        
    }
    lenSequence = lenSequence-u;
    sequence = (int*)realloc(sequence,lenSequence*sizeof(int));
}