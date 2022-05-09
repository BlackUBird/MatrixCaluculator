#include <stdio.h>
#include <stdlib.h>
#include "Matrix2.h"

int main(void)
{
	//行数を入力
	int rows;
	printf( "行数:" );	scanf_s( "%d" , &rows );
	//列数を入力
	int columns;
	printf( "列数:" );	scanf_s( "%d" , &columns);

	//行列Aを宣言
	Matrix_t Matrix_A;
	Matrix2_Initialize( &Matrix_A , rows , columns );

	//行列Bを宣言
	Matrix_t Matrix_B;
	Matrix2_Initialize( &Matrix_B , rows , columns );

	//行列Aを描画
	printf( "MatrixA\n" );
	Matrix2_DrawAllElements( Matrix_A );
	printf( "\n" );

	//行列Bを描画
	printf( "MatrixB\n" );
	Matrix2_DrawAllElements( Matrix_B );
	printf( "\n" );

	//行列Aの成分を設定(ついでにBも)
	//行列Aの行数分ループ
	for( int i = 0 ; i < Matrix2_GetRows( Matrix_A ) ; i++ )
	{
		//行列Aの列数分ループ
		for( int j = 0 ; j < Matrix2_GetColumns( Matrix_A ) ; j++ )
		{
			//代入する値を入力
			double newElement;
			printf( "(%d,%d):" , i , j );	scanf_s( "%lf" , &newElement );

			//更新
			Matrix2_SetElement( &Matrix_A , i , j , newElement );
			Matrix2_SetElement( &Matrix_B , i , j , 20.0 - newElement );
		}
	}

	//再度行列Aを表示
	printf( "MatrixA\n" );
	Matrix2_DrawAllElements( Matrix_A );
	printf( "\n" );
	
	//再度行列Bを表示
	printf( "MatrixB\n" );
	Matrix2_DrawAllElements( Matrix_B );
	printf( "\n" );

	//演算
	//結果格納用
	Matrix_t Matrix_Result;
	
	//行列A + 行列B
	//結果格納用行列の形を決定
	Matrix2_Initialize( &Matrix_Result , Matrix2_GetRows( Matrix_A ) , Matrix2_GetColumns( Matrix_A ) );
	//加算
	//計算ができたら結果を表示
	if( Matrix2_Sum( Matrix_A , Matrix_B , &Matrix_Result ) )
	{
		printf( "A+B\n" );
		Matrix2_DrawAllElements( Matrix_Result );
	}
	//できなかったらエラーメッセージを表示
	else
	{
		printf( "A+B は失敗しました\n" );
	}
	//成分の格納領域を破棄
	Matrix2_Finalize( &Matrix_Result );
	printf( "\n" );

	//行列A - 行列B
	//結果格納用行列の形を決定
	Matrix2_Initialize( &Matrix_Result , Matrix2_GetRows( Matrix_A ) , Matrix2_GetColumns( Matrix_A ) );
	//減算
	//計算ができたら結果を表示
	if( Matrix2_Sub( Matrix_A , Matrix_B , &Matrix_Result ) )
	{
		printf( "A-B\n" );
		Matrix2_DrawAllElements( Matrix_Result );
	}
	//できなかったらエラーメッセージを表示
	else
	{
		printf( "A-B は失敗しました\n" );
	}
	//成分の格納領域を破棄
	Matrix2_Finalize( &Matrix_Result );
	printf( "\n" );

	//行列A * 行列B
	//結果格納用行列の形を決定
	Matrix2_Initialize( &Matrix_Result , Matrix2_GetRows( Matrix_A ) , Matrix2_GetColumns( Matrix_A ) );
	//乗算
	//計算ができたら結果を表示
	if( Matrix2_Mul( Matrix_A , Matrix_B , &Matrix_Result ) )
	{
		printf( "A*B\n" );
		Matrix2_DrawAllElements( Matrix_Result );
	}
	//できなかったらエラーメッセージを表示
	else
	{
		printf( "A*B は失敗しました\n" );
	}
	//成分の格納領域を破棄
	Matrix2_Finalize( &Matrix_Result );
	printf( "\n" );

	//行列A / 行列B
	//結果格納用行列の形を決定
	Matrix2_Initialize( &Matrix_Result , Matrix2_GetRows( Matrix_A ) , Matrix2_GetColumns( Matrix_A ) );
	//除算
	//計算ができたら結果を表示
	if( Matrix2_Div( Matrix_A , Matrix_B , &Matrix_Result ) )
	{
		printf( "A/B\n" );
		Matrix2_DrawAllElements( Matrix_Result );
	}
	//できなかったらエラーメッセージを表示
	else
	{
		printf( "A/B は失敗しました。\n" );
	}
	//成分の格納領域を破棄
	Matrix2_Finalize( &Matrix_Result );
	printf( "\n" );

	//LU分解をする
	//分解後の行列を宣言
	Matrix_t Matrix_L;
	Matrix2_Initialize( &Matrix_L , Matrix2_GetRows( Matrix_A ) , Matrix2_GetColumns( Matrix_A ) ); 
	Matrix_t Matrix_U;
	Matrix2_Initialize( &Matrix_U , Matrix2_GetRows( Matrix_A ) , Matrix2_GetColumns( Matrix_A ) );
	//LU分解
	//LU分解ができたら結果を表示
	if( Matrix2_LUDecomposition( Matrix_A , &Matrix_L , &Matrix_U ) )
	{
		printf( "A=LU" );
		printf( "MatrixA\n" );	Matrix2_DrawAllElements( Matrix_A );
		printf( "MatrixL\n" );	Matrix2_DrawAllElements( Matrix_L );
		printf( "MatrixU\n" );	Matrix2_DrawAllElements( Matrix_U );
	}
	//できなかったらエラーメッセージを表示
	else
	{
		printf( "LU分解　は失敗しました" );
	}
	//成分の格納領域を破棄
	Matrix2_Finalize( &Matrix_L );
	Matrix2_Finalize( &Matrix_U );
	printf( "\n" );


	system("pause");

	//行列Aの終了処理
	Matrix2_Finalize( &Matrix_A );

	return (0);
}