#include "cubeClass.h"
#include <time.h>


using namespace std;

cubeClass::cubeClass() { RESET(); }
cubeClass::~cubeClass(){}




//-----------------------------------------------METODI ESTERNI-----------------------------------------------
void cubeClass::StampaC()
{
	cout << "-----------------------CUBE SOLVER-----------------------\n";
	for (int y = 0; y < 3; y++)
	{
		cout << "\t\t\t";
		for (int x = 0; x < 3; x++)
		{
			Color(cube[5][y][x]);
			cout << cube[5][y][x] << "  ";
		}
		cout << endl;
	}

	cout << endl;
	for (int y = 0; y < 3; y++)
	{
		cout << "\t   ";
		for (int x = 0; x < 3; x++)
		{
			Color(cube[4][y][x]);
			cout << cube[4][y][x] << "  ";
		}

		cout << "\t";
		for (int x = 0; x < 3; x++)
		{
			Color(cube[1][y][x]);
			cout << cube[1][y][x] << "  ";
		}

		cout << "    ";
		for (int x = 0; x < 3; x++)
		{
			Color(cube[2][y][x]);
			cout << cube[2][y][x] << "  ";
		}

		cout << "    ";
		for (int x = 0; x < 3; x++)
		{
			Color(cube[3][y][x]);
			cout << cube[3][y][x] << "  ";
		}

		cout << endl;
		
	}

	cout << endl;
	for (int y = 0; y < 3; y++)
	{
		cout << "\t\t\t";
		for (int x = 0; x < 3; x++)
		{
			Color(cube[0][y][x]);
			cout << cube[0][y][x] << "  ";
		}
		cout << endl;
	}
	Color(0);
	cout << "-----------------------CUBE SOLVER-----------------------\n";

}
void cubeClass::Logo()
{
	std::cout << "---------------------------------------------------------\n";
	std::cout << "-----------------------VITO  BARRA-----------------------\n";
	std::cout << "-----------------------CUBE SOLVER-----------------------\n";
	std::cout << "-----------------------RELESE v1.3-----------------------\n";
	std::cout << "---------------------------------------------------------\n";
}


///-----------------------------------------------RES|SET-----------------------------------------------
void cubeClass::RESET()
{
	for (int Y = 0; Y < 3; Y++)
	{
		for (int X = 0; X < 3; X++)
			cube[0][Y][X] = 1;
		for (int X = 0; X < 3; X++)
			cube[1][Y][X] = 2;
		for (int X = 0; X < 3; X++)
			cube[2][Y][X] = 3;
		for (int X = 0; X < 3; X++)
			cube[3][Y][X] = 4;
		for (int X = 0; X < 3; X++)
			cube[4][Y][X] = 5;
		for (int X = 0; X < 3; X++)
			cube[5][Y][X] = 6;
	}
}
void cubeClass::SET_sc()
{
	for (int Y = 0; Y < 3; Y++)
	{
		for (int X = 0; X < 3; X++)
			cube[5][Y][X] = 1;
		for (int X = 0; X < 3; X++)
			cube[1][Y][X] = 2;
		for (int X = 0; X < 3; X++)
			cube[4][Y][X] = 3;
		for (int X = 0; X < 3; X++)
			cube[3][Y][X] = 4;
		for (int X = 0; X < 3; X++)
			cube[2][Y][X] = 5;
		for (int X = 0; X < 3; X++)
			cube[0][Y][X] = 6;
	}
}
///-----------------------------------------------MOVE area-----------------------------------------------
void cubeClass::U(int N)
{
	int Y = 0;
	int temp[3];
	for (int j = 0; j < N; j++)
	{
		for (int X = 0; X < 3; X++)
			temp[X] = cube[1][Y][X];
		for (int X = 0; X < 3; X++)
			cube[1][Y][X] = cube[2][Y][X];
		for (int X = 0; X < 3; X++)
			cube[2][Y][X] = cube[3][Y][X];
		for (int X = 0; X < 3; X++)
			cube[3][Y][X] = cube[4][Y][X];
		for (int X = 0; X < 3; X++)
			cube[4][Y][X] = temp[X];


		//angoli
		temp[0] = cube[5][2][0];
		cube[5][2][0] = cube[5][2][2];
		cube[5][2][2] = cube[5][0][2];
		cube[5][0][2] = cube[5][0][0];
		cube[5][0][0] = temp[0];
		//spigoli
		temp[1] = cube[5][1][0];
		cube[5][1][0] = cube[5][2][1];
		cube[5][2][1] = cube[5][1][2];
		cube[5][1][2] = cube[5][0][1];
		cube[5][0][1] = temp[1];

	}
}
void cubeClass::Ui(int N)
{
	int Y = 0;
	int temp[3];
	for (int j = 0; j < N; j++)
	{
		for (int X = 0; X < 3; X++)
			temp[X] = cube[1][Y][X];
		for (int X = 0; X < 3; X++)
			cube[1][Y][X] = cube[4][Y][X];
		for (int X = 0; X < 3; X++)
			cube[4][Y][X] = cube[3][Y][X];
		for (int X = 0; X < 3; X++)
			cube[3][Y][X] = cube[2][Y][X];
		for (int X = 0; X < 3; X++)
			cube[2][Y][X] = temp[X];


		//angoli
		temp[0] = cube[5][0][2];
		cube[5][0][2] = cube[5][2][2];
		cube[5][2][2] = cube[5][2][0];
		cube[5][2][0] = cube[5][0][0];
		cube[5][0][0] = temp[0];
		//spigoli
		temp[1] = cube[5][0][1];
		cube[5][0][1] = cube[5][1][2];
		cube[5][1][2] = cube[5][2][1];
		cube[5][2][1] = cube[5][1][0];
		cube[5][1][0] = temp[1];

	}

}

void cubeClass::D( int N)
{
	int Y = 2;
	int temp[3];
	for (int j = 0; j < N; j++)
	{
		for (int X = 0; X < 3; X++)
			temp[X] = cube[1][Y][X];
		for (int X = 0; X < 3; X++)
			cube[1][Y][X] = cube[4][Y][X];
		for (int X = 0; X < 3; X++)
			cube[4][Y][X] = cube[3][Y][X];
		for (int X = 0; X < 3; X++)
			cube[3][Y][X] = cube[2][Y][X];
		for (int X = 0; X < 3; X++)
			cube[2][Y][X] = temp[X];


		//angoli
		temp[0] = cube[0][2][0];
		cube[0][2][0] = cube[0][2][2];
		cube[0][2][2] = cube[0][0][2];
		cube[0][0][2] = cube[0][0][0];
		cube[0][0][0] = temp[0];
		//spigoli
		temp[1] = cube[0][1][0];
		cube[0][1][0] = cube[0][2][1];
		cube[0][2][1] = cube[0][1][2];
		cube[0][1][2] = cube[0][0][1];
		cube[0][0][1] = temp[1];
	}
}
void cubeClass::Di(int N)
{
	int Y = 2;
	int temp[3];

	for (int j = 0; j < N; j++)
	{
		for (int X = 0; X < 3; X++)
			temp[X] = cube[1][Y][X];
		for (int X = 0; X < 3; X++)
			cube[1][Y][X] = cube[2][Y][X];
		for (int X = 0; X < 3; X++)
			cube[2][Y][X] = cube[3][Y][X];
		for (int X = 0; X < 3; X++)
			cube[3][Y][X] = cube[4][Y][X];
		for (int X = 0; X < 3; X++)
			cube[4][Y][X] = temp[X];
		//angoli
		temp[0] = cube[0][0][2];
		cube[0][0][2] = cube[0][2][2];
		cube[0][2][2] = cube[0][2][0];
		cube[0][2][0] = cube[0][0][0];
		cube[0][0][0] = temp[0];
		//spigoli
		temp[1] = cube[0][0][1];
		cube[0][0][1] = cube[0][1][2];
		cube[0][1][2] = cube[0][2][1];
		cube[0][2][1] = cube[0][1][0];
		cube[0][1][0] = temp[1];

	}
}

void cubeClass::L(int N)
{
	int X = 0;
	int temp[3];
	for (int j = 0; j < N; j++)
	{
		for (int Y = 0; Y < 3; Y++)
			temp[Y] = cube[1][Y][X];
		for (int Y = 0; Y < 3; Y++)
			cube[1][Y][X] = cube[5][Y][X];
		for (int Y = 0, s = 2; Y < 3; Y++, s--)
			cube[5][Y][X] = cube[3][s][2];
		for (int Y = 0, s = 2; Y < 3; Y++, s--)
			cube[3][Y][2] = cube[0][s][X];
		for (int Y = 0; Y < 3; Y++)
			cube[0][Y][X] = temp[Y];
		//angoli
		temp[0] = cube[4][0][0];
		cube[4][0][0] = cube[4][2][0];
		cube[4][2][0] = cube[4][2][2];
		cube[4][2][2] = cube[4][0][2];
		cube[4][0][2] = temp[0];
		//spigoli
		temp[1] = cube[4][1][0];
		cube[4][1][0] = cube[4][2][1];
		cube[4][2][1] = cube[4][1][2];
		cube[4][1][2] = cube[4][0][1];
		cube[4][0][1] = temp[1];
	}
}
void cubeClass::Li(int N)
{
	int X = 0;
	int temp[3];
	for (int j = 0; j < N; j++)
	{
		for (int Y = 0; Y < 3; Y++)
			temp[Y] = cube[1][Y][X];
		for (int Y = 0; Y < 3; Y++)
			cube[1][Y][X] = cube[0][Y][X];
		for (int Y = 0, s = 2; Y < 3; Y++, s--)
			cube[0][Y][X] = cube[3][s][2];
		for (int Y = 0, s = 2; Y < 3; Y++, s--)
			cube[3][Y][2] = cube[5][s][X];
		for (int Y = 0; Y < 3; Y++)
			cube[5][Y][X] = temp[Y];
		//angoli
		temp[0] = cube[4][0][0];
		cube[4][0][0] = cube[4][0][2];
		cube[4][0][2] = cube[4][2][2];
		cube[4][2][2] = cube[4][2][0];
		cube[4][2][0] = temp[0];
		//spigoli
		temp[1] = cube[4][1][0];
		cube[4][1][0] = cube[4][0][1];
		cube[4][0][1] = cube[4][1][2];
		cube[4][1][2] = cube[4][2][1];
		cube[4][2][1] = temp[1];
	}
}

void cubeClass::R(int N)
{
	int X = 2;
	int temp[3];
	for (int j = 0; j < N; j++)
	{
		for (int Y = 0; Y < 3; Y++)
			temp[Y] = cube[1][Y][X];
		for (int Y = 0; Y < 3; Y++)
			cube[1][Y][X] = cube[0][Y][X];
		for (int Y = 0, s = 2; Y < 3; Y++, s--)
			cube[0][Y][X] = cube[3][s][0];
		for (int Y = 0, s = 2; Y < 3; Y++, s--)
			cube[3][Y][0] = cube[5][s][X];
		for (int Y = 0; Y < 3; Y++)
			cube[5][Y][X] = temp[Y];

		//angoli
		temp[0] = cube[2][2][0];
		cube[2][2][0] = cube[2][2][2];
		cube[2][2][2] = cube[2][0][2];
		cube[2][0][2] = cube[2][0][0];
		cube[2][0][0] = temp[0];
		//spigoli
		temp[1] = cube[2][1][0];
		cube[2][1][0] = cube[2][2][1];
		cube[2][2][1] = cube[2][1][2];
		cube[2][1][2] = cube[2][0][1];
		cube[2][0][1] = temp[1];

	}
}
void cubeClass::Ri(int N)
{
	int X = 2;
	int temp[3];
	for (int j = 0; j < N; j++)
	{
		for (int Y = 0; Y < 3; Y++)
			temp[Y] = cube[1][Y][X];
		for (int Y = 0; Y < 3; Y++)
			cube[1][Y][X] = cube[5][Y][X];
		for (int Y = 0, s = 2; Y < 3; Y++, s--)
			cube[5][Y][X] = cube[3][s][0];
		for (int Y = 0, s = 2; Y < 3; Y++, s--)
			cube[3][Y][0] = cube[0][s][X];
		for (int Y = 0; Y < 3; Y++)
			cube[0][Y][X] = temp[Y];

		//angoli
		temp[0] = cube[2][0][2];
		cube[2][0][2] = cube[2][2][2];
		cube[2][2][2] = cube[2][2][0];
		cube[2][2][0] = cube[2][0][0];
		cube[2][0][0] = temp[0];
		//spigoli
		temp[1] = cube[2][0][1];
		cube[2][0][1] = cube[2][1][2];
		cube[2][1][2] = cube[2][2][1];
		cube[2][2][1] = cube[2][1][0];
		cube[2][1][0] = temp[1];

	}
}

void cubeClass::F(int N)
{
	int Y = 2;
	int temp[3];
	for (int j = 0; j < N; j++)
	{
		for (int X = 0; X < 3; X++)
			temp[X] = cube[5][Y][X];
		for (int X = 0, s = 2; X < 3; X++, s--)
			cube[5][Y][X] = cube[4][s][Y];
		for (int X = 0; X < 3; X++)
			cube[4][X][Y] = cube[0][0][X];
		for (int X = 0, s = 2; X < 3; X++, s--)
			cube[0][0][X] = cube[2][s][0];
		for (int X = 0; X < 3; X++)
			cube[2][X][0] = temp[X];

		//angoli
		temp[0] = cube[1][2][0];
		cube[1][2][0] = cube[1][2][2];
		cube[1][2][2] = cube[1][0][2];
		cube[1][0][2] = cube[1][0][0];
		cube[1][0][0] = temp[0];
		//spigoli
		temp[1] = cube[1][1][0];
		cube[1][1][0] = cube[1][2][1];
		cube[1][2][1] = cube[1][1][2];
		cube[1][1][2] = cube[1][0][1];
		cube[1][0][1] = temp[1];
	}
}
void cubeClass::Fi(int N)
{
	int Y = 2;
	int temp[3];
	for (int j = 0; j < N; j++)
	{
		for (int X = 0; X < 3; X++)
			temp[X] = cube[5][Y][X];
		for (int X = 0, s = 2; X < 3; X++, s--)
			cube[5][Y][X] = cube[2][X][0];
		for (int X = 0, s = 2; X < 3; X++, s--)
			cube[2][X][0] = cube[0][0][s];
		for (int X = 0; X < 3; X++)
			cube[0][0][X] = cube[4][X][Y];
		for (int X = 0, s = 2; X < 3; X++, s--)
			cube[4][s][Y] = temp[X];



		//angoli
		temp[0] = cube[1][0][0];
		cube[1][0][0] = cube[1][0][2];
		cube[1][0][2] = cube[1][2][2];
		cube[1][2][2] = cube[1][2][0];
		cube[1][2][0] = temp[0];
		//spigoli
		temp[1] = cube[1][1][0];
		cube[1][1][0] = cube[1][0][1];
		cube[1][0][1] = cube[1][1][2];
		cube[1][1][2] = cube[1][2][1];
		cube[1][2][1] = temp[1];
	}
}

void cubeClass::B(int N)
{
	int Y = 0;
	int temp[3];
	for (int j = 0; j < N; j++)
	{
		for (int X = 0; X < 3; X++)
			temp[X] = cube[5][Y][X];
		for (int X = 0; X < 3; X++)
			cube[5][Y][X] = cube[2][X][2];
		for (int X = 0, s = 2; X < 3; X++, s--)
			cube[2][X][2] = cube[0][2][s];
		for (int X = 0; X < 3; X++)
			cube[0][2][X] = cube[4][X][Y];
		for (int X = 0, s = 2; X < 3; X++, s--)
			cube[4][X][Y] = temp[s];
		//angoli
		temp[0] = cube[3][0][0];
		cube[3][0][0] = cube[3][2][0];
		cube[3][2][0] = cube[3][2][2];
		cube[3][2][2] = cube[3][0][2];
		cube[3][0][2] = temp[0];
		//spigoli
		temp[1] = cube[3][1][0];
		cube[3][1][0] = cube[3][2][1];
		cube[3][2][1] = cube[3][1][2];
		cube[3][1][2] = cube[3][0][1];
		cube[3][0][1] = temp[1];
	}
}
void cubeClass::Bi(int N)
{
	int Y = 0;
	int temp[3];
	for (int j = 0; j < N; j++)
	{
		for (int X = 0; X < 3; X++)
			temp[X] = cube[5][Y][X];
		for (int X = 0, s = 2; X < 3; X++, s--)
			cube[5][Y][s] = cube[4][X][Y];
		for (int X = 0; X < 3; X++)
			cube[4][X][Y] = cube[0][2][X];
		for (int X = 0, s = 2; X < 3; X++, s--)
			cube[0][2][X] = cube[2][s][2];
		for (int X = 0; X < 3; X++)
			cube[2][X][2] = temp[X];
		//angoli
		temp[0] = cube[3][0][0];
		cube[3][0][0] = cube[3][0][2];
		cube[3][0][2] = cube[3][2][2];
		cube[3][2][2] = cube[3][2][0];
		cube[3][2][0] = temp[0];
		//spigoli
		temp[1] = cube[3][1][0];
		cube[3][1][0] = cube[3][0][1];
		cube[3][0][1] = cube[3][1][2];
		cube[3][1][2] = cube[3][2][1];
		cube[3][2][1] = temp[1];
	}
}

void cubeClass::M(int N)
{
	int X = 1;
	int temp[3];
	for (int j = 0; j < N; j++)
	{
		for (int Y = 0; Y < 3; Y++)
			temp[Y] = cube[1][Y][X];
		for (int Y = 0; Y < 3; Y++)
			cube[1][Y][X] = cube[5][Y][X];
		for (int Y = 0, s = 2; Y < 3; Y++, s--)
			cube[5][Y][X] = cube[3][s][1];
		for (int Y = 0, s = 2; Y < 3; Y++, s--)
			cube[3][Y][1] = cube[0][s][X];
		for (int Y = 0; Y < 3; Y++)
			cube[0][Y][X] = temp[Y];
	}

}
void cubeClass::Mi(int N)
{
	int X = 1;
	int temp[3];
	for (int j = 0; j < N; j++)
	{
		for (int Y = 0; Y < 3; Y++)
			temp[Y] = cube[1][Y][X];
		for (int Y = 0; Y < 3; Y++)
			cube[1][Y][X] = cube[0][Y][X];
		for (int Y = 0, s = 2; Y < 3; Y++, s--)
			cube[0][Y][X] = cube[3][s][1];
		for (int Y = 0, s = 2; Y < 3; Y++, s--)
			cube[3][Y][1] = cube[5][s][X];
		for (int Y = 0; Y < 3; Y++)
			cube[5][Y][X] = temp[Y];
	}
}

void cubeClass::S(int N)
{
	int Y = 1;
	int temp[3];
	for (int j = 0; j < N; j++)
	{
		for (int X = 0; X < 3; X++)
			temp[X] = cube[5][Y][X];
		for (int X = 0, s = 2; X < 3; X++, s--)
			cube[5][Y][X] = cube[4][s][Y];
		for (int X = 0; X < 3; X++)
			cube[4][X][Y] = cube[0][0][X];
		for (int X = 0, s = 2; X < 3; X++, s--)
			cube[0][1][X] = cube[2][s][1];
		for (int X = 0; X < 3; X++)
			cube[2][X][1] = temp[X];
	}
}
void cubeClass::Si(int N)
{
	int Y = 1;
	int temp[3];
	for (int j = 0; j < N; j++)
	{
		for (int X = 0; X < 3; X++)
			temp[X] = cube[5][Y][X];
		for (int X = 0, s = 2; X < 3; X++, s--)
			cube[5][Y][X] = cube[2][X][1];
		for (int X = 0, s = 2; X < 3; X++, s--)
			cube[2][X][1] = cube[0][1][s];
		for (int X = 0; X < 3; X++)
			cube[0][1][X] = cube[4][X][Y];
		for (int X = 0, s = 2; X < 3; X++, s--)
			cube[4][s][Y] = temp[X];
	}
}

void cubeClass::E(int N)
{
	int Y = 1;
	int temp[3];
	for (int j = 0; j < N; j++)
	{
		for (int X = 0; X < 3; X++)
			temp[X] = cube[1][Y][X];
		for (int X = 0; X < 3; X++)
			cube[1][Y][X] = cube[4][Y][X];
		for (int X = 0; X < 3; X++)
			cube[4][Y][X] = cube[3][Y][X];
		for (int X = 0; X < 3; X++)
			cube[3][Y][X] = cube[2][Y][X];
		for (int X = 0; X < 3; X++)
			cube[2][Y][X] = temp[X];
	}
}
void cubeClass::Ei(int N)
{
	int Y = 1;
	int temp[3];
	for (int j = 0; j < N; j++)
	{
		for (int X = 0; X < 3; X++)
			temp[X] = cube[1][Y][X];
		for (int X = 0; X < 3; X++)
			cube[1][Y][X] = cube[2][Y][X];
		for (int X = 0; X < 3; X++)
			cube[2][Y][X] = cube[3][Y][X];
		for (int X = 0; X < 3; X++)
			cube[3][Y][X] = cube[4][Y][X];
		for (int X = 0; X < 3; X++)
			cube[4][Y][X] = temp[X];
	}
}


void cubeClass::RW(int N)
{
	R(N);
	Mi(N);
}
void cubeClass::RWi(int N)
{
	Ri(N);
	M(N);
}
void cubeClass::LW(int N)
{
	L(N);
	M(N);
}
void cubeClass::LWi(int N)
{
	Li(N);
	Mi(N);
}
void cubeClass::UW(int N)
{
	U(N);
	Ei(N);
}
void cubeClass::UWi(int N)
{
	Ui(N);
	E(N);
}
void cubeClass::DW(int N)
{
	E(N);
	D(N);
}
void cubeClass::DWi(int N)
{
	Ei(N);
	Di(N);
}
void cubeClass::FW(int N)
{
	S(N);
	F(N);
}
void cubeClass::FWi(int N)
{
	Si(N);
	Fi(N);
}
void cubeClass::BW(int N)
{
	Si(N);
	B(N);
}
void cubeClass::BWi(int N)
{
	S(N);
	Bi(N);
}


///-----------------------------------------------rotation-----------------------------------------------
void cubeClass::x(int N)
{
		RW(N);
		Li(N);

}
void cubeClass::xi(int N)
{
		RWi(N);
		L(N);
}
void cubeClass::y(int N)
{
		UW(N);
		Di(N);

}
void cubeClass::yi(int N)
{
		UWi(N);
		D(N);
}
void cubeClass::z(int N)
{
		FW(N);
		Bi(N);

}
void cubeClass::zi(int N)
{
		FWi(N);
		B(N);
}



///-----------------------------------------------scramble-----------------------------------------------4
void cubeClass::ExecuteScramble()
{
	string lis[50];
	int startPointer = 0, endPointer = 0, lPointer = 0;
	cout << "------------------------SCRAMBLE-------------------------\n";


	while (endPointer < scr.length())
	{
		while (endPointer < scr.length() && scr[endPointer] != ' ')
			endPointer++;

		if (endPointer != scr.length())
			for (int j = startPointer; j < endPointer; j++)
				lis[lPointer] += scr[j];
		else
			for (int j = startPointer; j < scr.length(); j++)
				lis[lPointer] += scr[j];

		startPointer = ++endPointer;
		lPointer++;
	}

	for (int j = 0; j <lPointer; j++)
	{
		//U
		if (lis[j] == "U")
			U();
		if (lis[j] == "U2")
			U( 2);
		if (lis[j] == "U'")
			Ui();
		if (lis[j] == "U'2")
			Ui( 2);

		//D
		if (lis[j] == "D")
			D();
		if (lis[j] == "D2")
			D( 2);
		if (lis[j] == "D'")
			Di();
		if (lis[j] == "D'2")
			Di( 2);

		//L
		if (lis[j] == "L")
			L();
		if (lis[j] == "L2")
			L( 2);
		if (lis[j] == "L'")
			Li();
		if (lis[j] == "L'2")
			Li( 2);

		//R
		if (lis[j] == "R")
			R();
		if (lis[j] == "R2")
			R( 2);
		if (lis[j] == "R'")
			Ri();
		if (lis[j] == "R'2")
			Ri( 2);

		//F
		if (lis[j] == "F")
			F();
		if (lis[j] == "F2")
			F( 2);
		if (lis[j] == "F'")
			Fi();
		if (lis[j] == "F'2")
			Fi( 2);

		//B
		if (lis[j] == "B")
			B();
		if (lis[j] == "B2")
			B( 2);
		if (lis[j] == "B'")
			Bi();
		if (lis[j] == "B'2")
			Bi( 2);

		//M
		if (lis[j] == "M")
			M();
		if (lis[j] == "M2")
			M( 2);
		if (lis[j] == "M'")
			Mi();
		if (lis[j] == "M'2")
			Mi( 2);

		//S
		if (lis[j] == "S")
			S();
		if (lis[j] == "S2")
			S( 2);
		if (lis[j] == "S'")
			Si();
		if (lis[j] == "S'2")
			Si( 2);

		//E
		if (lis[j] == "E")
			E();
		if (lis[j] == "E2")
			E( 2);
		if (lis[j] == "E'")
			Ei();
		if (lis[j] == "E'2")
			Ei( 2);

		//RW
		if (lis[j] == "r")
			RW();
		if (lis[j] == "r2")
			RW( 2);
		if (lis[j] == "r'")
			RWi();
		if (lis[j] == "r'2")
			RWi( 2);

		//LW
		if (lis[j] == "l")
			LW();
		if (lis[j] == "l2")
			LW( 2);
		if (lis[j] == "l'")
			LWi();
		if (lis[j] == "l'2")
			LWi( 2);

		//UW
		if (lis[j] == "u")
			UW();
		if (lis[j] == "u2")
			UW( 2);
		if (lis[j] == "u'")
			UWi();
		if (lis[j] == "u'2")
			UWi( 2);

		//DW
		if (lis[j] == "d")
			DW();
		if (lis[j] == "d2")
			DW( 2);
		if (lis[j] == "d'")
			DWi();
		if (lis[j] == "d'2")
			DWi( 2);

		//FW
		if (lis[j] == "f")
			FW();
		if (lis[j] == "f2")
			FW( 2);
		if (lis[j] == "f'")
			FWi();
		if (lis[j] == "f'2")
			FWi( 2);

		//BW
		if (lis[j] == "b")
			BW();
		if (lis[j] == "b2")
			BW( 2);
		if (lis[j] == "b'")
			BWi();
		if (lis[j] == "b'2")
			BWi( 2);

		//x
		if (lis[j] == "x")
			x();
		if (lis[j] == "x2")
			x( 2);
		if (lis[j] == "x'")
			xi();
		if (lis[j] == "x'2")
			xi( 2);

		//y
		if (lis[j] == "y")
			y();
		if (lis[j] == "y2")
			y( 2);
		if (lis[j] == "y'")
			yi();
		if (lis[j] == "y'2")
			yi( 2);

		//z
		if (lis[j] == "z")
			z();
		if (lis[j] == "z2")
			z( 2);
		if (lis[j] == "z'")
			zi();
		if (lis[j] == "z'2")
			zi( 2);
	}
	StampaC();
	cout << "------------------------SCRAMBLE-------------------------\n";
}
void cubeClass::scramble_generator(int Lenght_Scramble)
{
	int z;
	int p = 0;
	int con = 0;
	srand(time(NULL));
	while (con < Lenght_Scramble)
	{
		z = rand() % 18;
		if (z / 3 != p / 3)
		{
			con++;
			if (z == 0) scr += "U ";
			if (z == 1) scr += "U' ";
			if (z == 2) scr += "U2 ";
			if (z == 3) scr += "F ";
			if (z == 4) scr += "F' ";
			if (z == 5) scr += "F2 ";
			if (z == 6) scr += "L ";
			if (z == 7) scr += "L' ";
			if (z == 8) scr += "L2 ";
			if (z == 9) scr += "D ";
			if (z == 10) scr += "D' ";
			if (z == 11) scr += "D2 ";
			if (z == 12) scr += "R ";
			if (z == 13) scr += "R' ";
			if (z == 14) scr += "R2 ";
			if (z == 15) scr += "B ";
			if (z == 16) scr += "B' ";
			if (z == 17) scr += "B2 ";
			p = z;
		}
	}
}

///-----------------------------------------------resolv-----------------------------------------------
void cubeClass::Cube_FIN()
{
	system("pause>nul");
	system("cls");


	cout << "-------------------------CROSS---------------------------\n";

	StampaC();
	while (cube[5][0][1] != 1 || cube[5][1][0] != 1 || cube[5][1][2] != 1 || cube[5][2][1] != 1)
	{

		//Up
		cout << "Up:\n";
		if (cube[5][0][1] == 1)
		{
			switch (cube[3][0][1])
			{
			case 2:
				B();
				U(2);
				Bi();
				U(2);
				break;
			case 3:
				Ui();
				L();
				U();
				Li();
				break;
			case 5:
				Bi();
				Ui();
				B();
				U();
				break;
			}
		}
		if (cube[5][1][0] == 1)
		{
			switch (cube[4][0][1])
			{
			case 2:
				L();
				U();
				Li();
				Ui();
				break;
			case 4:
				Li();
				Ui();
				L();
				U();
				break;
			case 5:
				U(2);
				Ri();
				U(2);
				R();
				break;
			}
		}
		if (cube[5][1][2] == 1)
		{
			switch (cube[2][0][1])
			{
			case 2:
				Ri();
				Ui();
				R();
				U();
				break;
			case 3:
				U(2);
				L();
				Ui(2);
				Li();
				break;
			case 4:
				R();
				U();
				Ri();
				Ui();
				break;
			}
		}
		if (cube[5][2][1] == 1)
		{
			switch (cube[1][0][1])
			{
			case 3:
				Fi();
				Ui();
				F();
				U();
				break;
			case 4:
				F();
				U(2);
				Fi();
				Ui(2);
				break;
			case 5:
				F();
				U();
				Fi();
				Ui();

				break;
			}
		}
		StampaC();

		if (cube[5][0][1] == 1 && cube[5][1][0] == 1 && cube[5][1][2] == 1 && cube[5][2][1] == 1)
			break;

		//Down
		while (cube[0][0][1] == 1 || cube[0][1][0] == 1 || cube[0][1][2] == 1 || cube[0][2][1] == 1)
		{
			cout << "down:\n";
			if (cube[0][0][1] == 1)
			{
				switch (cube[1][2][1])
				{
				case 2:
					F(2);
					break;
				case 3:
					Di();
					Li(2);
					break;
				case 4:
					D(2);
					B(2);
					break;
				case 5:
					D();
					R(2);
					break;
				}
			}
			if (cube[0][1][0] == 1)
			{
				switch (cube[4][2][1])
				{
				case 2:
					D();
					F(2);
					break;
				case 3:
					Li(2);

					break;
				case 4:
					Di(2);
					B(2);
					break;
				case 5:
					D(2);
					R(2);
					break;
				}
			}
			if (cube[0][1][2] == 1)
			{
				switch (cube[2][2][1])
				{
				case 2:
					Di();
					F(2);
					break;
				case 3:
					D(2);
					Li(2);
					break;
				case 4:
					D();
					B(2);
					break;
				case 5:
					R(2);
					break;
				}
			}
			if (cube[0][2][1] == 1)
			{
				switch (cube[3][2][1])
				{
				case 2:
					D(2);
					F(2);
					break;
				case 3:
					D();
					Li(2);
					break;
				case 4:
					B(2);
					break;
				case 5:
					Di();
					R(2);
					break;
				}
			}
			StampaC();
		}
		if (cube[0][0][1] == 1 && cube[0][1][0] == 1 && cube[0][1][2] == 1 && cube[0][2][1] == 1)
			break;

		//Front
		while (cube[1][0][1] == 1 || cube[1][1][0] == 1 || cube[1][1][2] == 1 || cube[1][2][1] == 1)
		{
			cout << "Front:\n";
			if (cube[1][0][1] == 1)
			{
				switch (cube[5][2][1])
				{
				case 2:
					Fi();
					U();
					Li();
					Ui();
					break;
				case 3:
					Fi();
					Li();
					break;
				case 4:
					F();
					U();
					R();
					Ui();
					break;
				case 5:
					F();
					R();
					break;
				}
			}
			if (cube[1][1][0] == 1)
			{
				switch (cube[4][1][2])
				{
				case 2:
					U();
					Li();
					Ui();
					break;
				case 3:
					Li();
					break;
				case 4:
					Ui();
					Li();
					U();
					break;
				case 5:
					U(2);
					Li();
					Ui(2);
					break;
				}
			}
			if (cube[1][1][2] == 1)
			{
				switch (cube[2][1][0])
				{
				case 2:
					Ui();
					R();
					U();
					break;
				case 3:
					U(2);
					R();
					Ui(2);

					break;
				case 4:
					U();
					R();
					Ui();
					break;
				case 5:
					R();
					break;
				}
			}
			if (cube[1][2][1] == 1)
			{
				switch (cube[0][0][1])
				{
				case 2:
					F();
					U();
					Li();
					Ui();

					break;
				case 3:
					F();
					Li();
					Fi();
					break;
				case 4:
					U(2);
					Fi();
					Ui();
					R();
					Ui();
					break;
				case 5:
					Fi();
					R();
					F();
					break;
				}
			}
			StampaC();
		}
		if (cube[1][0][1] == 1 && cube[1][1][0] == 1 && cube[1][1][2] == 1 && cube[1][2][1] == 1)
			break;

		//Right
		while (cube[2][0][1] == 1 || cube[2][1][0] == 1 || cube[2][1][2] == 1 || cube[2][2][1] == 1)
		{
			cout << "Right:\n";
			if (cube[2][0][1] == 1)
			{
				switch (cube[5][1][2])
				{
				case 2:
					Ri();
					Fi();
					break;
				case 3:
					Ri();
					Ui();
					Fi();
					U();
					break;
				case 4:
					R();
					B();
					break;
				case 5:
					Ri();
					U();
					Fi();
					Ui();
					break;
				}
			}
			if (cube[2][1][0] == 1)
			{
				switch (cube[1][1][2])
				{
				case 2:
					Fi();
					break;
				case 3:
					Ui();
					Fi();
					U();
					break;
				case 4:
					R(2);
					B();
					break;
				case 5:
					U();
					Fi();
					Ui();
					break;
				}
			}
			if (cube[2][1][2] == 1)
			{
				switch (cube[3][1][0])
				{
				case 2:
					Ri(2);
					Fi();
					R(2);
					break;
				case 3:
					U();
					B();
					Ui();
					break;
				case 4:
					B();
					break;
				case 5:
					Ui();
					B();
					U();

					break;
				}
			}
			if (cube[2][2][1] == 1)
			{
				switch (cube[0][1][2])
				{
				case 2:
					R();
					Fi();
					Ri();
					break;
				case 3:
					Di();
					F();
					Li();
					Fi();
					break;
				case 4:
					Ri();
					B();
					R();
					break;
				case 5:
					R();
					U();
					Fi();
					Ui();

					break;
				}
			}
			StampaC();
		}
		if (cube[2][0][1] == 1 && cube[2][1][0] == 1 && cube[2][1][2] == 1 && cube[2][2][1] == 1)
			break;

		//Back
		while (cube[3][0][1] == 1 || cube[3][1][0] == 1 || cube[3][1][2] == 1 || cube[3][2][1] == 1)
		{
			cout << "Back:\n";
			if (cube[3][0][1] == 1)
			{
				switch (cube[5][0][1])
				{
				case 2:
					Bi();
					Ui();
					Ri();
					U();

					break;
				case 3:
					B();
					L();
					break;
				case 4:
					B();
					Ui();
					L();
					U();
					break;
				case 5:
					Bi();
					Ri();

					break;
				}
			}
			if (cube[3][1][0] == 1)
			{

				switch (cube[2][1][2])
				{
				case 2:
					Ui();
					Ri();
					U();
					break;
				case 3:
					Ui(2);
					Ri();
					U(2);
					break;
				case 4:
					U();
					Ri();
					Ui();
					break;
				case 5:
					Ri();
					break;
				}
			}
			if (cube[3][1][2] == 1)
			{
				switch (cube[4][1][0])
				{
				case 2:
					U();
					L();
					Ui();
					break;
				case 3:
					L();
					break;
				case 4:
					Ui();
					L();
					U();
					break;
				case 5:
					Ui();
					B();
					U();
					break;
				}
			}
			if (cube[3][2][1] == 1)
			{
				switch (cube[0][2][1])
				{
				case 2:
					D(2);
					F();
					U();
					Li();
					Ui();
					break;
				case 3:
					U();
					Bi();
					Ui();
					L();
					break;
				case 4:
					Bi();
					Ui();
					L();
					U();
					break;
				case 5:
					Ui();
					B();
					U();
					Ri();
					break;
				}
			}
			StampaC();
		}
		if (cube[3][0][1] == 1 && cube[3][1][0] == 1 && cube[3][1][2] == 1 && cube[3][2][1] == 1)
			break;

		//Left
		while (cube[4][0][1] == 1 || cube[4][1][0] == 1 || cube[4][1][2] == 1 || cube[4][2][1] == 1)
		{
			cout << "Left:\n";
			if (cube[4][0][1] == 1)
			{
				switch (cube[5][1][0])
				{
				case 2:
					L();
					F();
					break;
				case 3:
					L();
					Ui();
					F();
					U();
					break;
				case 4:
					Li();
					Bi();
					break;
				case 5:
					L();
					U();
					F();
					Ui();
					break;
				}
			}
			if (cube[4][1][0] == 1)
			{
				switch (cube[3][1][2])
				{
				case 2:
					U(2);
					Bi();
					Ui(2);
					break;
				case 3:
					U();
					Bi();
					Ui();
					break;
				case 4:
					Bi();
					break;
				case 5:
					Ui();
					Bi();
					U();
					break;
				}
			}
			if (cube[4][1][2] == 1)
			{
				switch (cube[1][1][0])
				{
				case 2:
					F();
					break;
				case 3:
					Ui();
					F();
					U();
					break;
				case 4:
					Ui(2);
					F();
					U(2);
					break;
				case 5:
					U();
					F();
					Ui();
					break;
				}
			}
			if (cube[4][2][1] == 1)
			{
				switch (cube[0][1][0])
				{
				case 2:
					U();
					Li();
					Ui();
					F();
					break;
				case 3:
					Li();
					Ui();
					F();
					U();
					break;
				case 4:
					L();
					Bi();
					Li();
					break;
				case 5:
					U(2);
					Li();
					Ui();
					F();
					Ui();
					break;
				}
			}
			StampaC();
		}
		if (cube[4][0][1] == 1 && cube[4][1][0] == 1 && cube[4][1][2] == 1 && cube[4][2][1] == 1)
			break;

	}

	StampaC();
	cout << "-------------------------CROSS---------------------------\n";

	system("pause>nul");
	system("cls");


	int N = 0;
	cout << "-------------------------FLOOR---------------------------\n";
	x(2);
	y(2);
	StampaC();
	while (cube[0][0][0] != 1 || cube[0][0][2] != 1 || cube[0][2][0] != 1 || cube[0][2][2] != 1)
	{

		while (cube[0][0][0] == 1 || N == 4)
		{

			//bed place
			if (cube[0][0][0] == 1 && (cube[1][2][0] != cube[1][1][1] || cube[4][2][2] != cube[4][1][1]))
			{
				Li();
				Ui();
				L();
			}
			//set 2
			y();
			N = 0;
		}

		for (int j = 0; j < 4; j++)
		{
			//Angle front
			if (cube[1][0][0] == 1 && cube[4][0][2] == cube[4][1][1] && cube[5][2][0] == cube[1][1][1])
			{
				cout << "Angle Front:\n";
				Angle_Front();
				StampaC();

			}
			//Angle Left
			if (cube[4][0][2] == 1 && cube[1][0][0] == cube[1][1][1] && cube[5][2][0] == cube[4][1][1])
			{
				cout << "Angle Left:\n";
				Angle_Left();
				StampaC();
			}
			//Angle Up
			if (cube[5][2][0] == 1 && cube[1][0][0] == cube[4][1][1] && cube[4][0][2] == cube[1][1][1])
			{
				cout << "Angle Up:\n";
				Angle_Up();
				StampaC();
			}
			//giostra
			if (cube[1][2][0] == 1)
			{
				F();
				U();
				Fi();
				Ui();
			}
			if (cube[4][2][2] == 1)
			{
				Li();
				Ui();
				L();
			}
			//set
			Ui();
			N++;
		}
	}
	//riposizionamento cubo
	cout << "riposizionamento:\n";
	switch (cube[1][1][1])
	{
	case 3:
		yi();
		break;
	case 4:
		y(2);
		break;
	case 5:
		y();
		break;
	}
	StampaC();
	cout << "-------------------------FLOOR---------------------------\n";

	system("pause>nul");
	system("cls");

	int con = 1;
	int x = 0;
	cout << "--------------------------F2L----------------------------\n";
	while (cube[1][1][0] != cube[1][1][1] || cube[1][1][2] != cube[1][1][1] ||
		cube[2][1][0] != cube[2][1][1] || cube[2][1][2] != cube[2][1][1] ||
		cube[3][1][0] != cube[3][1][1] || cube[3][1][2] != cube[3][1][1] ||
		cube[4][1][0] != cube[4][1][1] || cube[4][1][2] != cube[4][1][1])
	{

		cout << x++ << endl;

		con = 1;
		while (con)
		{
			con = 0;
			for (int j = 0; j < 4; j++)
			{
				if (cube[1][0][1] == cube[1][1][1] && cube[5][2][1] == cube[2][1][1])
				{
					cout << "Right:\n";
					F2L_Right();
					StampaC();
				}
				if (cube[1][0][1] == cube[1][1][1] && cube[5][2][1] == cube[4][1][1])
				{
					cout << "Left:\n";
					F2L_Left();
					StampaC();
				}
				U();
			}

			if ((cube[1][1][2] != cube[1][1][1] && cube[1][1][2] != 6 && cube[2][1][0] != 6) || (cube[1][1][2] == cube[1][1][1] && cube[2][1][0] != cube[2][1][1]))
			{
				cout << "Co-Right:\n";
				F2L_Right();
				con = 1;
				StampaC();
			}
			if ((cube[1][1][0] != cube[1][1][1] && cube[1][1][0] != 6 && cube[4][1][2] != 6) || (cube[1][1][0] == cube[1][1][1] && cube[4][1][2] != cube[4][1][1]))
			{
				cout << "Co-Left:\n";
				F2L_Left();
				con = 1;
				StampaC();
			}
		}
		cout << "Rotation y:\n";
		y();
		StampaC();
	}
	StampaC();
	cout << "--------------------------F2L----------------------------\n";

	system("pause>nul");
	system("cls");

	cout << "--------------------------OLL----------------------------\n";
	if (!(cube[5][0][1] == 6 && cube[5][1][0] == 6 && cube[5][1][2] == 6 && cube[5][2][1] == 6))
	{
	
		OLL_Uni();
		y();
		OLL_Uni();
		OLL_Uni();
		yi();
	}
	if (cube[5][0][1] == 6 && cube[5][2][1] == 6 && !(cube[5][0][1] == 6 && cube[5][1][0] == 6 && cube[5][1][2] == 6 && cube[5][2][1] == 6))
	{
		
		OLL_Uni();
		OLL_Uni();
	}
	if (cube[5][1][0] == 6 && cube[5][1][2] == 6 && !(cube[5][0][1] == 6 && cube[5][1][0] == 6 && cube[5][1][2] == 6 && cube[5][2][1] == 6))
	{
		
		y();
		OLL_Uni();
		OLL_Uni();
		yi();
	}
	if (cube[5][0][1] == 6 && cube[5][1][0] == 6 && !(cube[5][0][1] == 6 && cube[5][1][0] == 6 && cube[5][1][2] == 6 && cube[5][2][1] == 6))
	{	
		OLL_Uni();
	}
	if (cube[5][0][1] == 6 && cube[5][1][2] == 6 && !(cube[5][0][1] == 6 && cube[5][1][0] == 6 && cube[5][1][2] == 6 && cube[5][2][1] == 6))
	{	
		yi();
		OLL_Uni();
		y();;
	}
	if (cube[5][2][1] == 6 && cube[5][1][2] == 6 && !(cube[5][0][1] == 6 && cube[5][1][0] == 6 && cube[5][1][2] == 6 && cube[5][2][1] == 6))
	{	
		yi(2);
		OLL_Uni();
		y(2);
	}
	if (cube[5][2][1] == 6 && cube[5][1][0] == 6 && !(cube[5][0][1] == 6 && cube[5][1][0] == 6 && cube[5][1][2] == 6 && cube[5][2][1] == 6))
	{
		y();
		OLL_Uni();
		yi();
	}


	StampaC();

	while (cube[5][0][0] != 6 || cube[5][0][2] != 6 ||
		cube[5][2][0] != 6 || cube[5][2][2] != 6)
	{

		if ((cube[5][0][1] == 6 && cube[5][1][0] == 6 && cube[5][1][2] == 6 && cube[5][2][1] == 6) && cube[5][0][2] == 6 && cube[1][0][2] == 6 && cube[3][0][2] == 6 && cube[5][0][2] == 6)
		{
			cout << "OLL27: \n";	OLL_list("OLL_27");
		}
		if ((cube[5][0][1] == 6 && cube[5][1][0] == 6 && cube[5][1][2] == 6 && cube[5][2][1] == 6) && cube[5][0][0] == 6 && cube[1][0][0] == 6 && cube[2][0][0] == 6 && cube[3][0][0] == 6)
		{
			cout << "OLL26: \n";	OLL_list("OLL_26");
		}
		if ((cube[5][0][1] == 6 && cube[5][1][0] == 6 && cube[5][1][2] == 6 && cube[5][2][1] == 6) && cube[5][0][0] == 6 && cube[5][2][2] == 6 && cube[1][0][0] == 6 && cube[2][0][2] == 6)
		{
			cout << "OLL25: \n";	OLL_list("OLL_25");
		}
		if ((cube[5][0][1] == 6 && cube[5][1][0] == 6 && cube[5][1][2] == 6 && cube[5][2][1] == 6) && cube[5][0][0] == 6 && cube[5][2][0] == 6 && cube[1][0][2] == 6 && cube[3][0][0] == 6)
		{
			cout << "OLL24: \n";	OLL_list("OLL_24");
		}
		if ((cube[5][0][1] == 6 && cube[5][1][0] == 6 && cube[5][1][2] == 6 && cube[5][2][1] == 6) && cube[5][0][0] == 6 && cube[5][0][2] == 6 && cube[1][0][0] == 6 && cube[1][0][2] == 6)
		{
			cout << "OLL23: \n";	OLL_list("OLL_23");
		}
		if ((cube[5][0][1] == 6 && cube[5][1][0] == 6 && cube[5][1][2] == 6 && cube[5][2][1] == 6) && cube[1][0][2] == 6 && cube[3][0][0] == 6 && cube[4][0][0] == 6 && cube[4][0][2] == 6)
		{
			cout << "OLL22: \n";	OLL_list("OLL_22");
		}
		if ((cube[5][0][1] == 6 && cube[5][1][0] == 6 && cube[5][1][2] == 6 && cube[5][2][1] == 6) && cube[1][0][0] == 6 && cube[1][0][2] == 6 && cube[3][0][0] == 6 && cube[3][0][2] == 6)
		{
			cout << "OLL21: \n";	OLL_list("OLL_21");
		}
		U();
		StampaC();
	}
	StampaC();
	cout << "--------------------------OLL----------------------------\n";

	system("pause>nul");
	system("cls");

	cout << "--------------------------PLL----------------------------\n";
	int c = 0;
	while ((cube[1][0][0] != cube[1][0][1] != cube[1][0][2] != cube[1][1][1]) &&
		(cube[2][0][0] != cube[2][0][1] != cube[2][0][2] != cube[2][1][1]) &&
		(cube[3][0][0] != cube[3][0][1] != cube[3][0][2] != cube[3][1][1]) &&
		(cube[4][0][0] != cube[4][0][1] != cube[4][0][2] != cube[4][1][1]))
	{
		cout << "G PERM:\n";
		for (int j = 0; j < 4; j++)
		{
			StampaC();
			if ((cube[4][0][1] == cube[2][1][1] && cube[2][0][1] == cube[3][1][1] && cube[3][0][1] == cube[4][1][1]) &&
				(cube[1][0][0] == cube[4][1][1] && cube[4][0][2] == cube[3][1][1]) &&
				(cube[4][0][0] == cube[3][1][1] && cube[3][0][2] == cube[2][1][1]) &&
				(cube[3][0][0] == cube[1][1][1] && cube[2][0][2] == cube[4][1][1]))
			{
				cout << "Ga: \n";	PLL_list("PLL_Ga"); StampaC(); c = 1; break;
			}
			if ((cube[4][0][1] == cube[3][1][1] && cube[3][0][1] == cube[2][1][1] && cube[2][0][1] == cube[4][1][1]) &&
				(cube[1][0][0] == cube[3][1][1] && cube[4][0][2] == cube[2][1][1]) &&
				(cube[2][0][2] == cube[3][1][1] && cube[3][0][0] == cube[4][1][1]) &&
				(cube[3][0][2] == cube[4][1][1] && cube[4][0][0] == cube[1][1][1]))
			{
				cout << "Gb: \n";	PLL_list("PLL_Gb"); StampaC(); c = 1; break;
			}
			if ((cube[1][0][1] == cube[4][1][1] && cube[4][0][1] == cube[2][1][1] && cube[2][0][1] == cube[1][1][1]) &&
				(cube[1][0][0] == cube[2][1][1] && cube[4][0][2] == cube[1][1][1]) &&
				(cube[1][0][2] == cube[3][1][1] && cube[2][0][0] == cube[4][1][1]) &&
				(cube[3][0][2] == cube[4][1][1] && cube[4][0][0] == cube[1][1][1]))
			{
				cout << "Gc: \n";	PLL_list("PLL_Gc"); StampaC(); c = 1; break;
			}
			if ((cube[1][0][1] == cube[3][1][1] && cube[3][0][1] == cube[4][1][1] && cube[4][0][1] == cube[1][1][1]) &&
				(cube[1][0][0] == cube[4][1][1] && cube[4][0][2] == cube[3][1][1]) &&
				(cube[4][0][0] == cube[3][1][1] && cube[3][0][2] == cube[2][1][1]) &&
				(cube[3][0][0] == cube[1][1][1] && cube[2][0][2] == cube[4][1][1]))
			{
				cout << "Gd: \n";	PLL_list("PLL_Gd"); StampaC(); c = 1; break;
			}
			U();
		}
		if (c)
			break;



		cout << "Swap one set of Diagonal Corners:\n";
		for (int j = 0; j < 4; j++)
		{
			StampaC();
			if ((cube[1][0][2] == cube[3][1][1] && cube[2][0][0] == cube[4][1][1]) &&
				(cube[4][0][0] == cube[2][1][1] && cube[3][0][2] == cube[1][1][1]) &&
				(cube[2][0][1] == cube[3][1][1] && cube[3][0][1] == cube[2][1][1]) &&
				(cube[1][0][0] == cube[1][1][1] && cube[1][0][1] == cube[1][1][1]) &&
				(cube[4][0][1] == cube[4][1][1] && cube[4][0][2] == cube[4][1][1]))
			{
				cout << "V: \n";	PLL_list("PLL_V"); StampaC(); c = 1; break;
			}
			if ((cube[1][0][2] == cube[3][1][1] && cube[2][0][0] == cube[4][1][1]) &&
				(cube[4][0][0] == cube[2][1][1] && cube[3][0][2] == cube[1][1][1]) &&
				(cube[4][0][1] == cube[3][1][1] && cube[3][0][1] == cube[4][1][1]) &&
				(cube[1][0][0] == cube[1][1][1] && cube[1][0][1] == cube[1][1][1]) &&
				(cube[2][0][1] == cube[2][1][1] && cube[2][0][2] == cube[2][1][1]))
			{
				cout << "Y: \n";	PLL_list("PLL_Y"); StampaC(); c = 1; break;
			}
			if ((cube[1][0][0] == cube[3][1][1] && cube[4][0][2] == cube[2][1][1]) &&
				(cube[2][0][2] == cube[4][1][1] && cube[3][0][0] == cube[1][1][1]) &&
				(cube[4][0][1] == cube[2][1][1] && cube[2][0][1] == cube[4][1][1]))
			{
				cout << "Na: \n";	PLL_list("PLL_Na"); StampaC(); c = 1; break;
			}
			if ((cube[1][0][2] == cube[3][1][1] && cube[2][0][0] == cube[4][1][1]) &&
				(cube[4][0][0] == cube[2][1][1] && cube[3][0][2] == cube[1][1][1]) &&
				(cube[4][0][1] == cube[2][1][1] && cube[2][0][1] == cube[4][1][1]))
			{
				cout << "Nb: \n";	PLL_list("PLL_Nb"); StampaC(); c = 1; break;
			}
			U();

		}
		if (c)
			break;

		cout << "Swap one set of Adjacent Corners:\n";
		for (int j = 0; j < 4; j++)
		{
			StampaC();
			if ((cube[1][0][2] == cube[2][1][1] && cube[2][0][0] == cube[3][1][1]) &&
				(cube[2][0][2] == cube[1][1][1] && cube[3][0][0] == cube[2][1][1]) &&
				(cube[3][0][1] == cube[4][1][1] && cube[4][0][1] == cube[3][1][1]))
			{
				cout << "Ra: \n";	 PLL_list("PLL_Ra"); StampaC(); c = 1; break;
			}
			if ((cube[1][0][1] == cube[2][1][1] && cube[2][0][1] == cube[1][1][1]) &&
				(cube[2][0][2] == cube[3][1][1] && cube[3][0][0] == cube[4][1][1]) &&
				(cube[3][0][2] == cube[2][1][1] && cube[4][0][0] == cube[3][1][1]) &&
				(cube[1][0][0] == cube[1][1][1] && cube[1][0][2] == cube[1][1][1]))
			{
				cout << "Rb: \n";	 PLL_list("PLL_Rb"); StampaC(); c = 1; break;
			}
			if ((cube[4][0][0] == cube[3][1][1] && cube[3][0][2] == cube[2][1][1]) &&
				(cube[2][0][2] == cube[3][1][1] && cube[3][0][0] == cube[4][1][1]) &&
				(cube[4][0][1] == cube[3][1][1] && cube[3][0][1] == cube[4][1][1]))
			{
				cout << "Ja: \n";	PLL_list("PLL_Ja"); StampaC(); c = 1; break;
			}


			if ((cube[1][0][1] == cube[2][1][1] && cube[2][0][1] == cube[1][1][1]) &&
				(cube[1][0][2] == cube[2][1][1] && cube[2][0][0] == cube[3][1][1]) &&
				(cube[3][0][0] == cube[2][1][1] && cube[2][0][2] == cube[1][1][1]))
			{
				cout << "Jb : \n";	PLL_list("PLL_Jb"); StampaC(); c = 1; break;
			}
			if ((cube[1][0][2] == cube[2][1][1] && cube[2][0][0] == cube[3][1][1]) &&
				(cube[2][0][2] == cube[1][1][1] && cube[3][0][0] == cube[2][1][1]) &&
				(cube[4][0][1] == cube[2][1][1] && cube[2][0][1] == cube[4][1][1]))
			{
				cout << "T: \n";	PLL_list("PLL_T"); StampaC(); c = 1; break;
			}
			if ((cube[1][0][1] == cube[3][1][1] && cube[3][0][1] == cube[1][1][1]) &&
				(cube[1][0][2] == cube[2][1][1] && cube[2][0][0] == cube[3][1][1]) &&
				(cube[3][0][0] == cube[2][1][1] && cube[2][0][2] == cube[1][1][1]))
			{
				cout << "F: \n";	PLL_list("PLL_F"); StampaC(); c = 1; break;
			}

			U();
		}
		if (c)
			break;

		cout << "PREM of edges only:\n";
		for (int j = 0; j < 4; j++)
		{
			StampaC();
			if (cube[1][0][1] == cube[4][1][1] && cube[4][0][1] == cube[2][1][1] && cube[2][0][1] == cube[1][1][1] &&
				(cube[3][1][1] == cube[3][0][0] && cube[3][0][0] == cube[3][0][1] && cube[3][0][1] == cube[3][0][2]))
			{
				cout << "Ua: \n";	PLL_list("PLL_Ua"); StampaC(); c = 1; break;
			}
			if (cube[1][0][1] == cube[2][1][1] && cube[2][0][1] == cube[4][1][1] && cube[4][0][1] == cube[1][1][1] &&
				(cube[3][1][1] == cube[3][0][0] && cube[3][0][0] == cube[3][0][1] && cube[3][0][1] == cube[3][0][2]))
			{
				cout << "Ub: \n";	PLL_list("PLL_Ub"); StampaC(); c = 1; break;
			}
			if ((cube[1][1][1] == cube[1][0][0] && cube[1][0][0] == cube[1][0][2]) &&
				(cube[3][1][1] == cube[3][0][0] && cube[3][0][0] == cube[3][0][2]) &&
				(cube[1][0][1] == cube[2][1][1] && cube[3][0][1] == cube[4][1][1]))
			{
				cout << "Z: \n";	PLL_list("PLL_Z"); StampaC(); c = 1; break;
			}

			if ((cube[1][0][0] == cube[1][0][2] && cube[3][0][0] == cube[3][0][2]) &&
				(cube[1][0][1] == cube[3][1][1] && cube[3][0][1] == cube[1][1][1]) &&
				(cube[2][0][1] == cube[4][1][1] && cube[4][0][1] == cube[2][1][1]))
			{
				cout << "H:  \n";	PLL_list("PLL_H"); StampaC(); c = 1; break;
			}
			U();
		}
		if (c)
			break;


		cout << "PERM of Corners Only:\n";
		for (int j = 0; j < 4; j++)
		{
			StampaC();
			if ((cube[2][0][0] == cube[4][1][1] && cube[1][0][2] == cube[3][1][1]) &&
				(cube[4][0][0] == cube[3][1][1] && cube[3][0][2] == cube[2][1][1]) &&
				(cube[3][0][0] == cube[2][1][1] && cube[2][0][2] == cube[1][1][1]) &&
				(cube[1][0][1] == cube[1][1][1] && cube[2][0][1] == cube[2][1][1]) &&
				(cube[3][0][1] == cube[3][1][1] && cube[4][0][1] == cube[4][1][1]))
			{
				cout << "Aa: \n";	PLL_list("PLL_Aa"); StampaC(); c = 1; break;
			}
			if ((cube[2][0][0] == cube[3][1][1] && cube[1][0][2] == cube[2][1][1]) &&
				(cube[3][0][0] == cube[4][1][1] && cube[2][0][2] == cube[3][1][1]) &&
				(cube[4][0][0] == cube[2][1][1] && cube[3][0][2] == cube[1][1][1]) &&
				(cube[1][0][1] == cube[1][1][1] && cube[2][0][1] == cube[2][1][1]) &&
				(cube[3][0][1] == cube[3][1][1] && cube[4][0][1] == cube[4][1][1]))
			{
				cout << "Ab: \n";	PLL_list("PLL_Ab"); StampaC(); c = 1; break;
			}
			if ((cube[1][0][0] == cube[4][1][1] && cube[4][0][2] == cube[3][1][1]) &&
				(cube[1][0][2] == cube[2][1][1] && cube[2][0][0] == cube[3][1][1]) &&
				(cube[3][0][0] == cube[2][1][1] && cube[2][0][2] == cube[1][1][1]) &&
				(cube[3][0][2] == cube[4][1][1] && cube[4][0][0] == cube[1][1][1]) &&
				(cube[1][0][1] == cube[1][1][1] && cube[2][0][1] == cube[2][1][1]) &&
				(cube[3][0][1] == cube[3][1][1] && cube[4][0][1] == cube[4][1][1]))
			{
				cout << "E: \n";	PLL_list("PLL_E"); StampaC(); c = 1; break;
			}
			U();
		}
		if (c)
			break;


		y();
		cout << "rotatiom y:\n";
		StampaC();
	}
	cout << "--------------------------PLL----------------------------\n";

	system("pause>nul");
	system("cls");
	StampaC();
}

//-----------------------------------------------METODI INTERNI-----------------------------------------------
void cubeClass::Color(int a) const
{
	switch (a)
	{
	case 1:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		break;
	case 2:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		break;
	case 3:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		break;
	case 4:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		break;
	case 5:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		break;
	case 6:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		break;
	default:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		break;
	}
}


//floor
void cubeClass::Angle_Up()
{
	Li();
	Ui(2);
	L();
	U();
	Li();
	Ui();
	L();
}
void cubeClass::Angle_Left()
{
	Li();
	Ui();
	L();
}
void cubeClass::Angle_Front()
{
	Ui();
	Li();
	U();
	L();
}

//F2L
void cubeClass::F2L_Right()
{
	U();
	R();
	U();
	Ri();
	Ui();
	Fi();
	Ui();
	F();
}
void cubeClass::F2L_Left()
{
	Ui();
	Li();
	Ui();
	L();
	U();
	F();
	U();
	Fi();
}

//OLL
void cubeClass::OLL_Uni()
{
	Ri();
	Ui();
	Fi();
	U();
	F();
	R();
}

///-----------------------------------------------resolv-----------------------------------------------

void cubeClass::OLL_list(std::string OLL)
{
	if (OLL == "OLL_27")
	{
		L();
		U();
		Li();
		U();
		L();
		U(2);
		Li();
	}
	else if (OLL == "OLL_26")
	{
		Ri();
		Ui();
		R();
		Ui();
		Ri();
		U(2);
		R();
	}
	else if (OLL == "OLL_25")
	{
		Ri();
		F();
		R();
		Bi();
		Ri();
		Fi();
		R();
		B();
	}
	else if (OLL == "OLL_24")
	{
		LWi();
		Ui();
		L();
		U();
		R();
		Ui();
		RWi();
		F();

	}
	else if (OLL == "OLL_23")
	{
		R(2);
		D();
		Ri();
		U(2);
		R();
		Di();
		Ri();
		U(2);
		Ri();
	}
	else if (OLL == "OLL_22")
	{
		R();
		Ui(2);
		R(2);
		Ui();
		R(2);
		Ui();
		R(2);
		Ui(2);
		R();
	}
	else if (OLL == "OLL_21")
	{
		R();
		U(2);
		Ri();
		Ui();
		R();
		U();
		Ri();
		Ui();
		R();
		Ui();
		Ri();
	}
}
void cubeClass::PLL_list(std::string PLL)
{
	if (PLL == "PLL_Ua")
	{
		R(2);
		U();
		R();
		U();
		Ri();
		Ui();
		Ri();
		Ui();
		Ri();
		U();
		Ri();
	}
	else if (PLL == "PLL_Ub")
	{
		R();
		Ui();
		R();
		U();
		R();
		U();
		R();
		Ui();
		Ri();
		Ui();
		R(2);
	}
	else if (PLL == "PLL_Z")
	{
		Mi(2);
		U();
		Mi(2);
		U();
		Mi();
		U(2);
		Mi(2);
		U(2);
		Mi();
		U(2);
	}
	else if (PLL == "PLL_H")
	{
		Mi(2);
		U();
		Mi(2);
		U(2);
		Mi(2);
		U();
		Mi(2);
	}
	else if (PLL == "PLL_Aa")
	{
		x();
		Ri();
		U();
		Ri();
		D(2);
		R();
		Ui();
		Ri();
		D(2);
		R(2);
		xi();
	}
	else if (PLL == "PLL_Ab")
	{
		x();
		Ri(2);
		D(2);
		R();
		U();
		Ri();
		D(2);
		R();
		Ui();
		R();
		xi();
	}
	else if (PLL == "PLL_E")
	{
		xi();
		R();
		Ui();
		Ri();
		D();
		R();
		U();
		Ri();
		Di();
		R();
		U();
		Ri();
		D();
		R();
		Ui();
		Ri();
		Di();
		x();
	}
	else if (PLL == "PLL_Ra")
	{
		R();
		Ui();
		Ri();
		Ui();
		R();
		U();
		R();
		D();
		Ri();
		Ui();
		R();
		Di();
		Ri();
		U(2);
		Ri();
		Ui();
	}
	else if (PLL == "PLL_Rb")
	{
		Ri();
		U(2);
		R();
		Ui(2);
		Ri();
		F();
		R();
		U();
		Ri();
		Ui();
		Ri();
		Fi();
		R(2);
		Ui();
	}
	else if (PLL == "PLL_Ja")
	{
		Ri();
		U();
		Li();
		U(2);
		R();
		Ui();
		Ri();
		U(2);
		R();
		L();
		Ui();
	}
	else if (PLL == "PLL_Jb")
	{
		R();
		U();
		Ri();
		Fi();
		R();
		U();
		Ri();
		Ui();
		Ri();
		F();
		R(2);
		Ui();
		Ri();
		Ui();
	}
	else if (PLL == "PLL_T")
	{
		R();
		U();
		Ri();
		Ui();
		Ri();
		F();
		R(2);
		Ui();
		Ri();
		Ui();
		R();
		U();
		Ri();
		Fi();
	}
	else if (PLL == "PLL_F")
	{
		Ri();
		Ui();
		Fi();
		R();
		U();
		Ri();
		Ui();
		Ri();
		F();
		R(2);
		Ui();
		Ri();
		Ui();
		R();
		U();
		Ri();
		U();
		R();
	}
	else if (PLL == "PLL_V")
	{
		Ri();
		U();
		Ri();
		Ui();
		y();
		Ri();
		Fi();
		R(2);
		Ui();
		Ri();
		U();
		Ri();
		F();
		R();
		F();
	}
	else if (PLL == "PLL_Y")
	{
		F();
		R();
		Ui();
		Ri();
		Ui();
		R();
		U();
		Ri();
		Fi();
		R();
		U();
		Ri();
		Ui();
		Ri();
		F();
		R();
		Fi();
	}
	else if (PLL == "PLL_Na")
	{
		R();
		U();
		Ri();
		U();
		R();
		U();
		Ri();
		Fi();
		R();
		U();
		Ri();
		Ui();
		Ri();
		F();
		R(2);
		Ui();
		Ri();
		U(2);
		R();
		Ui();
		Ri();
	}
	else if (PLL == "PLL_Nb")
	{
		Ri();
		U();
		R();
		Ui();
		Ri();
		Fi();
		Ui();
		F();
		R();
		U();
		Ri();
		F();
		Ri();
		Fi();
		R();
		Ui();
		R();
	}
	else if (PLL == "PLL_Ga")
	{
		R(2);
		U();
		Ri();
		U();
		Ri();
		Ui();
		R();
		Ui();
		R(2);
		D();
		Ui();
		Ri();
		U();
		R();
		Di();
		U();
	}
	else if (PLL == "PLL_Gb")
	{
		Fi();
		Ui();
		F();
		R(2);
		UW();
		Ri();
		U();
		R();
		Ui();
		R();
		UWi();
		Ri(2);
	}
	else if (PLL == "PLL_Gc")
	{
		R(2);
		Ui();
		R();
		Ui();
		R();
		U();
		Ri();
		U();
		R(2);
		Di();
		U();
		R();
		Ui();
		Ri();
		D();
		Ui();
	}
	else if (PLL == "PLL_Gd")
	{
		Di();
		R();
		U();
		Ri();
		Ui();
		D();
		R(2);
		Ui();
		R();
		Ui();
		Ri();
		U();
		Ri();
		U();
		R(2);
		U();
	}
}




std::ostream& operator<< (std::ostream& stream, const cubeClass& C)
{
	stream << "-----------------------C.cube SOLVER-----------------------\n";
	for (int y = 0; y < 3; y++)
	{
		stream << "\t\t\t";
		for (int x = 0; x < 3; x++)
		{
			C.Color(C.cube[5][y][x]);
			stream << C.cube[5][y][x] << "  ";
		}
		stream << endl;
	}

	stream << endl;
	for (int y = 0; y < 3; y++)
	{
		stream << "\t   ";
		for (int x = 0; x < 3; x++)
		{
			C.Color(C.cube[4][y][x]);
			stream << C.cube[4][y][x] << "  ";
		}

		stream << "\t";
		for (int x = 0; x < 3; x++)
		{
			C.Color(C.cube[1][y][x]);
			stream << C.cube[1][y][x] << "  ";
		}

		stream << "    ";
		for (int x = 0; x < 3; x++)
		{
			C.Color(C.cube[2][y][x]);
			stream << C.cube[2][y][x] << "  ";
		}

		stream << "    ";
		for (int x = 0; x < 3; x++)
		{
			C.Color(C.cube[3][y][x]);
			stream << C.cube[3][y][x] << "  ";
		}

		stream << endl;

	}

	stream << endl;
	for (int y = 0; y < 3; y++)
	{
		stream << "\t\t\t";
		for (int x = 0; x < 3; x++)
		{
			C.Color(C.cube[0][y][x]);
			stream << C.cube[0][y][x] << "  ";
		}
		stream << endl;
	}
	C.Color(0);
	stream << "-----------------------CUBE SOLVER-----------------------\n";
	return stream;
}