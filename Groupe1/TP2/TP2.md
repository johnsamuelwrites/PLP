## Année: 2024-2025

### Travaux pratiques 2

## Objectifs

1. **Débogage :** Apprendre à utiliser les outils de débogage (`gdb` pour C et `pdb` pour Python) pour identifier et corriger les erreurs dans les programmes.

2. **Chaîne de compilation :** Comprendre le processus complet de compilation en C avec `gcc`, y compris les étapes de prétraitement, compilation, assemblage et édition des liens.

3. **Inspection de code :** Utiliser `dis` en Python pour inspecter le bytecode et comprendre comment le code source est transformé en instructions exécutables.

4. **Manipulation de chaînes de caractères :** Maîtriser les techniques de manipulation de chaînes de caractères en C et en Python, incluant les opérations de recherche, découpage, formatage et gestion des encodages.

5. **Gestion des données et recherche de phrases :** Comparer la gestion des structures de données en C (structures) et en Python (classes) pour la gestion d'informations comme les données d’étudiant.e.s, et implémenter des techniques pour rechercher des phrases spécifiques dans des fichiers en utilisant C et Python.

## Exercice 2.1 [★]

### GDB (C)

Cet exercice présente une brève introduction à `gdb` et explique comment déboguer votre programme C à l'aide de `gdb`.

Le code suivant (**erreurs.c**) présente une erreur majeure : il tente d'accéder à des indices de tableau supérieurs à la taille maximale du tableau (100).

#### Exemple (erreurs.c)

```
#include <stdio.h>

int main() {

   int tableau[100];

   for (int compteur = 0; compteur < sizeof(tableau); compteur++) { //Erreur
       tableau[compteur] = tableau[compteur] * 2;
   }

   return (0);

}
```

Pour la compilation et la création d'un exécutable

```
$ gcc erreurs.c
```

Lorsque nous exécutons le code, nous obtenons l'erreur suivante et le programme se plante (comme prévu).

```
./a.out
*** stack smashing detected ***: terminated
fish: Job 1, './a.out' terminated by signal SIGABRT (Abort)
```

Pour déboguer ce code et trouver la source de l'erreur, nous devrons d'abord le compiler et ajouter des informations supplémentaires pour le débogage avec l'option `-ggdb3`.

```
$ gcc -ggdb3 erreurs.c
```

Nous allons maintenant exécuter le code avec gdb.

```
$ gdb a.out
GNU gdb (Ubuntu 12.0.90-0ubuntu1) 12.0.90
Copyright (C) 2022 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from a.out...
(gdb)
```

Une fois que vous exécutez gdb, vous verrez une autre ligne de commande avec `(gdb)`.

Tapez `r` pour exécuter le programme.

```
(gdb) r
Starting program: ./ProgC/gdb/a.out
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
*** stack smashing detected ***: terminated

Program received signal SIGABRT, Aborted.
__pthread_kill_implementation (no_tid=0, signo=6, threadid=140737351481152) at ./nptl/pthread_kill.c:44
44	./nptl/pthread_kill.c: No such file or directory.
```

Le programme s'est écrasé et pour trouver la ligne qui est la raison de l'écrasement, tapez `bt`.

```
(gdb) bt
#0  __pthread_kill_implementation (no_tid=0, signo=6, threadid=140737351481152) at ./nptl/pthread_kill.c:44
#1  __pthread_kill_internal (signo=6, threadid=140737351481152) at ./nptl/pthread_kill.c:78
#2  __GI___pthread_kill (threadid=140737351481152, signo=signo@entry=6) at ./nptl/pthread_kill.c:89
#3  0x00007ffff7dbc476 in __GI_raise (sig=sig@entry=6) at ../sysdeps/posix/raise.c:26
#4  0x00007ffff7da27f3 in __GI_abort () at ./stdlib/abort.c:79
#5  0x00007ffff7e036f6 in __libc_message (action=action@entry=do_abort, fmt=fmt@entry=0x7ffff7f55943 "*** %s ***: terminated\n")
    at ../sysdeps/posix/libc_fatal.c:155
#6  0x00007ffff7eb076a in __GI___fortify_fail (msg=msg@entry=0x7ffff7f5592b "stack smashing detected") at ./debug/fortify_fail.c:26
#7  0x00007ffff7eb0736 in __stack_chk_fail () at ./debug/stack_chk_fail.c:24
#8  0x00005555555551c1 in main () at erreurs.c:13
(gdb)

```

Nous voyons que l'erreur se situe à la ligne 13 du programme (erreurs.c). Vous pouvez maintenant quitter gdb en utilisant `quit`, corriger le code et répéter les étapes ci-dessus jusqu'à ce que l'erreur soit résolue.

```
(gdb) quit
A debugging session is active.

	Inferior 1 [process 3886] will be killed.

Quit anyway? (y or n) y
```

### PDB (Python)

L'objectif est d'apprendre à utiliser le débogueur Python pas à pas pour analyser et corriger une erreur dans le code.

#### Exemple 1 (erreurs1.py):

```python
from typing import List
import pdb

def double_values(tableau: List[int]) -> None:
    for compteur in range(len(tableau)):
        # Introduire une erreur : parfois multiplier par 3 au lieu de 2
        if compteur % 2 == 0:
            tableau[compteur] *= 2
        else:
            tableau[compteur] *= 3
        # Insérer un point d'arrêt pour observer la valeur de 'tableau' à chaque étape
        pdb.set_trace()

    return tableau

# Créer un tableau d'exemple
tableau: List[int] = [1, 2, 3, 4, 5]

# Appeler la fonction et stocker le résultat
resultat = double_values(tableau)

# Afficher le résultat final
print(resultat)
```

##### Instructions :

1. Exécutez le programme.
2. Lorsque le débogueur s'active (grâce à `pdb.set_trace()`), utilisez les commandes suivantes pour examiner l'état du programme :
    - `n` pour passer à la ligne suivante.
    - `p tableau` pour afficher le contenu du tableau à chaque étape.
    - `p compteur` pour afficher la valeur actuelle du compteur.
3. Essayez de comprendre pourquoi le tableau ne se comporte pas comme prévu (certains éléments sont multipliés par 3).
4. Utilisez les informations obtenues pour corriger l'erreur dans la fonction.
5. Si vous voulez sortir du débogueur à tout moment, tapez la commande q et appuyez sur Entrée. Cela mettra fin à l'exécution du programme et vous ramènera au terminal.

#### Exemple 2 :

```python
from typing import List

def double_values(tableau: List[int]) -> None:
    for compteur in range(len(tableau)):
        # Introduire une erreur : parfois multiplier par 3 au lieu de 2
        if compteur % 2 == 0:
            tableau[compteur] *= 2
        else:
            tableau[compteur] *= 3

    return tableau

# Créer un tableau d'exemple
tableau: List[int] = [1, 2, 3, 4, 5]

# Appeler la fonction et stocker le résultat
resultat = double_values(tableau)

# Afficher le résultat final
print(resultat)
```

##### Instructions pour l'exercice :

1. Enregistrez ce code dans un fichier (par exemple, `exercice_pdb.py`).
2. Ouvrez votre terminal et exécutez la commande suivante pour lancer le débogueur :

    ```bash
    python3 -m pdb exercice_pdb.py
    ```

3. Une fois dans le débogueur, les commandes suivantes vous aideront à explorer le programme :

    - `l` : pour lister les lignes de code autour de la ligne actuelle.
    - `n` : pour passer à la ligne suivante.
    - `b <numéro_ligne>` : pour placer un point d'arrêt (breakpoint) à une ligne spécifique (par exemple, `b 5` pour placer un point d'arrêt sur la ligne 5).
    - `c` : pour continuer l'exécution jusqu'au prochain point d'arrêt.
    - `p tableau` : pour afficher le contenu du tableau à tout moment.
    - `p compteur` : pour voir la valeur actuelle de `compteur`.

4. Déroulement de l'exercice :

    - Identifiez pourquoi certains éléments du tableau sont multipliés par 3.
    - Corrigez l'erreur dans le code après avoir observé les résultats du débogueur.

5. Sortir de pdb :
    - Si vous voulez sortir du débogueur à tout moment, tapez la commande q et appuyez sur Entrée. Cela mettra fin à l'exécution du programme et vous ramènera au terminal.

## Exercice 2.2 [★]

### Chaîne de compilation (C)

Voici les étapes de la chaîne de compilation :

1. Préprocesseur : Le préprocesseur gère les directives comme `#include` pour insérer des bibliothèques et des macros.

2. Compilation : Le compilateur transforme le code en assembleur et optimise les performances.

3. Edition de liens : L'éditeur de liens combine les fichiers objets et bibliothèques nécessaires.

4. Exécution : Enfin, le programme binaire est exécuté.

#### Exemple 1 (aire.c)

```c
// Directive de préprocesseur pour inclure la bibliothèque mathématique
#include <math.h>  // Pour utiliser la constante M_PI

#include <stdio.h>

// Fonction pour calculer l'aire d'un cercle
float calculer_aire(float rayon) {
    // Utilisation de la constante pi de la bibliothèque mathématique
    return M_PI * rayon * rayon;
}

// Point d'entrée du programme
int main() {
    float rayon = 5.0;
    float aire = calculer_aire(rayon);
    // Affichage du résultat
    printf("L'aire du cercle de rayon %.2f est %.2f\n", rayon, aire);
    return 0;
}
```

### Étapes de compilation avec optimisation :

1. **Préprocesseur** :

    ```
    gcc -E aire.c -o aire.i
    ```

2. **Compilation** avec optimisation de niveau 2 :

    ```
    gcc -O2 -S aire.i -o aire.s
    ```

3. **Assemblage** :

    ```
    gcc -c aire.s -o aire.o
    ```

4. **Édition de liens** :

    ```
    gcc aire.o -lm -o aire
    ```

5. **Exécution** :
    ```
    ./aire
    ```

L'option `-O2` active des optimisations standard qui améliorent la performance sans compromettre la taille du code ou la compatibilité.

#### Exemple 2 (sphere.h, surface.c, volume.c, main.c)

Un programme C qui calcule le volume et la surface d'une sphère en utilisant deux fichiers source distincts : un pour le calcul du volume et un autre pour la surface.

##### Étapes de la chaîne de compilation avec optimisation :

1. **Préprocesseur** :

    ```
    gcc -E main.c -o main.i
    gcc -E volume.c -o volume.i
    gcc -E surface.c -o surface.i
    ```

2. **Compilation** avec optimisation de niveau 3 (pour plus d'optimisations) :

    ```
    gcc -O3 -c main.i -o main.o
    gcc -O3 -c volume.i -o volume.o
    gcc -O3 -c surface.i -o surface.o
    ```

3. **Édition de liens** :

    ```
    gcc main.o volume.o surface.o -lm -o sphere
    ```

4. **Exécution** :
    ```
    ./sphere
    ```

L'option `-O3` active des optimisations plus agressives que `-O2`, telles que l'optimisation des boucles, l'inlining de fonctions, et d'autres techniques qui peuvent améliorer la performance dans les calculs intensifs comme ceux de ce programme.

## Exercice 2.3 [★]

Apprendre à analyser le bytecode d'une fonction Python avec le module `dis` et comprendre comment l'interpréteur Python exécute les instructions.

Dans cet exercice, vous allez utiliser le module `dis` pour examiner le bytecode d'une fonction Python et répondre à des questions précises sur le processus d'interprétation. Le but est de comprendre comment Python traduit des fonctions en instructions bas-niveau et de découvrir les optimisations internes.

1. **Exécuter et observer le bytecode** :
    - Exécutez le code ci-dessous. Que remarquez-vous dans la sortie du module `dis` ?
    - Le bytecode est une suite d'instructions que l'interpréteur Python va exécuter.
2. **Explication des instructions** :
    - Pour chaque instruction du bytecode généré, essayez de comprendre son rôle. Utilisez la documentation ou les explications fournies ci-dessous.
3. **Expérimentation** :
    - Modifiez la fonction `calculer_aire` en simplifiant l'expression mathématique, par exemple, en remplaçant `math.pi * rayon * rayon` par une valeur constante. Exécutez à nouveau `dis` et comparez le bytecode généré. Quelles différences voyez-vous ?
4. **Réflexion sur l'optimisation** :
    - Quelles optimisations sont mises en œuvre par Python lorsque vous remplacez l'expression mathématique par une constante ? Observez si certaines instructions sont supprimées ou simplifiées.

#### Exemple 1

```python
import math
import dis

def calculer_aire(rayon: float) -> float:
    return math.pi * rayon * rayon

def main() -> None:
    rayon : float = 5.0
    aire : float = calculer_aire(rayon)
    print(f"L'aire du cercle de rayon {rayon:.2f} est {aire:.2f}")

if __name__ == "__main__":
    # Utilisation de dis pour afficher le bytecode de la fonction
    dis.dis(calculer_aire)
    main()
```

1. **Que fait chaque instruction du bytecode ?**  
   Par exemple, les instructions comme `LOAD_GLOBAL`, `LOAD_FAST`, ou `BINARY_MULTIPLY` apparaîtront dans le bytecode. Que signifient-elles ?

    - **`LOAD_GLOBAL`** : Cette instruction charge une variable globale (ici `math.pi`).
    - **`LOAD_FAST`** : Charge une variable locale, comme `rayon`.
    - **`BINARY_MULTIPLY`** : Effectue une multiplication binaire entre deux éléments du sommet de la pile.

2. **Modification de l’expression** :  
   Si vous remplacez l'expression `math.pi * rayon * rayon` par une valeur constante, quel changement observe-t-on dans le bytecode ? Est-il plus simple ou plus court ?

3. **Comment fonctionne la pile d’exécution ?**  
   Lors de l'analyse du bytecode, observez comment Python utilise une pile pour stocker temporairement les valeurs intermédiaires lors des calculs. Par exemple, les valeurs de `rayon` et de `math.pi` sont empilées, puis multipliées.

#### Exemple 2

Ci-dessous un deuxième exemple utilisant le module `dis` pour analyser le bytecode d'une autre fonction, cette fois-ci en introduisant une structure de contrôle comme une boucle `for`. Cet exemple aidera à explorer le fonctionnement des boucles et des instructions associées dans le bytecode Python.

Analyser le bytecode d'une fonction Python contenant une boucle `for` pour comprendre comment Python gère les structures de contrôle. Dans cet exercice, vous allez explorer comment le bytecode est généré pour une fonction qui utilise une boucle `for`. Vous allez comparer la gestion de la boucle avec des opérations simples et découvrir comment l'interpréteur Python implémente ces structures de contrôle.

### Étapes de l'exercice :

1. **Analyser le bytecode d'une boucle `for`** :

    - Exécutez le code ci-dessous et utilisez le module `dis` pour observer le bytecode de la fonction `calculer_somme`.
    - Notez les instructions spécifiques liées à la gestion de la boucle.

2. **Comprendre les instructions de la boucle** :
    - Essayez de comprendre le fonctionnement des instructions comme `SETUP_LOOP`, `GET_ITER`, `FOR_ITER`, et `POP_BLOCK`.
3. **Expérimentation** :
    - Modifiez la fonction pour utiliser un autre type de boucle, comme une boucle `while`, et observez les différences dans le bytecode généré.

### Exemple 2 (somme_dis.py):

```python
import dis

def calculer_somme(n: int) -> int:
    somme = 0
    for i in range(n):
        somme += i
    return somme

def main() -> None:
    n = 10
    resultat = calculer_somme(n)
    print(f"La somme des entiers de 0 à {n-1} est {resultat}")

if __name__ == "__main__":
    # Utilisation de dis pour afficher le bytecode de la fonction
    dis.dis(calculer_somme)
    main()
```

1. **Comment est gérée la boucle `for` dans le bytecode ?**

    - Examinez les instructions `GET_ITER` et `FOR_ITER`. Que font-elles ?
    - **`GET_ITER`** : Cette instruction obtient un itérateur à partir de l'objet `range(n)`.
    - **`FOR_ITER`** : Récupère le prochain élément de l'itérateur et gère l'arrêt de la boucle lorsqu'il n'y a plus d'éléments.

2. **Structure de la boucle** :  
   Identifiez les instructions comme `SETUP_LOOP` et `POP_BLOCK`. Quel est leur rôle dans la gestion de la boucle ?

    - **`SETUP_LOOP`** : Prépare la gestion de la boucle et la gestion des exceptions (comme une interruption de la boucle).
    - **`POP_BLOCK`** : Enlève la boucle de la pile de contrôle une fois qu'elle est terminée.

3. **Modification de la boucle** :  
   Changez la boucle `for` pour une boucle `while` et exécutez à nouveau le module `dis` pour voir les différences dans le bytecode.

    Exemple de modification :

    ```python
    def calculer_somme(n: int) -> int:
        somme = 0
        i = 0
        while i < n:
            somme += i
            i += 1
        return somme
    ```

    Comparez les instructions générées pour la boucle `while` avec celles de la boucle `for`.

## Exercice 2.4 [★★]

**Manipulation de Chaînes de Caractères**

**Objectif :** Écrire des programmes en C et en Python pour effectuer les opérations suivantes sur des chaînes de caractères, sans utiliser de bibliothèques standard ou externes :

1. **Calcul de la Longueur d'une Chaîne :**

    - Écrire une fonction qui calcule le nombre de caractères dans une chaîne de caractères. Cette fonction doit parcourir la chaîne caractère par caractère jusqu'à atteindre le caractère nul (`\0`) et compter les caractères.

2. **Copie d'une Chaîne :**

    - Écrire une fonction qui copie une chaîne de caractères dans une autre chaîne. Cette fonction doit parcourir la chaîne source caractère par caractère et les copier dans la chaîne de destination. Assurez-vous que la chaîne destination se termine par le caractère nul (`\0`).

3. **Concaténation de Deux Chaînes :**
    - Écrire une fonction qui concatène deux chaînes de caractères. La fonction doit copier la première chaîne dans une chaîne de résultat, puis ajouter les caractères de la deuxième chaîne à partir de la fin de la première chaîne. Le résultat doit se terminer par le caractère nul (`\0`).

**Instructions :**

-   **En C :** Écrire un programme nommé `chaine.c` qui utilise les fonctions définies pour calculer la longueur, copier, et concaténer les chaînes. Demandez à l'utilisateur de saisir deux chaînes de caractères et affichez les résultats de chaque opération.

-   **En Python :** Écrire un programme nommé `chaine.py` qui réalise les mêmes opérations que le programme en C. Demandez à l'utilisateur de saisir deux chaînes de caractères et affichez les résultats de chaque opération.

## Exercice 2.5 [★★]

**Gestion des données d'étudiant.e.s**

**Objectif :** Écrire des programmes en C et en Python pour gérer les données de 5 étudiant.e.s en utilisant des structures en C et des classes en Python.

### En C

1. **Définir une Structure :**

    - Créez une structure (`struct`) pour représenter les informations d'un étudiant. Cette structure doit inclure des membres pour le nom, le prénom, l'adresse, et les notes, par exemple.

2. **Initialiser et manipuler les données :**

    - Utilisez la fonction `strcpy` pour initialiser les chaînes de caractères dans la structure.
    - Créez un tableau de 5 éléments de cette structure pour représenter 5 étudiant.e.s.

3. **Saisie et affichage des données :**
    - Demandez à l'utilisateur de saisir les détails pour chaque étudiant.
    - Affichez les informations des 5 étudiant.e.s après la saisie.

### En Python

1. **Définir une classe :**

    - Créez une classe pour représenter les informations d'un étudiant. Cette classe doit inclure des attributs pour le nom, le prénom, l'adresse, et les notes.

2. **Initialiser et manipuler les données :**

    - Créez une instance de la classe pour chaque étudiant.e.
    - Stockez ces instances dans une liste.

3. **Saisie et affichage des données :**
    - Demandez à l'utilisateur de saisir les détails pour chaque étudiant.
    - Affichez les informations de chaque étudiant après la saisie.

**Exemple :**

Un exemple d'utilisation de ce programme pourrait être :

-   L'utilisateur entre les détails de 5 étudiant.e.s, puis le programme affiche ces informations, par exemple :

```
  Étudiant.e 1 :
  Nom : Dupont
  Prénom : Marie
  Adresse : 20, Boulevard Niels Bohr, Lyon
  Note 1 : 16.5
  Note 2 : 12.1

  Étudiant.e 2 :
  Nom : Martin
  Prénom : Pierre
  Adresse : 22, Boulevard Niels Bohr, Lyon
  Note 1 : 14.0
  Note 2 : 14.1

  ...
```

## Exercice 2.6 [★★]

**Recherche de phrases dans un fichier**

**Objectif :** Écrire des programmes en C et en Python qui permettent à l'utilisateur de rechercher une phrase spécifique dans un fichier donné. Le programme doit afficher les lignes du fichier où la phrase est présente, ainsi que le nombre de fois qu'elle apparaît dans chaque ligne.

### En C

1. **Demander les entrées :**

    - Demandez à l'utilisateur de saisir le nom du fichier dans lequel la recherche sera effectuée.
    - Demandez à l'utilisateur de saisir la phrase à rechercher.

2. **Ouvrir et lire le fichier :**

    - Utilisez les fonctions de lecture de fichiers en C telles que `fopen`, `fgets`, et `fclose` pour ouvrir le fichier et lire son contenu ligne par ligne.

3. **Rechercher la phrase :**

    - Pour chaque ligne lue, comptez combien de fois la phrase apparaît.
    - Si la phrase est présente, affichez le numéro de la ligne et le nombre de fois qu'elle apparaît.

4. **Afficher les résultats :**
    - Affichez les résultats de la recherche de manière formatée.

### En Python

1. **Demander les entrées :**

    - Demandez à l'utilisateur de saisir le nom du fichier dans lequel la recherche sera effectuée.
    - Demandez à l'utilisateur de saisir la phrase à rechercher.

2. **Ouvrir et lire le fichier :**

    - Utilisez les fonctions de lecture de fichiers en Python comme `open` et `readlines` pour ouvrir le fichier et lire son contenu ligne par ligne.

3. **Rechercher la phrase :**

    - Pour chaque ligne lue, comptez combien de fois la phrase apparaît.
    - Si la phrase est présente, affichez le numéro de la ligne et le nombre de fois qu'elle apparaît.

4. **Afficher les résultats :**
    - Affichez les résultats de la recherche de manière formatée.

### Exemple d'utilisation

```
Entrez le nom du fichier : fichier.txt
Entrez la phrase que vous souhaitez rechercher : exemple de phrase

Résultats de la recherche :
Ligne 10, 2 fois
Ligne 30, 1 fois
```

## Exercice 2.7 [★★★]

**Gestion des couleurs et comptage des occurrences**

**Objectif :** Écrire des programmes en C et en Python qui stockent un ensemble de couleurs et affichent les couleurs distinctes avec leur nombre d'occurrences. Chaque couleur est représentée par quatre valeurs : R (rouge), G (vert), B (bleu), et A (alpha), chacune étant un octet.

### En C

1. **Définir une structure :**

    - Créez une structure `Color` pour représenter une couleur, avec des membres pour R, G, B et A.

2. **Créer un tableau de couleurs :**

    - Déclarez un tableau de 100 éléments de type `Color` pour stocker les couleurs.

3. **Compter les occurrences :**

    - Créez une autre structure ou tableau pour stocker les couleurs distinctes et leur nombre d'occurrences.
    - Parcourez le tableau initial de couleurs, vérifiez si chaque couleur est déjà présente dans la structure de couleurs distinctes, et mettez à jour le compteur approprié.

4. **Afficher les résultats :**
    - Affichez chaque couleur distincte et le nombre d'occurrences dans le tableau initial.

### En Python

1. **Définir une classe :**

    - Créez une classe `Color` pour représenter une couleur, avec des attributs pour R, G, B et A.

2. **Créer un tableau de couleurs :**

    - Créez une liste de 100 instances de la classe `Color` pour stocker les couleurs.

3. **Compter les occurrences :**

    - Utilisez un dictionnaire pour stocker les couleurs distinctes et leur nombre d'occurrences.
    - Parcourez la liste de couleurs, vérifiez si chaque couleur est déjà présente dans le dictionnaire, et mettez à jour le compteur approprié.

4. **Afficher les résultats :**
    - Affichez chaque couleur distincte et le nombre d'occurrences dans la liste initiale.

### Exemples

-   Supposons que le tableau de couleurs contienne :
    ```
    ff 0x23 0x23 0x45
    ff 0x00 0x23 0x12
    ff 0x23 0x23 0x45
    ```
    Le programme doit afficher :
    ```
    ff 0x23 0x23 0x45 : 2
    ff 0x00 0x23 0x12 : 1
    ```

## Exercice 2.8 [★★★]

**Exercice : Synthèse des approches en langage C et Python**

**Objectif :** Créer un rapport comparatif (`programmation_C_Python.md`) détaillé qui synthétise les différentes approches de programmation en C et Python, en couvrant les aspects suivants :

1. **Débogage :** Compare les méthodes de débogage en C (avec `gdb`) et en Python (avec `pdb`), en expliquant les outils, les techniques et les différences dans l'approche du débogage.

2. **Chaîne de Compilation :** Décris le processus de compilation en C avec `gcc`, en détaillant chaque étape (prétraitement, compilation, assemblage, et édition des liens) et compare-le avec la gestion des modules en Python.

3. **Inspection de Code :** Analyse l’utilisation de `dis` en Python pour examiner le bytecode et compare-le avec les outils disponibles pour inspecter le code compilé en C.

4. **Manipulation de Chaînes de Caractères :** Compare les techniques de manipulation de chaînes en C (comme les fonctions de la bibliothèque standard) et en Python (comme les méthodes de chaîne et les f-strings), en mettant en évidence les avantages et les inconvénients de chaque approche.

5. **Gestion des Données et Recherche dans les Fichiers :** Compare la gestion des structures de données en C (structures) et en Python (classes) pour les données d’étudiant.e.s, et explique les techniques pour rechercher des phrases dans des fichiers en utilisant les deux langages.
