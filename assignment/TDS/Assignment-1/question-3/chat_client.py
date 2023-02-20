import xmlrpc.client
 
server = xmlrpc.client.ServerProxy('http://localhost:8000')

while True:
    message = input('> ')
    server.send_message(message)
    messages = server.get_messages()
    for msg in messages:
        print(msg)
