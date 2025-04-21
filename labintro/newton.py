# Pegá este código en un archivo .py para correrlo

import matplotlib.pyplot as plt
import numpy as np

def newton_iteration_console():
    def f(x, R):
        return x**3 - R

    def f_prime(x):
        return 3 * x**2

    print("Método de Newton para f(x) = x^3 - R")
    R = float(input("Ingrese el valor de R (>0): "))
    x0 = float(input("Ingrese el valor inicial x0: "))
    iterations = int(input("Ingrese la cantidad de iteraciones a mostrar: "))

    x_vals = np.linspace(-2, 2, 400)
    y_vals = f(x_vals, R)

    plt.figure(figsize=(10, 6))
    plt.plot(x_vals, y_vals, label=r"$f(x) = x^3 - R$", color='blue')
    plt.axhline(0, color='black', linewidth=1)
    plt.axvline(R**(1/3), color='green', linestyle='--', label=r"$\sqrt[3]{R}$")

    x_n = x0
    for i in range(iterations):
        if f_prime(x_n) == 0:
            print(f"Derivada cero en iteración {i}, deteniendo.")
            break
        y_n = f(x_n, R)
        slope = f_prime(x_n)
        intercept = y_n - slope * x_n
        xt = np.linspace(x_n - 0.5, x_n + 0.5, 100)
        yt = slope * xt + intercept
        plt.plot(xt, yt, linestyle='--', label=f"Tangente {i}", alpha=0.7)
        plt.plot(x_n, y_n, 'o', label=f"$x_{{{i}}}$ = {x_n:.4f}")
        x_n = x_n - f(x_n, R) / f_prime(x_n)

    plt.title(f"Método de Newton para $f(x) = x^3 - {R}$ con $x_0 = {x0}$")
    plt.xlabel("x")
    plt.ylabel("f(x)")
    plt.grid(True)
    plt.legend()
    plt.tight_layout()
    plt.show()

newton_iteration_console()
