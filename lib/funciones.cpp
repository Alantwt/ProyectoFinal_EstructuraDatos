#include "../include/funciones.h"

//SE ENCARGA DE GENERAR EL ARBOL BINARIO CON EL INPUT DEL USUARIO 
void BinaryTreeGenerate(int** sequence, int lenSequence, char* option){
    nodosPH = (int*)calloc(1,sizeof(int));
    lenNodosPH = 0;
    BinaryTreeDelete(&arbolBinario);
    //Dar espacio en memoria para el array de post, in, pre, order
    orderSecuencia = (int*)calloc(lenSequence,sizeof(int));
    // printf("\nGenerar Arbol\n");
    BTsequence = sequence;
    BTlenSequence = lenSequence;
    iSequence = 0;
    BinaryTree* father = NULL;
    //BUCLE PARA ITERAR TODOS LOS ELEMENTOS DEL SEQUENCE QUE ES UN ARRAY DE ENTEROS 
    for(iSequence = 0; iSequence <= lenSequence-1; iSequence++){
        printf("\nnodo:%d\n",*((*sequence)+iSequence));
        BinaryTreeFill(&arbolBinario,&father,*((*sequence)+iSequence), sequence);
    }

    if(strcmp(option,"preorder") == 0){
         BinaryTreePreorden( &orderSecuencia, lenSequence);
    }
    if(strcmp(option,"postorder") == 0){
        BinaryTreeInorden(&orderSecuencia,lenSequence);
    }
    if(strcmp(option,"postorder") == 0){
        BinaryTreePostorden(&orderSecuencia,lenSequence);
    }
}

//FUNCION PARA BUSCAR ALTURA DE UN ELEMENTO, USA EL PROCESO RECURSIVO DE ABAJO
int BinaryTreeSrchHeightOf(int element){
    counterHeigth = 0;
    nodoFound = false;
    srcHeigth(&arbolBinario,element);
    return heigthFound;
}

//PROCESO RECURSIVO PARA BUSCAR LA ALTURA DEL ELEMENTO INDICADO
void srchHeigth(BinaryTree** nodo, int element){
    //CADA VEZ QUE ENTRE A ESTA FUNCION SE AUMENTA EN 1 PARA SIMULAR LA ALTURA DEL NODO
    counterHeigth++;
    if(element == (*nodo)->info){
        //SI ENCUENTRA EL VALOR PEDIDO SE ESTABLECE EN LA VARIABLE UN TRUE INDICANDO QUE YA SE ENCONTRO
        nodoFound = true;
        //SE ALMACENA LA ALTURA EN UNA VARIABLE 
        heigthFound = counterHeigth;
        return;
    }else if (nodoFound == false){
        //SOLO ENTRA AQUI SI SE ESTABLECE QUE EL NODO PEDIDO POR EL USUARIO NO SE AH ENCONTRADO
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
    if(fatherFound == true)return fatherElement;
    else return 0;
}

void srchFather(BinaryTree** nodo, int element){
    
    if(*nodo != NULL && fatherFound == false){
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
    if(*nodo == NULL){
        *nodo = (BinaryTree*)calloc(1,sizeof(BinaryTree));
        (*nodo)->info = element;
        (*nodo)->derecho = NULL;
        (*nodo)->izquierdo = NULL;

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
void BinaryTreeInorden(int** sequence, int lenSequence){
    counterInOrder = 0;
    inOrden(&arbolBinario,sequence);
}

void inOrden(BinaryTree** nodo,int** sequence){
    if(*nodo != NULL){
        if(counterHeigth == BTlenSequence)return;
        if((*nodo)->izquierdo != NULL){
            inOrden(&(*nodo)->izquierdo, sequence);
        }
        *(*sequence+counterInOrder) = (*nodo)->info;
        counterInOrder++;
        if((*nodo)->derecho != NULL){
            inOrden(&(*nodo)->derecho,sequence);
        }
    }
}

void BinaryTreePostorden(int** sequence, int lenSequence){
        counterPostOrder = 0;
        postOrden(&arbolBinario,sequence);
}
void postOrden(BinaryTree** nodo, int**sequence){
    
    if(*nodo != NULL){
        if(counterHeigth == BTlenSequence)  
        return; 
        if((*nodo)->izquierdo != NULL){
            postOrden(&(*nodo)->izquierdo,sequence); 
        }
        if((*nodo)->derecho != NULL){
            postOrden(&(*nodo)->derecho,sequence); 
        }
       *(orderSecuencia+counterPostOrder) = (*nodo)->info; 
         counterPostOrder++;
    }
}
void BinaryTreePreorden(int** sequence, int lenSequence){
    counterPreOrder = 0;
    preOrden(&arbolBinario,sequence); 
}
void preOrden(BinaryTree** nodo, int**sequence){
    if(*nodo != NULL){
        if(counterHeigth == BTlenSequence)return;
        *(orderSecuencia+counterPreOrder) = (*nodo)->info;
        counterPreOrder++;
        if((*nodo)->izquierdo != NULL){
            preOrden(&(*nodo)->izquierdo,sequence);
        }
        if((*nodo)->derecho != NULL){
            preOrden(&(*nodo)->derecho,sequence);
        }
    }
}

int BinaryTreeSrchAllFather(int** sequence, int lenSequence){
    int j = 0;
    int f = 0;
    for(int i = 0; i <= lenSequence-1; i++){
        f = BinaryTreeSrchFather(*(*sequence+i));
        if(f != 0){
            *(nodosPH+j) = f;
            printf("\nentra %d-%d\n",f,*(*sequence+i));
            j++;
            nodosPH = (int*)realloc(nodosPH,(j+1)*sizeof(int));
        }
    }
    return j;
}

int BinaryTreeSrchLeafs(){
    lenNodosLeaf = 0;
    srchLeafs(&arbolBinario);
    return lenNodosLeaf;
}

void srchLeafs(BinaryTree** nodo){
    if(((*nodo)->izquierdo == NULL)&&((*nodo)->derecho == NULL)){
        *(nodosPH+lenNodosLeaf) = (*nodo)->info;
        lenNodosLeaf++;
        nodosPH = (int*)realloc(nodosPH,(lenNodosLeaf+1)*sizeof(int));
    }
    if((*nodo)->izquierdo != NULL){
        srchLeafs(&(*nodo)->izquierdo);
    }
    if((*nodo)->derecho != NULL){
        srchLeafs(&(*nodo)->derecho);
    }
}

int BinaryTreeSrchNodo(int element){
    nodoEncontrado = false;
    lenNodos = 0;
    srchNodo(&arbolBinario,element);
    if(nodoEncontrado == true)return lenNodos;
    else return 0;
}

void srchNodo(BinaryTree** nodo, int element){
    if((*nodo)->info == element){
        nodoEncontrado = true;
        *(nodosPH+lenNodos) = (*nodo)->info;
        lenNodos++;
        nodosPH = (int*)realloc(nodosPH,(lenNodos)*sizeof(int));
    }
    if(nodoEncontrado == false){
        printf("nodo: %d ",(*nodo)->info);
        *(nodosPH+lenNodos) = (*nodo)->info;
        lenNodos++;
        nodosPH = (int*)realloc(nodosPH,(lenNodos+1)*sizeof(int));
        if((element < (*nodo)->info)&&((*nodo)->izquierdo != NULL)){
            srchNodo(&(*nodo)->izquierdo,element);
        }
        if((element > (*nodo)->info)&&((*nodo)->derecho != NULL)){
            srchNodo(&(*nodo)->derecho,element);
        }
    }
}







 