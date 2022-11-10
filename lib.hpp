#include <iostream>
#include <thread>
#include <vector>
#include <fstream>
#include <chrono>
#include <string>
#include <math.h>

typedef long long int ll;

void generate_file(ll n, ll m, ll d, ll e);

std::vector<std::vector<ll>> matrix_multiplication(std::vector<std::vector<ll>> a, std::vector<std::vector<ll>> b);

void vector_multiplication(std::vector<std::vector<ll>> a, std::vector<std::vector<ll>> b, std::vector<std::vector<ll>>& c, std::vector<std::pair<int, int>> indexes, std::vector<bool>& done, int i);

int get_status(std::vector<bool> done);

void progress_bar(double progress);

void print_matrix_to_file(std::vector<std::vector<ll>> a, std::string name);

std::vector<std::vector<ll>> matrix_multiplication_parallel(std::vector<std::vector<ll>> a, std::vector<std::vector<ll>> b, int NUM_THREADS, int NUM_CONCURRENT, std::vector<std::vector<std::pair<int, int>>> indexes, std::string filename);

void print_matrix(std::vector<std::vector<ll>> a);

void print_matrix_to_file(std::vector<std::vector<ll>> a, std::string name);