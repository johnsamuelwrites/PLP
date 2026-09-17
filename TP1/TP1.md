# Travaux pratiques 1

## Année: 2026-2027

## Objectifs

C est un langage procédural et bas niveau. Il permet de comprendre la gestion mémoire, les types de données et les structures de contrôle. Les objectifs des TP se concentrent sur :

1. **Bases de la programmation :** Utilisation des fonctions pour afficher des données (`printf`), manipulation des entrées et sorties, compilation et exécution.
2. **Manipulation des variables :** Déclaration explicite des types de variables (`int`, `float`, `char`, etc.).
3. **Opérateurs :** Arithmétiques, logiques, de comparaison et bit à bit.
4. **Boucles et structures de contrôle :** `for`, `while`, `do..while`, `if`, `else`, `break`, `continue`.
5. **Conversion et formatage :** Techniques de formatage et conversion des types (ex. conversion en binaire).

---

## Exercice 1.1 [★]

### **Affichage de "Bonjour le Monde" en C**

#### **Objectif :**

Écrire un programme simple en C qui affiche le message "Bonjour le Monde!" à l'écran.

#### Étapes :

1. Créez le fichier `bonjour.c` et écrivez le programme qui affiche le message.
2. Compilez le fichier en utilisant GCC :

```bash
$ gcc bonjour.c
```

3. Exécutez le programme :

```bash
$ ./a.out
```

4. Pour générer un exécutable avec un nom spécifique :

```bash
$ gcc -o bonjour bonjour.c
$ ./bonjour
```

5. Pour voir tous les avertissements pendant la compilation :

```bash
$ gcc -Wall -Wextra -o bonjour bonjour.c
$ ./bonjour
```

---

## Exercice 1.2 [★]

### **Calcul de l'aire et du périmètre d'un cercle en C**

1. Créez `cercle.c`.
2. Demandez à l'utilisateur de saisir le rayon (`float` ou `double`).
3. Calculez l’aire : `aire = pi * rayon * rayon` (pi ≈ 3.14159).
4. Calculez le périmètre : `perimetre = 2 * pi * rayon`.
5. Affichez les résultats avec `printf()`.

**Compilation et exécution :**

```bash
$ gcc -o cercle cercle.c -lm
$ ./cercle
```

*(L’option `-lm` permet de lier la bibliothèque mathématique `<math.h>`.)*

---

## Exercice 1.3 [★]

### **Tailles des types de base en C**

1. Créez `sizeof_types.c`.
2. Affichez la taille en octets des types :

* `char`, `signed char`, `unsigned char`
* `short`, `unsigned short`
* `int`, `unsigned int`
* `long int`, `unsigned long int`
* `long long int`
* `float`
* `double`
* `long double`

3. Utilisez l’opérateur `sizeof()` et `printf()` pour afficher les résultats.

**Compilation et exécution :**

```bash
$ gcc -o sizeof_types sizeof_types.c
$ ./sizeof_types
```

---

## Exercice 1.4 [★★]

### **Affectation et affichage des variables de types de base en C**

1. Créez `variables.c`.
2. Déclarez des variables pour tous les types de base (`char`, `short`, `int`, `long int`, `long long int`, `float`, `double`, `long double`), y compris les versions signées et non signées.
3. Assignez des valeurs représentatives (valeurs négatives pour les types signés et maximales pour les types non signés).
4. Affichez toutes les variables avec `printf()`.
5. Compilez et exécutez :

```bash
$ gcc -o variables variables.c
$ ./variables
```

---

## Exercice 1.5 [★★]

### **Utilisation des opérateurs arithmétiques et logiques en C**

1. Créez `operateurs.c`.
2. Déclarez deux variables : `a = 16`, `b = 3`.
3. Effectuez et affichez :

* Addition, soustraction, multiplication, division, modulo
* Comparaisons : égalité (`==`), supérieur (`>`)

**Compilation et exécution :**

```bash
$ gcc -o operateurs operateurs.c
$ ./operateurs
```

---

## Exercice 1.6 [★★]

### **Affichage d'un triangle rectangle avec des boucles**

1. Créez `boucles.c`.
2. Demandez à l’utilisateur d’entrer une taille `< 10`.
3. Affichez un triangle rectangle dont les bords sont en `*` et l'intérieur en `#` (la dernière ligne ne contient que des `*`).

Exemple pour taille = 5 :

```
*
* *
* # *
* # # *
* * * * *
```

4. Réalisez deux versions :

* avec boucle `for`
* avec boucle `while` ou `do..while`

5. Testez avec différentes tailles pour vérifier que les bords, l'intérieur et la taille sont corrects.

---

## Exercice 1.7 [★★]

### **Structures de contrôle avec boucles et conditions en C**

1. Créez `controle.c`.
2. Parcourez les nombres de 1 à 1000 et appliquez les conditions suivantes :

* Divisible par 4 mais pas par 6
* Nombre pair et divisible par 8
* Divisible par 5 ou 7 mais pas par 10

3. Utilisez des boucles (`for`, `while`, `do..while`) et des instructions conditionnelles (`if`, `else`, `break`, `continue`).

**Compilation et exécution :**

```bash
$ gcc -o controle controle.c
$ ./controle
```

---

## Exercice 1.8 [★★★]

### **Opérations arithmétiques et bit à bit avec structures de contrôle**

1. Créez `calculs.c`.
2. Déclarez `num1`, `num2` (entiers) et `op` (caractère).
3. Utilisez un `switch` pour effectuer l’opération correspondante :

* `+` Addition
* `-` Soustraction
* `*` Multiplication
* `/` Division
* `%` Modulo
* `&` ET bit à bit
* `|` OU bit à bit
* `~` NON bit à bit (un seul opérande)

4. Affichez le résultat et gérez les erreurs (ex. division par zéro).

**Compilation et exécution :**

```bash
$ gcc -o calculs calculs.c
$ ./calculs
```

---

## Exercice 1.9 [★★★]

### **Affichage d'un nombre en format binaire**

1. Créez `binaire.c`.
2. Déclarez une variable entière.
3. Convertissez et affichez sa représentation binaire :

   * utilisez la division par 2 et le reste pour obtenir chaque chiffre binaire
   * affichez les bits dans l’ordre correct

**Compilation et exécution :**

```bash
$ gcc -o binaire binaire.c
$ ./binaire
```

**Instructions supplémentaires :**

* Testez avec plusieurs valeurs : 0, 4096, 65536, 65535, 1024.

---



## Fichiers à rendre

* **Markdown :** `CONTRIBUTORS.md`, `README.md`
* **C :** `binaire.c`, `bonjour.c`, `boucles.c`, `calculs.c`, `cercle.c`, `controle.c`, `operateurs.c`, `sizeof_types.c`, `variables.c`

---

## Instructions générales

1. Ajoutez des commentaires clairs : nom du fichier, objectif, auteurs, lignes importantes.
2. Respectez les noms de fichiers indiqués dans chaque exercice.
3. Votre code doit compiler sans erreur et, dans la mesure du possible, sans avertissement (`gcc -Wall -Wextra`).
4. Complétez le fichier `README.md` : auto-évaluation, bibliothèques utilisées, références, difficulté et commentaires.
5. Les fichiers de ce TP font partie du rendu unique (TP1 à TP5) décrit dans le [README](../README.md) du dépôt.

### Exemple

#### CONTRIBUTORS.md

```
 1. NOM Prénom
 2. NOM Prénom
```

#### README.md

```
# Auto-évaluation (TP1)
| Exercice | État       | Remarques                    |
|----------|------------|------------------------------|
| 1.1      | réalisé    |                              |
| 1.2      | partiel    | périmètre non affiché        |
| ..       | ..         | ..                           |

# Bibliothèques
* stdio.h
* math.h
* ..

# Références
* groupe..
* http://www.example.com
* ..

# Difficulté
* ..

# Commentaires
* commentaire 1
* commentaire 2
* ..
```
