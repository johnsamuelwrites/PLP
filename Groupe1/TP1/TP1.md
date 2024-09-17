Année: 2023-2024
----------------

# Travaux pratiques 1

## Objectifs

C et Python appartiennent à des paradigmes de programmation différents : C est procédural et bas niveau, tandis que Python est impératif, orienté objet et de haut niveau. Malgré ces différences, ils partagent des concepts comme les variables, les structures de contrôle et les opérateurs. Voici comment ces similarités et différences se reflètent à travers les objectifs :

1. **Bases de la programmation :** Les deux langages utilisent des fonctions pour afficher des données (`printf` en C, `print` en Python), mais Python a une syntaxe plus simple et une gestion automatique de la mémoire.

2. **Manipulation des variables :** C exige une déclaration explicite des types de variables, tandis que Python utilise un typage dynamique et peut également supporter des annotations pour le typage statique.

3. **Opérateurs :** Les deux langages utilisent des opérateurs arithmétiques, logiques, de comparaison, bit à bit, ainsi que des opérateurs d'assignation.

4. **Boucles et structures de contrôle :** C utilise des accolades pour les blocs de code, tandis que Python utilise l'indentation. Les deux langages ont des boucles (`for`, `while`) et des structures conditionnelles (`if`, `else`).

5. **Conversion et formatage :** Les deux langages nécessitent des techniques de formatage (comme la conversion en binaire), mais C utilise des fonctions spécifiques tandis que Python propose des f-strings et des méthodes intégrées pour un formatage plus flexible.


## Exercice 1.1 [★]

### **Affichage de "Bonjour le Monde" en C et en Python**

#### **Objectif :**
Écrire des programmes simples en C et en Python qui affichent le message "Bonjour le Monde!" à l'écran. 

#### **En C**

1. **Écrire le programme en C :**

   Écrivez un programme C nommé `bonjour.c` qui affiche le message "Bonjour le Monde!" à l'écran.

2. **Compiler et exécuter le programme en C:**

   Ouvrez un terminal et compilez le fichier en utilisant GCC :

   ```bash
   $ gcc bonjour.c
   ```

   Cela générera un fichier exécutable par défaut appelé `a.out`. Vous pouvez exécuter le programme avec :

   ```bash
   $ ./a.out
   ```

   Vous devriez voir le message "Bonjour le Monde!" affiché à l'écran.

3. **Renommer l'exécutable (optionnel) :**

   Pour générer un exécutable avec un nom spécifique (par exemple, `bonjour`), utilisez l'option `-o` lors de la compilation :

   ```bash
   $ gcc -o bonjour bonjour.c
   ```

   Exécutez le programme avec le nouveau nom d'exécutable :

   ```bash
   $ ./bonjour
   ```

4. **Afficher les avertissements (optionnel) :**

   Pour voir tous les avertissements pendant la compilation, utilisez les options `-Wall` et `-Wextra` :

   ```bash
   $ gcc -Wall -Wextra -o bonjour bonjour.c
   ```

   Exécutez le programme avec les avertissements activés :

   ```bash
   $ ./bonjour
   ```

#### **En Python**

1. **Écrire le programme en Python :**

   Écrivez un programme Python nommé `bonjour.py` qui affiche le message "Bonjour le Monde!" à l'écran.

2. **Exécuter le programme :**

   Ouvrez un terminal et exécutez le programme avec Python :

   ```bash
   $ python3 bonjour.py
   ```

   Vous devriez voir le message "Bonjour le Monde!" affiché à l'écran.

### **Instructions supplémentaires :**

1. **Vérifiez que le message "Bonjour le Monde!" s'affiche correctement** à l'écran pour les deux programmes.
2. **Assurez-vous que le programme Python utilise la commande correcte** pour l'exécuter (avec `python3` si vous utilisez Python 3).


## Exercice 1.2 [★]

**Calcul de l'aire et du périmètre d'un cercle en C et Python**

Dans le fichier *cercle.c*, écrivez un programme en C qui calcule à la fois l'aire et le périmètre d'un cercle. Utilisez une variable `rayon` de type `float` ou `double` pour stocker le rayon du cercle.

Dans un second fichier *cercle.py*, écrivez un programme Python qui effectue les mêmes opérations.

Les étapes à suivre pour les deux programmes sont les suivantes :

1. Demandez à l'utilisateur de saisir la valeur du rayon du cercle.
2. Calculez l'aire du cercle en utilisant la formule :
   - aire = pi * rayon * rayon
   (où pi peut être approximé à 3.14159, ou en Python vous pouvez utiliser `math.pi` de la bibliothèque `math`).
3. Calculez le périmètre du cercle en utilisant la formule :
   - périmètre = 2 * pi * rayon
4. Affichez les valeurs calculées de l'aire et du périmètre du cercle.

### Pour le fichier en C :
- Compilez le fichier *cercle.c* en utilisant GCC pour créer un exécutable nommé "cercle". Utilisez la commande suivante dans le terminal :

   ```
   $ gcc -o cercle cercle.c -lm
   ```

   L'option `-lm` est utilisée pour lier la bibliothèque mathématique standard (`<math.h>`).

- Exécutez le programme en utilisant la commande suivante :

   ```
   $ ./cercle
   ```

### Pour le fichier en Python :
- Exécutez le fichier *cercle.py* directement à partir du terminal avec la commande suivante :

   ```
   $ python3 cercle.py
   ```

Assurez-vous que vous obtenez les mêmes résultats pour les valeurs de l'aire et du périmètre du cercle en fonction du rayon saisi, dans les deux programmes.

## Exercice 1.3 [★]

### Tailles des types de base en C et Python

#### En C (fichier *sizeof_types.c*)
Écrivez un programme qui affiche la taille en octets des différents types de base, en utilisant l'opérateur `sizeof()` pour les types suivants :

1. `char`
2. `short`
3. `int`
4. `long int`
5. `long long int`
6. `float`
7. `double`
8. `long double`

Affichez également les versions signées (`signed`) et non-signées (`unsigned`) pour les types `char`, `short`, `int`, et `long int`.

Compilez et exécutez ce programme :

```bash
$ gcc -o sizeof_types sizeof_types.c
$ ./sizeof_types
```

#### En Python (fichier *sizeof_types.py*)

Python n'a pas les mêmes types statiques que C, mais voici les types de base que vous pouvez examiner pour obtenir leur taille avec la fonction `sys.getsizeof()` :

1. `int` (pour les entiers, qui sont dynamiques en Python)
2. `float` (qui correspond au type `double` en C)
3. `bool` (pour les valeurs booléennes)
4. `str` (pour les chaînes de caractères)
5. `list` (pour les listes)
6. `tuple` (pour les tuples)
7. `dict` (pour les dictionnaires)

## Exercice 1.4 [★★]

### **Affectation et affichage des variables de types de base en C et Python**

#### **En C (fichier *variables.c*)**

1. Déclare des variables pour chacun des types de base suivants :
   - `char`
   - `signed char`
   - `unsigned char`
   - `short`
   - `unsigned short`
   - `int`
   - `unsigned int`
   - `long int`
   - `unsigned long int`
   - `long long int`
   - `float`
   - `double`
   - `long double`

2. Assigne une valeur à chaque variable. Choisis des valeurs représentatives pour chaque type de donnée, y compris des valeurs négatives pour les types signés et des valeurs maximales pour les types non-signés.

3. Affiche les valeurs de toutes les variables à l'aide de la fonction `printf()`.

4. Compile et exécute le programme en utilisant les commandes suivantes :

   ```bash
   $ gcc -o variables variables.c
   $ ./variables
   ```

#### **En Python (fichier *variables.py*)**

1. Déclare des variables pour chacun des types suivants :
   - `int`
   - `float`
   - `str` (chaîne de caractères)
   - `bool` (valeur booléenne)
   - `list` (liste)
   - `tuple` (tuple)
   - `dict` (dictionnaire)

2. Assigne une valeur à chaque variable. Choisis des valeurs représentatives pour chaque type de donnée.

3. Affiche les valeurs de toutes les variables à l'aide de la fonction `print()`.

4. Exécute le programme en utilisant la commande suivante :

   ```bash
   $ python3 variables.py
   ```


## Exercice 1.5 [★★]

### **Utilisation des opérateurs arithmétiques et logiques en C et Python**

Écrivez un programme dans les langages C et Python qui utilise deux variables `a` et `b` avec les valeurs suivantes :

- `a = 16`
- `b = 3`

Pour chaque langage, effectuez les opérations suivantes et affichez les résultats :

1. Additionnez `a` et `b`.
2. Soustrayez `b` de `a`.
3. Multipliez `a` par `b`.
4. Divisez `a` par `b` (assurez-vous de gérer les types de données correctement pour obtenir un résultat précis).
5. Utilisez l'opérateur de modulo (`%`) pour calculer le reste de la division de `a` par `b`.
6. Vérifiez si `a` est égal à `b` et affichez le résultat sous forme de booléen.
7. Vérifiez si `a` est supérieur à `b` et affichez le résultat sous forme de booléen.

#### **En C (fichier *operateurs.c*)**

1. Déclarez les variables `a` et `b`.
2. Effectuez les opérations arithmétiques et logiques mentionnées ci-dessus.
3. Utilisez `printf()` pour afficher les résultats.

Compilez et exécutez le programme :

```bash
$ gcc -o operateurs operateurs.c
$ ./operateurs
```

#### **En Python (fichier *operateurs.py*)**

1. Déclarez les variables `a` et `b`.
2. Effectuez les opérations arithmétiques et logiques mentionnées ci-dessus.
3. Utilisez `print()` pour afficher les résultats.

Exécutez le programme :

```bash
$ python3 operateurs.py
```

Assurez-vous que les opérations sont correctement réalisées et que les résultats sont affichés correctement pour les deux langages.

## Exercice 1.6 [★★]

### **Affichage d'un triangle rectangle avec des boucles**

#### **Objectif :**
Écrire des programmes en C et en Python pour afficher un triangle rectangle. La taille du triangle sera déterminée par une variable entrée par l'utilisateur, et les caractères alternés (`*` et `#`) seront utilisés pour remplir le triangle.

Entrez une valeur pour `taille` (strictement inférieure à 10) pour voir le triangle rectangle.

#### **Instructions supplémentaires :**

1. **Testez chaque programme** avec différentes valeurs pour vérifier que les triangles sont correctement affichés.
2. **Assurez-vous que la taille du triangle** est correcte et que les boucles fonctionnent comme prévu.
3. **Vérifiez que les caractères sont alternés** correctement dans chaque ligne du triangle.

Voici un exemple de ce que le programme doit afficher lorsque `compteur` est égal à 5 :

```
*
* *
* # *
* # # *
* * * * *
```

Testez le code en utilisant différentes valeurs de `compteur`.

Après avoir réussi avec des boucles `for`, écrivez une nouvelle version du code en utilisant soit une boucle `while` ou `do..while`. Vous pouvez utiliser des branchements conditionnels (`if`) et inconditionnels (`break` ou `continue`) pour atteindre cet objectif.

## Exercice 1.7 [★★]

### **Structures de contrôle avec boucles et conditions en C et Python**

#### **Objectif :**
Écrivez des programmes en C et en Python pour tester diverses structures de contrôle en utilisant des boucles et des branchements conditionnels. Vous devez :

1. **Afficher les nombres de 1 à 1000** qui répondent à une condition donnée.

2. **Utiliser des boucles** (`for`, `while`, `do..while`) pour parcourir les nombres et appliquer les conditions.

3. **Utiliser des branchements conditionnels** (`if`, `else`, `break`, `continue`) pour contrôler le flux du programme.

#### **Conditions à tester :**

1. **Divisibilité :** Affichez les nombres de 1 à 1000 qui sont divisibles par 4 mais pas par 6.

2. **Paire ou Impair :** Affichez les nombres de 1 à 1000 qui sont pairs et divisibles par 8.

3. **Divisibilité multiple :** Affichez les nombres de 1 à 1000 qui sont divisibles par 5 ou 7, mais ne sont pas divisibles par 10.

#### **En C (fichier *controle.c*)**

1. **Divisibilité par 4 mais pas par 6 :**
   - Utilisez une boucle pour parcourir les nombres de 1 à 1000.
   - Utilisez des instructions conditionnelles pour vérifier si un nombre est divisible par 4 mais pas par 6.
   
2. **Nombres pairs et divisibles par 8 :**
   - Utilisez une boucle pour parcourir les nombres de 1 à 1000.
   - Vérifiez si un nombre est pair et divisible par 8.

3. **Divisibilité par 5 ou 7 mais pas par 10 :**
   - Utilisez une boucle pour parcourir les nombres de 1 à 1000.
   - Vérifiez si un nombre est divisible par 5 ou 7 mais pas par 10.

Compilez et exécutez le programme :

```bash
$ gcc -o controle controle.c
$ ./controle
```

#### **En Python (fichier *controle.py*)**

1. **Divisibilité par 4 mais pas par 6 :**
   - Utilisez une boucle `for` pour parcourir les nombres de 1 à 1000.
   - Utilisez des instructions conditionnelles pour vérifier si un nombre est divisible par 4 mais pas par 6.

2. **Nombres pairs et divisibles par 8 :**
   - Utilisez une boucle `for` pour parcourir les nombres de 1 à 1000.
   - Vérifiez si un nombre est pair et divisible par 8.

3. **Divisibilité par 5 ou 7 mais pas par 10 :**
   - Utilisez une boucle `for` pour parcourir les nombres de 1 à 1000.
   - Vérifiez si un nombre est divisible par 5 ou 7 mais pas par 10.

Exécutez le programme :

```bash
$ python3 controle.py
```

Assurez-vous que les boucles et les conditions fonctionnent correctement pour les deux programmes.

## Exercice 1.8 [★★★]

### **Exercice : Opérations mathématiques et bitwise avec structures de contrôle**

#### **Objectif :**
Écrire des programmes en C et en Python qui utilisent une structure de contrôle (`switch` en C et une série de `if-elif` en Python) pour effectuer différentes opérations en fonction d'un opérateur.

#### **Description :**

Écrivez un programme qui :

1. **Déclare trois variables :**
   - `num1` (entier)
   - `num2` (entier)
   - `op` (un caractère représentant un opérateur)

2. **Utilisez une structure `switch` en C** ou des conditions `if-elif` en Python pour effectuer l'opération correspondant à la valeur de `op` :
   - `+` : Addition
   - `-` : Soustraction
   - `*` : Multiplication
   - `/` : Division
   - `%` : Modulo
   - `&` : Opération bitwise AND
   - `|` : Opération bitwise OR
   - `~` : Opération bitwise NOT (un seul opérande)

3. **Affichez le résultat de l'opération.**

#### **En C (fichier *calculs.c*)**

1. Utilisez une structure `switch` pour déterminer l'opération en fonction de la valeur de `op`.
2. Assurez-vous de gérer les erreurs possibles, comme la division par zéro.


Compilez et exécutez le programme :

```bash
$ gcc -o calculs calculs.c
$ ./calculs
```

#### **En Python (fichier *calculs.py*)**

1. Pour déterminer l'opération en fonction de la valeur de op, vous pouvez utiliser des instructions if-elif pour les versions de Python antérieures à 3.10. À partir de Python 3.10, vous pouvez également utiliser le mot-clé match, qui offre une alternative plus concise et expressive pour les comparaisons de valeurs, remplaçant ainsi les structures if-elif-else traditionnelles.
2. Assurez-vous de gérer les erreurs possibles, comme la division par zéro.

Exécutez le programme :

```bash
$ python3 calculs.py
```

#### **Instructions supplémentaires :**

1. **Vérifiez que le programme gère correctement chaque opérateur** et affiche le résultat attendu.
2. **Assurez-vous de gérer les erreurs** comme la division par zéro et les opérateurs non reconnus.
3. **Testez le programme avec différentes valeurs** pour vérifier le comportement pour chaque opérateur.

## Exercice 1.9 [★★★]

### **Exercice : Affichage d'un nombre en format binaire**

#### **Objectif :**
Écrire des programmes en C et en Python pour convertir et afficher un nombre entier en format binaire.

#### **Description :**

Écrivez un programme qui :

1. **Déclare une variable entière** et calcule sa représentation binaire en utilisant une boucle.
2. **Affiche la représentation binaire** du nombre de manière appropriée.

Vous devez utiliser la division par 2 et le reste de la division pour obtenir chaque chiffre binaire et afficher ces chiffres dans l'ordre correct.

#### **En C (fichier *binaire.c*)**

1. Utilisez une boucle `for` pour traiter les bits du nombre entier.
2. Conservez les bits dans un tableau ou directement dans une chaîne de caractères.
3. Affichez les bits dans l'ordre correct pour obtenir la représentation binaire.


Compilez et exécutez le programme :

```bash
$ gcc -o binaire binaire.c
$ ./binaire
```

#### **En Python (fichier *binaire.py*)**

1. Utilisez une boucle pour traiter les bits du nombre entier.
2. Conservez les bits dans une chaîne de caractères.
3. Affichez les bits dans l'ordre correct pour obtenir la représentation binaire.


Exécutez le programme :

```bash
$ python3 binaire.py
```

#### **Instructions supplémentaires :**

1. **Vérifiez que le programme affiche correctement la représentation binaire** pour chaque nombre donné.
2. **Assurez-vous que la représentation binaire est correcte** pour les valeurs testées : 0, 4096, 65536, 65535, 1024.
3. **Testez le programme avec différentes valeurs** pour confirmer que les conversions sont correctement effectuées.

## Exercice 1.10 [★★★]

**Exercice : Comparaison entre C et Python**

**Objectif :** Créer un document *comparaisons.md* qui résume les différences et similarités entre les langages C et Python en tenant compte des concepts suivants :

1. **Bases de la programmation :** Compare l'utilisation des fonctions pour afficher des données (`printf` en C vs `print` en Python) et discute des différences de syntaxe et de gestion de la mémoire.

2. **Manipulation des variables :** Compare la déclaration explicite des types en C avec le typage dynamique en Python, ainsi que l'utilisation des annotations pour le typage statique en Python.

3. **Opérateurs :** Détaille les opérateurs arithmétiques, logiques, et bit à bit en C, et explique comment Python gère les opérations.

4. **Boucles et structures de contrôle :** Compare l'utilisation des accolades pour délimiter les blocs de code en C avec l'indentation en Python, ainsi que les boucles (`for`, `while`) et les structures conditionnelles (`if`, `else`).

5. **Conversion et formatage :** Compare les techniques de formatage et de conversion (comme la conversion en binaire) en C et Python, en mettant en évidence les différences entre les fonctions spécifiques en C et les f-strings en Python.

**Instructions :**
1. **Comparaison :** Pour chaque concept, fais une comparaison claire entre C et Python, en expliquant les similarités et les différences.
2. **Exemples :** Inclue des exemples de code pour illustrer les différences et similarités lorsque cela est pertinent.


## Fichiers à rendre

- Fichiers md: comparaisons.md, CONTRIBUTORS.md, README.md
- Fichiers C: *binaire.c, bonjour.c, boucles.c, calculs.c, cercle.c, controle.c, opérateurs.c, sizeof_types.c, variables.c*
- Fichiers Python: *binaire.py, bonjour.py, boucles.py, calculs.py, cercle.py, controle.py, opérateurs.py, sizeof_types.py, variables.py*

## Instructions

- N'oubliez pas les commentaires (nom du fichier, objectif, auteurs, lignes importantes de code, etc.). Les commentaires sont notés.
- N'oubliez pas de mettre à jour le fichier README.md et d'ajouter les détails.
- Compte rendu au format .zip en un seul fichier.

### Exemple

 
#### CONTRIBUTORS.md

```             
 1. NOM Prénom
 2. NOM Prénom
```             


#### README.md

```             
# Bibliothèques:               
* stdio.h               
* ..              

# Références:               
* groupe..               
* http://www.example.com               
* ..              

# Difficulté: ..               
* ..              

# Commentaires               
* commentaire 1               
* commentaire 2               
* ..             
```
