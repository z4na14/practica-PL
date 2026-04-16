#!/bin/bash
cd /home/denismoldovan/Repositorios/Universidad/Tercero/Cuatrimestre_2/Procesadores/practica-PL/src/practica_parte_3

OUTPUT_FILE="resultados.txt"
> "$OUTPUT_FILE"

for dir in 00 01 02 03; do
  for cfile in "$dir"/*.c; do
    [ -f "$cfile" ] || continue
    name=$(basename "$cfile" .c)
    lfile="${dir}/${name}.l"

    echo "========================================" >> "$OUTPUT_FILE"
    echo "ARCHIVO: $cfile" >> "$OUTPUT_FILE"
    echo "========================================" >> "$OUTPUT_FILE"

    echo "--- Traduccion (trad3) ---" >> "$OUTPUT_FILE"
    ./trad3 < "$cfile" > "$lfile" 2>>"$OUTPUT_FILE"
    trad_exit=$?
    if [ $trad_exit -ne 0 ]; then
      echo "[ERROR trad3: exit code $trad_exit]" >> "$OUTPUT_FILE"
    else
      echo "[trad3 OK]" >> "$OUTPUT_FILE"
    fi
    cat "$lfile" >> "$OUTPUT_FILE"
    echo "" >> "$OUTPUT_FILE"

    echo "--- Ejecucion (clisp) ---" >> "$OUTPUT_FILE"
    timeout 10 clisp "$lfile" >> "$OUTPUT_FILE" 2>&1
    clisp_exit=$?
    if [ $clisp_exit -eq 124 ]; then
      echo "[TIMEOUT clisp: posible bucle infinito]" >> "$OUTPUT_FILE"
    elif [ $clisp_exit -ne 0 ]; then
      echo "[ERROR clisp: exit code $clisp_exit]" >> "$OUTPUT_FILE"
    else
      echo "[clisp OK]" >> "$OUTPUT_FILE"
    fi
    echo "" >> "$OUTPUT_FILE"
  done
done

echo "COMPLETADO" >> "$OUTPUT_FILE"
echo "Proceso completado. $(wc -l < "$OUTPUT_FILE") lineas en $OUTPUT_FILE"
