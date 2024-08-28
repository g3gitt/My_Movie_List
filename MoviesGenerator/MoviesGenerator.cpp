#include<iostream>
#include<string>
#include<random>
#include<vector>
#include<fstream>

using namespace std;

int main()
{
	std::vector<std::string>movies;
	std::ifstream MoviesFile("movies.txt");
	for (std::string line; std::getline(MoviesFile, line);) {
		if (line.empty()) {
			continue;
		}
		movies.push_back(line);
	}

std::mt19937 rng(std::random_device{}());
std::uniform_int_distribution<int>dist(0, movies.size() - 1);
const std::string target = movies[dist(rng)];

cout << target;
	return 0;
}