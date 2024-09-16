# Author: Matéo Guenot
# Date: 16/09/2024

def main():
    num1 = int(input("Entrez le numéro 1 : "))

    num2 = int(input("Entrez le numéro 2 : "))

    operator = input("Entrez l'opérateur (+, -, *, /, %) : ")

    match operator:
        case "+":
            print(num1, "+", num2, "=", num1 + num2)
        case "-":
            print(num1, "-", num2, "=", num1 - num2)
        case "*":
            print(num1, "*", num2, "=", num1 * num2)
        case "/":
            if num2 == 0:
                print("Division par zéro")
            else:
                print(num1, "/", num2, "=", num1 / num2)
        case "%":
            print(num1, "%", num2, "=", num1 % num2)
        case _:
            print("Opérateur invalide")

if __name__ == "__main__":
    main()