
import random

class Item:
    def _init_(self, value, weight):
        self.value = value
        self.weight = weight

knapsack_items = [Item(60, 10), Item(100, 20), Item(120, 30)]
knapsack_size = 50
population_size = 10
num_generations = 100
mutation_rate = 0.1
tournament_size = 2

random.seed()

def random_int(from_, to):
    return random.randint(from_, to)

def random_double(from_, to):
    return random.uniform(from_, to)

def generate_random_solution():
    solution = []
    for i in range(len(knapsack_items)):
        solution.append(random_int(0, 1))
    return solution

def evaluate_fitness(solution):
    total_value = 0
    total_weight = 0
    for i in range(len(solution)):
        if solution[i]:
            total_value += knapsack_items[i].value
            total_weight += knapsack_items[i].weight
    if total_weight > knapsack_size:
        total_value = 0
    return total_value

def tournament_selection(population, fitness_values):
    best_solution = None
    best_fitness = -1
    for i in range(tournament_size):
        random_index = random_int(0, population_size - 1)
        if fitness_values[random_index] > best_fitness:
            best_fitness = fitness_values[random_index]
            best_solution = population[random_index]
    return best_solution

def crossover(parent1, parent2):
    child = []
    crossover_point = random_int(0, len(parent1) - 1)
    for i in range(crossover_point):
        child.append(parent1[i])
    for i in range(crossover_point, len(parent2)):
        child.append(parent2[i])
    return child

def mutate(solution):
    for i in range(len(solution)):
        if random_double(0, 1) < mutation_rate:
            solution[i] = not solution[i]
    return solution

population = []
fitness_values = []
best_solution = None

for i in range(population_size):
    solution = generate_random_solution()
    population.append(solution)
    fitness = evaluate_fitness(solution)
    fitness_values.append(fitness)

for generation in range(1, num_generations + 1):
    new_population = []
    new_fitness_values = []

    for i in range(population_size):
        parent1 = tournament_selection(population, fitness_values)
        parent2 = tournament_selection(population, fitness_values)
        child = crossover(parent1, parent2)
        child = mutate(child)
        fitness = evaluate_fitness(child)
        new_population.append(child)
        new_fitness_values.append(fitness)

    population = new_population
    fitness_values = new_fitness_values

    best_fitness = -1
    for i in range(population_size):
        if fitness_values[i] > best_fitness:
            best_fitness = fitness_values[i]
            best_solution = population[i]

    print("Generation {}, Best fitness = {}".format(generation, best_fitness))

print("\nBest solution found:")
total_value = 0
for i in range(len(best_solution)):
    if best_solution[i]:
        print("Item {}: Value = {}, Weight = {}".format(i+1, knapsack_items[i].value, knapsack_items[i].weight))
        total_value += knapsack_items[i].value

print("Total value: {}".format(total_value))
# import random
# # Define problem parameters
# items = [("item1", 10, 5), ("item2", 20, 10), ("item3", 30, 15), ("item4", 40, 20), ("item5", 50, 25)] # (name, value, weight)
# knapsack_capacity = 50

# # Define genetic algorithm parameters
# population_size = 50
# mutation_rate = 0.1
# num_generations = 100

# # Define helper functions
# def generate_random_solution():
#     return [random.randint(0, 1) for _ in range(len(items))]

# def calculate_fitness(solution):
#     total_value = sum(item[1] * solution[i] for i, item in enumerate(items))
#     total_weight = sum(item[2] * solution[i] for i, item in enumerate(items))
#     if total_weight > knapsack_capacity:
#         return 0
#     else:
#         return total_value

# def tournament_selection(population, fitness_fn, k=3):
#     tournament = random.sample(population, k)
#     return max(tournament, key=fitness_fn)

# def one_point_crossover(parent1, parent2):
#     crossover_point = random.randint(1, len(parent1) - 1)
#     child1 = parent1[:crossover_point] + parent2[crossover_point:]
#     child2 = parent2[:crossover_point] + parent1[crossover_point:]
#     return child1, child2

# def mutate(solution, mutation_rate):
#     for i in range(len(solution)):
#         if random.random() < mutation_rate:
#             solution[i] = 1 - solution[i] # flip the bit
#     return solution

# # Generate initial population
# population = [generate_random_solution() for _ in range(population_size)]

# # Evolution loop
# for generation in range(num_generations):
#     # Evaluate fitness of each solution
#     fitness_scores = [calculate_fitness(solution) for solution in population]

#     # Select parents for reproduction
#     parents = [tournament_selection(population, fitness_scores) for _ in range(population_size)]

#     # Perform crossover to create new children
#     children = []
#     for i in range(0, population_size, 2):
#         child1, child2 = one_point_crossover(parents[i], parents[i+1])
#         children.append(child1)
#         children.append(child2)

#     # Perform mutation to introduce randomness
#     mutated_children = [mutate(child, mutation_rate) for child in children]

#     # Replace the old population with the new one
#     population = mutated_children

#     # Print the best solution of the current generation
#     best_solution = max(population, key=calculate_fitness)
#     print("Generation", generation+1, "Best Solution:", best_solution, "Fitness:", calculate_fitness(best_solution))