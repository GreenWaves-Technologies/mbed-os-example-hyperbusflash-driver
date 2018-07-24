#include "mbed.h"
#include "HYPERBUSFBlockDevice.h"

// Create flash device on HYPERBUS bus with GAP8
HYPERBUSFBlockDevice bd(HYPERBUS_DQ0, HYPERBUS_DQ1, HYPERBUS_DQ2, HYPERBUS_DQ3,
                       HYPERBUS_DQ4, HYPERBUS_DQ5, HYPERBUS_DQ6, HYPERBUS_DQ7,
                       HYPERBUS_CLK, HYPERBUS_CLKN, HYPERBUS_RWDS, HYPERBUS_CSN0, HYPERBUS_CSN1);

int main() {
    printf("hyperbusf test\n");

    // Initialize the SPI flash device and print the memory layout
    bd.init();
    printf("hyperbusf size: %llu\n",         bd.size());
    printf("hyperbusf read size: %llu\n",    bd.get_read_size());
    printf("hyperbusf program size: %llu\n", bd.get_program_size());
    printf("hyperbusf erase size: %llu\n",   bd.get_erase_size());

    // Write "Hello World!" to the first block
    char *buffer = (char*)malloc(bd.get_erase_size());

    sprintf(buffer, "Hello World!\n");
    bd.erase(0, bd.get_erase_size());
    bd.program(buffer, 0, bd.get_erase_size());

    // Read back what was stored
    bd.read(buffer, 0, bd.get_erase_size());
    printf("%s", buffer);

    // Deinitialize the device
    bd.deinit();
    free(buffer);
}
