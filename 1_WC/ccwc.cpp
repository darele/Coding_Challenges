#include <stdio.h>
#include <string.h>
#include "error_codes.h"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        fprintf(stderr, "Error: No arguments were provided\n");
        return NO_ARGUMENTS_PROVIDED;
    }
    if (!strcmp(argv[1], "-c")) {
        if (argc < 3) {
            fprintf(stderr, "Error: filename missing\n");
            return FILENAME_NOT_PROVIDED;
        }
        FILE *inputFile = fopen(argv[2], "rb");
        if (inputFile == NULL) {
            fprintf(stderr, "Error: File %s not found", argv[2]);
            return FILE_NOT_FOUND;
        }
        char *c;
        size_t byteCount = 0;
        while (fread(&c, 1, 1, inputFile)) {
            byteCount++;
        }
        printf("%u", byteCount);
    }
    return OK;
}