// Denis Loren Moldovan, Jorge Adrian Saghin Dudulea, Gr. 121
// 100522240@alumnos.uc3m.es, 100522257@alumnos.uc3m.es
int datos[10];
int resultado = 0;

llenar(int n) {
    for (int i = 0; i < n; inc(i)) {
        datos[i] = i * i;
    }
}

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

maximo_arr(int n) {
    int m = datos[0];
    int i = 1;
    while (i < n) {
        if (datos[i] > m) {
            m = datos[i];
        }
        i = i + 1;
    }
    return m;
}

main() {
    llenar(8);
    int idx = buscar(8, 25);
    int max = maximo_arr(8);
    int local_arr[5];
    local_arr[0] = 10;
    local_arr[1] = 20;
    local_arr[2] = datos[3];
    printf("%d", idx);
    printf("%d", max);
    printf("%d", local_arr[1]);
    printf("%d", local_arr[2]);
}

//@(main)
