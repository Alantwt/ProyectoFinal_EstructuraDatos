
#define _WIN32_WINNT 0x0500 // Es necesaria esta definicion para esconder ventana de consola; 0x0500 son las versiones de windows con las que es compatible

#include "../include/funciones.h"
#include "../include/wfunciones.h"

int WINAPI WinMain (HINSTANCE hThisInstance,HINSTANCE hPrevInstance,LPSTR lpszArgument,int nCmdShow){

     //ESTILO DE LA VENTANA
    wClass.hInstance = hThisInstance;
    wClass.lpszClassName = (LPCWSTR)className;
    wClass.lpfnWndProc = WindowProcedure;
    wClass.style = CS_DBLCLKS;                      //Hace que la ventana diferencie entre un click y doble click
    wClass.cbSize = sizeof (WNDCLASSEX);            //Indica a la ventana cual es el tamaño en bit que ocupara la ventana de estilos

    wClass.hIconSm = LoadIcon (NULL, IDI_WINLOGO);  //modifica el icono de la aplicacion en la ventana y tambien en el escritorio
    wClass.hCursor = LoadCursor (NULL, IDC_ARROW);  //Cambia el estilo del cursor
    wClass.lpszMenuName = NULL;                     //Se crea un Menu
    wClass.cbClsExtra = 0;
    wClass.cbWndExtra = 0;
    wClass.hbrBackground = (HBRUSH) COLOR_WINDOW; //Cambia el color de fondo de la ventana
    


    //SE VALIDA LA CLASE VENTANA
    if (!RegisterClassEx(&wClass))return 0;

    //CREAR LA VENTANA
    mainW = CreateWindowEx(
        0,
        className,                      //Tipo de la ventana
        L"Concecionario De Autos",      //Titulo de la ventana
        WS_OVERLAPPEDWINDOW|WS_BORDER, 
        200,30,                         //Posicion 'x' y 'y' de la ventana  
        1000,700,                       //Tamaño de la ventana en 'x' y 'y'    
        HWND_DESKTOP,                   //Ventana Padre
        NULL,                           //Sin Menu
        hThisInstance,                  
        NULL                 
    );

    //HACER LA VENTANA VISIBLE
    ShowWindow (mainW, nCmdShow);

    //ESCONDER LA VENTANA DEL CMD
    //ShowWindow(GetConsoleWindow(), SW_HIDE );


    //BUCLE DE LA VENTANA, SE EJECUTA HASTA QUE SEA 0
    while (GetMessage (&msgW, NULL, 0, 0)){

        //Traduce mensajes virtual-key 
        TranslateMessage(&msgW);

        //Envia mensajes a WindowProcedure 
        DispatchMessage(&msgW);

    }



    return msgW.wParam;

}

LRESULT CALLBACK WindowProcedure(HWND mainWindow,UINT messageW,WPARAM wParam,LPARAM lParam){

    //GESTION DE MENSAJES
    switch (messageW)
    {
        case WM_CLOSE: //MENSAJE DE CERRAR LA VENTANA
            DestroyWindow(mainWindow);
            break;

        case WM_DESTROY://MENSAJE PARA DESTRUIR LA VENTANA 
            PostQuitMessage(0);
            break;

        case WM_CREATE:
            initComponents(mainWindow);
            break;

        case WM_COMMAND:
            if(LOWORD(BTNgenerar) == wParam)generarButtonAction(mainWindow,4);
            else if(LOWORD(RBTNinOrder) == wParam)inOrderRbuttonAction();
            else if(LOWORD(RBTNpostOrder) == wParam)preOrderRbuttonAction();
            else if(LOWORD(RBTNpreOrder) == wParam)postOrderRbtnAction();
            break;
    
        default:  

            return DefWindowProc (mainWindow, messageW, wParam, lParam);
    }
}