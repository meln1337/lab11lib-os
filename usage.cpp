#include "lib.hpp"

int main()
{
    std::string name = "100x200_200x300";
	int NUM_THREADS, NUM_CONCURRENT;
	std::cout << "Enter NUM_THREADS = ";
	std::cin >> NUM_THREADS;
	std::cout << "Enter NUM_CONCURRENT = ";
	std::cin >> NUM_CONCURRENT;
	std::ifstream file(name + ".txt");
	ll n, m;
	file >> n >> m;
	std::vector<std::vector<ll>> a(n, std::vector<ll>(m));
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < m; j++) file >> a[i][j];
	}
	ll d, e;
	file >> d >> e;
	std::vector<std::vector<ll>> b(d, std::vector<ll>(e));
	for (ll i = 0; i < d; i++)
	{
		for (ll j = 0; j < e; j++) file >> b[i][j];
	}
	if (NUM_THREADS > n * e)
	{
		std::cout << "Too many threads" << std::endl;
		NUM_THREADS = n * e;
	}
	std::vector < std::vector < std::pair<int, int >> > indexes(NUM_THREADS, std::vector<std::pair<int, int>>());
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < e; j++)
		{
			indexes[count % NUM_THREADS].push_back({ i, j });
			count++;
		}
	}
	/*for (int i = 0; i < NUM_THREADS; i++)
	{
		cout << i << "-th thread: ";
		for (int j = 0; j < indexes[i].size(); j++)
		{
			cout << "{" << indexes[i][j].first << ", " << indexes[i][j].second << "}" << ", ";
		}
		cout << endl;
	}*/
	/*std::vector<std::vector<ll>> c1 = matrix_multiplication(a, b);
	print_matrix_to_file(c1, name + "_output.txt");*/
	std::vector<std::vector<ll>> c2 = matrix_multiplication_parallel(a, b, NUM_THREADS, NUM_CONCURRENT, indexes, name);
	print_matrix_to_file(c2, name + "output_parallel.txt");
	//this_thread::sleep_until(chrono::high_resolution_clock::now() + chrono::seconds(1));
	//print_matrix(c1);
	//cout << endl;
	//print_matrix(c2);
	file.close();
    return 0;
}

// g++ -fPIC -c lib.cpp
// ar -cq lib.a lib.o
// g++ usage.cpp -L. -lexample -o usage