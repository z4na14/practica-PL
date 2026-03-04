#import "@local/report-template-typst:0.1.0": conf, azuluc3m

#show: conf.with(
  degree: "Ingenieria Informatica",
  subject: "Procesadores de Lenguaje",
  year: (25, 26),
  project: "Práctica 6",
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

= Cuestiones

== Modificaciones

Hemos sustituido el contenido de las acciones semánticas por printfs para que se pueda imprimir en la terminal para que devuelva la notación postfija de los axiomas.
En el main tambien hemos añadido dos printfs. Uno que imprime en la terminal las variables de la 'A' a la 'Z', y otro printf en el que se imprimen el negate.
De esta manera no será necesario definir cada variable al usar gforth.

```
printf("variable A variable B variable C variable D variable E variable F variable G variable H variable I variable J variable K variable L variable M variable N variable O variable P variable Q variable R variable S variable T variable U variable V variable W variable X variable Y variable Z \n");
printf(": negate -1 * ; \n");
```

== Pruebas

```
1+2+3+4+5+6+7+8+9
(1+2)*(3+4)*(5+6)
100/2/2/2/2/5
A=5
B=10
C=A+B*2
D=(A+B)*2
E=100-(50-20-10)
-5+10
10+(-5)
A=-B
-(5+3)*2
((((1+2)+3)+4)+5)
A=1
B=2
C=3
D=4
E=5
A+B*C-D/E
10*5/2+1
1+10*5/2
A=10/3
(1+2)*(3/(4-1))
-10*-10
A=10
B=A*A*A
A+A+A+A+A+A
(5+3)*-(2+2)
```

Salida: 

```
󰘧 cat pruebas.txt | ./calc5 | gforth
syntax error en la linea 29
Gforth 0.7.3, Copyright (C) 1995-2008 Free Software Foundation, Inc.
Gforth comes with ABSOLUTELY NO WARRANTY; for details type `license'
Type `bye' to exit
variable A variable B variable C variable D variable E variable F variable G variable H variable I variable J variable K variable L variable M variable N variable O variable P variable Q variable R variable S variable T variable U variable V variable W variable X variable Y variable Z  redefined i with I  redefined j with J  redefined k with K   ok
: negate -1 * ;  redefined negate   ok
1 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + .  45  ok
1 2 + 3 4 + * 5 6 + * .  231  ok
100 2 / 2 / 2 / 2 / 5 / .  1  ok
5 A !   ok
10 B !   ok
A @ B @ 2 * + C !   ok
A @ B @ + 2 * D !   ok
100 50 20 - 10 - - E !   ok
5 negate 10 + .  5  ok
10 5 negate + .  5  ok
B @ negate A !   ok
5 3 + negate 2 * .  -16  ok
1 2 + 3 + 4 + 5 + .  15  ok
1 A !   ok
2 B !   ok
3 C !   ok
4 D !   ok
5 E !   ok
A @ B @ C @ * + D @ E @ / - .  7  ok
10 5 * 2 / 1 + .  26  ok
1 10 5 * 2 / + .  26  ok
10 3 / A !   ok
1 2 + 3 4 1 - / * .  3  ok
10 negate 10 negate * .  100  ok
10 A !   ok
A @ A @ * A @ * B !   ok
A @ A @ + A @ + A @ + A @ + A @ + .  60  ok
5 3 + 2 2 + negate * .  -32  ok
```