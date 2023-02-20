import xmlrpc.client 

proxy = xmlrpc.client.ServerProxy("http://localhost:8001")

result = proxy.get_current_datetime()

print("The current date and time are: ", result)
