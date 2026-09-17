# Travaux pratiques 5

## Année: 2026-2027

## Objectifs

1. **Gérer les variables dans l'interpréteur :** Permettre l'affectation, le stockage et la récupération de valeurs pour des variables dans l'interpréteur.

2. **Implémenter, parser et évaluer des expressions lambda :** Ajouter le support des fonctions anonymes et évaluer dynamiquement les expressions mathématiques contenant des variables.

## Exercice 5.1 [★★]

### Gérer les variables dans l'interpréteur

**Objectif :**

Étendre l'interpréteur existant pour qu'il prenne en charge l'affectation simple de variables. L'objectif est de permettre l'affectation de valeurs à des variables, tout en respectant certaines contraintes de type et en utilisant l'encodage UTF-8 pour les noms de variables.

### Contraintes :

1. **Pas de changement de type :** Une fois qu'une variable est affectée à un type (entier, nombre réel ou chaîne de caractères), elle doit conserver ce type. Par exemple, si `x = 12`, on ne peut pas réaffecter `x = 12.3`.
2. **Types autorisés :** Seuls trois types sont autorisés pour les variables :
   - **Entiers** (par exemple, `12`)
   - **Nombres réels** (par exemple, `12.3`)
   - **Chaînes de caractères** (par exemple, `"hello"`)
3. **Noms de variables en UTF-8 :** Les noms de variables peuvent contenir des caractères Unicode et doivent être encodés en UTF-8.

### Structures de données :

- **Table de symboles (variables)** : Utiliser une table (ou une structure équivalente) pour stocker les noms des variables, leurs valeurs et leur type.

### Étapes à suivre :

1. **Ajouter la gestion des variables dans l'interpréteur :**
   - Implémenter une table de symboles qui stocke les variables avec leurs valeurs et types respectifs.

2. **Reconnaître les affectations de variables :**
   - Lorsqu'une commande de type `> variable = valeur` est saisie, ajouter ou mettre à jour la variable dans la table de symboles, en respectant les contraintes de type.

3. **Accéder aux valeurs des variables :**
   - Si l'utilisateur saisit uniquement le nom d'une variable (par exemple, `> x`), afficher la valeur actuelle de cette variable.
   - Si la variable n'est pas définie, afficher un message d'erreur indiquant que la variable n'existe pas.

### Exemple :

- **Entrée** : `> x = 4`
- **Sortie** : `Variable x définie avec la valeur 4 (entier)`

- **Entrée** : `> z = "Bonjour"`
- **Sortie** : `Variable z définie avec la valeur "Bonjour" (chaîne de caractères)`

- **Entrée** : `> x = 12.3`
- **Sortie** : `Erreur : changement de type non autorisé pour la variable x`

- **Entrée** : `> π = 3.14`
- **Sortie** : `Variable π définie avec la valeur 3.14 (nombre réel)`

- **Entrée** : `> y`
- **Sortie** : `Erreur : la variable y n'est pas définie`


## Exercice 5.2 [★★★]

### Implémenter, parser et évaluer des expressions lambda

**Objectif :**

Étendre l'interpréteur pour qu'il prenne en charge les expressions lambda de la forme `(lambda x.une expression mathématique sans/avec parenthèses qui contient x) un nombre/variable`. L'objectif est de permettre l'évaluation des expressions lambda où la variable `x` est remplacée par une valeur numérique ou une variable déjà définie.

### Contraintes :

1. Les expressions lambda doivent suivre la syntaxe : `(lambda x.une expression mathématique)` où `une expression mathématique` peut inclure des opérateurs arithmétiques de base (+, -,...) et des parenthèses.
2. Lors de l'évaluation, la valeur numérique ou la variable fournie après l'expression lambda doit remplacer toutes les occurrences de `x` dans l'expression mathématique.
3. Si une variable est utilisée comme argument après l'expression lambda, elle doit être définie dans l'interpréteur, sinon une erreur doit être renvoyée.

### Étapes à suivre :

1. **Parsing de l'expression lambda :**
   - Identifier la structure `(lambda x.une expression mathématique)` et extraire la variable `x` ainsi que l'expression mathématique.
   - Vérifier que l'expression mathématique est bien formée et respecter les règles de priorité des opérateurs.

2. **Évaluation de l'expression lambda :**
   - Remplacer la variable `x` par la valeur fournie (soit un nombre, soit la valeur de la variable déjà définie).
   - Évaluer l'expression mathématique résultante après substitution.

3. **Gestion des erreurs :**
   - Si une variable non définie est utilisée comme argument, afficher un message d'erreur approprié.
   - Assurer une gestion correcte des types de valeurs (entiers, réels, chaînes de caractères).

### Exemple :

1. **Entrée** : `> (lambda x.x + 2 * x) 3`
   - **Étapes** :
     - Le parseur identifie `lambda x` et l'expression `x + 2 * x`.
     - Remplace `x` par `3`.
     - Évalue l'expression `3 + 2 * 3 = 9`.
   - **Sortie** : `9`

2. **Entrée** : `> (lambda x.(x + 2) * x) y`
   - Supposons que la variable `y` ait été définie précédemment avec la valeur `4`.
   - **Étapes** :
     - Le parseur identifie `lambda x` et l'expression `(x + 2) * x`.
     - Remplace `x` par `4`.
     - Évalue l'expression `(4 + 2) * 4 = 24`.
   - **Sortie** : `24`

3. **Entrée** : `> (lambda x.x + 1) w`
   - Si la variable `w` n'est pas définie dans la table de symboles.
   - **Sortie** : `Erreur : la variable w n'est pas définie`

### Structures de données :

- **Table de symboles (variables)** : Pour récupérer les valeurs des variables déjà définies.
- **Parseur d'expressions lambda** : Pour analyser et extraire les composants de l'expression lambda.

---

## Fichiers à rendre

Ce TP étend l'interpréteur des TP3 et TP4, dans le dossier partagé [`interpreteur/src/`](../interpreteur/README.md) :
ne recopiez pas les sources, complétez-les.

* **Markdown :** `CONTRIBUTORS.md`, `README.md` (dans `TP5/`)
* **C :** `symboles.c` et `symboles.h` (table de symboles), `lambda.c` et `lambda.h` (expressions lambda), et `repl.c` modifié

## Instructions générales

1. Ajoutez des commentaires clairs : nom du fichier, objectif, auteurs, lignes importantes.
2. Respectez les noms de fichiers indiqués dans chaque exercice.
3. Votre code doit compiler sans erreur et, dans la mesure du possible, sans avertissement (`gcc -Wall -Wextra`).
4. Complétez le fichier `README.md` : auto-évaluation, bibliothèques utilisées, références, difficulté et commentaires.
5. Ces fichiers font partie du rendu unique (TP1 à TP5) décrit dans le [README](../README.md) du dépôt ; l'interpréteur y est livré une seule fois, dans `src/interpreteur/`.
