#include <stdio.h>
#include <stdlib.h>
#define N 10

char automate[N][N];

/*Initialise l'automate ave que des cellules mortes*/
void Init_automate(char automate[N][N]){
	int i, j;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			automate[i][j]=' ';
		}
	}
}

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
/*$$$$$$$$$$$$$$$$$$$$$ LIRE OU ECRIRE DES COORDNNEES D'UNE MATRICE DANS UN FICHIER $$$$$$$$$$$$$$$$$$$$$*/
/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

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
}

/* Permet de lire les coordonnées ecrit dans le fichier et rempli la matrice automate */
void Lire_coord_automate(void){
	FILE *fic;
	char nom_fichier[20];
	int i, j, nbr_coord, ligne, colonne;
	
	printf("Quel est le nom du fichier que vous voulez lire ? ");
	scanf("%s", nom_fichier);
	
	printf("\ncombien de coordonnées voulez vous lire ? :");
	scanf("%i", &nbr_coord);

	fic=fopen(nom_fichier, "r");
	for(i=0; i < nbr_coord; i++){
		fscanf(fic, "%i %i", &ligne, &colonne);
		automate[ligne][colonne]='*';
	}	
	fclose(fic);
}
/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/


/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ AFFICHAGE OU ECRITURE DE LA MATRICE $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

/* Affiche une bordure pour afficher l'automate */
void Afficher_bordure(void){
	int i, j;
	printf("+");
	for(i=0; i<N; i++){
		printf("---+");
	}
	printf("\n");
}


/* Affiche la matrice automate */
void Afficher_automate(char automate[N][N]){
	int i, j;
	Afficher_bordure();
	for(i=0; i<N; i++){
		printf("|");
		for(j=0; j<N; j++){
			printf(" %c |", automate[i][j]);
		}
		printf("\n");
		Afficher_bordure();
	}
}

/* Ecrit une bordure dans le fichier fic */
void Ecrire_bordure(FILE *fic){  //fic est le fichier d'ecriture en supposant qu'il est DEJA OUVERT
	int i, j;
	fprintf(fic, "+");
	for(i=0; i<N; i++){
		fprintf(fic, "---+");
	}
	fprintf(fic, "\n");
}

/* Ecrit le contenu de la matrice dans le fichier fic */
void Ecrire_automate(char automate[N][N]){
	int i, j;
	FILE *fic;
	char nom_fichier[20];

	printf("Dans quel fichier voulez vous ecrire l'automate cellulaire ?");
	scanf("%s", nom_fichier);
	fic=fopen(nom_fichier, "w");

	Ecrire_bordure(fic);
	for(i=0; i<N; i++){
		fprintf(fic, "|");
		for(j=0; j<N; j++){
			fprintf(fic, " %c |", automate[i][j]);
		}
		fprintf(fic, "\n");
		Ecrire_bordure(fic);
	}
	fclose(fic);
}

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/



int main(){
	int choix=-1; 
	
	printf("			MENU					\n\n");
	printf("	1. Initialiser l'automate				\n");
	printf("	2. Ecrire les coordonnees des cellules vivantes		\n");
	printf("	3. Lire les coordonnees des cellules vivantes		\n");
	printf("	4. Afficher l'automate cellulaire 			\n");
	printf("	5. Ecrire l'automate cellulaire dans un fichier		\n");
	printf("	6. QUITTER						\n");
	
	scanf("%i", &choix);
	while(	choix != 6){
		switch(choix){
				case 1: Init_automate(automate); break;
				case 2: Ecrire_coord_automate(); break; 
				case 3: Lire_coord_automate(); break;
				case 4: Afficher_automate(automate); break;
				case 5: Ecrire_automate(automate); break;
				case 6: return 0; break;
		}
		scanf("%i", &choix);
	}
}
