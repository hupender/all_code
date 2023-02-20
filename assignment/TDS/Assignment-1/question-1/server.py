from xmlrpc.server import SimpleXMLRPCServer as serv
import xmlrpc.server
import math


class Calculator:
    def add(self, x, y):
        print("add request called! ", x, "+", y)
        return x+y

    def subtract(self, x, y):
        print("subtract request called! ", x, "+", y)
        return x-y

    def multiply(self, x, y):
        print("multiply request is called! ", x, "*", y)
        return x*y

    def divide(self, x, y):
        print("divide request is called! ", x, "/", y)
        return x/y

    def exponent(self, x, y):			# x^y
        print("Exponentiation request is called! ", x, "^", y)
        return x**y

    def logarithm(self, x, y):		# log y(x)	base is y
        print("Logarithm request is called! log", y, "(", x, ")")
        return math.log(x, y)


server = serv(('localhost', 8000))

server.register_instance(Calculator())

# start the server
print("----Starting the server----")

# server retention
server.serve_forever()
