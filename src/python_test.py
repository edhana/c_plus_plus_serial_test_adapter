import serial

class SerialController:
	def __init__(self, port, speed):
		self.conexion = serial.Serial(port, speed)

	# arg should be a python string
	def serial_send(arg):		
		if isinstance(arg, str):
			self.connection.write(arg)
		else:
			return None
	
	def serial_read():
		return None

controller = None
		
def open_serial_conection(serial_port, speed):	
	try:
		print "Porta: %s"%serial_port
		print "Velocidade %i"%speed

		controller = SerialController(serial_port, speed)
	except Exception:
		print "Could not open the SERIAL port."
		controller = None

def send_bytes(byte_array):
	if controller != None:
		controller.serial_send(byte_array)
	else:
		print "Could not use the serial connection"

def receive_bytes():
	return controller.serial_read()
