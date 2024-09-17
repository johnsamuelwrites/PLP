import math

def calculer_aire(rayon: float) -> float:
    return math.pi * rayon * rayon

def main() -> None:
    rayon : float = 5.0
    aire : float = calculer_aire(rayon)
    print(f"L'aire du cercle de rayon {rayon:.2f} est {aire:.2f}")

if __name__ == "__main__":
    main()
