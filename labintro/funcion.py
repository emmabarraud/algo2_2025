

import math

def reciprocal_sqrt_newton(r, x0=0.5, tol=1e-4, max_iter=100):
    def iteration(x):  # Fórmula de Newton
        return x * (3/2 - (r/2) * x**2)

    exact = 1 / math.sqrt(r)
    x = x0
    history = []

    for i in range(max_iter):
        error_rel = abs((x - exact) / exact)
        history.append((i, x, error_rel))
        if error_rel < tol:
            break
        x = iteration(x)

    return x, history, i+1

# === Ejecutar con r = 5, x0 = 1 ===
r = 5
x0 = 1.0
resultado, historial, iteraciones = reciprocal_sqrt_newton(r, x0)

print(f"Aproximación final: {resultado:.8f}")
print(f"Valor exacto      : {1 / math.sqrt(r):.8f}")
print(f"Iteraciones       : {iteraciones}")
print("\nHistorial de iteraciones:")
print("Iter\tAprox\t\tError Relativo")
for i, x, err in historial:
    print(f"{i}\t{x:.8f}\t{err:.2e}")





import numpy as np
import matplotlib.pyplot as plt
from tabulate import tabulate

# Cambiar la función f(x)
def f(x):
    return 4 * np.sin(x) - x + 1

def biseccion(f, a, b, tol=1e-6, max_iter=100):
    fa = f(a)
    fb = f(b)
    
    if fa * fb >= 0:
        raise ValueError("La función no cambia de signo en el intervalo [a, b].")

    pasos = []
    for i in range(max_iter):
        c = (a + b) / 2
        fc = f(c)
        pasos.append((i+1, a, b, c, fc))

        if abs(fc) < tol or (b - a)/2 < tol:
            return c, i+1, pasos

        if fa * fc < 0:
            b = c
            fb = fc
        else:
            a = c
            fa = fc

    raise RuntimeError("No se encontró la raíz en el número máximo de iteraciones.")

# Parámetros
a, b = 2, 3  # Cambia el intervalo según las necesidades
tol = 1e-6
max_iter = 100

# Ejecutamos el método de bisección
raiz, iteraciones, tabla = biseccion(f, a, b, tol, max_iter)

# Mostrar tabla de iteraciones
headers = ["Iteración", "a", "b", "c (punto medio)", "f(c)"]
print(tabulate(tabla, headers=headers, floatfmt=".6f"))

# Mostrar resultado final
print(f"\nRaíz aproximada: {raiz:.6f}")
print(f"Iteraciones realizadas: {iteraciones}")

# Graficar la función y los puntos intermedios
x_vals = np.linspace(a - 0.5, b + 0.5, 500)
y_vals = f(x_vals)

plt.figure(figsize=(10, 5))
plt.axhline(0, color='gray', linestyle='--')
plt.plot(x_vals, y_vals, label="f(x)", color='blue')

# Agregar puntos c en cada iteración
c_vals = [fila[3] for fila in tabla]
plt.plot(c_vals, [f(c) for c in c_vals], 'ro', label="Iteraciones (c)")

plt.title("Método de Bisección")
plt.xlabel("x")
plt.ylabel("f(x)")
plt.legend()
plt.grid(True)
plt.show()
