# Author: Matéo Guenot
# Date: 16/09/2024

def main():
    # Déclaration et assignation des variables
    entier = 42                # int
    flottant = 3.14            # float
    chaine = "Bonjour"         # str
    booleen = True             # bool

    liste = [1, 2, 3, 4, 5]    # list
    tuple_ = (10, 20, 30)      # tuple
    dictionnaire = {           # dict
        "nom": "Alice",
        "age": 30,
        "ville": "Paris"
    }

    # Affichage des valeurs avec print()
    print("int:", entier)
    print("float:", flottant)
    print("str:", chaine)
    print("bool:", booleen)

    print("list:", liste)
    print("tuple:", tuple_)
    print("dict:", dictionnaire)

# Appel de la fonction main
if __name__ == "__main__":
    main()
