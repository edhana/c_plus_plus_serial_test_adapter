import serial

class SerialController:
	def __init__(self, port, speed):
		self.conexion = serial.Serial(port, speed)

	# arg should be a python string
	def serial_send(arg):		
		if isinstance(arg, str):
			self.connection.write(arg)
		else
			return None
	
	def serial_read():
		return None

controller = SerialController('/dev/ttyUSB0', 115200)

def send_bytes(byte_array):
	controller.serial_send(byte_array)

def receive_bytes():
	return controller.serial_read()

# if __name__ == "__main__":
# 	teste()
# 	puts "coco "