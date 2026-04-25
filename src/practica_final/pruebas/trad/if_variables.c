int global = 100;
int resultado = 0;
int a = 0;
int b = 0;
main() {
    int x = 10;
    if (x == 10) {
        x = 99;
    }
    printf("%d", x);
    int y = 5;
    if (y == 0) {
        b = 123;
    } else {
        b = 456;
    }
    printf("%d", b);
    int p = 5;
    int q = 10;
    if (p > 0) {
        if (q > 0) {
            p = p + q;
        } else {
            p = 0;
        }
    }
    printf("%d", p);
    int w = 10;
    while (w > 0) {
        if (w == 5) {
            a = 1;
        } else {
            a = 0;
        }
        w = w - 1;
    }
    printf("%d", a);
    int local = 5;
    local = local + 1;
    global = global + local;
    printf("%d", global);
    int m = 5;
    int n = 10;
    if (m > 0 && n < 20) {
        m = m + 1;
    } else {
        n = n - 1;
    }
    printf("%d", m);
    int i = 0;
    while (i != 5) {
        i = i + 1;
        a = a + i;
    }
    printf("%d", a);
    puts("resultado:");
    int r = 42;
    printf("%d", r);
    int z = 0;
    if (!z) {
        a = 1;
    } else {
        a = 0;
    }
    printf("%d", a);
    int j = 1;
    int suma = 0;
    while (j <= 10) {
        if (j % 2 == 0) {
            suma = suma + j;
        }
        j = j + 1;
    }
    resultado = suma;
    printf("%d", resultado);
}
//@(main)
