#ifndef MATRIX2_H
#define MATRIX2_H

typedef struct
{
	double** Elements;	//¬•ª
	int Rows;	//s”
	int Columns;	//—ñ”
} Matrix_t;

//‰Šú‰»
void Matrix2_Initialize( Matrix_t* Matrix , int Rows , int Columns);

//æ“¾—p
//¬•ª
double Matrix2_GetElement( Matrix_t Matrix , int posRow , int posColumn );
//—ñ”
int Matrix2_GetColumns( Matrix_t Matrix );
//s”
int Matrix2_GetRows( Matrix_t Matrix );

//İ’è—p
//¬•ª
double Matrix2_SetElement( Matrix_t* Matrix , int posRow , int posColumn , double newElement );

//•`‰æ
//‘S‚Ä‚Ì¬•ª
void Matrix2_DrawAllElements( Matrix_t Matrix );
//s”
void Matrix2_DrawRows( Matrix_t Matrix );
//—ñ”
void Matrix2_DrawColumns( Matrix_t Matrix );

//‰‰Z
//‰ÁZ
bool Matrix2_Sum( Matrix_t FirstMatrix , Matrix_t SecondMatrix , Matrix_t* ResultMatrix );
//Œ¸Z
bool Matrix2_Sub( Matrix_t FirstMatrix , Matrix_t SecondMatrix , Matrix_t* ResultMatrix );
//æZ
bool Matrix2_Mul( Matrix_t FirstMatrix , Matrix_t SecondMatrix , Matrix_t* ResultMatrix );
//œZ
bool Matrix2_Div( Matrix_t FirstMatrix , Matrix_t SecondMatrix , Matrix_t* ResultMatrix );
//LU•ª‰ğ‚ğ‚·‚é
bool Matrix2_LUDecomposition( Matrix_t Matrix , Matrix_t* LMatrix , Matrix_t* UMatrix );

//I—¹ˆ—
void Matrix2_Finalize( Matrix_t* Matrix );

#endif