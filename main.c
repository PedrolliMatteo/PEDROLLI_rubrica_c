#include <stdio.h>
#include <stdlib.h>

//ricorda di mettere prima le struct e poi il main

struct Contatto
{
    char nome[30];
    char cognome[30];
    char telefono[15];
};

int main(void) {

    struct Contatto contatti[100];
    int scelta, i = 0, controllo = 0;
    char cercaCognome[30];

    while (controllo == 0)
    {
        printf("Cosa fare oggi nella rubrica?\n"
           "1. Aggiungere contatto\n"
           "2. Visualizzare tutti i contatti\n"
           "3. Cercare un contatto per cognome\n"
           "4. Eliminare un contatto per cognome\n"
           "5. Uscire\n");

        scanf("%d", &scelta);

        switch (scelta)
        {
            case 1:
                printf("Inserisci il nome del nuovo contatto:\n");
                scanf("%s", &contatti[i].nome);
                printf("Inserisci il cognome del nuovo contatto:\n");
                scanf("%s", &contatti[i].cognome);
                printf("Inserisci il numero di telefono del nuovo contatto:\n");
                scanf("%s", &contatti[i].telefono);
                i++;
                break;
            case 2:
                for (int j = 0; j < i; j++)
                {
                    printf("Nome:\t\t%s\nCognome:\t%s\nTelefono:\t%s\n\n", contatti[j].nome, contatti[j].cognome, contatti[j].telefono);
                }
                break;
            case 3:
                printf("Inserire il cognome del contatto da cercare:\n");
                scanf("%s", &cercaCognome);
                printf("Ecco tutti i contatti con il cognome %s:\n", cercaCognome);
                for (int j = 0; j < i; j++)
                {
                    if (cercaCognome == contatti[j].cognome)
                    {
                        printf("Nome:\t\t%s\nCognome:\t%s\nTelefono:\t%s\n\n", contatti[j].nome, contatti[j].cognome, contatti[j].telefono);
                    }
                    else
                    {
                        printf("Trovato nulla");
                    }
                }
                break;
            case 4:
                break;
            case 5:
                controllo ++;
                break;
            default:
                break;
        }

    }

    return 0;
}
