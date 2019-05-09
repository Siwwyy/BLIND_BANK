#include "Logowanie.h"

void Load_Form()
{
	BLINDBANK::Logowanie^ program = gcnew BLINDBANK::Logowanie();
	//Logowanie^ program = gcnew Logowanie();
	program->ShowDialog();
}