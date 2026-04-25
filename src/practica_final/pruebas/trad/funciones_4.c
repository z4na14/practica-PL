// Denis Loren Moldovan, Jorge Adrian Saghin Dudulea, Gr. 121
// 100522240@alumnos.uc3m.es, 100522257@alumnos.uc3m.es
int resultado = 0;
int contador = 0;
int global_a = 10;
int global_b = 5;

suma(int a, int b) {
    return a + b;
}

resta(int a, int b) {
    return a - b;
}

multiplica(int a, int b) {
    return a * b;
}

divide(int a, int b) {
    return a / b;
}

maximo(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

minimo(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

es_par(int v) {
    if (v % 2 == 0) {
        return 1;
    }
    return 0;
}

valor_absoluto(int v) {
    if (v < 0) {
        return -v;
    }
    return v;
}

factorial(int n) {
    int res = 1;
    int i = 1;
    while (i != n) {
        res = res * i;
        i = i + 1;
    }
    return res;
}

suma_hasta(int n) {
    int res = 0;
    int i = 0;
    while (i != n) {
        i = i + 1;
        res = res + i;
    }
    return res;
}

cuenta_pares(int n) {
    int res = 0;
    int i = 0;
    while (i != n) {
        i = i + 1;
        if (es_par(i)) {
            res = res + 1;
        }
    }
    return res;
}

imprime_resultado(int v) {
    printf("%d", v);
}

incrementa_global() {
    contador = contador + 1;
}

main() {
    resultado = suma(3, 5);
    imprime_resultado(resultado);
    resultado = resta(10, 4);
    imprime_resultado(resultado);
    resultado = multiplica(3, 4);
    imprime_resultado(resultado);
    resultado = divide(10, 2);
    imprime_resultado(resultado);
    resultado = maximo(7, 3);
    imprime_resultado(resultado);
    resultado = minimo(7, 3);
    imprime_resultado(resultado);
    resultado = es_par(4);
    imprime_resultado(resultado);
    resultado = es_par(7);
    imprime_resultado(resultado);
    resultado = valor_absoluto(-5);
    imprime_resultado(resultado);
    resultado = valor_absoluto(5);
    imprime_resultado(resultado);
    resultado = factorial(5);
    imprime_resultado(resultado);
    resultado = suma_hasta(10);
    imprime_resultado(resultado);
    resultado = cuenta_pares(10);
    imprime_resultado(resultado);
    resultado = suma(maximo(3, 5), minimo(10, 7));
    imprime_resultado(resultado);
    resultado = suma(global_a, global_b);
    imprime_resultado(resultado);
    incrementa_global();
    incrementa_global();
    incrementa_global();
    imprime_resultado(contador);
    resultado = suma(factorial(3), factorial(4));
    imprime_resultado(resultado);
    resultado = maximo(suma(1, 2), suma(3, 4));
    imprime_resultado(resultado);
}
//@(main)
