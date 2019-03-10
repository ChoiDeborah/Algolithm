#include <iostream>

#define BUFFER_SIZE 10000
#define ARR_SIZE	100

using namespace std;

int read_line(FILE** fp, int _Data[], int _N);
int get_min(int _Data[], int _M);

void main()
{
	int N = 0, M = 0;

	cin >> N;
	M = sqrt(N);

	int Data[BUFFER_SIZE] = {};
	int MinGroup[ARR_SIZE] = {};

	FILE* fp = nullptr;
	char * path = "../Algolithm/data.txt";
	errno_t err = fopen_s(&fp, path, "rt");

	if (err == 0)
	{
		char chBuffer = 0;
		int count = 0;

		while (count < N)
		{
			Data[count++] = read_line(&fp, Data, N);
		}

		int index = 0;
		int numOfGroup = 0;

		if (N%M == 0) numOfGroup = N / M;
		else numOfGroup = N / M + 1;

		for (int i = 0; i < numOfGroup; i++) {

			int Temp[ARR_SIZE] = {};

			for (int j = 0; j < M; j++) {
				index = i * M + j;
				Temp[j] = Data[index];
			}
			MinGroup[i] = get_min(Temp, M);
		}

	}
	else cout << "FILE OPEN FAILURE" << endl;

}

int get_min(int _Data[], int _M)
{
	int iMin = INT_MAX;

	for (int i = 0; i < _M; i++)
	{
		if (iMin > _Data[i] && _Data[i] > 0)
			iMin = _Data[i];
	}

	return iMin;
}

int read_line(FILE** fp, int _Data[], int _N)
{
	char chBuffer = 0;
	int result = 0;

	while (chBuffer != '\n') {

		result *= 10;
		chBuffer = fgetc(*fp);
		result += atoi(&chBuffer);

	}

	return result;
}