# Travaux pratiques 3

## Année: 2026-2027

## Objectifs

1. **Exploration de l'interpréteur de commandes**: Comprendre le fonctionnement de l'interpréteur de commandes et tester ses fonctionnalités.

2. **Améliorer l'interpréteur de commandes**: Ajouter de nouvelles fonctionnalités.

3. **Ajouter le support des commandes en français**: Permettre l'utilisation de commandes en français et gérer les accents et les caractères spéciaux.

4. **Réaliser un évaluateur pour l'interpréteur**: Créer un tokenizeur, un parseur et un évaluateur pour les expressions mathématiques pour évaluer les expressions arithmétiques.

## Exercice 3.1 [★]

L'objectif du premier exercice est de comprendre le fonctionnement de l'interpréteur de commandes et de tester ses fonctionnalités.

**Étapes :**

1. Compilez et exécutez le programme `repl.c` (dossier `interpreteur/src/`) avec le `Makefile` fourni (ou directement avec `gcc`, voir [interpreteur/README.md](../interpreteur/README.md)) :

```bash
$ cd interpreteur
$ make
$ ./interpreteur
```
2. Lorsque le programme démarre, vous devriez voir un prompt de commande `>`. Tapez une commande et appuyez sur Entrée.
3. Testez les commandes suivantes et observez les résultats :
	* `echo Hello World` : devrait afficher "Echo: Hello World".
	* `echo Bonjour à tous` : devrait afficher "Echo: Bonjour à tous" (les caractères accentués, encodés en UTF-8, sont affichés tels quels).
	* `foo` : devrait afficher "Commande non reconnue...".
	* `quit` : devrait arrêter le programme.
4. Modifiez le code pour ajouter une nouvelle commande, par exemple `date`, qui affiche la date actuelle.
5. Testez la nouvelle commande et vérifiez qu'elle fonctionne correctement.

**Questions à réfléchir :**

* Qu'est-ce qui se passe lorsque vous tapez une commande inconnue?
* Comment l'interpréteur traite les espaces dans les commandes?
* Qu'est-ce qui se passe lorsque vous utilisez la commande `echo` avec des arguments?
* Comment pourriez-vous modifier le code pour ajouter de nouvelles commandes?

**Conseils pour la modification du code :**

* Pour ajouter une nouvelle commande, vous devrez modifier la fonction `main()` pour traiter la nouvelle commande.
* Vous pouvez utiliser des structures de contrôle (par exemple, `if`/`else if`/`else`) pour traiter les différentes commandes.
* N'oubliez pas de mettre à jour le prompt de commande et les messages d'erreur pour refléter les changements.

## Exercice 3.2 [★★]

Ajouter de nouvelles fonctionnalités à l'interpréteur de commandes, incluant les commandes `help` et `version`, ainsi que des fonctions pour les traiter.

**Tâches :**

1. **Ajouter une commande `version`** :
	* Créez une nouvelle fonction `afficher_version()` qui affiche la version de l'interpréteur de commandes.
	* Modifiez le code pour ajouter la commande `version` et appeler la fonction `afficher_version()` lorsque cette commande est saisie.
2. **Ajouter une commande `help`** :
	* Créez une nouvelle fonction `afficher_aide()` qui affiche les commandes disponibles et leur utilisation.
	* Modifiez le code pour ajouter la commande `help` et appeler la fonction `afficher_aide()` lorsque cette commande est saisie.
3. **Améliorer la commande `echo`** :
	* Créez une nouvelle fonction `traiter_echo()` qui traite la commande `echo` et affiche le texte saisi par l'utilisateur.
	* Modifiez le code pour appeler la fonction `traiter_echo()` lorsque la commande `echo` est saisie.
4. **Améliorer la commande `quit`** :
	* Créez une nouvelle fonction `traiter_quit()` qui traite la commande `quit` et ferme l'interpréteur de commandes.
	* Modifiez le code pour appeler la fonction `traiter_quit()` lorsque la commande `quit` est saisie.
5. **Utiliser des tableaux pour stocker les commandes** :
	* Créez un tableau de structures qui stocke les commandes et leurs fonctions associées.
	* Modifiez le code pour utiliser ce tableau pour traiter les commandes saisies par l'utilisateur.

N'oubliez pas de tester votre code pour vous assurer qu'il fonctionne correctement.

## Exercice 3.3 [★★]

Ajouter le support des commandes en français à l'interpréteur de commandes, en plus des commandes en anglais.

**Tâches :**

1. **Ajouter les commandes en français** :
	* Modifiez le code pour ajouter les commandes en français, par exemple :
		+ `aide` pour afficher les commandes disponibles et leur utilisation (équivalent à `help`)
		+ `quitter` pour fermer l'interpréteur de commandes (équivalent à `quit`)
		+ `version` pour afficher la version de l'interpréteur de commandes (déjà existant)
	* Assurez-vous de prendre en compte les différences de casse et d'accentuation entre les commandes en anglais et en français.
2. **Modifier les fonctions pour supporter les commandes en français** :
	* Modifiez les fonctions `traiter_echo()`, `traiter_quit()`, `afficher_version()` et `afficher_aide()` pour supporter les commandes en français.
	* Assurez-vous de prendre en compte les différences de formatage et de contenu entre les messages en anglais et en français.
3. **Gérer les erreurs de saisie** :
	* Modifiez le code pour gérer les erreurs de saisie, par exemple lorsque l'utilisateur saisit une commande en français avec des erreurs d'orthographe ou de casse.
	* Assurez-vous de fournir des messages d'erreur clairs et utiles pour aider l'utilisateur à corriger ses erreurs.

Assurez-vous de tester votre code pour vous assurer qu'il fonctionne correctement.

## Exercice 3.4 [★★★]

Pour le dernier exercice, vous devrez réaliser un évaluateur pour l'interpréteur. Cela implique de créer un tokenizeur, un parseur et un évaluateur capable d'évaluer des expressions arithmétiques `(A opération B)`.

**Tâche 1 : Réaliser un tokenizeur (lexer) pour les expressions mathématiques**

*   Créez un tokenizeur (lexer) (fichiers: `lexer.c`, `lexer.h`) qui prend en entrée une chaîne de caractères représentant une expression mathématique et renvoie une liste de jetons (tokens) représentant les éléments de l'expression, tels que :
    *   Nombres entiers et réels
    *   Opérateurs mathématiques (+, -, \*, /)
*   Assurez-vous que le tokenizeur traite correctement les erreurs de syntaxe, telles que des caractères non autorisés ou des opérateurs mal placés.

**Tâche 2 : Réaliser un parseur pour les expressions mathématiques**

*   Créez un parseur (fichiers: `parseur.c`, `parseur.h`) qui prend en entrée la liste de jetons (tokens) générée par le tokenizeur et renvoie une représentation interne de l'expression mathématique, telle que :
    *   `opération : +, -, \*, /`
    *   `opérande 1 : A`
    *   `opérande 2 : B`
*   Le parseur devra simplement extraire l'opération et les deux opérandes de la liste de jetons et les stocker dans une structure de données simple.
*   Assurez-vous que le parseur traite correctement les erreurs de syntaxe, telles que des caractères non autorisés ou des opérateurs mal placés.

Exemple de représentation interne de l'expression mathématique :

*   `A + B` pourrait être représenté comme :
    *   `opération : +`
    *   `opérande 1 : A`
    *   `opérande 2 : B`
*   `A * B` pourrait être représenté comme :
    *   `opération : *`
    *   `opérande 1 : A`
    *   `opérande 2 : B`

Le parseur devra ensuite passer cette représentation interne à une fonction d'évaluation (tâche suivante) pour obtenir le résultat final.

**Tâche 3 : Évaluer les expressions mathématiques**

*   Créez une fonction dans le fichier `evaluation.c` (et `evaluation.h`) qui prend en entrée la représentation interne de l'expression mathématique générée par le parseur et évalue l'expression en renvoyant le résultat.
*   La fonction devra prendre en compte les opérations suivantes :
    *   Addition (A + B)
    *   Soustraction (A - B)
    *   Multiplication (A \* B)
    *   Division (A / B)
*   Assurez-vous que la fonction traite correctement les erreurs de division par zéro et renvoie un message d'erreur approprié.

Exemple d'évaluation :

*   Si la représentation interne de l'expression mathématique est :
    *   `opération : +`
    *   `opérande 1 : 2`
    *   `opérande 2 : 4`

La fonction devra renvoyer le résultat 6.

Remarque : la fonction devra être capable de gérer les expressions avec des nombres réels et des entiers.

Note : Vous pouvez utiliser des structures de données simples pour représenter la représentation interne de l'expression mathématique.

```
> 2 + 3
5
> 1.2 * 4.0
4.8
```

Testez votre interpréteur pour vous assurer qu'il fonctionne correctement avec les expressions mathématiques.

---

## Fichiers à rendre

Les TP3, TP4 et TP5 construisent un seul interpréteur, de manière itérative : tout son code source est
dans le dossier partagé [`interpreteur/src/`](../interpreteur/README.md). Ce TP y remplit :

* **Markdown :** `CONTRIBUTORS.md`, `README.md` (dans `TP3/`)
* **C :** `repl.c`, `lexer.c`, `lexer.h`, `parseur.c`, `parseur.h`, `evaluation.c`, `evaluation.h`

## Instructions générales

1. Ajoutez des commentaires clairs : nom du fichier, objectif, auteurs, lignes importantes.
2. Respectez les noms de fichiers indiqués dans chaque exercice.
3. Votre code doit compiler sans erreur et, dans la mesure du possible, sans avertissement (`gcc -Wall -Wextra`).
4. Complétez le fichier `README.md` : auto-évaluation, bibliothèques utilisées, références, difficulté et commentaires.
5. Ces fichiers font partie du rendu unique (TP1 à TP5) décrit dans le [README](../README.md) du dépôt ; l'interpréteur y est livré une seule fois, dans `src/interpreteur/`.

