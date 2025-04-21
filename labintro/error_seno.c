import math

def calcular_error_relativo(x):
    """Calcula el error relativo de la aproximación sin(x) ≈ x."""
    if abs(math.sin(x)) < 1e-15:  # Evitar división por cero para x muy pequeño
        return float('inf')
    return abs((x - math.sin(x)) / math.sin(x))

def encontrar_intervalo(epsilon_objetivo=0.5e-14):
    """Encuentra el intervalo alrededor de 0 donde el error relativo es menor o igual al objetivo."""
    limite_superior = 1.0e-6  # Comenzamos con un valor pequeño
    limite_inferior = 0.0

    for _ in range(500):  # Número de iteraciones para la búsqueda binaria
        punto_medio = (limite_superior + limite_inferior) / 2.0
        error = calcular_error_relativo(punto_medio)

        if error <= epsilon_objetivo:
            limite_superior = punto_medio
        else:
            limite_inferior = punto_medio

        if limite_superior - limite_inferior < 1e-18:  # Criterio de convergencia
            break

    return -limite_superior, limite_superior

if __name__ == "__main__":
    intervalo_inferior, intervalo_superior = encontrar_intervalo()
    print(f"El intervalo aproximado alrededor de 0 es: [{intervalo_inferior:.15e}, {intervalo_superior:.15e}]")

    # Evaluación cerca del límite teórico
    x_teorico = 1.7320508075688772e-7
    error_teorico = calcular_error_relativo(x_teorico)
    print(f"\nPara x = {x_teorico:.15e}, el error relativo es: {error_teorico:.15e}")