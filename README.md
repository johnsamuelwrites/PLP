# PLP
Principes des Langages de Programmation

## Année: 2026-2027

Les sujets sont communs aux trois groupes de travaux pratiques.

### Sujets de travaux pratiques
- [TP1](TP1/TP1.md) : bases du C — types, variables, opérateurs et structures de contrôle
- [TP2](TP2/TP2.md) : compilation, débogage et manipulation de chaînes, structures et fichiers
- [TP3](TP3/TP3.md) : construction d'un interpréteur — commandes, analyse et évaluation d'expressions simples
- [TP4](TP4/TP4.md) : expressions arithmétiques — notations infixée et postfixée, parenthèses et évaluation
- [TP5](TP5/TP5.md) : extension de l'interpréteur — variables et expressions lambda

Les TP3, TP4 et TP5 construisent de manière itérative un seul interpréteur : son code source est
partagé dans le dossier [interpreteur/](interpreteur/README.md).

### Rendu
Un seul rendu regroupe les travaux demandés pour TP1 à TP5 (noté sur 20 points). La date limite de
soumission est précisée sur e-campus.

L'archive doit être nommée `groupe_N1_N2.zip` (par exemple `groupe_DUPONT_SMITH.zip`) et contenir :

```
groupe_N1_N2.zip
├── README.md          # rapport d'auto-évaluation, bibliothèques, références, difficulté, commentaires
├── CONTRIBUTORS.md    # noms et prénoms des membres du binôme
└── src/
    ├── TP1/           # fichiers .c demandés dans TP1
    ├── TP2/           # fichiers .c, .h et .md demandés dans TP2
    └── interpreteur/  # l'interpréteur des TP3, TP4 et TP5 (contenu de interpreteur/src/)
```

Organisation du dépôt :

* `TP1/`, `TP2/` : le sujet (`TPn.md`), les modèles `README.md` et `CONTRIBUTORS.md` à compléter, et un
  dossier `src/` avec les fichiers de départ ;
* `TP3/`, `TP4/`, `TP5/` : le sujet et les modèles `README.md` et `CONTRIBUTORS.md` ; les sources sont
  dans `interpreteur/src/`, communes aux trois TP.

## Author
* John Samuel

## Archives and Releases
* [Zenodo](https://doi.org/10.5281/zenodo.15674125)
* [Software Heritage](https://archive.softwareheritage.org/browse/origin/directory/?origin_url=https://github.com/johnsamuelwrites/PLP)
* [Release Notes](RELEASE.md)

## Licence
All code are released under GPLv3+ licence. The associated documentation and other content are released under [CC-BY-SA](http://creativecommons.org/licenses/by-sa/4.0/).
