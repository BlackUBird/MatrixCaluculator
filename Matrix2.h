#ifndef MATRIX2_H
#define MATRIX2_H

typedef struct
{
	double** Elements;	//成分
	int Rows;	//行数
	int Columns;	//列数
} Matrix_t;

//初期化
void Matrix2_Initialize( Matrix_t* Matrix , int Rows , int Columns);

//取得用
//成分
double Matrix2_GetElement( Matrix_t Matrix , int posRow , int posColumn );
//列数
int Matrix2_GetColumns( Matrix_t Matrix );
//行数
int Matrix2_GetRows( Matrix_t Matrix );

//設定用
//成分
double Matrix2_SetElement( Matrix_t* Matrix , int posRow , int posColumn , double newElement );

//描画
//全ての成分
void Matrix2_DrawAllElements( Matrix_t Matrix );
//行数
void Matrix2_DrawRows( Matrix_t Matrix );
//列数
void Matrix2_DrawColumns( Matrix_t Matrix );

//演算
//加算
bool Matrix2_Sum( Matrix_t FirstMatrix , Matrix_t SecondMatrix , Matrix_t* ResultMatrix );
//減算
bool Matrix2_Sub( Matrix_t FirstMatrix , Matrix_t SecondMatrix , Matrix_t* ResultMatrix );
//乗算
bool Matrix2_Mul( Matrix_t FirstMatrix , Matrix_t SecondMatrix , Matrix_t* ResultMatrix );
//除算
bool Matrix2_Div( Matrix_t FirstMatrix , Matrix_t SecondMatrix , Matrix_t* ResultMatrix );
//LU分解をする
bool Matrix2_LUDecomposition( Matrix_t Matrix , Matrix_t* LMatrix , Matrix_t* UMatrix );

//終了処理
void Matrix2_Finalize( Matrix_t* Matrix );

#endif