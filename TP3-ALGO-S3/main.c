#include <stdio.h>
#include <stdlib.h>
#define N 10

char automate[N+1][N+1];



/********************************************************************************************************/
/*$$$$$$$$$$$$$$$$$$$$$$$$$$$ INITIALISATION AVEC OU SANS FICHIER $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
/********************************************************************************************************/


/*Initialise l'automate ave que des cellules mortes*/
void Init_automate_mort(char automate[N+1][N+1]){
	int i, j;
	for(i=1; i<N; i++){
		for(j=1; j<N; j++){
			automate[i][j]=' ';
		}
	}
}

/* Initialise la matrice de l'automate depuis des coordonnées ecris dans un fichier*/
void Init_automate_fichier(char automate[N+1][N+1]) { 
	int ligne, colonne;
	FILE *fic;
	char nom_fichier[20];

	printf("A partir de quel fichier voulez vous initialiser l'automate cellulaire ? : ");
	scanf("%s", nom_fichier);
	fic = fopen(nom_fichier, "r");
	fscanf(fic, "%i%i", &ligne, &colonne);
	while(!feof(fic)){
		fscanf(fic,"%i%i", &ligne, &colonne);
		automate[ligne][colonne]='*';
	}
	fclose(fic);
}
/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/



/*********************************************************************************************************/
/*$$$$$$$$$$$$$$$$$$$$$ LIRE OU ECRIRE DES COORDNNEES D'UNE MATRICE DANS UN FICHIER $$$$$$$$$$$$$$$$$$$$$*/
/*********************************************************************************************************/


/*Ecrit les coordonnées de l'automate dans un fichier choisi*/
void Ecrire_coord_automate(void){ //nbr de lignes a lire
	FILE *fic;
	char nom_fichier[20];
	int i, x, y, nbr_coord;
	
	printf("Quel est le nom du fichier que vous voulez creer ? ");
	scanf("%s", nom_fichier);

	printf("combien de coordonnees voulez vous ecrire ? \n");
	scanf("%i", &nbr_coord);

	fic=fopen(nom_fichier, "w");
	for(i=0; i< nbr_coord; i++){
		printf("entrez les coordonnees d'une cellule vivante :\n");
		scanf("%i%i", &x, &y);
		fprintf(fic, "%i %i", x, y);
	}
	fclose(fic);
	printf("Nous avons bien pris vos coordonnées en compte , Merci.\n");
}
/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/



/**********************************************************************************************************/
/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ AFFICHAGE OU ECRITURE DE LA MATRICE $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
/**********************************************************************************************************/


/* Affiche une bordure pour afficher l'automate */
void Afficher_bordure(void){
	int i;
	printf("+");
	for(i=1; i<N; i++){
		printf("---+");
	}
	printf("\n");
}

/* Affiche la matrice automate */
void Afficher_automate(char automate[N+1][N+1]){
	int i, j;
	Afficher_bordure();
	for(i=1; i<N; i++){
		printf("|");
		for(j=1; j<N; j++){
			printf(" %c |", automate[i][j]);
		}
		printf("\n");
		Afficher_bordure();
	}
}

/* Ecrit une bordure dans le fichier fic */
void Ecrire_bordure(FILE *fic){  //fic est le fichier d'ecriture en supposant qu'il est DEJA OUVERT
	int i;
	fprintf(fic, "+");
	for(i=1; i<N; i++){
		fprintf(fic, "---+");
	}
	fprintf(fic, "\n");
}

/* Ecrit le contenu de la matrice dans le fichier fic */
void Ecrire_automate(char automate[N+1][N+1]){
	int i, j;
	FILE *fic;
	char nom_fichier[20];

	printf("Dans quel fichier voulez vous ecrire l'automate cellulaire ?");
	scanf("%s", nom_fichier);
	fic=fopen(nom_fichier, "w");

	Ecrire_bordure(fic);
	for(i=1; i<N; i++){
		fprintf(fic, "|");
		for(j=1; j<N; j++){
			fprintf(fic, " %c |", automate[i][j]);
		}
		fprintf(fic, "\n");
		Ecrire_bordure(fic);
	}
	fclose(fic);
}
/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/



int main(){
	int choix=-1; 
	
	printf("			MENU					\n\n\n\n");
	printf("	1. Initialiser l'automate				\n\n");
	printf("	2. Ecrire les coordonnees des cellules vivantes		\n\n");
	printf("	3. Lire les coordonnees des cellules vivantes		\n\n");
	printf("	4. Afficher l'automate cellulaire 			\n\n");
	printf("	5. Ecrire l'automate cellulaire dans un fichier		\n\n");
	printf("	6. Afficher l'automate après plusieurs générations	    ");
	printf("\n	 	(en cours de programmation)			\n\n\n");	
	printf("	10. QUITTER						\n\n");
	
	scanf("%i", &choix);
	while(	choix != 6){
		switch(choix){
				case 1: Init_automate_mort(automate); break;
				case 2: Ecrire_coord_automate(); break; 
				case 3: Init_automate_fichier(automate); break;
				case 4: Afficher_automate(automate); break;
				case 5: Ecrire_automate(automate); break;
				case 6: Afficher_automate(automate); break;
				case 10: return 0; break;
		}
		scanf("%i", &choix);
	}
}
