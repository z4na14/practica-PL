#import "@local/report-template-typst:0.1.0": conf, azuluc3m

#show: conf.with(
  degree: "Ingenieria Informatica",
  subject: "Procesadores de Lenguaje",
  year: (25, 26),
  project: "Lab 8",
  title: "Infijo a Prefijo",
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


= Cambios respecto a la Segunda Aproximación

== Nuevas estructuras de datos: el nodo AST

El cambio más relevante entre `calc7.y` y `calc8.y` es la introducción de una estructura de nodo para el AST. En lugar de acumular la traducción en cadenas de caracteres (`char *cadena`), cada regla gramatical construye ahora un nodo del árbol:

== Funciones auxiliares para el AST

Se añaden tres funciones que gestionan el ciclo de vida del AST:

- `createASTNode(op, type, left, right)`: reserva memoria y construye un nodo con el operador, tipo y sus hijos indicados.
- `freeAST(node)`: libera recursivamente toda la memoria del árbol tras su uso, evitando fugas de memoria.
- `printAST2Prefix(node)`: recorre el árbol en preorden e imprime la expresión en notación prefija con el formato que espera Lisp, usando paréntesis para delimitar subexpresiones.

La función de impresión distingue los tres tipos de nodo:

```c
void printAST2Prefix(t_node *node) {
    if (node == NULL) return;
    else if (node->type == 0)      // hoja
        printf("%s ", node->op);
    else if (node->type == 1) {    // unario
        printf("(%s ", node->op);
        printAST2Prefix(node->left);
        printf(") ");
    } else {                       // binario
        printf("(%s ", node->op);
        printAST2Prefix(node->left);
        printAST2Prefix(node->right);
        printf(") ");
    }
}
```

== Cambios en las acciones semánticas

Las acciones semánticas de todas las reglas gramaticales se adaptan para construir nodos AST en lugar de concatenar cadenas.

== Cambios en el axioma

En la segunda aproximación, el axioma imprimía directamente la cadena resultante mediante `printf`. En la tercera aproximación, se invoca `printAST2Prefix` sobre el nodo raíz del AST para generar la salida, y a continuación se libera el árbol con `freeAST`.

= Gramática

La gramática de `calc8.y` es idéntica a la de `calc7.y` en cuanto a reglas de producción y declaraciones de precedencia y asociatividad. No se requirió ninguna modificación gramatical para soportar los AST, ya que todos los cambios se limitan a las acciones semánticas.

= Verificación y pruebas

Para verificar el correcto funcionamiento del traductor se utilizó el intérprete `clisp`, usando:

```
./calc8 <prueba.txt | clisp
```

La salida del traductor es código Lisp válido que el intérprete evalúa directamente. Por ejemplo, la entrada:

```
3 + 4 * 2
a = 5 + 3
@ a
```

produce la salida:

```
(+ 3 (* 4 2))
(setq a (+ 5 3))
(print a)
```

que al ser procesada por `clisp` evalúa correctamente las expresiones y muestra los resultados esperados.
