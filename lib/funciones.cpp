#include "../include/funciones.h"

//SE ENCARGA DE GENERAR EL ARBOL BINARIO CON EL INPUT DEL USUARIO 
void BinaryTreeGenerate(int** sequence, int lenSequence, char* option){
    BTsequence = sequence;
    BTlenSequence = lenSequence;
    iSequence = 0;
    BinaryTree* father = NULL;
    //BUCLE PARA ITERAR TODOS LOS ELEMENTOS DEL SEQUENCE QUE ES UN ARRAY DE ENTEROS 
    //[3][1][4][2][6][7]
    for(iSequence = 0; iSequence <= lenSequence-1; iSequence++){
        BinaryTreeFill(&arbolBinario,&father,*((*sequence)+iSequence), sequence);
    }
    // for(int i = 0; i <= lenSequence-1; i++){
    //     cout<<*(sequence+i)<<endl;
    // }

    // if(strcmp(option,"preorder")){
    //      BinaryTreePreorden( sequence, lenSequence,  option);
    // }
    // else if(strcmp(option,"postorder")){
    //     BinaryTreeInorden( sequence,  lenSequence, option);
    // }
    // if(strcmp(option,"postorder")){
    //     BinaryTreePostorden(sequence,  lenSequence);
    // }
}

//FUNCION PARA BUSCAR ALTURA DE UN ELEMENTO, USA EL PROCESO RECURSIVO DE ABAJO
int BinaryTreeSrchHeightOf(int element){
    for(int i = 0; i <= BTlenSequence-1; i++){
        printf("arbol binario: %d",*((*BTsequence)+i));
    }
    srchHeigth(&arbolBinario,element);
    if(nodoFound == true)return heigthFound;
    else return 0;
}

//PROCESO RECURSIVO PARA BUSCAR LA ALTURA DEL ELEMENTO INDICADO
void srchHeigth(BinaryTree** nodo, int element){
    //CADA VEZ QUE ENTRE A ESTA FUNCION SE AUMENTA EN 1 PARA SIMULAR LA ALTURA DEL NODO
    counterHeigth++;
    //printf("\nH:%d, E: %d\n",counterHeigth,(*nodo)->info);
    if(element == (*nodo)->info){
        //printf("es igual H: %d\n",counterHeigth);
        //SI ENCUENTRA EL VALOR PEDIDO SE ESTABLECE EN LA VARIABLE UN TRUE INDICANDO QUE YA SE ENCONTRO
        nodoFound = true;
        //SE ALMACENA LA ALTURA EN UNA VARIABLE 
        heigthFound = counterHeigth;
        return;
    }else if (nodoFound == false){
        //SOLO ENTRA AQUI SI SE ESTABLECE QUE EL NODO PEDIDO POR EL USUARIO NO SE AH ENCONTRADO
        //printf("no es igual\n");
        if((*nodo)->izquierdo != NULL){
            //SE VA A LA ISQUIERDA
            printf("va a la parte izquierda, E: %d\n",(*nodo)->info);
            srchHeigth(&(*nodo)->izquierdo, element);
        }
        else printf("izquierda NUll\n");

        if((*nodo)->derecho != NULL){
            //SE VA A LA RAMA DERECHA
            printf("va a la parte derecha, E: %d\n",(*nodo)->info);
            srchHeigth(&(*nodo)->derecho, element);
        }
        else printf("derecha NULL\n");
        //CONFORME VA REGRESANDO A LAS FUNCIONES ANTERIOES(QUE SON ESTA MISMAS*RECORDAR QUE ES UN PROCESO RECURSIVO*) REDUCE EN 1 LA ALTURA PARA TENER LA ALTURA CORRECTA
        counterHeigth--;
    }
}   

//FUNCION PARA BUSCAR EL PADRE DE UN NODO RECIBIDO COMO PARAMETRO
int BinaryTreeSrchFather(int element){
    for(int i = 0; i <= BTlenSequence; i++){

    }
}

//FUNCION PARA LLENAR EL ARBOL BINARIO CON EL INPUT DEL USUARIO, ES UN PROCESO RECURSIVO
void BinaryTreeFill(BinaryTree** nodo, BinaryTree** father, int element, int** sequence){
    //printf("LLenar el arbol binario\n");
    if(*nodo == NULL){
        *nodo = (BinaryTree*)calloc(1,sizeof(BinaryTree));
        (*nodo)->info = element;
        (*nodo)->derecho = NULL;
        (*nodo)->izquierdo = NULL;
        cout<<*nodo<<endl;

        if(*father != NULL){
            if(element > (*father)->info){
                //SI EL ELEMENTO ES MAYOR QUE EL NODO PADRE SE POSICIONA A LA DERECHA DEL NODO PADRE
                (*father)->derecho = *nodo;
            }else{
                //SI EL ELEMENTO ES MENOR SE POSICIONA A LA IZQUIERDA DEL NODO PADRE
                (*father)->izquierdo = *nodo;
            }
        } 
        else{
            //SI EL NODO PADRE ES NULL SIGNIFICA QUE EL EL NODO RAIZ Y RETORNA
            return;
        }
    }else{
        //ENTRA AQUI SI EL NODO ACTUAL ES DIFERENTE A NULL, OSEA SI TIENE MEMORIA Y ESTA LLENO
        if(element > (*nodo)->info){
            //SI EL VALOR DE LA SECUENCIA ES MAYOR AL NODO HACE UN PROCESO RECURSIVO PARA MANDAR AL NODO HIJO DE LA PARTE DERECHA A ESTA MISMA FUNCION
            BinaryTreeFill(&(*nodo)->derecho, &*nodo, element, sequence);
        }
        if(element < (*nodo)->info){
            //SI EL VALOR DE LA SECUENCIA ES MENOR AL NODO HACE UN PROCESO RECURSIVO PARA MANDAR AL NODO HIJO DE LA PARTE IZQUIERDA A ESTA MISMA FUNCION
            BinaryTreeFill(&(*nodo)->izquierdo, &*nodo, element, sequence);
        }
    }
}


// int BinaryTreePostorden(int** sequence, int lenSequence){
//         if(arbolBinario != NULL){
//         BinaryTreePostorden(*(*arbolBinario)->izquierdo, lenSequence);
//         BinaryTreePostorden(*(*arbolBinario)->derecho, lenSequence);
//         printf("%d",arbolBinario->info);
//     }
// }