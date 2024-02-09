#include <stdlib.h>

int main() {
    char *lol = NULL;
    lol = realloc(lol, 8 * sizeof(char));
    lol = realloc(lol, 8 * sizeof(char));
    lol = realloc(lol, 6 * sizeof(char));
    // lol = realloc(lol, 10 * sizeof(char));
    free(lol);
}
