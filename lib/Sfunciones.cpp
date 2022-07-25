
#include "../include/Sfunciones.h"

int splitStringBy(wchar_t* stringS,char symbol,int** list){
    wchar_t* cadTemp;
    wstring cadenaT;
    wchar_t* t;
    cadTemp = (wchar_t*)calloc(1,sizeof(wchar_t));
    *list = (int*)calloc(1,sizeof(int));
    int i = 0;
    int cadCom = 0;
    
    for(int c = 0; c <= wcslen(stringS)-1; c++){
        if(stringS[c] != symbol){
            //SI ENCUENTRA QUE NO ES UN NUMERO ELIMINA LA MEMORIA DEL PUNTERO Y RETORNA 0
            //cout<<isdigit(stringS[c])<<endl;
            if(isdigit(stringS[c]) != 1){free(*list);return 0;}
            cadTemp = (wchar_t*)realloc(cadTemp,(c+1)*sizeof(wchar_t));
            cadenaT = stringS[c];
            t = _wcsdup(cadenaT.c_str());
            wcscat(cadTemp,t);
            cadenaT = L"";
        }
        if((stringS[c] == symbol || c == wcslen(stringS)-1)&&(cadenaT != L"0")){
            *list = (int*)realloc(*list,(i+1)*sizeof(int));
            //TRANSFORMA LA CADENA EN ENTEROS Y LOS AGREGA A LA LISTA DE INTS 
            *((*list)+i) = _wtoi(cadTemp); 
            wcscpy(cadTemp,L"");
            //printf("numero:%d\ni:%d\n",*(*list+i),i);
            i++;
        }
    }
    return i;

}
