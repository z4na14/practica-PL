#!/bin/bash

# Uso:
#   bash tests/run_tests.sh             -> compara salida actual contra .expected
#   bash tests/run_tests.sh --regenerar -> sobreescribe los .expected con la salida actual

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$DIR/.."

TRAD="$ROOT/trad"
BACK="$ROOT/back"

GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
BOLD='\033[1m'
NC='\033[0m'

PASS=0
FAIL=0
TOTAL=0

REGENERAR=0
[ "${1:-}" = "--regenerar" ] && REGENERAR=1

run_test() {
    local binary="$1"
    local input="$2"
    local desc="$3"
    local name
    name=$(basename "$input")
    local ext="${input##*.}"
    local expected="${input%.$ext}.expected"

    TOTAL=$((TOTAL + 1))

    if [ ! -x "$binary" ]; then
        echo -e "  ${RED}ERROR${NC}: binario '$(basename $binary)' no encontrado"
        FAIL=$((FAIL + 1))
        return
    fi

    actual=$("$binary" < "$input" 2>/dev/null)
    local exit_code=$?

    if [ $exit_code -ne 0 ]; then
        echo -e "  ${RED}ERROR${NC}: $name — traductor terminó con código $exit_code"
        FAIL=$((FAIL + 1))
        return
    fi

    if [ "$REGENERAR" = "1" ]; then
        echo "$actual" > "$expected"
        echo -e "  ${YELLOW}GUARDADO${NC}  $name"
        return
    fi

    if [ ! -f "$expected" ]; then
        echo -e "  ${YELLOW}SIN EXPECTED${NC}  $name — ejecutar con --regenerar"
        FAIL=$((FAIL + 1))
        return
    fi

    exp=$(cat "$expected")

    if [ "$actual" = "$exp" ]; then
        echo -e "  ${GREEN}OK${NC}  $name"
        PASS=$((PASS + 1))
    else
        echo -e "  ${RED}FALLO${NC}  $name  ($desc)"
        diff <(echo "$exp") <(echo "$actual") | head -30 | sed 's/^/    /'
        FAIL=$((FAIL + 1))
    fi
}

if [ "$REGENERAR" = "1" ]; then
    echo -e "${YELLOW}Regenerando archivos .expected...${NC}"
fi

echo ""
echo -e "${BOLD}=== trad: C → Common Lisp ===${NC}"
echo -e "    Constructs: vars globales, funciones con args, while, for anidado,"
echo -e "    if/else, switch/case, return en rama, arrays, &&/||/!, mult_asign, printf/puts"
echo ""
run_test "$TRAD" "$DIR/trad/test_complejo.c" "test de complejidad elevada"

echo ""
echo -e "${BOLD}=== back: Common Lisp → Forth ===${NC}"
echo -e "    Constructs: setq/setf, aritmetica anidada, todos los comparadores,"
echo -e "    and/or/not, print/princ, loop-while, if/else anidado, progn, defun main"
echo ""
run_test "$BACK" "$DIR/back/test_complejo.lisp" "test de complejidad elevada"

echo ""
if [ "$REGENERAR" = "1" ]; then
    echo -e "${YELLOW}Listo. Archivos .expected actualizados.${NC}"
else
    if [ $FAIL -eq 0 ]; then
        echo -e "${GREEN}${BOLD}Resultado: $PASS/$TOTAL OK${NC}"
    else
        echo -e "${RED}${BOLD}Resultado: $PASS/$TOTAL OK — $FAIL fallos${NC}"
        exit 1
    fi
fi
