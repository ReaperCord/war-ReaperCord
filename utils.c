#include <stdio.h>
#include "utils.h"

void limparBufferDeEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
