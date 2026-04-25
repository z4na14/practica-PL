
int resultado = 0;
int contador = 0;
 
suma(int a, int b) {
    resultado = a + b;
}
 
multiplica(int a, int b) {
    resultado = a * b;
}
 
es_par(int v) {
    if (v % 2 == 0) {
        contador = 1;
    } else {
        contador = 0;
    }
}
 
cuenta_hasta(int n) {
    int i = 0;
    while (i != n) {
        contador = contador + 1;
        i = i + 1;
    }
}
 
main() {
    suma(3, 5);
    printf("%d", resultado);
    multiplica(4, 6);
    printf("%d", resultado);
    es_par(10);
    printf("%d", contador);
    es_par(7);
    printf("%d", contador);
    cuenta_hasta(5);
    printf("%d", contador);
}
//@(main)
