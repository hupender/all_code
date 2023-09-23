class Graph:
    def __init__(self, num_processes):
        self.num_processes = num_processes
        self.edges = [[] for _ in range(num_processes)]
    
    def add_edge(self, process_id, edge):
        self.edges[process_id].append(edge)
    
    def detect_deadlocks(self):
        for process_id in range(self.num_processes):
            visited = set()
            stack = [process_id]
            while stack:
                current_process = stack.pop()
                visited.add(current_process)
                for edge in self.edges[current_process]:
                    next_process = edge[1]
                    if next_process == process_id:
                        print(f"Deadlock detected involving process {process_id}")
                        return
                    elif next_process not in visited:
                        stack.append(next_process)
        print("No deadlocks detected")

graph = Graph(4)
graph.add_edge(0, (0, 1))
graph.add_edge(1, (1, 2))
graph.add_edge(2, (2, 3))
graph.add_edge(3, (3, 0))
graph.detect_deadlocks()