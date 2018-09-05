#include "iostream"
//#define LINE 4;
//#define ROW 5;
using namespace std;

class Matrix
{
public:
	Matrix();
	Matrix(int,int);
	Matrix(Matrix&);
	~Matrix();
	void initialise ();
	void getData();//cin输入元素
	void putData();//cout输出元素
	void addMatrix(Matrix&,Matrix&);//矩阵相加
	void subMatrix(Matrix&,Matrix&);//矩阵相减
	void delete_Matrix();
	bool matrixSucced = true;
	int LINE,ROW;
	Matrix & operator=(const Matrix & other)
	{
		delete_Matrix();
		LINE = other.LINE;
		ROW = other.ROW;
		this->initialise();
		//Matrix result(LINE,ROW);
		for (int i = 0; i < LINE; ++i)
		{
			for (int j = 0; j < ROW; ++j)
			{
				matrix[i][j] = other.matrix[i][j];
			}
		}
	}

	friend Matrix operator+ (const Matrix &other1 ,const Matrix &other2);  
    friend Matrix operator- (const Matrix &other1 ,const Matrix &other2);
private:
	int **matrix;
	
};
Matrix::Matrix(int _LINE, int _ROW)
{
	LINE = _LINE;
	ROW = _ROW;
}
Matrix::Matrix(Matrix &B)
{
	LINE = B.LINE;
	ROW = B.ROW;
	initialise();

	for (int i = 0; i < LINE; ++i)
	{
		for (int j = 0; j < ROW; ++j)
		{
			matrix[i][j] = B.matrix[i][j];
		}
	}

}
Matrix::~Matrix()
{
	delete_Matrix();
}

void Matrix::delete_Matrix()
{
	if (matrix)
	{
		for (int i = 0; i < LINE; ++i)
		{
			delete matrix[i];
		}
		delete matrix;
		matrix = NULL;
	}
	matrix = NULL;
}

void Matrix::initialise()
{
	matrix = new int*[LINE];
	if(matrix != NULL)
	{
		for (int i = 0; i < LINE; ++i)
		{
			*(matrix+i) = new int[ROW];
			if (matrix+i == NULL)
			{
				cout<<"error"<<endl;
				matrixSucced = false;
			}
		}
	}
	else
	{
		cout<<"error"<<endl;
		matrixSucced = false;
	}
}
void Matrix::getData()
{
	initialise();
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
			matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
		}
	}
}
void Matrix::subMatrix(Matrix &A, Matrix &B)
{
	for (int i = 0; i < LINE; ++i)
	{
		for (int j = 0; j < ROW; ++j)
		{
			matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
		}
	}
}




Matrix operator+(const Matrix &other1, const Matrix &other2)
{
	Matrix temp;
	if (other1.LINE == other2.LINE&&other1.ROW == other2.ROW)
	{
		temp.LINE = other1.LINE;
		temp.ROW = other1.ROW;
		for (int i = 0; i < temp.LINE; ++i)
		{
			for (int j = 0; j < temp.ROW; ++j)
			{
				temp.matrix[i][j] = other1.matrix[i][j] + other2.matrix[i][j];
			}
		}
	}
	return temp;
}

Matrix operator-(const Matrix &other1, const Matrix &other2)
{
	Matrix temp;
	if (other1.LINE == other2.LINE&&other1.ROW == other2.ROW)
	{
		temp.LINE = other1.LINE;
		temp.ROW = other1.ROW;
		for (int i = 0; i < temp.LINE; ++i)
		{
			for (int j = 0; j < temp.ROW; ++j)
			{
				temp.matrix[i][j] = other1.matrix[i][j] - other2.matrix[i][j];
			}
		}
	}
	return temp;
}
int main(int argc, char const *argv[])
{
	int LINE,ROW;
	cout<<"get_line_row:"<<endl;
	cin>>LINE>>ROW;
	Matrix A1(LINE,ROW);
	A1.getData();
	cout<<"get_line_row:"<<endl;
	cin>>LINE>>ROW;
	Matrix A2(LINE,ROW);
	A2.getData();

	Matrix A3;
	A3 = A1 + A2;
	A3.putData();
	A3 = A1 - A2;
	A3.putData();
	

	cout<<"get_line_row:"<<endl;
	cin>>LINE>>ROW;
	Matrix *pA1 = new Matrix(LINE,ROW);
	pA1->getData();

	//cout<<"get_line_row_row:"<<endl;
	//cin>>LINE>>row;
	Matrix *pA2 = new Matrix(LINE,ROW);
	pA2->getData();

	Matrix *pA3 = new Matrix(LINE,ROW);
	pA3->addMatrix(pA1,pA2);
	pA3->putData();

	pA3->subMatrix(pA1,pA2);
	pA3->putData();

	pA1->~Matrix();
	pA2->~Matrix();
	pA3->~Matrix();
	return 0;
}
