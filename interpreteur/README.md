# Interpréteur (TP3, TP4 et TP5)

Les TP3, TP4 et TP5 construisent **un seul et même interpréteur**, de manière itérative. Tout son
code source se trouve dans ce dossier, dans `src/` : chaque TP complète les fichiers du TP précédent
au lieu d'en recopier une nouvelle version.

| TP  | Étape                                                         | Fichiers concernés                                                     |
|-----|---------------------------------------------------------------|------------------------------------------------------------------------|
| TP3 | Commandes (`echo`, `help`, `version`, `quit` et leurs équivalents en français), puis lexer, parseur et évaluateur d'expressions simples `A op B` | `repl.c`, `lexer.c/.h`, `parseur.c/.h`, `evaluation.c/.h` |
| TP4 | Notation infixée → postfixée, parenthèses, évaluation par pile | `postfixe.c/.h` (+ `repl.c`)                                           |
| TP5 | Variables (table de symboles) et expressions lambda            | `symboles.c/.h`, `lambda.c/.h` (+ `repl.c`)                            |

Le point d'entrée est `repl.c`, fourni. Les autres fichiers sont vides : c'est à vous de les
remplir au fil des TP.

## Compilation et exécution

Un `Makefile` est fourni : il compile chaque fichier `.c` séparément en un fichier objet `.o`, puis
lie les objets en un exécutable (voir la chaîne de compilation, cours 3 et TP2). Seuls les fichiers
modifiés sont recompilés.

```bash
$ cd interpreteur
$ make            # compile (gcc -Wall -Wextra -O2)
$ ./interpreteur
> echo Bonjour
Echo: Bonjour
> quit
```

Autres cibles : `make run` (compile et lance), `make debug` (recompile avec `-ggdb3 -O0` pour `gdb`),
`make clean` (supprime les `.o` et l'exécutable).

Sans `make`, la commande équivalente est :

```bash
$ gcc -Wall -Wextra -o interpreteur src/*.c -lm
```

Un fichier vide compile sans erreur : la compilation fonctionne donc dès le TP3, avant que
`postfixe.c`, `symboles.c` ou `lambda.c` ne soient écrits.

## Rendu

Les sujets (`TP3.md`, `TP4.md`, `TP5.md`) et les fichiers `README.md` (auto-évaluation) et
`CONTRIBUTORS.md` restent dans les dossiers `TP3/`, `TP4/` et `TP5/`. Dans l'archive rendue, le contenu
de `interpreteur/src/` est livré une seule fois, dans `src/interpreteur/` (voir le
[README](../README.md) du dépôt).
