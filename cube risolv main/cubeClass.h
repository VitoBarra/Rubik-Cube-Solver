#pragma once
#include <iostream>
#include <windows.h>
#include <string>

class cubeClass
{
public:
	//-----------------------------------------------DIS/COSTRUTTORI-----------------------------------------------
	cubeClass();


	~cubeClass();
	//-----------------------------------------------METODI ESTERNI-----------------------------------------------
	///-----------------------------------------------stampa-----------------------------------------------
	void StampaC();
	void Logo();

	///-----------------------------------------------res|set-----------------------------------------------
	void SET_sc();
	void RESET();

	///-----------------------------------------------scramble-----------------------------------------------
	void ExecuteScramble();
	void scramble_generator(int = 25);

	///-----------------------------------------------MOVE area-----------------------------------------------
	void U(int = 1);
	void Ui(int = 1);
	void D(int = 1);
	void Di(int = 1);
	void L(int = 1);
	void Li(int = 1);
	void R(int = 1);
	void Ri(int = 1);
	void F(int = 1);
	void Fi(int = 1);
	void B(int = 1);
	void Bi(int = 1);
	void M(int = 1);
	void Mi(int = 1);
	void S(int = 1);
	void Si(int = 1);
	void E(int = 1);
	void Ei(int = 1);
	void RW(int = 1);
	void RWi(int = 1);
	void LW(int = 1);
	void LWi(int = 1);
	void UW(int = 1);
	void UWi(int = 1);
	void DW(int = 1);
	void DWi(int = 1);
	void FW(int = 1);
	void FWi(int = 1);
	void BW(int = 1);
	void BWi(int = 1);
	///-----------------------------------------------rotation-----------------------------------------------
	void x(int = 1);
	void xi(int = 1);
	void y(int = 1);
	void yi(int = 1);
	void z(int = 1);
	void zi(int = 1);


	///-----------------------------------------------resolv-----------------------------------------------
	void Cube_FIN();


	std::string scr = "";

private:

	//-----------------------------------------------METODI INTERNI-----------------------------------------------
	///-----------------------------------------------stampa-----------------------------------------------
	void Color(int a) const;

	///-----------------------------------------------MOVE area-----------------------------------------------
	//floor
	void Angle_Up();
	void Angle_Left();
	void Angle_Front();

	//F2L
	void F2L_Right();
	void F2L_Left();

	//OLL
	void OLL_Uni();
	

	///-----------------------------------------------resolv-----------------------------------------------
	void OLL_list(std::string);
	void PLL_list(std::string);

	//-----------------------------------------------STATO INTERNO-----------------------------------------------
	friend std::ostream& operator<< (std::ostream&, const cubeClass&);
	//-----------------------------------------------STATO INTERNO-----------------------------------------------
	int cube[6][3][3];
	
};

