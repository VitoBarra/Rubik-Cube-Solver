#include <iostream>
#include <windows.h>
#include <time.h>
#include <string>
#include "cubeClass.h"


using namespace std;


int main()
{
	cubeClass C;
	int n = 4;
	int N = 0;
	char  S;
	


	do
	{
		system("cls");


		C.Logo();
		C.SET_sc();
		cout << endl << C;
		cout << "\n\n--------------------------MENU---------------------------\n";
		cout << "1)Scramble in input\n2)Scramble generato\n3)Esci";
		cout << "\n--------------------------MENU---------------------------\nChe vuoi fare:\t";
		cin >> S;

		switch (S)
		{
		case '1':
			//scramble input
			cout << "\nmischia il cubo! scrivi uno scramble (es. U L U' L R) (MAX:50):\n";
			cin.get();
			getline(cin, C.scr);
			cout << endl;
			C.ExecuteScramble();
			C.Cube_FIN();
			break;


			system("pause>nul");
			system("cls");
			break;
		case '2':
			//scramble rand
			C.scramble_generator();
			cout << "Scr: " << C.scr << endl << endl;
			C.ExecuteScramble();
			C.Cube_FIN();

			system("pause>nul");
			break;
		case '3':
			//uscita programma
			system("cls");
			C.Logo();
			cout << endl << C;
			
			system("pause>nul");
			return 0;
		}
		system("cls");
	} while (true);
	return 0;

}