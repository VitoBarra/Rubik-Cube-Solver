void OLL_21(int cube[][3][3])
{
	R(cube);
	U(cube, 2);
	Ri(cube);
	Ui(cube);
	R(cube);
	U(cube);
	Ri(cube);
	Ui(cube);
	R(cube);
	Ui(cube);
	Ri(cube);

}

void OLL_22(int cube[][3][3])
{
	R(cube);
	Ui(cube, 2);
	R(cube, 2);
	Ui(cube);
	R(cube, 2);
	Ui(cube);
	R(cube, 2);
	Ui(cube, 2);
	R(cube);
}

void OLL_23(int cube[][3][3])
{
	R(cube, 2);
	D(cube);
	Ri(cube);
	U(cube, 2);
	R(cube);
	Di(cube);
	Ri(cube);
	U(cube, 2);
	Ri(cube);
}


void OLL_24(int cube[][3][3])
{
	LWi(cube);
	Ui(cube);
	L(cube);
	U(cube);
	R(cube);
	Ui(cube);
	RWi(cube);
	F(cube);
}


void OLL_25(int cube[][3][3])
{
	Ri(cube);
	F(cube);
	R(cube);
	Bi(cube);
	Ri(cube);
	Fi(cube);
	R(cube);
	B(cube);

}

void OLL_26(int cube[][3][3])
{
	Ri(cube);
	Ui(cube);
	R(cube);
	Ui(cube);
	Ri(cube);
	U(cube, 2);
	R(cube);
}

void OLL_27(int cube[][3][3])
{
	L(cube);
	U(cube);
	Li(cube);
	U(cube);
	L(cube);
	U(cube,2);
	Li(cube); 
}