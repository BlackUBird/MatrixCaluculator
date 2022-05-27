#include <stdio.h>
#include <stdlib.h>
#include "Matrix2.h"

int main(void)
{
	////�s�������
	//int rows;
	//printf( "�s��:" );	scanf_s( "%d" , &rows );
	////�񐔂����
	//int columns;
	//printf( "��:" );	scanf_s( "%d" , &columns);

	////�s��A��錾
	//Matrix_t Matrix_A;
	//Matrix2_Initialize( &Matrix_A , rows , columns );

	////�s��B��錾
	//Matrix_t Matrix_B;
	//Matrix2_Initialize( &Matrix_B , rows , columns );

	////�s��A��`��
	//printf( "MatrixA\n" );
	//Matrix2_DrawAllElements( Matrix_A );
	//printf( "\n" );

	////�s��B��`��
	//printf( "MatrixB\n" );
	//Matrix2_DrawAllElements( Matrix_B );
	//printf( "\n" );

	////�s��A�̐�����ݒ�(���ł�B��)
	////�s��A�̍s�������[�v
	//for( int i = 0 ; i < Matrix2_GetRows( Matrix_A ) ; i++ )
	//{
	//	//�s��A�̗񐔕����[�v
	//	for( int j = 0 ; j < Matrix2_GetColumns( Matrix_A ) ; j++ )
	//	{
	//		//�������l�����
	//		double newElement;
	//		printf( "(%d,%d):" , i , j );	scanf_s( "%lf" , &newElement );

	//		//�X�V
	//		Matrix2_SetElement( &Matrix_A , i , j , newElement );
	//		Matrix2_SetElement( &Matrix_B , i , j , 20.0 - newElement );
	//	}
	//}

	////�ēx�s��A��\��
	//printf( "MatrixA\n" );
	//Matrix2_DrawAllElements( Matrix_A );
	//printf( "\n" );
	//
	////�ēx�s��B��\��
	//printf( "MatrixB\n" );
	//Matrix2_DrawAllElements( Matrix_B );
	//printf( "\n" );

	////���Z
	////���ʊi�[�p
	//Matrix_t Matrix_Result;
	//
	////�s��A + �s��B
	////���ʊi�[�p�s��̌`������
	//Matrix2_Initialize( &Matrix_Result , Matrix2_GetRows( Matrix_A ) , Matrix2_GetColumns( Matrix_A ) );
	////���Z
	////�v�Z���ł����猋�ʂ�\��
	//if( Matrix2_Sum( Matrix_A , Matrix_B , &Matrix_Result ) )
	//{
	//	printf( "A+B\n" );
	//	Matrix2_DrawAllElements( Matrix_Result );
	//}
	////�ł��Ȃ�������G���[���b�Z�[�W��\��
	//else
	//{
	//	printf( "A+B �͎��s���܂���\n" );
	//}
	////�����̊i�[�̈��j��
	//Matrix2_Finalize( &Matrix_Result );
	//printf( "\n" );

	////�s��A - �s��B
	////���ʊi�[�p�s��̌`������
	//Matrix2_Initialize( &Matrix_Result , Matrix2_GetRows( Matrix_A ) , Matrix2_GetColumns( Matrix_A ) );
	////���Z
	////�v�Z���ł����猋�ʂ�\��
	//if( Matrix2_Sub( Matrix_A , Matrix_B , &Matrix_Result ) )
	//{
	//	printf( "A-B\n" );
	//	Matrix2_DrawAllElements( Matrix_Result );
	//}
	////�ł��Ȃ�������G���[���b�Z�[�W��\��
	//else
	//{
	//	printf( "A-B �͎��s���܂���\n" );
	//}
	////�����̊i�[�̈��j��
	//Matrix2_Finalize( &Matrix_Result );
	//printf( "\n" );

	////�s��A * �s��B
	////���ʊi�[�p�s��̌`������
	//Matrix2_Initialize( &Matrix_Result , Matrix2_GetRows( Matrix_A ) , Matrix2_GetColumns( Matrix_A ) );
	////��Z
	////�v�Z���ł����猋�ʂ�\��
	//if( Matrix2_Mul( Matrix_A , Matrix_B , &Matrix_Result ) )
	//{
	//	printf( "A*B\n" );
	//	Matrix2_DrawAllElements( Matrix_Result );
	//}
	////�ł��Ȃ�������G���[���b�Z�[�W��\��
	//else
	//{
	//	printf( "A*B �͎��s���܂���\n" );
	//}
	////�����̊i�[�̈��j��
	//Matrix2_Finalize( &Matrix_Result );
	//printf( "\n" );

	////�s��A / �s��B
	////���ʊi�[�p�s��̌`������
	//Matrix2_Initialize( &Matrix_Result , Matrix2_GetRows( Matrix_A ) , Matrix2_GetColumns( Matrix_A ) );
	////���Z
	////�v�Z���ł����猋�ʂ�\��
	//if( Matrix2_Div( Matrix_A , Matrix_B , &Matrix_Result ) )
	//{
	//	printf( "A/B\n" );
	//	Matrix2_DrawAllElements( Matrix_Result );
	//}
	////�ł��Ȃ�������G���[���b�Z�[�W��\��
	//else
	//{
	//	printf( "A/B �͎��s���܂����B\n" );
	//}
	////�����̊i�[�̈��j��
	//Matrix2_Finalize( &Matrix_Result );
	//printf( "\n" );

	////LU����������
	////������̍s���錾
	//Matrix_t Matrix_L;
	//Matrix2_Initialize( &Matrix_L , Matrix2_GetRows( Matrix_A ) , Matrix2_GetColumns( Matrix_A ) ); 
	//Matrix_t Matrix_U;
	//Matrix2_Initialize( &Matrix_U , Matrix2_GetRows( Matrix_A ) , Matrix2_GetColumns( Matrix_A ) );
	////LU����
	////LU�������ł����猋�ʂ�\��
	//if( Matrix2_LUDecomposition( Matrix_A , &Matrix_L , &Matrix_U ) )
	//{
	//	printf( "A=LU" );
	//	printf( "MatrixA\n" );	Matrix2_DrawAllElements( Matrix_A );
	//	printf( "MatrixL\n" );	Matrix2_DrawAllElements( Matrix_L );
	//	printf( "MatrixU\n" );	Matrix2_DrawAllElements( Matrix_U );
	//}
	////�ł��Ȃ�������G���[���b�Z�[�W��\��
	//else
	//{
	//	printf( "LU�����@�͎��s���܂���" );
	//}
	////�����̊i�[�̈��j��
	//Matrix2_Finalize( &Matrix_L );
	//Matrix2_Finalize( &Matrix_U );
	//printf( "\n" );

	//�K�E�X�̏����@�ɂ��A��������������
	printf( "�K�E�X�̏����@�ɂ��A��������������\n" );
	//�s�������
	int order;
	printf( "���������:" );	scanf_s( "%d" , &order );
	//�W���s���錾
	Matrix_t Matrix_Cffc;
	Matrix2_Initialize( &Matrix_Cffc , order , order );
	//���̃x�N�g����錾
	Matrix_t Matrix_Vctr;
	Matrix2_Initialize( &Matrix_Vctr , order , 1 );
	//�W���s��̐�����ݒ�
	//�W���s��̍s�������[�v
	for( int i = 0 ; i < Matrix2_GetRows( Matrix_Cffc ) ; i++ )
	{
		//�s��A�̗񐔕����[�v
		for( int j = 0 ; j < Matrix2_GetColumns( Matrix_Cffc ) ; j++ )
		{
			//�������l�����
			double newElement;
			printf( "(%d,%d):" , i , j );	scanf_s( "%lf" , &newElement );

			//�X�V
			Matrix2_SetElement( &Matrix_Cffc , i , j , newElement );
		}
	}
	//���̃x�N�g���̐�����ݒ�
	//���̃x�N�g���̗v�f�������[�v
	for( int i = 0 ; i < Matrix2_GetRows( Matrix_Vctr ) ; i++ )
	{
		//�������l�����
		double newElement;
		printf( "[%d]:" , i );	scanf_s( "%lf" , &newElement );

		//�X�V
		Matrix2_SetElement( &Matrix_Vctr , i , 0 , newElement );
	}
	//�W���s���`��
	printf( "�W���s��\n" );
	Matrix2_DrawAllElements( Matrix_Cffc );
	printf( "\n" );
	//���̃x�N�g����`��
	printf( "���̃x�N�g��\n" );
	Matrix2_DrawAllElements( Matrix_Vctr );
	printf( "\n" );
	//�K�E�X�̏����@������
	//�v�Z��̉����i�[����x�N�g����錾
	Matrix_t resultVector;
	Matrix2_Initialize( &resultVector , order , 1 );
	//�\��
	printf( "�K�E�X�̏����@�O\n" );
	Matrix2_DrawAllElements( resultVector );
	//�v�Z
	Matrix2_GaussianElimination( Matrix_Cffc , &resultVector , Matrix_Vctr );
	//���ʂ�\��
	printf( "�K�E�X�̏����@��\n" );
	Matrix2_DrawAllElements( resultVector );



	system("pause");

	//�s��A�̏I������
	//Matrix2_Finalize( &Matrix_A );

	return (0);
}