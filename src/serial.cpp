#include <iostream>
#include <string>
#include "serial.h"
#include "serial_comm.h"

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
	if (is_connected || init_serial(serial_port, speed))
		is_connected = true;
	else
		is_connected = false;

	return is_connected;
}

bool Serial::send(char inByte){
	if(is_connected){
		char bytes[1];
		bytes[0] = inByte;

		if(send_bytes(bytes, 1) > 0){
			return true;
		}
	}

	return false; // Error
}

bool Serial::send(char *byteArray, int nbytes){
	if(is_connected){
		if(send_bytes(byteArray, nbytes) > 0){
			return true;
		}
	}

	return false;
}

bool Serial::receive(char *input_bytes, int nbytes){	
	if(is_connected){
		if(receive_bytes(input_bytes, nbytes) > 0)
			return true;
	}

	return false;
}