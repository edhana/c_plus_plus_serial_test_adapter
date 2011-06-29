#ifndef SERIAL_H
#define SERIAL_H

using namespace std;

class Serial{
public:
	Serial(char *port, int speed);
	~Serial();
	bool connect();
	bool send(char inByte);
	bool send(char *byteArray, int nbytes);
	bool receive(char *byteArray, int nbytes);
private:
	// Attributes
	char *serial_port;
	int speed;	
	bool is_connected;
};

#endif