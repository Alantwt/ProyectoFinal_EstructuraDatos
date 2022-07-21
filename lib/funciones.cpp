#include "../include/funciones.h"

void BinaryTreeGenerate(int** sequence, int lenSequence, char* option){
    cout<<"hellor world"<<endl;
    cout<<option<<endl;
    for(int i = 0; i <= lenSequence-1; i++){
        cout<<*(sequence+i)<<endl;
    }

    if(strcmp(option,"preorder")){
        void preorder();
    }
    else if(strcmp(option,"postorder")){
        void postorder();
    }
    else if(strcmp(option,"postorder")){
        void inorder();
    }
}

int BinaryTreeSrchHeightOf(BinaryTree* bTree, int element){

}