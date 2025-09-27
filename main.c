#include <stdio.h>
#include <string.h>

//ricorda di mettere prima tutto e poi il main

struct Contatto
{
    char nome[30];
    char cognome[30];
    char telefono[15];
};

struct Contatto contatti[100];

//confronta le 2 stringhe cog1 e cog2
int confrontoCognomi(char cog1[30], char cog2[30])
{
    /* con questo codice mi ritorna 1 anche se cog1 = "p" e cog2 = "pippo",
     * non so perché ma ritorna 1 se l'input ha almeno 1 iniziale del cognome
     * funziona anche con input = "pippo2" e cog2 = "pippo", ma non dovrebbe
     *ho provato a non usare strcmp ma non funziona bene
    int i = 0;
    while (cog1[i] != '\0' && cog2[i] != '\0') {
        if (cog1[i] != cog2[i]) {
            return 0;
        }
        i++;
    }
    return 1;
    */
    if (strcmp(cog1, cog2) == 0)
    {
        return 1;
    }

    return 0;

    //return 0;
}

//ricrea la lista togliendo le informazioni in posizione n
void rifareLista(struct Contatto listaContatti[100], int n, int l)
{
    for (int i = n; i < l-1; i ++)
    {
        listaContatti[i] = listaContatti[i+1];
    }
}

//aggiunge un contatto alla lista
int aggiungiContatto(int i)
{
    if (i >= 100)
    {
        printf("Errore! La rubrica è piena e non si possono aggiungere altri contatti");
        return i;
    }

    printf("Inserisci il nome del nuovo contatto:\n");
    scanf("%29s", contatti[i].nome);
    printf("Inserisci il cognome del nuovo contatto:\n");
    scanf("%29s", contatti[i].cognome);
    printf("Inserisci il numero di telefono del nuovo contatto:\n");
    scanf("%29s", contatti[i].telefono);
    i ++;
    return i;
}

//visualizza tutti i contatti nella lista
void visualizzaContatti(int i)
{
    printf("Ecco la lista con tutti i contatti:\n");
    for (int j = 0; j < i; j++)
    {
        printf("Nome:\t\t%s\nCognome:\t%s\nTelefono:\t%s\n\n", contatti[j].nome, contatti[j].cognome, contatti[j].telefono);
    }
}

//cerca tutti i contatti con un cognome specifico
void cercaContatto(int i)
{
    char cercaCognome[30];
    int vuoto = 0;
    printf("Inserire il cognome del contatto da cercare:\n\n");
    scanf("%29s", cercaCognome);
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
}

//elimina tutti i contatti con un cognome specifico
int eliminaContatto(int i)
{
    char cercaCognome[30];
    int vuoto = 0;
    printf("Inserire il cognome del contatto da eliminare:\n");
    scanf("%29s", cercaCognome);
    for (int j = 0; j < i; )
    {
        if (confrontoCognomi(cercaCognome, contatti[j].cognome) == 1)
        {
            rifareLista(contatti, j, i);
            vuoto ++;
            i --;
        }
        else
        {
            j ++;
        }
    }
    if (vuoto == 0)
    {
        printf("Zero contatti con il cognome %s\n\n", cercaCognome);
        vuoto = 0;
    }
    return i;
}



//main
int main(void) {

    int scelta, i = 0, controllo = 0;

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
                i = aggiungiContatto(i);
                break;
            case 2:
                visualizzaContatti(i);
                break;
            case 3:
                cercaContatto(i);
                break;
            case 4:
                i = eliminaContatto(i);
                break;
            case 5:
                controllo ++;
                break;
            default:
                printf("Errore!");
                controllo ++;
                break;
        }
    }
    return 0;
}