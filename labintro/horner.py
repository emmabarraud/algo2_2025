def punto_flotante_3_digitos(numero):
    """
    Simula la representación de un número en punto flotante de 3 dígitos decimales.

    Args:
        numero (float): El número a representar.

    Returns:
        float: El número representado en punto flotante de 3 dígitos.
    """
    if numero == 0:
        return 0.0

    signo = 1
    if numero < 0:
        signo = -1
        numero = -numero

    exponente = 0
    if numero >= 1.0:
        while numero >= 1.0:
            numero /= 10
            exponente += 1
    else:
        while numero < 0.1 and numero != 0:
            numero *= 10
            exponente -= 1

    mantisa_str = "{:.3f}".format(numero)
    mantisa = float(mantisa_str)

    return signo * mantisa * (10**exponente)

def evaluar_polinomio_directo_pf(x):
    """
    Evalúa el polinomio P(x) = x^3 - 6x^2 + 3x - 0.149 usando aritmética
    de punto flotante de 3 dígitos.

    Args:
        x (float): El valor de x.

    Returns:
        float: El valor del polinomio evaluado con aritmética de punto flotante.
    """
    x_pf = punto_flotante_3_digitos(x)
    x_cuadrado_pf = punto_flotante_3_digitos(x_pf * x_pf)
    x_cubo_pf = punto_flotante_3_digitos(x_cuadrado_pf * x_pf)
    term2_pf = punto_flotante_3_digitos(6 * x_cuadrado_pf)
    term3_pf = punto_flotante_3_digitos(3 * x_pf)
    constante_pf = punto_flotante_3_digitos(0.149)

    resultado_intermedio1 = punto_flotante_3_digitos(x_cubo_pf - term2_pf)
    resultado_intermedio2 = punto_flotante_3_digitos(resultado_intermedio1 + term3_pf)
    resultado_final = punto_flotante_3_digitos(resultado_intermedio2 - constante_pf)

    return resultado_final

# Valor de x
x_valor = 4.71

# Evaluar el polinomio directamente con aritmética de punto flotante de 3 dígitos
resultado_directo_pf = evaluar_polinomio_directo_pf(x_valor)
print(f"Resultado de la evaluación directa con PF de 3 dígitos: {resultado_directo_pf}")

# Calcular el resultado exacto (para comparar)
resultado_exacto = (x_valor**3) - 6*(x_valor**2) + 3*x_valor - 0.149
print(f"Resultado exacto: {resultado_exacto}")

# Calcular el error absoluto
error_absoluto_directo = abs(resultado_exacto - resultado_directo_pf)
print(f"Error absoluto (evaluación directa): {error_absoluto_directo}")