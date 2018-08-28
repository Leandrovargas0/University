#include "stdlist.h"

int main_Menu_Interacao();
int main_Menu_Index(Nodo *lista);

void main(){
    int usuario;
    Nodo *lista = Lista_Novo();

    do{
        usuario = main_Menu_Interacao();

        switch (usuario)
        {
            case 0:{
                Lista_Clear(lista);
                break;
            }
            case 1:{
                Nodo *nodo = Nodo_Novo();
                Lista_Adicionar_Inicio(lista, nodo);
                break;
            }
            case 2:{
                Nodo *nodo = Nodo_Novo();
                Lista_Adicionar_Final(lista, nodo);
                break;
            }
            case 3:{
                Nodo *nodo = Nodo_Novo();
                Lista_Adicionar_Index(lista, nodo, main_Menu_Index(lista));
                break;
            }
            case 4:{
                Lista_Exibir_Todos(lista);
                break;
            }
            case 5:{
                Lista_Exibir_Index(lista, main_Menu_Index(lista));
                break;
            }
            case 6:{
                Nodo_Liberar(Lista_Remover_Inicio(lista));
                break;
            }
            case 7:{
                Nodo_Liberar(Lista_Remover_Final(lista));
                break;
            }
            case 8:{
                Nodo_Liberar(Lista_Remover_Index(lista, main_Menu_Index(lista)));
                break;
            }
        }
    }
    while(usuario != 0);
}

int main_Menu_Index(Nodo *lista){
    int index;
    printf("\n--------------------------------\n");
    printf("Digite o index desejado [0-%d]\t", Lista_Count(lista) - 1); //Considerar 0 como INDEX inicial
    scanf("%d", &index);

    return index;
}

int main_Menu_Interacao(){
    int usuario;
    printf("--------------------------------\n");
    printf("| 1 | Adicionar no Início\n");
    printf("| 2 | Adicionar no Final\n");
    printf("| 3 | Adicionar por Index\n");
    printf("--------------------------------\n");
    printf("| 4 | Exibir todos\n");
    printf("| 5 | Exibir por Index\n");
    printf("--------------------------------\n");
    printf("| 6 | Remover no Início\n");
    printf("| 7 | Remover no Final\n");
    printf("| 8 | Remover por Index\n");
    printf("--------------------------------\n");
    printf("| 0 | Sair\n\n");

    printf("Digite o comando desejado: ");
    scanf("%d", &usuario);
    system("clear");

    return usuario;
}