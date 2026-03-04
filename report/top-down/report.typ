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

= Cuestiones

== Funciones de lexer

El lexer va leyendo caracteres, hasta la terminación del programa mediante 
señales (`Ctrl+C`), o hasta EOF (Input mediante ficheros usando el operador
de entrada `<`) facilitando las pruebas automatizadas. Este se va saltando
las tabulaciones, espacios en blanco, y saltos de línea (Cuando este último
ocurre, aumenta el contador de líneas).

Cuand se lee cualquier elemento, se actualiza el token anterior ($\LL(k) \/ k=1$).

- Mientras sea un ńumero, simplemente devuelve el token de dítito.
- Cuando sea un caracter, este lee el siguiente, lo almacena junto con el token como información sumplimentaria, y devuelve el token de variable.
- Si es un operador, ocurre igual que con los dígitos, y lo devuelve directamente.
- Finalmente, si no ramificamos de ninguna manera, el token se devuelve como literal.

== Gramática


```
Axioma             ::= Expresion
Expresion          ::= (Operador Expresion) | Numero | Variable
Operador Expresion ::= + Expresion Expresion
Numero             ::= 0 | 1
Variable           ::= a Contvariable
Contvariable       ::= a | 0 | #
```

Equivalente en JFLAP:

```
A -> E
E -> (O)
E -> N
E -> V
O -> +EE
N -> 0
N -> 1
V -> a
V -> b
```
#image("img/jflap.jpeg")
