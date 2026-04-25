#set page(paper: "a4", flipped: true, margin: (x: 1.5cm, y: 1.5cm))
#set text(size: 7pt, font: "Noto Sans Mono")

#grid(
  columns: (1fr, 1fr),
  align(left)[#text(size: 9pt, weight: "bold")[trad.y]],
  align(right)[Denis Loren Moldovan, Jorge Adrian Saghin Dudulea, Gr. 121],
)

#line(length: 100%)
#v(0.3em)

#raw(read("../../src/practica_final/trad.y"), block: true)
