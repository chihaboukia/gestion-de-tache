#include <stdio.h>

int taille = 0;

struct date {
    int day;
    int month;
    int year;
};

struct tache {
    char name[50];
    char descreption[200];
    int priority;
    struct date tacheDate;
};

void add_tache(struct tache taches[]) {
    printf("--Entrer la tache-- :\n");
    scanf(" %[^\n]", taches[taille].name);

    printf("---Description--- :\n");
    scanf(" %[^\n]", taches[taille].descreption);

    printf("---Date--- :\n");
    scanf("%d %d %d", &taches[taille].tacheDate.day, &taches[taille].tacheDate.month, &taches[taille].tacheDate.year);

    printf("---Priorite--- (1 = normal , 2 = important ):\n");
    scanf("%d", &taches[taille].priority);

    taille++;
}

void afficher_tache(struct tache taches[]) {
    printf("liste des taches\n :");
    for (int i = 0; i < taille; i++) {
        printf("tache : %d\n", i + 1);
        printf("name : %s\n", taches[i].name);
        printf("description : %s\n", taches[i].descreption);
        printf("priority : %d\n", taches[i].priority);
        printf("date : %d %d %d\n ", taches[i].tacheDate.day, taches[i].tacheDate.month, taches[i].tacheDate.year);
    }
}

void suprimer_tache(struct tache taches[]) {
    int index;
    printf("Entrer l'index de la tache à supprimer :\n");
    scanf("%d", &index);
    if (index >= 1 && index <= taille) {
        for (int i = index - 1; i < taille - 1; i++) {
            taches[i] = taches[i + 1];
        }
        taille--;
        printf("Tache supprimée avec succès.\n");
    } else {
        printf("Index invalide.\n");
    }
}

void modifier(struct tache taches[]) {
    int index;
    printf("Entrer l'index de la tache à modifier :\n ");
    scanf("%d", &index);

    if (index >= 1 && index <= taille) {
        printf("--Modifier la tache-- :\n");
        printf("---Nom--- :\n");
        scanf("%s", taches[index - 1].name);

        printf("---Description--- :\n");
        scanf(" %[^\n]", taches[index - 1].descreption);

        printf("---Priorite--- :\n");
        scanf("%d", &taches[index - 1].priority);

        printf("---Date--- :\n");
        scanf("%d %d %d", &taches[index - 1].tacheDate.day, &taches[index - 1].tacheDate.month, &taches[index - 1].tacheDate.year);

        printf("Tache modifiée avec succès.\n");
    } else {
        printf("Index invalide. Veuillez entrer un index valide.\n");
    }
}

void filtrer(struct tache taches[]) {
    int choix;
    printf("Choisir entre 1 pour normale, 2 pour important : ");
    scanf("%d", &choix);
    for (int i = 0; i < taille; i++) {
        if (taches[i].priority == choix) {
            printf("Tache : %s\n", taches[i].name);
        }
    }
}
void ordonner_croissant(struct tache taches[]) {
    for (int i = 0; i < taille - 1; i++) {
        for (int j = i + 1; j < taille; j++) {
            if ((taches[i].tacheDate.year > taches[j].tacheDate.year) || (taches[i].tacheDate.year == taches[j].tacheDate.year && taches[i].tacheDate.month > taches[j].tacheDate.month) || (taches[i].tacheDate.month == taches[j].tacheDate.month && taches[i].tacheDate.day > taches[j].tacheDate.day)) {
                struct tache temp;
                temp = taches[i];
                taches[i] = taches[j];
                taches[j] = temp;
            }
        }
    }
    afficher_tache(taches);
}

void ordonner_decroissant(struct tache taches[]) {
    for (int i = 0; i < taille - 1; i++) {
        for (int j = i + 1; j < taille; j++) {
            if (taches[i].tacheDate.year < taches[j].tacheDate.year || (taches[i].tacheDate.year == taches[j].tacheDate.year && taches[i].tacheDate.month < taches[j].tacheDate.month) || (taches[i].tacheDate.month == taches[j].tacheDate.month && taches[i].tacheDate.day < taches[j].tacheDate.day)) {
                struct tache temp;
                temp = taches[i];
                taches[i] = taches[j];
                taches[j] = temp;
            }
        }
    }
    afficher_tache(taches);
}

void menu(struct tache taches[]) {
    int choix;
    do {
        printf("<1>-ajouter une tache :\n");
        printf("<2>-afficher la liste des taches :\n");
        printf("<3>-supprimer une tache :\n");
        printf("<4>-modifier une tache :\n");
        printf("<5>-filtrer les taches :\n");
        printf("<6>-ordonner croissant :\n");
        printf("<7>-ordonner decroissant :\n");
        printf("<8>-Quitter :\n");
        printf("entrer votre choix :\n");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                add_tache(taches);
                break;
            case 2:
                afficher_tache(taches);
                break;
            case 3:
                suprimer_tache(taches);
                break;
            case 4:
                modifier(taches);
                break;
            case 5:
                filtrer(taches);
                break;
            case 6:  
                 ordonner_croissant(taches);
                 break;
            case 7:
                ordonner_decroissant(taches);
                break;
            case 8:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez entrer un choix valide.\n");
                break;
        }
    } while (choix != 8);
}

int main() {
    struct tache taches[100];
    menu(taches);

    return 0;
}
