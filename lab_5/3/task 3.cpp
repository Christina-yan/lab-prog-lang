#include "Matrix.h"

int main()
{
	int i = 2, j = 3;
	Matrix<int> m({
		{1,2,3},
		{4,5,6},
		{7,8,9}
		});

	//m.Set(0, 0, 5);
	//cout << m.Get(0,0);

	cout << m;
}
