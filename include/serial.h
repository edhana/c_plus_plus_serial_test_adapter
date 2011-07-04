#ifndef SERIAL_H
#define SERIAL_H

#include <termios.h> /* POSIX terminal control definitions */
#define BUFFER_SIZE 2

using namespace std;

class Serial{
public:
	Serial(char *port, int speed);
	~Serial();
	bool connect();
	bool send(char inByte);
	bool send(char *byteArray, int nbytes);
	bool receive(char *byteArray, int nbytes);
	void close_serial();
private:
	// Attributes
	char *serial_port;
	int speed;	
	int file_descriptor; /* serial conneciton file descriptor */
	struct termios port_options;
	bool is_connected;
};

#endif