# Author:    Rémi Jara
# Created:   17/09/2024

import pdb
from typing import List


def double_values(tableau: List[int]) -> None:
    for compteur in range(len(tableau)):
        tableau[compteur] *= 2 
        # Insérer un point d'arrêt pour observer la valeur de 'tableau' à chaque étape
        pdb.set_trace()

    return tableau

# Créer un tableau d'exemple
tableau: List[int] = [1, 2, 3, 4, 5]

# Appeler la fonction et stocker le résultat
resultat = double_values(tableau)

# Afficher le résultat final
print(resultat)

