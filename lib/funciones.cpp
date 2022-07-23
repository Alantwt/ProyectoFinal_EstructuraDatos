#include "../include/funciones.h"

//SE ENCARGA DE GENERAR EL ARBOL BINARIO CON EL INPUT DEL USUARIO 
void BinaryTreeGenerate(int** sequence, int lenSequence, char* option){
    //Dar espacio en memoria para el array de post, in, pre, order
    orderSecuencia = (int*)calloc(lenSequence,sizeof(int));
    
    // printf("\n___________________________________________________________\n");
    // printf("\nGenerar Arbol\n");
    BinaryTreeDelete(&arbolBinario);
    BTsequence = sequence;
    BTlenSequence = lenSequence;
    iSequence = 0;
    BinaryTree* father = NULL;
    //BUCLE PARA ITERAR TODOS LOS ELEMENTOS DEL SEQUENCE QUE ES UN ARRAY DE ENTEROS 
    for(iSequence = 0; iSequence <= lenSequence-1; iSequence++){
        BinaryTreeFill(&arbolBinario,&father,*((*sequence)+iSequence), sequence);
    }
    // printf("\nGenerar Arbol Fin\n");
    // printf("\n___________________________________________________________\n");

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
    // printf("\n___________________________________________________________\n");
    // printf("\nBuscar Altura\n");
    counterHeigth = 0;
    nodoFound = false;
    // for(int i = 0; i <= BTlenSequence-1; i++){
    //     printf("arbol binario: %d",*((*BTsequence)+i));
    // }
    srcHeigth(&arbolBinario,element);
    // if(nodoFound == true)return heigthFound;
    // else return 0;
    // printf("**%d**",heigthFound);
    // printf("\nBuscar Altura fin\n");
    // printf("\n___________________________________________________________\n");
    return heigthFound;
}

//PROCESO RECURSIVO PARA BUSCAR LA ALTURA DEL ELEMENTO INDICADO
void srchHeigth(BinaryTree** nodo, int element){
    //CADA VEZ QUE ENTRE A ESTA FUNCION SE AUMENTA EN 1 PARA SIMULAR LA ALTURA DEL NODO
    counterHeigth++;
    printf("\nH:%d, E: %d, e: %d, xd: %d\n",counterHeigth,(*nodo)->info, element,arbolBinario->info);
    if(element == (*nodo)->info){
        printf("es igual H: %d\n",counterHeigth);
        //SI ENCUENTRA EL VALOR PEDIDO SE ESTABLECE EN LA VARIABLE UN TRUE INDICANDO QUE YA SE ENCONTRO
        nodoFound = true;
        //SE ALMACENA LA ALTURA EN UNA VARIABLE 
        heigthFound = counterHeigth;
        return;
    }else if (nodoFound == false){
        //SOLO ENTRA AQUI SI SE ESTABLECE QUE EL NODO PEDIDO POR EL USUARIO NO SE AH ENCONTRADO
        printf("no es igual\n");
        if((*nodo)->izquierdo != NULL){
            //SE VA A LA ISQUIERDA
            //printf("va a la parte izquierda, E: %d\n",(*nodo)->info);
            srchHeigth(&(*nodo)->izquierdo, element);
        }
        //else printf("izquierda NUll\n");

        if((*nodo)->derecho != NULL){
            //SE VA A LA RAMA DERECHA
            //printf("va a la parte derecha, E: %d\n",(*nodo)->info);
            srchHeigth(&(*nodo)->derecho, element);
        }
        //else printf("derecha NULL\n");
        //CONFORME VA REGRESANDO A LAS FUNCIONES ANTERIOES(QUE SON ESTA MISMAS*RECORDAR QUE ES UN PROCESO RECURSIVO*) REDUCE EN 1 LA ALTURA PARA TENER LA ALTURA CORRECTA
        counterHeigth--;
    }
}   

void srcHeigth(BinaryTree** nodo, int element){
    counterHeigth++;
    if(*(nodo) != NULL){
        if(element == (*nodo)->info){
           printf("Encontrado element: %d, H:%d\n",(*nodo)->info,counterHeigth); 
           heigthFound = counterHeigth;
        }
        if((*nodo)->izquierdo != NULL){
            srcHeigth(&(*nodo)->izquierdo,element);
        }
        if((*nodo) != NULL){
            srcHeigth(&(*nodo)->derecho,element);
        }
    }//else printf("Sin Elementos\n");
    counterHeigth--;
}
//FUNCION PARA BUSCAR EL PADRE DE UN NODO RECIBIDO COMO PARAMETRO
int BinaryTreeSrchFather(int element){
    // printf("\n___________________________________________________________\n");
    // printf("\nBuscar Padre\n");
    fatherElement = 0;
    fatherFound = false;
    srchFather(&arbolBinario, element);
    // printf("\nBuscar Padre Fin\n");
    // printf("\n___________________________________________________________\n");
    printf("\nFather: %d E: %d\n",fatherElement,element);
    if(fatherFound == true)return fatherElement;
    else return 0;
}

void srchFather(BinaryTree** nodo, int element){
    
    if(*nodo != NULL && fatherFound == false){
        printf("\nentra\n");
        printf("\nf: %d- e: %d",(*nodo)->info,element);
        if((*nodo)->izquierdo != NULL){
            if((*nodo)->izquierdo->info == element){
                fatherFound = true;
            }
        }
        if((*nodo)->derecho != NULL){
            if((*nodo)->derecho->info == element){
                fatherFound = true;
            }
        }
        if(fatherFound == true){
            fatherElement = (*nodo)->info;
        }
        else {
            srchFather(&(*nodo)->izquierdo,element);
            srchFather(&(*nodo)->derecho,element);
        }
    }
    else return;
}

//FUNCION PARA LLENAR EL ARBOL BINARIO CON EL INPUT DEL USUARIO, ES UN PROCESO RECURSIVO
void BinaryTreeFill(BinaryTree** nodo, BinaryTree** father, int element, int** sequence){
    // printf("\n___________________________________________________________\n");
    // printf("\nLLenar Arbol\n");
    if(*nodo == NULL){
        *nodo = (BinaryTree*)calloc(1,sizeof(BinaryTree));
        (*nodo)->info = element;
        (*nodo)->derecho = NULL;
        (*nodo)->izquierdo = NULL;
        //cout<<*nodo<<endl;

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
    // printf("\nLLenar Arbol Fin\n");
    // printf("\n___________________________________________________________\n");
}

//BORRAR ARBOL BINARIO
void BinaryTreeDelete(BinaryTree** nodo){
    if(*nodo != NULL){
        if((*nodo)->izquierdo != NULL){
            BinaryTreeDelete(&(*nodo)->izquierdo);
            (*nodo)->izquierdo = NULL;
        }
        if((*nodo)->derecho != NULL){
            BinaryTreeDelete(&(*nodo)->derecho);
            (*nodo)->derecho = NULL;
        }
        *nodo = NULL;
    }
}

//RECORRIDO INORDER
void BinaryTreeInorden(int** sequence, int* lenSequence){
    counterInOrder = 0;
    // printf("\n___________________________________________________________\n");
    // printf("\nInOrder\n");
    inOrden(&arbolBinario,sequence);
    printf("\nIn Order fin\n");
    printf("\n___________________________________________________________\n");
}

void inOrden(BinaryTree** nodo,int** sequence){
    if(*nodo != NULL){
        if(counterHeigth == BTlenSequence)return;
        if((*nodo)->izquierdo != NULL){
            inOrden(&(*nodo)->izquierdo, sequence);
        }
        *(*sequence+counterInOrder) = (*nodo)->info;
        counterInOrder++;
        printf("\nIO:%d-%d\n",(*nodo)->info,counterInOrder);
        if((*nodo)->derecho != NULL){
            inOrden(&(*nodo)->derecho,sequence);
        }
    }
}




 