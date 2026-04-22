#import "@local/report-template-typst:0.1.0": conf, azuluc3m

#show: conf.with(
  degree: "Ingenieria Informatica",
  subject: "Procesadores de Lenguaje",
  year: (25, 26),
  project: "Practica Final - Tercera Parte",
  title: "Traductor de un subconjunto de Lisp a Forth (back-end)",
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

= Qué hemos hecho en clase
Al compilar con bison el back.y, hemos obtenido un conflicto shift-reduce en las reglas siguientes:
```bash
  Example: '(' SETQ IDENTIF number • ')'
  Shift derivation
    expression1
    ↳ 7: '(' SETQ IDENTIF number • ')'
  Reduce derivation
    expression1
    ↳ 8: '(' SETQ IDENTIF expression           ')'
                          ↳ 24: operand
                                ↳ 41: number •
```

Para arreglar este conflicto, solo tuvimos que eliminar la regla `'(' SETQ IDENTIF number • ')'` para evitar redundancias.