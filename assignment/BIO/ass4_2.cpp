#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

std::vector<std::tuple<std::string, int, int>> items = {{"item1", 10, 5}, {"item2", 20, 10}, {"item3", 30, 15}, {"item4", 40, 20}, {"item5", 50, 25}};
int knapsack_capacity = 50;

int population_size = 50;
double mutation_rate = 0.1;
int num_generations = 100;

std::vector<int> generate_random_solution() {
    std::vector<int> solution;
    for (int i = 0; i < items.size(); i++) {
        solution.push_back(rand() % 2);
    }
    return solution;
}

int calculate_fitness(std::vector<int> solution) {
    int total_value = 0;
    int total_weight = 0;
    for (int i = 0; i < items.size(); i++) {
        total_value += std::get<1>(items[i]) * solution[i];
        total_weight += std::get<2>(items[i]) * solution[i];
    }
    if (total_weight > knapsack_capacity) {
        return 0;
    }
    else {
        return total_value;
    }
}

std::vector<int> tournament_selection(std::vector<std::vector<int>> population, int (*fitness_fn)(std::vector<int>), int k=3) {
    std::vector<std::vector<int>> tournament;
    std::sample(population.begin(), population.end(), std::back_inserter(tournament), k, std::mt19937{std::random_device{}()});
    auto max_fitness = std::max_element(tournament.begin(), tournament.end(), [fitness_fn](std::vector<int> a, std::vector<int> b) {return fitness_fn(a) < fitness_fn(b);});
    return *max_fitness;
}

std::pair<std::vector<int>, std::vector<int>> one_point_crossover(std::vector<int> parent1, std::vector<int> parent2) {
    int crossover_point = rand() % (parent1.size() - 1) + 1;
    std::vector<int> child1(parent1.begin(), parent1.begin() + crossover_point);
    child1.insert(child1.end(), parent2.begin() + crossover_point, parent2.end());
    std::vector<int> child2(parent2.begin(), parent2.begin() + crossover_point);
    child2.insert(child2.end(), parent1.begin() + crossover_point, parent1.end());
    return std::make_pair(child1, child2);
}

std::vector<int> mutate(std::vector<int> solution, double mutation_rate) {
    for (int i = 0; i < solution.size(); i++) {
        if ((double)rand() / RAND_MAX < mutation_rate) {
            solution[i] = 1 - solution[i];
        }
    }
    return solution;
}

int main() {
    srand(time(NULL));
    std::vector<std::vector<int>> population;
    for (int i = 0; i < population_size; i++) {
        population.push_back(generate_random_solution());
    }
    for (int generation = 0; generation < num_generations; generation++) {
        
    }
    return 0;
}