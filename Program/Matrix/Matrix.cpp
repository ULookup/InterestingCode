#include"Matrix.h"


bool Matrix::CheckMatrix()//检查矩阵是不是有效矩阵
{
	return _row > 0 && _col > 0;
}
bool Matrix::CheckType(const Matrix& B)//检查是不是同型矩阵
{
	return _row == B._row && _col == B._col;
}
bool Matrix::CheckMN(const Matrix& B)
{
	if (_col == B._row)
		return 1;
	else
		return 0;
}

Matrix::Matrix(int row, int col)//构造函数
        :_matrix(new int[row*col]{0})
	    ,_col(col)
		,_row(row)
	    ,_capacity(row*col)
{
		if (!CheckMatrix())
		{
			cout << "矩阵非法!" << endl;
		}
}

Matrix::Matrix(const Matrix& matrix)//拷贝构造
{
	_col = matrix._col;
	_row = matrix._row;
	_capacity = matrix._capacity;

	_matrix = new int[_capacity];
	memcpy(_matrix, matrix._matrix, _capacity*sizeof(int));

}

Matrix::~Matrix()//析构函数
{
	delete[] _matrix;
	_matrix = nullptr;

	_col = 1;
	_row = 1;
	_capacity = 1;
}

void Matrix::Input()//输入矩阵
{
	cout<<"请输入矩阵的数据:"<<endl;
	for (int i = 1; i <= _row; i++)
	{
		for (int j = 1; j <= _col; j++)
		{
			scanf("%d",&_matrix[(j + (i - 1) * _col) - 1]);
		} 
	}
}

void Matrix::Print()//打印矩阵
{
	for (int i = 1; i <= _row; i++)
	{
		for (int j = 1; j <= _col; j++)
		{
			cout << _matrix[(j + (i - 1) * _col) - 1] << ' ';
		}
		cout << endl;
	}
}

bool Matrix::operator==(const Matrix& B)//等于运算符重载
{
    for (int i = 0; i < _capacity; i++)
	{
		if (_matrix[i] != B._matrix[i])
			return 0;
	}
	return 1;
}
Matrix Matrix::operator+(const Matrix& B)//+重载
{
	if (!CheckType(B))
	{
		cout << "非同型矩阵！" << endl;
		return *this;
	}
	else
	{
		Matrix temp(*this);
		for (int i = 0; i < _capacity; i++)
		{
			temp._matrix[i] = _matrix[i] + B._matrix[i];
		}
		return temp;
	}
}
bool Matrix::operator!=(const Matrix& B)//!=重载
{
	return !(*this == B);
}
Matrix Matrix::operator=(const Matrix& B)//赋值运算符重载
{
	if (*this != B && CheckType(B))
	{
		_col = B._col;
		_row = B._row;
		_capacity = B._capacity;

		memcpy(_matrix, B._matrix, sizeof(int) * _capacity);
	}
	return *this;
}
Matrix Matrix::operator*(const Matrix& B)
{
	Matrix temp(_row, B._col);
	if (!CheckMN(B))
		cout << "两个矩阵无法相乘！" << endl;
	else
	{
		for (int i = 1; i <= _row; i++)
		{
			for (int j = 1; j <= B._col; j++)
			{
				int sum = 0;
				for (int k = 1; k <= _col; k++)
				{
						sum+= _matrix[(k + (i - 1) * _col) - 1] 
							* B._matrix[j + (k - 1) * B._col-1];//我把后面的j写成i了
				}
				temp._matrix[j + (i - 1) * _col - 1] = sum;
			} 
		}
		/*for (int i = 1; i <= _row; i++)
		{
			for (int j = 1; j <= B._col; j++)
			{
				int sum = 0;
				for (int k = 1; k <= _col; k++)
				{
					sum += _matrix[(i-1) * _col + k-1] * B._matrix[(k-1) * B._col + j-1]; 
				}
				temp._matrix[(i-1) * B._col + j-1] = sum; 
			}
		}
		*/
	}
	return temp;
}