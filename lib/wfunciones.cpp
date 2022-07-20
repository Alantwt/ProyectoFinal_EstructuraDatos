//INICIAR COMPONENTES
void initComponents(HWND masterWindow){
    //Predefinir el tamaño de cada elemento del arbol binario
    elementSize.x = 10;
    elementSize.y = 10;
    //Definir la posicion inicial de cada elemento en X
    lastPositionX = 10;
    //Entrada del usuario
    lblUserInput = CreateWindowEx(0,L"static",L"Ingrese la secuencia",WS_VISIBLE|WS_CHILD,20,20,150,20,masterWindow,NULL,NULL,NULL); 
    wUserInput = CreateWindowEx(0,L"edit",L"",WS_VISIBLE|WS_CHILD|WS_BORDER|SS_CENTER|ES_MULTILINE|ES_AUTOVSCROLL,170,20,150,20,masterWindow,NULL,NULL,NULL);
    //RadioButtons
    rbtnInOrder = CreateWindowEx(0,L"button",L"InOrder",WS_VISIBLE|WS_CHILD|BS_RADIOBUTTON,20,50,80,20,masterWindow,(HMENU)RBTNinOrder,NULL,NULL);
    rbtnPostOrder = CreateWindowEx(0,L"button",L"PostOrder",WS_VISIBLE|WS_CHILD|BS_RADIOBUTTON,100,50,100,20,masterWindow,(HMENU)RBTNpostOrder,NULL,NULL);;
    rbtnPreOrder = CreateWindowEx(0,L"button",L"PreOrder",WS_VISIBLE|WS_CHILD|BS_RADIOBUTTON,200,50,100,20,masterWindow,(HMENU)RBTNpreOrder,NULL,NULL);;
}   

//ACCION DE LOS BOTONES
void generarButtonAction(HWND masterWindow, int heightBT){
    panelBinaryTree = CreateWindowEx(0,L"static",NULL,WS_VISIBLE|WS_CHILD|WS_BORDER,20,60,(elementSize.x+10)*(heightBT+heightBT),(heightBT*elementSize.y)+heightBT,masterWindow,NULL,NULL,NULL);
}

void inOrderRbuttonAction(){

}
void preOrderRbuttonAction(){

}
void postOrderRbtnAction(){

}