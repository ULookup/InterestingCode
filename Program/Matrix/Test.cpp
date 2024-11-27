#include"Matrix.h"
int main()
{
 	Matrix A(3, 3);
	Matrix B(3, 3);
	A.Print();
	A.Input();
	B.Input();

	Matrix C(3,3);
	C = A * B;
	C.Print();

	return 0;
}