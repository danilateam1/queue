#include <iostream>
#include <queue>
int main() {
	srand(time(NULL));
	int n;
	std::cin >> n;
	int** array = new int* [n];
	for (int count = 0; count < n; count++)
		array[count] = new int[n];
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (i != j) {
				array[i][j] = rand() % 2;
				array[j][i] = array[i][j];
			}
			else array[i][j] = 0;
		}
	}
	;

	for (int i = 0; i < n; i++) {
		std::cout << " \n";
		for (int j = 0; j < n; j++)
			std::cout << array[i][j];
	};
	int x; int y;
	std::cin >> x >> y;

	std::queue<int> q;

	int* massiv = new int[n];
	for (int i = 0; i < n; i++) {
		massiv[i] = n+1;
	}

	int k = 0;
	q.push(x);
	massiv[q.front()] = k;
	while ((massiv[y] == n+1)&(!q.empty())) {
		for (int i = 0; i < n; i++)
			if ((array[q.front()][i] == 1) & (massiv[i] == n + 1)) {
				k++;
				q.push(i); massiv[i] = k;
			}
		q.pop();
	}

	//for (int i = 0; i < n; i++)
	//	std::cout << massiv[i];


	int t = n; int p = 0; int p1 = 0;
	if (massiv[y] != 0) { std::cout << "ect put ";
	std::cout << y;
	
		for (int i = 0; i < n; i++)
			if ((array[y][i] == 1) & (t > massiv[i])) { t = massiv[i]; p = i; }
		k = 1;
		std::cout << p;
		p1 = p;
		while (p1 != x) {
		t = n;
		p = p1;
		for (int i = 0; i < n; i++)
			if ((array[p][i] == 1) & (t > massiv[i])) { t = massiv[i]; p1 = i; }
		k++;
		std::cout << p1;
	}
		std::cout << "\n " <<"dlina = "<< k;
	}
	else { std::cout << "net puti"; }

	return 0;
}