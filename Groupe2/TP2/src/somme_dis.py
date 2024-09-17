import dis

"""def calculer_somme(n: int) -> int:
    somme = 0
    for i in range(n):
        somme += i
    return somme 
"""

def calculer_somme(n: int) -> int:
       somme = 0
       i = 0
       while i < n:
           somme += i
           i += 1
       return somme

def main() -> None:
    n = 10
    resultat = calculer_somme(n)
    print(f"La somme des entiers de 0 à {n-1} est {resultat}")

if __name__ == "__main__":
    # Utilisation de dis pour afficher le bytecode de la fonction
    dis.dis(calculer_somme)
    main()

