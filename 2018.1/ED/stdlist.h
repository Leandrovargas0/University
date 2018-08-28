#include <stdio.h>
#include <stdlib.h>

typedef struct TItem{
    int id;
    //Adicionar a partir daqui os atributos adicionais.
} Item;

typedef struct TNodo{
    struct TNodo *prox; //Um ponteiro com o nome de 'prox' do tipo de 'Nodo'
    Item *item; //Um ponteiro com o nome de 'item' do tipo de 'Item'
} Nodo;

Item *Item_Novo();
Nodo *Nodo_Novo();
Nodo *Lista_Novo();

void Lista_Adicionar_Inicio(Nodo *lista, Nodo *nodo);
void Lista_Adicionar_Final(Nodo *lista, Nodo *nodo);
void Lista_Adicionar_Index(Nodo *lista, Nodo *nodo, int index);

int Lista_Count(Nodo *lista);
void Lista_Clear(Nodo *lista);

void Nodo_Liberar(Nodo *nodo);
void Nodo_Exibir(Nodo *nodo);

Nodo *Lista_Remover_Inicio(Nodo *lista);
Nodo *Lista_Remover_Final(Nodo *lista);
Nodo *Lista_Remover_Final(Nodo *lista);

Item *Item_Novo(){
    Item *item = (Item *) malloc(sizeof(Item));
    //Um ponteiro com nome 'item' do tipo 'Item' recebe um espaço de 
    //memória do tamanho de 'Item' convertido para um
    //ponteiro do tipo 'Item'
    printf("ID\t");
    scanf("%d", &item->id);
    //Adicionar a partir daqui os comandos de atribuição dos atributos adicionais, se houver.
    return item;
}

Nodo *Nodo_Novo(){
    Nodo *nodo = (Nodo *) malloc(sizeof(Nodo));
    //Um ponteiro com nome 'Nodo' do tipo 'Nodo' recebe um espaço de 
    //memória do tamanho de 'Nodo' convertido para um
    //ponteiro do tipo 'Nodo'
    Item *item = Item_Novo();

    nodo->item = item;
    nodo->prox = NULL;

    return nodo;
}

Nodo *Lista_Novo(){
    Nodo *lista = (Nodo *) malloc(sizeof(Nodo));
    //Um ponteiro com nome 'lista' do tipo 'Nodo' recebe um espaço de 
    //memória do tamanho de 'Nodo' convertido para um
    //ponteiro do tipo 'Nodo'
    lista->item = NULL;
    lista->prox = NULL;

    return lista;
}

void Lista_Clear(Nodo *lista){
    while(lista->prox != NULL){
        Nodo_Liberar(Lista_Remover_Inicio(lista));
    }
}

void Lista_Adicionar_Inicio(Nodo *lista, Nodo *nodo){
    Nodo *temp = lista->prox;

    if(temp == NULL){
        lista->prox = nodo;
    }
    else{
        nodo->prox = temp;
        lista->prox = nodo;
    }
}

void Lista_Adicionar_Final(Nodo *lista, Nodo *nodo){
    Nodo *temp = lista->prox;

    if(temp == NULL){
        Lista_Adicionar_Inicio(lista, nodo);
    }
    else{
        while(temp->prox != NULL){
            temp = temp->prox;
        }
        temp->prox = nodo;
    }
}

void Lista_Adicionar_Index(Nodo *lista, Nodo *nodo, int index){
    if(index <= Lista_Count(lista)){
        Nodo *temp = lista->prox;
        Nodo *ant = lista;

        for(int i = 0; i < index; i++){
            ant = temp;
            temp = ant->prox;
        }
        nodo->prox = temp;
        ant->prox = nodo;
    }
}

int Lista_Count(Nodo *lista){
    int count = 0;
    Nodo *temp = lista->prox;
    while(temp != NULL){
        count++;
        temp = temp->prox;
    }
    return count;
}

Nodo *Lista_Remover_Inicio(Nodo *lista){
    Nodo *temp = lista->prox;
    if(temp != NULL){
        lista->prox = temp->prox;
        temp->prox = NULL;
        return temp;
    }
}

Nodo *Lista_Remover_Final(Nodo *lista){
    Nodo *temp = lista->prox;
    Nodo *ant = lista;
    if(temp != NULL){
        while(temp->prox != NULL){
            ant = temp;
            temp = temp->prox;
        }
        ant->prox = temp->prox; //Vai ser NULL, mas por questões de segurança, preferi assim.
        return temp;
    }
}

Nodo *Lista_Remover_Index(Nodo *lista, int index){
    Nodo *temp = lista->prox;
    Nodo *ant = lista;

    if(index <= Lista_Count(lista)){
        for(int i = 0; i < index; i++){
            ant = temp;
            temp = temp->prox;
        }
        ant->prox = temp->prox;
        temp->prox = NULL;

        return temp;
    }
}

void Nodo_Liberar(Nodo *nodo){
    free(nodo);
}

void Nodo_Exibir(Nodo *nodo){
    printf("ID\t%d", nodo->item->id);
    //Imprimir a partir daqui os atributos adicionais, se houver.
    printf("\n--------------------------------\n");
}

void Lista_Exibir_Todos(Nodo *lista){
    Nodo *temp = lista->prox;
    while(temp != NULL){
        Nodo_Exibir(temp);
        temp = temp->prox;
    }
}

void Lista_Exibir_Index(Nodo *lista, int index){
    Nodo *temp = lista->prox;
    Nodo *ant = lista;

    if(index <= Lista_Count(lista)){
        for(int i = 0; i < index; i++){
            ant = temp;
            temp = temp->prox;
        }
        Nodo_Exibir(ant);
    }
}