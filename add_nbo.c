#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <arpa/inet.h> // For ntohl function

void error(const char *msg) {
    perror(msg);
    exit(1);
}

uint32_t read_number_from_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        error("Error opening file");
    }

    uint32_t number;
    if (fread(&number, sizeof(number), 1, file) != 1) {
        fclose(file);
        error("Error reading from file");
    }

    fclose(file);

    return ntohl(number); // Convert from network byte order to host byte order
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        exit(1);
    }

    uint32_t num1 = read_number_from_file(argv[1]);
    uint32_t num2 = read_number_from_file(argv[2]);
    uint32_t sum = num1 + num2;

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", num1, num1, num2, num2, sum, sum);

    return 0;
}

