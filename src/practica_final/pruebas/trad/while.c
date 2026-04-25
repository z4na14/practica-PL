// Denis Loren Moldovan, Jorge Adrian Saghin Dudulea, Gr. 121
// 100522240@alumnos.uc3m.es, 100522257@alumnos.uc3m.es
int x = 5;
int y = 3;
int a = 0;
int b = 0;
main() {
    while(x > 0) {
        x = x - 1;
    }
    while(x != 5) {
        printf("valor: ", x);
        x = x + 1;
    }
    while(x > 0 && y < 5) {
        x = x - 1;
        y = y + 1;
    }
    while(x > 0) {
        while(y > 0) {
            y = y - 1;
        }
        x = x - 1;
    }
    while(x - 1 > 0) {
        x = x - 1;
    }
    while(x > 0) {
        a = a + x;
        b = b + 1;
        x = x - 1;
    }
}
//@(main)
