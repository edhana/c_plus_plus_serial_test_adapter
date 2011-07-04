#include <iostream>
#include <string>

#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */

#include "serial.h"

using namespace std;

Serial::Serial(char *port, int speed){
	this->serial_port = port;
	this->speed = speed;
	is_connected = false;
}

Serial::~Serial(){
	if(is_connected){
		close_serial();
	}
}

bool Serial::connect(){

	file_descriptor = open(serial_port, O_RDWR | O_NOCTTY | O_NDELAY);
	if (file_descriptor == -1){
		is_connected = false;
		return is_connected;
	}else{
		fcntl(file_descriptor, F_SETFL, 0); // Set flags to 0 - wait for the port response 
	}
	
	is_connected = true;

	// Get the serial port options for configuration
	tcgetattr(file_descriptor, &port_options);

	// Configure the connection baudrate
	cfsetispeed(&port_options, B115200); // input
    cfsetospeed(&port_options, B115200); // output

    //Enable the receiver and set local mode...   
    port_options.c_cflag |= (CLOCAL | CREAD);

	// 8N1
	port_options.c_cflag &= ~PARENB;
	port_options.c_cflag &= ~CSTOPB;
	port_options.c_cflag &= ~CSIZE; // Mask the character size bits
	port_options.c_cflag |= CS8;    // Select 8 data bits

	tcsetattr(file_descriptor, TCSANOW, &port_options);

	return is_connected;
}

void Serial::close_serial(){
	close(file_descriptor);
	is_connected = false;
}

bool Serial::send(char in_byte){
	int written_bytes = 0;

	char bytes[1] = {in_byte};

	if(is_connected){
		written_bytes = write(file_descriptor, bytes, 1);
		if(written_bytes < 0)
			return false;
		else
			return true;
	}

	return false; // Error
}

bool Serial::send(char *byteArray, int nbytes){

	// if(is_connected){
	// 	if(send_bytes(byteArray, nbytes) > 0){
	// 		return true;
	// 	}
	// }

	return false;
}

bool Serial::receive(char *input_bytes, int nbytes){    
	if(is_connected){
		if(read(file_descriptor, input_bytes, nbytes))
			return true;
	}

	return false;
}

// int main(void){
// 	cout << "Iniciando o parangole: " << endl;
	
// 	Serial serial((char *)"/dev/tty.PL2303-00001004", 115200);
	
// 	if(serial.connect()){
// 		if(serial.send('a'))
// 			cout << "Enviou 1 byte" << endl;
// 		else
// 			cout << "Deu merda" << endl;

// 		if(serial.send('b'))
// 			cout << "Enviou 1 byte" << endl;
		
// 		char received[1];

// 		if(serial.receive(received, 1))
// 			cout << "Recebeu o byte: " <<  received << endl;

// 		if(serial.receive(received, 1))
// 			cout << "Recebeu o byte: " <<  received << endl;
			
// 		serial.close_serial();	
		
// 	}else{
// 		cout << "Nao foi possivel conectar com a serial" << endl;
// 	}

// 	return 0;
// }