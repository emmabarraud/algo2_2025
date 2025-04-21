import math

def calcular_error_relativo(x):
    """Calcula el error relativo de la aproximación sin(x) ≈ x."""
    if abs(math.sin(x)) < 1e-15:
        return float('inf')
    return abs((x - math.sin(x)) / math.sin(x))

def encontrar_intervalo_refinado(epsilon_objetivo=0.5e-14):
    """Encuentra el intervalo alrededor de 0 con búsqueda refinada."""
    limite_superior_inicial = 2.0e-7  # Comenzamos cerca del valor teórico
    limite_inferior = 0.0

    limite_superior = limite_superior_inicial
    for _ in range(1000):  # Aumentamos el número de iteraciones
        punto_medio = (limite_superior + limite_inferior) / 2.0
        error = calcular_error_relativo(punto_medio)

        if error <= epsilon_objetivo:
            limite_superior = punto_medio
        else:
            limite_inferior = punto_medio

        if limite_superior - limite_inferior < 1e-19:  # Criterio de convergencia más estricto
            break

    return -limite_superior, limite_superior

if __name__ == "__main__":
    intervalo_inferior, intervalo_superior = encontrar_intervalo_refinado()
    print(f"El intervalo aproximado alrededor de 0 (refinado) es: [{intervalo_inferior:.15e}, {intervalo_superior:.15e}]")

    x_teorico = 1.7320508075688772e-7
    error_teorico = calcular_error_relativo(x_teorico)
    print(f"\nPara x = {x_teorico:.15e}, el error relativo es: {error_teorico:.15e}")