# Travaux pratiques 2

## Année: 2026-2027

## Objectifs

1. **Débogage :** Apprendre à utiliser les outils de débogage (`gdb`) pour identifier et corriger les erreurs dans les programmes en C.

2. **Chaîne de compilation :** Comprendre le processus complet de compilation en C avec `gcc`, y compris les étapes de prétraitement, compilation, assemblage et édition des liens.

3. **Manipulation de chaînes de caractères :** Maîtriser les techniques de manipulation de chaînes de caractères en C, incluant les opérations de recherche, découpage, et concaténation.

4. **Gestion des données et recherche de phrases :** Utiliser les structures en C pour gérer des informations (comme les données d’étudiant.e.s) et implémenter des techniques pour rechercher des phrases spécifiques dans des fichiers.

---

## Exercice 2.1 [★] – Débogage avec GDB

Cet exercice présente une brève introduction à `gdb` et explique comment déboguer votre programme C à l'aide de `gdb`.

Le code suivant (**erreurs.c**) présente une erreur majeure : il tente d'accéder à des indices de tableau supérieurs à la taille maximale du tableau (100).

### Exemple (erreurs.c)

```c
#include <stdio.h>

int main() {
   int tableau[100];

   for (int compteur = 0; compteur < sizeof(tableau); compteur++) { //Erreur
       tableau[compteur] = tableau[compteur] * 2;
   }
   
   return 0;
}
```

#### Compilation et exécution

1. Compilation simple :

```bash
$ gcc erreurs.c
```

2. Exécution :

```bash
$ ./a.out
*** stack smashing detected ***: terminated
```

Le programme plante comme prévu : `sizeof(tableau)` vaut 400 (100 entiers de 4 octets), et non 100.

#### Débogage avec GDB

1. Compiler avec informations de débogage :

```bash
$ gcc -ggdb3 erreurs.c -o erreurs
```

2. Lancer GDB :

```bash
$ gdb erreurs
```

Vous verrez l’invite `(gdb)`.

3. Exécuter le programme :

```gdb
(gdb) r
```

Le programme s'arrête en cas d'erreur. Pour voir la pile d'appels :

```gdb
(gdb) bt
```

4. Placer un point d'arrêt à la ligne 7 (le corps de la boucle) :

```gdb
(gdb) break erreurs.c:7
```

5. Exécuter jusqu’au point d’arrêt :

```gdb
(gdb) r
```

6. Inspecter les variables :

```gdb
(gdb) p compteur
(gdb) p sizeof(tableau)
(gdb) p tableau[0]@5
```

7. Avancer instruction par instruction :

```gdb
(gdb) n
```

8. Continuer l’exécution jusqu’au prochain point d’arrêt ou fin :

```gdb
(gdb) continue
```

9. Quitter GDB :

```gdb
(gdb) quit
```

**Question :** compilez avec `gcc -Wall -Wextra erreurs.c`. Quel avertissement obtenez-vous, et quel est son lien avec l'erreur ? Quel type faudrait-il donner à `compteur` ?

---

## Exercice 2.2 [★] – Chaîne de compilation en C

### Étapes de la chaîne de compilation

1. **Préprocesseur :** Gère les directives `#include` et les macros.
2. **Compilation :** Transforme le code en assembleur.
3. **Assemblage :** Produit des fichiers objets `.o`.
4. **Édition de liens :** Combine les objets et bibliothèques pour créer l’exécutable.
5. **Exécution :** Lancer le programme binaire.

### Exemple (aire.c)

```c
#include <math.h>
#include <stdio.h>

float calculer_aire(float rayon) {
    return M_PI * rayon * rayon;
}

int main() {
    float rayon = 5.0;
    float aire = calculer_aire(rayon);
    printf("L'aire du cercle de rayon %.2f est %.2f\n", rayon, aire);
    return 0;
}
```

#### Compilation avec étapes détaillées

```bash
# Préprocesseur
gcc -E aire.c -o aire.i

# Compilation
gcc -O2 -S aire.i -o aire.s

# Assemblage
gcc -c aire.s -o aire.o

# Edition de liens
gcc aire.o -lm -o aire

# Exécution
./aire
```

---

## Exercice 2.3 [★] – Compilation d'un programme multi-fichiers en C

Le programme `sphere` est réparti sur plusieurs fichiers :

* `sphere.h` : prototypes des fonctions
* `surface.c` : fonctions surface
* `volume.c` : fonctions volume
* `main.c` : programme principal

Compilez-le étape par étape, puis modifiez uniquement `volume.c` et observez quels fichiers doivent être recompilés.

#### Compilation multi-fichiers

```bash
# Préprocesseur
gcc -E main.c -o main.i
gcc -E volume.c -o volume.i
gcc -E surface.c -o surface.i

# Compilation avec optimisation
gcc -O3 -c main.i -o main.o
gcc -O3 -c volume.i -o volume.o
gcc -O3 -c surface.i -o surface.o

# Edition de liens
gcc main.o volume.o surface.o -lm -o sphere

# Exécution
./sphere
```

---

## Exercice 2.4 [★★] – Manipulation de chaînes de caractères en C

**Objectifs :**

1. Calculer la longueur d’une chaîne.
2. Copier une chaîne dans une autre.
3. Concaténer deux chaînes.

**Instructions :**
Écrire un programme `chaine.c` qui demande à l’utilisateur deux chaînes et applique les trois opérations. Les résultats doivent être affichés.

---

## Exercice 2.5 [★★] – Gestion des données d’étudiant.e.s en C

**Objectif :** Écrire un programme `bd_ecole.c` pour gérer les données de 5 étudiant.e.s.

1. Définir une structure `struct` pour l’étudiant (nom, prénom, adresse, notes).
2. Initialiser et manipuler les données (`strcpy`).
3. Demander à l’utilisateur de saisir les informations pour chaque étudiant.
4. Afficher les informations après saisie.

---

## Exercice 2.6 [★★] – Recherche de phrases dans un fichier en C

**Objectif :** Écrire un programme `phrases.c` pour rechercher une phrase dans un fichier.

1. Demander le nom du fichier et la phrase à rechercher.
2. Lire le fichier ligne par ligne (`fopen`, `fgets`, `fclose`).
3. Pour chaque ligne, compter le nombre d’occurrences de la phrase.
4. Afficher les résultats formatés.

---

## Exercice 2.7 [★★★] – Gestion des couleurs et comptage

**Objectif :** Écrire un programme `couleurs.c` qui stocke 100 couleurs (R, G, B, A) et affiche les couleurs distinctes avec leur nombre d’occurrences.

1. Définir une structure `Couleur`.
2. Créer un tableau de 100 couleurs.
3. Compter les occurrences de chaque couleur distincte.
4. Afficher les résultats.

---

## Exercice 2.8 [★★★] – Rechercher une phrase dans un tableau de phrases

Écrivez un programme en C nommé `chercher.c` qui contient un tableau de 10 phrases (tableau de tableaux de caractères) et qui recherche si une phrase donnée est présente dans le tableau. L'objectif est de réaliser cette recherche sans utiliser les fonctions de bibliothèques standards ou externes.

**Exemple**:
Supposons que le tableau contienne les phrases suivantes :

```
 "Bonjour, comment ça va ?"
 "Le temps est magnifique aujourd'hui."
 "C'est une belle journée."
 "La programmation en C est amusante."
 "Les tableaux en C sont puissants."
 "Les pointeurs en C peuvent être déroutants."
 "Il fait beau dehors."
 "La recherche dans un tableau est intéressante."
 "Les structures de données sont importantes."
 "Programmer en C, c'est génial."
```

Si on recherche la phrase `La programmation en C est amusante.`, le programme doit afficher `Phrase trouvée`. Si on recherche `Je préfère le Python.`, le programme doit afficher `Phrase non trouvée`.

---

## Exercice 2.9 [★★★] – Synthèse des approches en C

**Objectif :** Créer un rapport (`programmation_C.md`) qui synthétise :

* Débogage avec GDB.
* Chaîne de compilation en C avec `gcc`.
* Manipulation de chaînes en C.
* Gestion des structures pour les données et recherche dans les fichiers.

---

## Fichiers à rendre

* **Markdown :** `programmation_C.md`, `CONTRIBUTORS.md`, `README.md`
* **C :** `aire.c`, `bd_ecole.c`, `chaine.c`, `chercher.c`, `couleurs.c`, `erreurs.c`, `main.c`, `phrases.c`, `sphere.h`, `surface.c`, `volume.c`

## Instructions générales

1. Ajoutez des commentaires clairs : nom du fichier, objectif, auteurs, lignes importantes.
2. Respectez les noms de fichiers indiqués dans chaque exercice.
3. Votre code doit compiler sans erreur et, dans la mesure du possible, sans avertissement (`gcc -Wall -Wextra`).
4. Complétez le fichier `README.md` : auto-évaluation, bibliothèques utilisées, références, difficulté et commentaires.
5. Les fichiers de ce TP font partie du rendu unique (TP1 à TP5) décrit dans le [README](../README.md) du dépôt.
