#include <stdio.h>
#include <stdlib.h>

//ricorda di mettere prima le struct e poi il main

struct Contatto
{
    char nome[30];
    char cognome[30];
    char telefono[15];
};

int confrontoCognomi(char cog1[30], char cog2[30])
{
    for (int i = 0; cog1[i] != '\0'; i++)
    {
        if ( cog1[i] != cog2[i])
        {
            return 0;
        }
    }
    return 1;
}

struct Contatto rifareLista(struct Contatto listaContatti[100], int n, int l)
{
    for (int i = n; i < l+1; i ++)
    {
        listaContatti[i] = listaContatti[i+1];
    }

    return listaContatti[100];
}

int main(void) {

    struct Contatto contatti[100];
    int scelta, i = 0, controllo = 0, vuoto = 0;
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
                printf("Ecco la lista con tutti i contatti:\n");
                for (int j = 0; j < i; j++)
                {
                    printf("Nome:\t\t%s\nCognome:\t%s\nTelefono:\t%s\n\n", contatti[j].nome, contatti[j].cognome, contatti[j].telefono);
                }
                break;
            case 3:
                printf("Inserire il cognome del contatto da cercare:\n\n");
                scanf("%s", &cercaCognome);
                printf("Ecco tutti i contatti con il cognome %s:\n", cercaCognome);
                for (int j = 0; j < i; j++)
                {
                    if (confrontoCognomi(cercaCognome, contatti[j].cognome) == 1)
                    {
                        printf("Nome:\t\t%s\nCognome:\t%s\nTelefono:\t%s\n\n", contatti[j].nome, contatti[j].cognome, contatti[j].telefono);
                        vuoto ++;
                    }
                }
                if (vuoto == 0)
                {
                    printf("Zero contatti con il cognome %s\n\n", cercaCognome);
                    vuoto = 0;
                }
                break;
            case 4:
                printf("Inserire il cognome del contatto da eliminare:\n");
                scanf("%s", &cercaCognome);
                for (int j = 0; j < i; j++)
                {
                    if (confrontoCognomi(cercaCognome, contatti[j].cognome) == 1)
                    {
                        contatti[100] = rifareLista(contatti, j, i);
                        vuoto ++;
                        i --;
                    }
                }
                if (vuoto == 0)
                {
                    printf("Zero contatti con il cognome %s\n\n", cercaCognome);
                    vuoto = 0;
                }
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
