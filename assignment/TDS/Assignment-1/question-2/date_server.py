from xmlrpc.server import SimpleXMLRPCServer as serv
import xmlrpc.server
import datetime
 
class DateTime:
	def get_current_datetime(self):
		now = datetime.datetime.now()
		print("Date and time information is requested!")
		return now.strftime("%Y-%m-%d %H:%M:%S")
		
server = serv(('localhost', 8001))

server.register_instance(DateTime())

print("----Starting the server----")

server.serve_forever()
