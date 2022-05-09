#ifndef MATRIX2_H
#define MATRIX2_H

typedef struct
{
	double** Elements;	//����
	int Rows;	//�s��
	int Columns;	//��
} Matrix_t;

//������
void Matrix2_Initialize( Matrix_t* Matrix , int Rows , int Columns);

//�擾�p
//����
double Matrix2_GetElement( Matrix_t Matrix , int posRow , int posColumn );
//��
int Matrix2_GetColumns( Matrix_t Matrix );
//�s��
int Matrix2_GetRows( Matrix_t Matrix );

//�ݒ�p
//����
double Matrix2_SetElement( Matrix_t* Matrix , int posRow , int posColumn , double newElement );

//�`��
//�S�Ă̐���
void Matrix2_DrawAllElements( Matrix_t Matrix );
//�s��
void Matrix2_DrawRows( Matrix_t Matrix );
//��
void Matrix2_DrawColumns( Matrix_t Matrix );

//���Z
//���Z
bool Matrix2_Sum( Matrix_t FirstMatrix , Matrix_t SecondMatrix , Matrix_t* ResultMatrix );
//���Z
bool Matrix2_Sub( Matrix_t FirstMatrix , Matrix_t SecondMatrix , Matrix_t* ResultMatrix );
//��Z
bool Matrix2_Mul( Matrix_t FirstMatrix , Matrix_t SecondMatrix , Matrix_t* ResultMatrix );
//���Z
bool Matrix2_Div( Matrix_t FirstMatrix , Matrix_t SecondMatrix , Matrix_t* ResultMatrix );
//LU����������
bool Matrix2_LUDecomposition( Matrix_t Matrix , Matrix_t* LMatrix , Matrix_t* UMatrix );

//�I������
void Matrix2_Finalize( Matrix_t* Matrix );

#endif