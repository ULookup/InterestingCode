#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Matrix
{
public:
	bool CheckMatrix();//检查矩阵是不是有效矩阵
	bool CheckType(const Matrix& B);//检查是不是同型矩阵
	bool CheckMN(const Matrix& B);//检查能否相乘

	Matrix(int row = 1, int col = 1);//构造函数

	Matrix(const Matrix& matrix);//拷贝构造


	~Matrix();//析构函数

	void Input();//输入矩阵
	void Print();//打印矩阵

	bool operator==(const Matrix& B);//等于运算符重载
	Matrix operator+(const Matrix& B);//+重载
	bool operator!=(const Matrix& B);//!=重载
	Matrix operator=(const Matrix& B);//赋值运算符重载
	Matrix operator*(const Matrix& B);

	template<typename Type>
	Matrix operator*(Type n)
	{
		for (int i = 0; i < _capacity; i++)
		{
			_matrix[i] *= n;
		}
		return *this;
	}

private:
	int* _matrix = nullptr;
	int _col = 1;
	int _row = 1;
	int _capacity = 1;
};