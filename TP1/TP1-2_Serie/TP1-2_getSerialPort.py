from serial import Serial

serial_port = Serial(port='/dev/cu.usbmodem1421', baudrate=9600)

def getTimeServerActif():
	return serial_port.readline()

while (1):
	raw_input("Appuyez sur enter pour afficher le temps.....")
	print '=> (ms) %s' %(getTimeServerActif())