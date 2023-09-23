import xmlrpc.server
 

class ChatServer:
    def __init__(self):
        self.messages = ["(Message from server) All of the messages recieved are: "]

    def send_message(self, message):
        self.messages.append(message)
        print("Message recieved is: ", message)
        return True

    def get_messages(self):
        return self.messages


server = xmlrpc.server.SimpleXMLRPCServer(('localhost', 8002))
print("----Starting the Server----")
server.register_instance(ChatServer())
server.serve_forever()
