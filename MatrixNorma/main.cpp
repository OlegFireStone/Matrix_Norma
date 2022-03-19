#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class MatrixFile {
private:
	char ch;
	int i = 0;
	int j = 0;
	ifstream Iobj;

	void SetMatrix() {
		Iobj.open("text.txt");
		if (!Iobj.is_open()) {
			cout << "ошибка при чтении файла";
		}
		else {
			while (Iobj.get(ch)) {

				if ((ch != ' ') && (ch != '\n')) {
					arr[i][j] = ch - '0';
					j++;
					if (j == 4) {
						j = 0;
						i++;
						cout << endl;
					}
				}
			}
		}

		Iobj.close();
	}

public:
	int arr[4][4];

	MatrixFile() {
		SetMatrix();
	}

	void ShowMatrix() {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}

	}


	~MatrixFile() {
		cout << "Вызвался деструктор!";
	}

};

class MatrixNorm_m_l : public MatrixFile {
public:
	float max_m = 0;
	float max_l = 0;

	MatrixNorm_m_l() : MatrixFile() {
		GetMatrixNorm_m_l();
	}

	void ShowNorm_m_l() {
		cout << "Норма матрицы ||A||m (m-норма): " << max_m << endl;
		cout << "Норма матрицы ||A||l (l-norma): " << max_l << endl;
	}

private:
	float m[4] = { 0,0,0,0 };
	float l[4] = { 0,0,0,0 };



	void GetMatrixNorm_m_l() {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				m[i] = m[i] + abs(arr[i][j]);
				l[j] = l[j] + abs(arr[i][j]);
			}
		}
		for (int i = 0; i < 4; i++) {
			if (max_m < m[i]) {
				max_m = m[i];
			}
		}
		for (int i = 0; i < 4; i++) {
			if (max_l < l[i]) {
				max_l = l[i];
			}
		}
	}
};

int main()
{
	setlocale(0, "rus");

	MatrixNorm_m_l objA;
	objA.ShowMatrix();
	objA.ShowNorm_m_l();


	cin.get();
	return 0;
}