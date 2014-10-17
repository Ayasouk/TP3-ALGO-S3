TP3-ALGO-S3
===========

#SUJET DU TP : 

Un automate cellulaire est constitué d'un ensemble de cellules qui évoquent par générations successives. 
On reprèsente un automate cellulaire par une grille NxN dont chaque case est occupée soit par une cellule vivante, 
soit par une cellule morte. Chaque case possède huit cases voisines (les quatres côtés plus les quatres coins). 
Les règles d'évolution sont les suivantes :
	
	-Si la cellule est vivantes et entourée par deux ou trois cellules vivantes, 
	elle reste en vie à la génération suivante, sinon elle meurt.
	
	-Si la cellule est morte et entourée par exactement trois cellules vivantes, 
	elle naît à la génération suivante.

#### Exemple :

															+---+---+---+
1.la cellule centrale, qui est morte , possède exactement trois voisins : elle sera vivante à la generation suivante : 	| o | o |   |
															+---+---+---+
															|   | * | o |
															+---+---+---+
															|   |   |   |
															+---+---+---+
 

2.La cellule centrale, qui est vivante, possède quatres voisins : à la génération suivante, elle meurt :   +---+---+---+
													   | o | o | o |
													   +---+---+---+
													   | o | o |   |
													   +---+---+---+
													   |   |   |   |
													   +---+---+---+

													        +---+---+---+  	
3.La cellule centrale est morte et ne possède que deux voisins : elle reste morte à la génération suivante :    |   |   |   |
														+---+---+---+
														| o |   | o |
														+---+---+---+
														|   |   |   |
														+---+---+---+

###PRATIQUE : 
_ Ecrire un programme qui initialise un automate cellulaire à partir d'un fichier texte puis affiche les X premieres generations
de l'automate.

##Mise en Oevre :
-    le fichier d'Initialisation, supposé sans erreurs, contient une séquence d'entiers qui reprèsentent les coordonnées des 
	cellules vivantes de la première génération .

	#### Par exemple, le fichier :
			1 8 2 3 6 4
	reprèsente une grille contenant trois cellules vivantes de coordonnées (1,8)(2,3) et (6,4).

-    Le nom du fichier d'initialisation et le nombre X de générations à afficher seront saisis au clavier par l'utilisateur.

-    Afin de faciliter la calcul du nombre de voisins, un automate cellulaire de dimensions NxN est reprèsenté dans une matrice
	(N+2)x(N+2), en laissant une <<bordure>> de cellules mortes sur le pourtour.
