#include<bits/stdc++.h>
#include <cstdlib>
#include <ctime>
using namespace std;
class Item {
public:
    int value;
    int weight;
    Item(int value, int weight) {
        this->value = value;
        this->weight = weight;
    }
};

vector<Item> knapsack_items;
int knapsack_size;
int population_size = 10;
int num_generations = 100;
double mutation_rate = 0.1;
int tournament_size = 2;

int random_int(int from_, int to) {
    return rand() % (to - from_ + 1) + from_;
}

double random_double(double from_, double to) {
    return (double)rand() / RAND_MAX * (to - from_) + from_;
}

vector<int> generate_random_solution() {
    vector<int> solution;
    for (int i = 0; i < knapsack_items.size(); i++) {
        solution.push_back(random_int(0, 1));
    }
    return solution;
}

int evaluate_fitness(vector<int> solution) {
    int total_value = 0;
    int total_weight = 0;
    for (int i = 0; i < solution.size(); i++) {
        if (solution[i]) {
            total_value += knapsack_items[i].value;
            total_weight += knapsack_items[i].weight;
        }
    }
    if (total_weight > knapsack_size) {
        total_value = 0;
    }
    return total_value;
}

vector<int> tournament_selection(vector<vector<int>> population, vector<int> fitness_values) {
    vector<int> best_solution;
    int best_fitness = -1;
    for (int i = 0; i < tournament_size; i++) {
        int random_index = random_int(0, population_size - 1);
        if (fitness_values[random_index] > best_fitness) {
            best_fitness = fitness_values[random_index];
            best_solution = population[random_index];
        }
    }
    return best_solution;
}

vector<int> crossover(vector<int> parent1, vector<int> parent2) {
    vector<int> child;
    int crossover_point = random_int(0, parent1.size() - 1);
    for (int i = 0; i < crossover_point; i++) {
        child.push_back(parent1[i]);
    }
    for (int i = crossover_point; i < parent2.size(); i++) {
        child.push_back(parent2[i]);
    }
    return child;
}

void mutate(vector<int>& solution) {
    for (int i = 0; i < solution.size(); i++) {
        if (random_double(0, 1) < mutation_rate) {
            solution[i] = 1 - solution[i];
        }
    }
}

vector<vector<int>> generate_initial_population() {
    vector<vector<int>> population;
    for (int i = 0; i < population_size; i++) {
        population.push_back(generate_random_solution());
    }
    return population;
}

vector<int> genetic_algorithm() {
    vector<vector<int>> population = generate_initial_population();
    for (int i = 0; i < num_generations; i++) {
        vector<int> fitness_values;
        for (int j = 0; j < population_size; j++) {
            fitness_values.push_back(evaluate_fitness(population[j]));
        }
        vector<vector<int>> new_population;
        for (int j = 0; j < population_size; j++) {
            vector<int> parent1 = tournament_selection(population, fitness_values);
            vector<int> parent2 = tournament_selection(population, fitness_values);
            vector<int> child = crossover(parent1, parent2);
            mutate(child);
            new_population.push_back(child);
        }
        population = new_population;
    }
    int best_fitness = -1;
    vector<int> best_solution;
    for (int i = 0; i < population_size; i++) {
        int fitness = evaluate_fitness(population[i]);
        if (fitness > best_fitness) {
            best_fitness = fitness;
            best_solution = population[i];
        }
    }
    return best_solution;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n;
    cin>>n>>knapsack_size;
    for(int i=0;i<n;i++) {
        int a,b;
        cin>>a>>b;
        knapsack_items.push_back(Item(a,b));
    }
    

    vector<int> solution = genetic_algorithm();
    cout << "Best solution: ";
    for (int i = 0; i < solution.size(); i++) {
        cout << solution[i] << " ";
    }
    cout << endl;
    cout << "Total value: " << evaluate_fitness(solution) << endl;
    return 0;
}