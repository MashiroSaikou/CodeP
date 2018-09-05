#include "iostream"
#define LINE 4;
#define ROW 5;
using namespace std;

class Matrix
{
public:
	Matrix();
	~Matrix();
	void getData();//cin输入元素
	void putData();//cout输出元素
	void addMatrix(Matrix&,Matrix&);//矩阵相加
	void subMatrix(Matrix&,Matrix&);//矩阵相减
private:
	int matrix[LINE][ROW];
};

void Matrix::getData()
{
	cout<<"Matrix:"<<endl;
	for (int i = 0; i < LINE; ++i)
	{
		for (int j = 0; j < ROW; ++j)
		{
			cin>>matrix[i][j];
		}
	}
}

void Matrix::putData()
{
	cout<<"The Matrix:"<<endl;
	for (int i = 0; i < LINE; ++i)
	{
		for (int j = 0; j < ROW; ++j)
		{
			cout<<matrix[i][j]<<"\t";
		}
		cout<<endl;
	}
}

void Matrix::addMatrix(Matrix &A, Matrix &B)
{
	for (int i = 0; i < LINE; ++i)
	{
		for (int j = 0; j < ROW; ++j)
		{
			matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
		}
	}
}
void Matrix::subMatrix(Matrix &A, Matrix &B)
{
	for (int i = 0; i < LINE; ++i)
	{
		for (int j = 0; j < ROW; ++j)
		{
			matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
		}
	}
}

int main(int argc, char const *argv[])
{
	Matrix A1, A2, A3;
	A1.getData();
	A2.getData();
	//读取
	A3.addMatrix(A1,A2);
	A3.putData();
	//相加
	A3.subMatrix(A1,A2);
	A3.putData();
	//相减
	return 0;
}