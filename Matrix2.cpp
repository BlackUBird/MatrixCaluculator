#include <stdio.h>
#include <stdlib.h>
#include "Matrix2.h"

//初期化
void Matrix2_Initialize( Matrix_t* Matrix , int Rows , int Columns)
{
	//行数、列数をセット
	Matrix->Rows = Rows;
	Matrix->Columns = Columns;

	//2次元データの格納先を確定する
	//疑似的な2次元配列の動的割り当てを行う
	Matrix->Elements = (double**)calloc( Rows , sizeof(double*) );
	for( int i = 0 ; i < Rows ; i++ )
	{
		Matrix->Elements[i] = (double*)calloc( Columns , sizeof(double) );
	}
}

//取得用
//要素
double Matrix2_GetElement( Matrix_t Matrix , int posRow , int posColumn )
{
	return (Matrix.Elements[posRow][posColumn]);
}
//列数
int Matrix2_GetColumns( Matrix_t Matrix )
{
	return (Matrix.Columns);
}
//行数
int Matrix2_GetRows( Matrix_t Matrix )
{
	return (Matrix.Rows);
}

//設定用
//要素
double Matrix2_SetElement( Matrix_t* Matrix , int posRow , int posColumn , double newElement )
{
	Matrix->Elements[posRow][posColumn] = newElement;

	//新しくしたのを返す
	return (Matrix->Elements[posRow][posColumn]);
}

//描画
//全ての要素
void Matrix2_DrawAllElements( Matrix_t Matrix )
{
	//描画
	//行数分までループ
	for( int i = 0 ; i < Matrix.Rows ; i++ )
	{
		//列数分までループ
		for( int j = 0 ; j < Matrix.Columns ; j++ )
		{
			printf( "%10.4lf" , Matrix.Elements[i][j] ); 
		}
		printf( "\n" );
	}
}
//行数
void Matrix2_DrawRows( Matrix_t Matrix )
{
	printf( "%d\n" , Matrix.Rows );
}
//列数
void Matrix2_DrawColumns( Matrix_t Matrix )
{
	printf( "%d\n" , Matrix.Columns );
}

//演算
//加算
bool Matrix2_Sum( Matrix_t FirstMatrix , Matrix_t SecondMatrix , Matrix_t* ResultMatrix )
{
	//1つ目と2つ目行列のサイズが一致していれば加算をする
	if( FirstMatrix.Rows == SecondMatrix.Rows && FirstMatrix.Columns == SecondMatrix.Columns )
	{
		//行数分までループ
		for( int i = 0 ; i < FirstMatrix.Rows ; i++ )
		{
			//列数分までループ
			for( int j = 0 ; j < FirstMatrix.Columns ; j++ )
			{
				ResultMatrix->Elements[i][j] = FirstMatrix.Elements[i][j] + SecondMatrix.Elements[i][j];
			}
		}
		//加算後trueを返す
		return (true);
	}
	//異なればfalseを返す
	else
	{
		return (false);
	}
}
//減算
bool Matrix2_Sub( Matrix_t FirstMatrix , Matrix_t SecondMatrix , Matrix_t* ResultMatrix )
{
	//1つ目と2つ目行列のサイズが一致していれば減算をする
	if( FirstMatrix.Rows == SecondMatrix.Rows && FirstMatrix.Columns == SecondMatrix.Columns )
	{
		//行数分までループ
		for( int i = 0 ; i < FirstMatrix.Rows ; i++ )
		{
			//列数分までループ
			for( int j = 0 ; j < FirstMatrix.Columns ; j++ )
			{
				ResultMatrix->Elements[i][j] = FirstMatrix.Elements[i][j] - SecondMatrix.Elements[i][j];
			}
		}
		//減算後trueを返す
		return (true);
	}
	//異なればfalseを返す
	else
	{
		return (false);
	}
}
//乗算
bool Matrix2_Mul( Matrix_t FirstMatrix , Matrix_t SecondMatrix , Matrix_t* ResultMatrix )
{
	//1つ目行列の列数と2つ目の行列の行数が一致していれば乗算をする
	if( FirstMatrix.Rows == SecondMatrix.Rows && FirstMatrix.Columns == SecondMatrix.Columns )
	{
		//1つ目の行列の行数分までループ
		for( int i = 0 ; i < FirstMatrix.Rows ; i++ )
		{
			//2つ目の行列の列数分までループ
			for( int j = 0 ; j < SecondMatrix.Columns ; j++ )
			{
				//1つ目行列の列数(2つ目の行列の行数でも可)分までループ
				for( int k = 0 ; k < FirstMatrix.Columns ; k++ )
				{
					ResultMatrix->Elements[i][j] += FirstMatrix.Elements[i][k] * SecondMatrix.Elements[k][j];
				}
			}
		}
		//乗算後trueを返す
		return (true);
	}
	//異なればfalseを返す
	else
	{
		return (false);
	}
}
//除算
bool Matrix2_Div( Matrix_t FirstMatrix , Matrix_t SecondMatrix , Matrix_t* ResultMatrix )
{
	//1つ目行列の列数と2つ目の行列の行数が一致していれば乗算をする
	if( FirstMatrix.Rows == SecondMatrix.Rows && FirstMatrix.Columns == SecondMatrix.Columns )
	{
		//1つ目の行列の行数分までループ
		for( int i = 0 ; i < FirstMatrix.Rows ; i++ )
		{
			//2つ目の行列の列数分までループ
			for( int j = 0 ; j < SecondMatrix.Columns ; j++ )
			{
				//1つ目行列の列数(2つ目の行列の行数でも可)分までループ
				for( int k = 0 ; k < FirstMatrix.Columns ; k++ )
				{
					ResultMatrix->Elements[i][j] += FirstMatrix.Elements[i][k] / SecondMatrix.Elements[k][j];
				}
			}
		}
		//乗算後trueを返す
		return (true);
	}
	//異なればfalseを返す
	else
	{
		return (false);
	}
}
//LU分解をする
bool Matrix2_LUDecomposition( Matrix_t Matrix , Matrix_t* LMatrix , Matrix_t* UMatrix )
{
	//分解される行列の行数分ループする
	for( int i = 0 ; i < Matrix.Rows ; i++ )
	{
		//行列Lの対角成分を1にする
		LMatrix->Elements[i][i] = 1.0;

		//行列Uの対角成分を計算する
		UMatrix->Elements[i][i] = Matrix.Elements[i][i];
		for( int k = 0 ; k < i ; k++ )
		{
			UMatrix->Elements[i][i] -= LMatrix->Elements[i][k] * UMatrix->Elements[k][i];
		}

		//分解される行列の列数分ループする
		for( int j = i+1 ; j < Matrix.Columns ; j++ )
		{
			//行列Lの(j,i)成分を計算
			LMatrix->Elements[j][i] = Matrix.Elements[j][i];
			for( int k = 0 ; k < i ; k++ )
			{
				LMatrix->Elements[j][i] -= LMatrix->Elements[j][k] * UMatrix->Elements[k][i];
			}
			LMatrix->Elements[j][i] /= UMatrix->Elements[i][i];

			//Uの(j,i)成分を更新
			UMatrix->Elements[j][i] = 0.0;

			//Lの(i,j)成分を更新
			LMatrix->Elements[i][j] = 0.0;

			//Uの(i,j)成分を更新
			UMatrix->Elements[i][j] = Matrix.Elements[i][j];
			for( int k = 0 ; k < i ; k++ )
			{
				UMatrix->Elements[i][j] -= LMatrix->Elements[i][k] * UMatrix->Elements[k][j];
			}
		}
	}

	return (true);
}

//終了処理
void Matrix2_Finalize( Matrix_t* Matrix )
{
	for( int i = 0 ; i < Matrix->Rows ; i++ )
	{
		free( Matrix->Elements[i] );
	}
	free( Matrix->Elements );
}