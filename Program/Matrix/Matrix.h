#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Matrix
{
public:
	bool CheckMatrix();//�������ǲ�����Ч����
	bool CheckType(const Matrix& B);//����ǲ���ͬ�;���
	bool CheckMN(const Matrix& B);//����ܷ����

	Matrix(int row = 1, int col = 1);//���캯��

	Matrix(const Matrix& matrix);//��������


	~Matrix();//��������

	void Input();//�������
	void Print();//��ӡ����

	bool operator==(const Matrix& B);//�������������
	Matrix operator+(const Matrix& B);//+����
	bool operator!=(const Matrix& B);//!=����
	Matrix operator=(const Matrix& B);//��ֵ���������
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