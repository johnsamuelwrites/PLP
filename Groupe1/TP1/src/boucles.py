# Author: Matéo Guenot
# Date: 16/09/2024


def main():
    compteur = int(input("Entrer la largeur du triangle rectangle : "))

    if compteur < 1:
        print("Le nombre doit être supérieur à 0.")
        return

    if compteur >= 10:
        print("Le nombre doit être inférieur à 10.")
        return


    for i in range(1, compteur + 1):
        for j in range(1, i + 1):
            if j == 1 or j == i or i == compteur:
                print("*", end="")
            else:
                print("#", end="")
        print()

    i = 1
    while i <= compteur:
        j = 1
        while j <= i:
            if j == 1 or j == i or i == compteur:
                print("*", end="")
            else:
                print("#", end="")
            j += 1
        print()
        i += 1

# Appel de la fonction main
if __name__ == "__main__":
    main()
