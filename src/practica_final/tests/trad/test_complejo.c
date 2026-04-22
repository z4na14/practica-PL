// Test de complejidad elevada para trad.y  (C subset -> Common Lisp)
// Cubre: variables globales, funciones con args, while, for, if/else,
//        switch/case, return en rama, arrays, && || !, mult_asign, printf/puts

int g_total = 0;
int g_cuenta = 0;
int g_max = 0;
int datos[10];
int flags[5];

// Devuelve el mayor de dos enteros (if/else, return en cada rama)
maximo(int a, int b) {
    if (a >= b) {
        return a;
    } else {
        return b;
    }
}

// Devuelve el menor de dos enteros
minimo(int a, int b) {
    if (a <= b) {
        return a;
    } else {
        return b;
    }
}

// Valor absoluto con if/else
abs_val(int n) {
    if (n < 0) {
        return 0 - n;
    } else {
        return n;
    }
}

// Suma de enteros en [desde, hasta] con bucle while y retorno de local
suma_rango(int desde, int hasta) {
    int resultado = 0;
    int i = desde;
    while (i <= hasta) {
        resultado = resultado + i;
        i = i + 1;
    }
    return resultado;
}

// Potencia: base^exp con while y multiplicacion acumulada
potencia(int base, int exp) {
    int resultado = 1;
    int i = 0;
    while (i < exp) {
        resultado = resultado * base;
        i = i + 1;
    }
    return resultado;
}

// Cuenta multiplos de d entre 1 y n usando for + if anidado
contar_multiplos(int n, int d) {
    int cuenta = 0;
    for (int i = 1; i <= n; inc(i)) {
        if (i % d == 0) {
            cuenta = cuenta + 1;
        }
    }
    return cuenta;
}

// Rellena el array global datos[0..n-1] con cuadrados: datos[i] = i*i
llenar_cuadrados(int n) {
    for (int i = 0; i < n; inc(i)) {
        datos[i] = i * i;
    }
}

// Encuentra el maximo en datos[0..n-1]; actualiza g_max global
max_array(int n) {
    int m = datos[0];
    int i = 1;
    while (i < n) {
        if (datos[i] > m) {
            m = datos[i];
        }
        i = i + 1;
    }
    g_max = m;
    return m;
}

// Clasifica un entero en cuatro categorias via switch/case
clasificar(int n) {
    int cat = 0;
    switch (n) {
        case 0:
            cat = 10;
            break;
        case 1:
            cat = 20;
            break;
        case 2:
            cat = 30;
            break;
        default:
            cat = 99;
            break;
    }
    return cat;
}

// Suma ponderada: recorre datos[0..n-1]; suma i*datos[i]
suma_ponderada(int n) {
    int acum = 0;
    for (int i = 0; i < n; inc(i)) {
        acum = acum + i * datos[i];
    }
    return acum;
}

// Busca 'val' en datos[0..n-1]; devuelve indice o -1 (return dentro de while)
buscar(int n, int val) {
    int i = 0;
    while (i < n) {
        if (datos[i] == val) {
            return i;
        }
        i = i + 1;
    }
    return 0 - 1;
}

// Funcion principal: ejercita todas las anteriores y varias construcciones
main() {
    // Declaracion multiple en una linea
    int a = 8, b = 3, c = 5;

    // Llamadas a funciones y asignacion
    int mx = maximo(a, b);
    int mn = minimo(b, c);
    int av = abs_val(0 - 7);
    int s = suma_rango(1, 100);
    int pw = potencia(2, 10);
    int cm = contar_multiplos(50, 7);

    // Aritmetica compleja con precedencia
    int expr1 = (a + b) * c - mx / mn;
    int expr2 = s % pw + av * cm;

    // Boolean: and, or, not
    int cond1 = 0;
    if (mx > 5 && mn < 5) {
        cond1 = 1;
    } else {
        cond1 = 0;
    }

    int cond2 = 0;
    if (s > 1000 || pw == 1024) {
        cond2 = 1;
    } else {
        cond2 = 0;
    }

    int cond3 = 0;
    if (!cond1 != 0) {
        cond3 = 1;
    } else {
        cond3 = 0;
    }

    // Rellena array y calcula estadisticas
    llenar_cuadrados(8);
    int max_v = max_array(8);
    int pond = suma_ponderada(8);
    int idx = buscar(8, 25);

    // Switch sobre resultado de clasificar
    int cl = clasificar(2);

    // Bucle for con cuerpo complejo (if dentro de for, variable local en cuerpo)
    int acum = 0;
    for (int i = 0; i < 8; inc(i)) {
        int contrib = datos[i] * (i + 1);
        if (contrib > 50) {
            acum = acum + contrib;
        } else {
            acum = acum + 1;
        }
    }

    // Bucle while con condicion booleana compuesta
    int p = 1;
    int q = 256;
    while (p < q && p < 200) {
        p = p * 2;
    }

    // Bucle for anidado dentro de while
    int tri = 0;
    int fila = 0;
    while (fila < 5) {
        for (int k = 0; k <= fila; inc(k)) {
            tri = tri + 1;
        }
        fila = fila + 1;
    }

    // Array con indice calculado
    int mid = 4;
    datos[mid] = maximo(datos[mid - 1], datos[mid + 1]);

    // Actualiza globales
    g_total = s + pw + acum;
    g_cuenta = cm;

    // Salida
    puts("=== Resultados ===");
    printf("max", mx);
    printf("min", mn);
    printf("suma rango", s);
    printf("potencia 2^10", pw);
    printf("multiplos", cm);
    printf("expr1", expr1);
    printf("max array", max_v);
    printf("ponderada", pond);
    printf("indice buscar", idx);
    printf("triangular", tri);
    printf("cond1 cond2", cond1, cond2);
    printf("acum", acum);
    printf("clasificar", cl);
}
