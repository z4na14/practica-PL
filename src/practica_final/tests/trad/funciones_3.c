int resultado = 0;

suma(int a, int b) {
    return a + b;
}

maximo(int a, int b) {
    if (a > b) {
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

factorial(int n) {
    int res = 1;
    int i = 1;
    while (i != n) {
        res = res * i;
        i = i + 1;
    }
    return res;
}

main() {
    printf("%d", resultado);
    printf("%d", resultado);
    printf("%d", resultado);
    printf("%d", resultado);
}
//@(main)
