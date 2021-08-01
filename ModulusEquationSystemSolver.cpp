//============================================================================
// Name        : ModulusEquationSolver.cpp
// Author      : Maxim Kholodilin
// Version     : v.0.2
// Copyright   : NONE
// Description : MODULUS_EQUATIONS
//============================================================================


#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct Equation{
	int line_remainder;
	int line_modulus;
};

vector<Equation> Input(){
	int num_of_equations;
	vector<Equation> equations;

	cout << "Enter the number of equations: "s;
	cin >> num_of_equations;

	while (num_of_equations != 0){
		int line_remainder, line_modulus;
		cout << "Enter line remainder: "s;
		cin >> line_remainder;
		cout << "Enter line modulus: "s;
		cin >> line_modulus;

		equations.push_back({line_remainder, line_modulus});

		--num_of_equations;
	}

	return equations;
}

int Calculation(vector<Equation> equations){
	int divider;
	int N = 1;
	vector<int> u_i;
	cout << endl;

	//finding N
	cout << "finding N"s << endl;
	for(const auto& equation : equations){
		N *= equation.line_modulus;
	}
	cout << "N is: "s << N << endl;
	cout << endl;

	//finding each N_i
	cout << "finding each N_i"s << endl;
	vector<int> vec_N_i;
	for (const auto& equation : equations){
		int N_i;
		N_i = N / equation.line_modulus;
		vec_N_i.push_back(N_i);
	}
	for (const auto& N_i : vec_N_i){
		cout << "N_i is: "s << N_i << endl;
	}
	cout << endl;

	// Euclid's algorithm
	cout << "Euclid's algorithm"s << endl;
	for (auto i = 0; i != static_cast<int>(equations.size()); ++i){
		int q, r, x;
		int x2 = 1;
		int x1 = 0;
		int N_i, n_i;
		N_i = vec_N_i[i];
		n_i = equations[i].line_modulus;
		cout << "N_i is: "s << N_i << endl;
		cout << "n_i is: "s << n_i << endl;
		cout << "x2 is: "s << x2 << endl;
		cout << "x1 is: "s << x1 << endl;
		while (n_i != 0){
			q = N_i / n_i;
			r = N_i % n_i;
			x = x2 - q*x1;
			N_i = n_i;
			n_i = r;
			x2 = x1;
			x1 = x;
			cout << "q is: "s << q << endl;
			cout << "r is: "s << r << endl;
			cout << "x is: "s << x << endl;
			cout << "N_i is: "s << N_i << endl;
			cout << "n_i is: "s << n_i << endl;
			cout << "x2 is: "s << x2 << endl;
			cout << "x1 is: "s << x1 << endl;
		}
		u_i.push_back(x2);
		cout << endl;
	}
	for (const auto& ui : u_i){
		cout << "u_i is: "s << ui << endl;
	}
	cout << endl;

	//Finding the divider
	cout << "Finding the divider"s << endl;
	for(auto i = 0; i != static_cast<int>(u_i.size()); ++i){
		divider += equations[i].line_remainder*u_i[i]*vec_N_i[i];
	}
	cout << endl;

	return divider;
}

int main() {
	auto equations = Input();
	auto result = Calculation(equations);
	cout << "Result is: "s << result << endl;

	return 0;
}
