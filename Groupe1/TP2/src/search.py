# Author: Matéo Guenot
# Date: 17/09/2024


def main():
    file = input("Entrer la nom du fichier : ")
    str = input("Entrer la phrase à rechercher : ")

    with open(file, "r") as f:
        for index, line in enumerate(f, start=1):
            if str in line:
                print(f"Ligne {index}, {line.count(str)} fois")

    return 0


# Appel de la fonction main
if __name__ == "__main__":
    main()
