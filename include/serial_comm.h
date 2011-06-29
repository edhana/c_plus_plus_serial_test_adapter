/*
 * Declaração do prototipo de comunicacao da interface serial para comunicação
 * o modulo FPGA
 */

// Configura a comunicação serial como modulo
int init_serial(char *serial_dev, int baudrate);

int send_bytes(char *bytes, int nbytes);

int receive_bytes(char *bytes, int nbytes);

void close_serial();

