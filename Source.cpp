#include <iostream> 
#include <string>   

using namespace std;

int count_max(int** matrix, int groups, int students) {
	double prmax = 0;  // prmax - presumably max
	double max = 0;
	int answer;
	for (int i = 0; i < students; i++)
	{
		max += matrix[0][i];
	}
	max /= students;

	for (int i = 1; i < groups; i++)
	{
		for (int j = 0; j < students; j++)
		{
			prmax += matrix[i][j];
		}
		prmax /= students;
		if (prmax > max) {
			max = prmax;
			answer = i;
		}
	}
	return answer + 1;
}

int count_min(int** matrix, int groups, int students) {
	double prmin = 0;  // prmin - presumably min
	double min = 0;
	int answer = 0;
	for (int i = 0; i < students; i++)
	{
		min += matrix[0][i];
	}
	min /= students;

	for (int i = 1; i < groups; i++)
	{
		for (int j = 0; j < students; j++)
		{
			prmin += matrix[i][j];
		}
		prmin /= students;
		if (prmin < min) {
			min = prmin;
			answer = i;
		}
	}
	return answer + 1;
}

int count_top_marks(int** matrix, int groups, int students) {
	int prtop = 0;  // prtop - presumably top
	int answer = 0;
	int top = 0;
	for (int i = 1; i < groups; i++)
	{
		for (int j = 0; j < students; j++)
		{
			if (matrix[i][j] == 10 || matrix[i][j] == 9) {
				top++;
			}
		}
		if (prtop < top) {
			prtop = top;
			answer = i;
		}
		top = 0;
	}
	return answer + 1;
}

string count_unsatisfactory_mark(int** matrix, int groups, int students) {
	string str = "";
	for (int i = 0; i < groups; i++)
	{
		for (int j = 0; j < students; j++)
		{
			if (matrix[i][j] <= 3) {
				str += to_string(i + 1) + " ";
				break;
			}
		}
	}
	return str;
}

void increase_by_one(int** matrix, int groups, int students) {
	int average = 0;
	int average_in_group = 0;
	for (int i = 0; i < groups; i++)
	{
		for (int j = 0; j < students; j++)
		{
			average += matrix[i][j];
		}
	}
	average /= (groups * students);

	for (int i = 0; i < groups; i++)
	{
		for (int j = 0; j < students; j++) {

			average_in_group += matrix[i][j];
		}

		average_in_group /= students;

		if (average_in_group > average) {
			for (int x = 0; x < groups; x++)
			{
				matrix[i][x]++;
			}
		}
	}
}

double find_even(int** matrix, int students, int index) {
	double even = 0;
	for (int i = 0; i < students; i++)
	{
		even += matrix[index][i];
	}
	even /= students;
	return even;
}

void swap_index(int** matrix, int students, int index) {
	for (int i = 0; i < students; i++)
	{
		int t = matrix[index][i];
		matrix[index][i] = matrix[index + 1][i];
		matrix[index + 1][i] = t;
	}

}

void sorting_d(int** matrix, int students, int groups) {
	for (int z = 0; z < groups; z++)
	{
		for (int i = 0; i < groups - 1; i++)
		{
			for (int j = 0; j < students; j++)
			{
				if (find_even(matrix, students, i) < find_even(matrix, students, i + 1)) {
					swap_index(matrix, students, i);
				}
			}

		}
	}
}

string show(int** matrix, int groups, int students, string data) {
	string msg = "";
	int count = 1;
	for (int i = 0; i < groups; i++)
	{
		msg += to_string(count) + data;
		for (int j = 0; j < students; j++)
		{
			msg += to_string(matrix[i][j]) + " ";

		}
		msg += "\n";
		count++;
	}
	return msg;
}

void random_init(int** matrix, int groups, int students) {
	for (int i = 0; i < groups; i++)
	{
		for (int j = 0; j < students; j++)
		{
			matrix[i][j] = rand() % 11;
		}
	}
}

int main() {
	srand(time(NULL));
	int groups = 5;
	int students = 12;
	int** matrix = new int* [groups];
	for (int i = 0; i < groups; i++)
	{
		matrix[i] = new int[students];

	}
	random_init(matrix, groups, students);
	cout << show(matrix, groups, students, "st group : ") << endl;
	cout << "Max: " << count_max(matrix, groups, students) << "st Group" << endl;
	cout << "Min: " << count_min(matrix, groups, students) << "st Group" << endl;
	cout << "Top marks: " << count_top_marks(matrix, groups, students) << "st Group" << endl;
	cout << "Group " << count_unsatisfactory_mark(matrix, groups, students) << "have unsatisfactory grades!" << endl;
	increase_by_one(matrix, groups, students);
	cout << endl << "In groups where the average performance is higher than the overall average performance " << endl << "throughout the academy, the academy increases the marks for each student by one point: " << endl;
	cout << show(matrix, groups, students, "st group : ") << endl;
	cout << "Groups in descending of their average performance: " << endl;
	sorting_d(matrix, students, groups);
	cout << show(matrix, groups, students, "st place : ") << endl;

	delete[] matrix;
	return 0;
}