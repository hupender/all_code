import time

class LamportClock:
    def __init__(self, process_id):
        self.time = 0
        self.process_id = process_id

    def get_time(self):
        self.time += 1
        return self.time

    def update_time(self, event_time):
        self.time = max(self.time, event_time) + 1

    def send_message(self, receiver, message):
        receiver.receive_message(self.get_time(), message)

    def receive_message(self, sender_time, message):
        self.update_time(sender_time)
        print(f"Process {self.process_id} received message '{message}' at time {sender_time}")
        print("Self time is now", self.time)

if __name__ == '__main__':
    process1 = LamportClock(1)
    process2 = LamportClock(2)
    process3 = LamportClock(3)

    process1.send_message(process2, "Hello, Process 2!")
    process2.send_message(process3, "Hello, Process 3!")
    process3.send_message(process1, "Hello, Process 1!")

    process2.send_message(process1, "How are you, Process 1?")
    process1.send_message(process3, "I'm doing fine, Process 3!")
    process3.send_message(process2, "Good to hear that, Process 2!")
