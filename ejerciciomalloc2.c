#include <stdlib.h>
#include <stdio.h>
#include <iso646.h>
#include <stdbool.h>

typedef struct tCell{
    int payload;
    struct tCell *next;
} Cell;

Cell* agrega(Cell *base, int entrada){
    Cell* reg;
    reg=malloc(sizeof(Cell));
    if (reg == NULL) {
        printf("nulo");
        return NULL;
    }
    reg->payload=entrada;
    reg->next = NULL;
    Cell* cursor = base;
    while(cursor->next !=NULL){
        cursor=(Cell*)cursor->next;
        }
    cursor->next=reg;
    return base;
}

void imprime(Cell *raiz){
    while(raiz->next !=NULL){
        printf("%d->",raiz->next->payload);
        raiz=raiz->next;
    }
}

Cell pop(Cell *ruta){
    if(ruta->next==NULL){return *ruta;} 
    Cell *cursor=ruta;
    while(((Cell*)cursor->next)->next !=NULL){
        cursor=(Cell*)cursor->next;
    }
        free((void *)cursor->next);
        cursor->next=NULL;
        return *ruta;
}

Cell erase(Cell *celda){
    while(celda->next!=NULL)
    pop(celda);
    return *celda;

}

Cell menu(Cell *base) {
        int menu1=1;
    while (menu1==1) {
        printf("Elije una opción:\n 0 - Agrega nodo\n 1 - Borra último nodo\n 2 - Imprime lista\n 3 - Salir\n");
        int q;
        int num;
        scanf("%d", &q);
        if (q==1) {
            pop(base);
        }
        else if (q==0) {
            printf("Escribe el número.\n");
            scanf("%d", &num);
            agrega(base, num);        
        }
        else if (q==2) {
            printf("\nAqui esta la lista:\n");
            imprime(base);
        }
        else if(q==3) {
            erase(base);
            printf("Ádiós C:");
            menu1=2;
        }else {
                printf("Escribe un número valido plox.\n");
            }
        } 
    return *base;
    }

int main(int argc, char* argv []) {
    Cell *root;
    root = (Cell *)malloc(sizeof(Cell));
    root->payload = -1;
    root->next = NULL;
    menu(root);
    return 0;
    }