#import "@local/report-template-typst:0.1.0": conf, azuluc3m

#show: conf.with(
  degree: "Ingenieria Informatica",
  subject: "Procesadores de Lenguaje",
  year: (25, 26),
  project: "Práctica 2",
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

= Questiones

== Prueba de expresiones

En nuestra definición de la gramática, como tenemos operando símbolo expresión, siempre resuelve la expresión de la derecha. Al final es como si resolvierámos el problema con paréntesis. Por ejemplo, 2*3+1 se resuelve como si fuera $2*(3+1)$, por lo que el resultado que nos devuelve es 8.

```
2*3+1
Expresion=8.000000
2+3*1
Expresion=5.000000
1+3*2
Expresion=7.000000
1*3+2
Expresion=5.000000
```

== Reemplazo del operando no terminal

Al cambiar operando por expresión en la gramática, hay una ambigüedad. Para resolverla, se utilizan los órdenes de preferencia definidos en la sección de declaraciones de bison. Entonces ahí determina que $*$ tiene más preferencia que $+$, por lo que resuelve 2*3 y con ese resultado se realiza la suma con 1.

```
2*3+1
Expresion=7.000000
2+3*1
Expresion=5.000000
1+3*2
Expresion=7.000000
1*3+2
Expresion=5.000000
```

== Añadir variables

Partiendo de los cambios del 4.2, ya que este no parece generar confusión en la gramática. Lo primero que se plantearía es añadir un nuevo no terminal generado por expresión, la igual que operando, que este tiene una generación única.

```
expresion:  operando
          | variable
          | ...
```

Y la variable se obtendría de un token usando el lexer, con el patrón:

```
[a-zA-Z][a-zA-A0-9]*
```

Donde tiene que empezar con un caracter, y luego cualquier elemento alfanumérico.

== Añadir asignaciones

La solución que planetamos es añadir una nueva regla al no terminal axioma, donde se genere también:

```
axioma:       expresion  '\n' { printf ("Expresion=%lf\n", $1) ; }    r_expr ;
      |       asignacion '\n' { $1; } r_expr ;
```

Para que luego la asignación genere:

```
asignacion:  variable '=' expresion { $1 = $2 }
```

Y variable se lea mediante el lexer usando el patrón mencionado anteriormente.