#import "@local/report-template-typst:0.1.0": conf, azuluc3m

#show: conf.with(
  degree: "Ingenieria Informatica",
  subject: "Procesadores de Lenguaje",
  year: (25, 26),
  project: "Top-Down",
  title: "Calculadora",
  group: 81,
  authors: (
    (
      name: "Denis Loren",
      surname: "Moldovan",
      nia: "100522240@alumnos.uc3m.es"
    ),
    (
      name: "Jorge Adrian",
      surname: "Saghin Dudulea",
      nia: "100522257@alumnos.uc3m.es"
    )
  ),
  team: "121",
  professor: "Maria Paz",
  toc: true,
  logo: "new",
  language: "es"
)

#set table(
      stroke: none,
      fill: (x, y) => if calc.even(y) == false { azuluc3m.transparentize(80%) },
      inset: (x: 1.0em, y: 0.5em),
      gutter: 0.2em, row-gutter: 0em, column-gutter: 0em
    )
#show table.cell.where(y: 0) : set text(weight: "bold")


= Variables globales

Para la inclusión de definiciones globales, hemos cambiado la gramática para que las reglas de sentencia se traduzcan a (setq <id> 0) o a (setq <id> termino). También hemos incluido un no terminal para poder realizar la definición multiple de variables con asignaciones opcionales. Dicho no terminal lo hemos llamado mult_asign y realiza llamadas recursivas. 

Para probar su correcto funcionamiento, hemos creado un archivo .txt que realiza los siguientes ejemplos de prueba:

== Tests — Paso 1: Variables Globales

#table(
  columns: (auto, 1fr, 1fr, 2fr),
  align: (center, left, left, left),
  inset: 6pt,

  table.header(
    [*Nº*], [*Descripción*], [*Entrada C*], [*Salida Lisp esperada*],
  ),

  [1], [Declaración simple de una variable], [`int x;`], [`(setq x 0)`],
  [2], [Declaración con nombre largo], [`int contador;`], [`(setq contador 0)`],
  [3], [Identificador de un solo carácter], [`int a;`], [`(setq a 0)`],
  [4], [Identificador con dígitos al final], [`int var1;`], [`(setq var1 0)`],
  [5], [Identificador con dígitos en el medio], [`int res2val;`], [`(setq res2val 0)`],
  [6], [Inicialización con valor 0 explícito], [`int z = 0;`], [`(setq z 0)`],
  [7], [Inicialización con valor 1], [`int activo = 1;`], [`(setq activo 1)`],
  [8], [Inicialización con valor positivo pequeño], [`int limite = 5;`], [`(setq limite 5)`],
  [9], [Inicialización con valor de dos cifras], [`int total = 42;`], [`(setq total 42)`],
  [10], [Inicialización con valor grande], [`int maximo = 32767;`], [`(setq maximo 32767)`],
  [11], [Inicialización con valor de tres cifras], [`int nivel = 100;`], [`(setq nivel 100)`],
  [12], [Identificador con mezcla de letras y números], [`int x1 = 10;`], [`(setq x1 10)`],
  [13], [Dos variables sin inicializar], [`int a, b;`], [`(setq a 0) (setq b 0)`],
  [14], [Tres variables sin inicializar], [`int i, j, k;`], [`(setq i 0) (setq j 0) (setq k 0)`],
  [15], [Cuatro variables sin inicializar], [`int a, b, c, d;`], [`(setq a 0) (setq b 0) (setq c 0) (setq d 0)`],
  [16], [Primera inicializada, segunda no], [`int x = 3, y;`], [`(setq x 3) (setq y 0)`],
  [17], [Primera no, segunda inicializada], [`int x, y = 5;`], [`(setq x 0) (setq y 5)`],
  [18], [Ambas variables inicializadas], [`int x = 1, y = 2;`], [`(setq x 1) (setq y 2)`],
  [19], [Primera y tercera inicializadas, segunda no], [`int a = 10, b, c = 20;`], [`(setq a 10) (setq b 0) (setq c 20)`],
  [20], [Primera no, segunda inicializada, tercera no], [`int a, b = 7, c;`], [`(setq a 0) (setq b 7) (setq c 0)`],
  [21], [Tres variables todas inicializadas], [`int p = 1, q = 2, r = 3;`], [`(setq p 1) (setq q 2) (setq r 3)`],
  [22], [Cinco variables sin inicializar], [`int a, b, c, d, e;`], [`(setq a 0) (setq b 0) (setq c 0) (setq d 0) (setq e 0)`],
  [23], [Variables con números en nombre, todas inicializadas], [`int x1 = 1, x2 = 2, x3 = 3;`], [`(setq x1 1) (setq x2 2) (setq x3 3)`],
  [24], [Dos declaraciones en líneas distintas], [`int suma;` \ `int producto;`], [`(setq suma 0) (setq producto 0)`],
  [25], [Tres declaraciones en líneas distintas con inicialización], [`int inicio = 0;` \ `int fin = 99;` \ `int paso = 1;`], [`(setq inicio 0) (setq fin 99) (setq paso 1)`],
  [26], [Mezcla de simple e inicializada en líneas distintas], [`int aux;` \ `int resultado = 8;`], [`(setq aux 0) (setq resultado 8)`],
  [27], [Identificador largo con valor grande], [`int numeromaxenteros = 10000;`], [`(setq numeromaxenteros 10000)`],
  [28], [Tres variables todas inicializadas a cero], [`int a = 0, b = 0, c = 0;`], [`(setq a 0) (setq b 0) (setq c 0)`],
  [29], [Declaración múltiple con último inicializado], [`int a, b, c = 99;`], [`(setq a 0) (setq b 0) (setq c 99)`],
  [30], [Múltiple con solo el primero sin inicializar], [`int a, b = 5, c = 10, d = 15;`], [`(setq a 0) (setq b 5) (setq c 10) (setq d 15)`],
)

Y la salida que hemos obtenido es:
```
(setq x 0)
(setq contador 0)
(setq a 0)
(setq var1 0)
(setq res2val 0)
(setq z 0)
(setq activo 1)
(setq limite 5)
(setq total 42)
(setq maximo 32767)
(setq nivel 100)
(setq x1 10)
(setq a 0) (setq b 0)
(setq i 0) (setq j 0) (setq k 0)
(setq a 0) (setq b 0) (setq c 0) (setq d 0)
(setq x 3) (setq y 0)
(setq x 0) (setq y 5)
(setq x 1) (setq y 2)
(setq a 10) (setq b 0) (setq c 20)
(setq a 0) (setq b 7) (setq c 0)
(setq p 1) (setq q 2) (setq r 3)
(setq a 0) (setq b 0) (setq c 0) (setq d 0) (setq e 0)
(setq x1 1) (setq x2 2) (setq x3 3)
(setq suma 0)
(setq producto 0)
(setq inicio 0)
(setq fin 99)
(setq paso 1)
(setq aux 0)
(setq resultado 8)
(setq numeromaxenteros 10000)
(setq a 0) (setq b 0) (setq c 0)
(setq a 0) (setq b 0) (setq c 99)
(setq a 0) (setq b 5) (setq c 10) (setq d 15)

```