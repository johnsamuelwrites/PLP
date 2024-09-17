# Author: Matéo Guenot
# Date: 17/09/2024


def longueur_chaine(chaine):
    longueur = 0
    for _ in chaine:
        longueur += 1
    return longueur


def copier_chaine(source):
    destination = ""
    for caractere in source:
        destination += caractere
    return destination


def concatener_chaine(chaine1, chaine2):
    resultat = ""

    # Ajouter chaque caractère de la première chaîne
    for caractere in chaine1:
        resultat += caractere

    # Ajouter chaque caractère de la deuxième chaîne
    for caractere in chaine2:
        resultat += caractere

    return resultat


def main():
    string1 = input("Entrer la première chaîne de caractères : ")
    string2 = input("Entrer la deuxième chaîne de caractères : ")

    print("La longueur de la première chaîne est : ", longueur_chaine(string1))
    print("La longueur de la deuxième chaîne est : ", longueur_chaine(string2))

    print("La première chaîne copiée est : ", copier_chaine(string1))

    print(
        "La concaténation des deux chaînes est : ", concatener_chaine(string1, string2)
    )

    return 0


# Appel de la fonction main
if __name__ == "__main__":
    main()
