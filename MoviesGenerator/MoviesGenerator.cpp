#include<iostream>
#include<string>
#include<random>
#include<vector>
#include<fstream>

using namespace std;

int main()
{
	while (true) {
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

	cout << "How about this movie?Text me 'cool' if ok or 'no'" << endl;
	cout << target<<endl;

	string inp;
	cin >> inp;
	if (inp == "cool") {
		break;
	}
	else {
		continue;
	}
}
std::cin.get();
return 0;
}
