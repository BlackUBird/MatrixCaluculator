#include <stdio.h>
#include <stdlib.h>
#include "Matrix2.h"

//������
void Matrix2_Initialize( Matrix_t* Matrix , int Rows , int Columns)
{
	//�s���A�񐔂��Z�b�g
	Matrix->Rows = Rows;
	Matrix->Columns = Columns;

	//2�����f�[�^�̊i�[����m�肷��
	//�^���I��2�����z��̓��I���蓖�Ă��s��
	Matrix->Elements = (double**)calloc( Rows , sizeof(double*) );
	for( int i = 0 ; i < Rows ; i++ )
	{
		Matrix->Elements[i] = (double*)calloc( Columns , sizeof(double) );
	}
}

//�擾�p
//�v�f
double Matrix2_GetElement( Matrix_t Matrix , int posRow , int posColumn )
{
	return (Matrix.Elements[posRow][posColumn]);
}
//��
int Matrix2_GetColumns( Matrix_t Matrix )
{
	return (Matrix.Columns);
}
//�s��
int Matrix2_GetRows( Matrix_t Matrix )
{
	return (Matrix.Rows);
}

//�ݒ�p
//�v�f
double Matrix2_SetElement( Matrix_t* Matrix , int posRow , int posColumn , double newElement )
{
	Matrix->Elements[posRow][posColumn] = newElement;

	//�V���������̂�Ԃ�
	return (Matrix->Elements[posRow][posColumn]);
}

//�`��
//�S�Ă̗v�f
void Matrix2_DrawAllElements( Matrix_t Matrix )
{
	//�`��
	//�s�����܂Ń��[�v
	for( int i = 0 ; i < Matrix.Rows ; i++ )
	{
		//�񐔕��܂Ń��[�v
		for( int j = 0 ; j < Matrix.Columns ; j++ )
		{
			printf( "%10.4lf" , Matrix.Elements[i][j] ); 
		}
		printf( "\n" );
	}
}
//�s��
void Matrix2_DrawRows( Matrix_t Matrix )
{
	printf( "%d\n" , Matrix.Rows );
}
//��
void Matrix2_DrawColumns( Matrix_t Matrix )
{
	printf( "%d\n" , Matrix.Columns );
}

//���Z
//���Z
bool Matrix2_Sum( Matrix_t FirstMatrix , Matrix_t SecondMatrix , Matrix_t* ResultMatrix )
{
	//1�ڂ�2�ڍs��̃T�C�Y����v���Ă���Ή��Z������
	if( FirstMatrix.Rows == SecondMatrix.Rows && FirstMatrix.Columns == SecondMatrix.Columns )
	{
		//�s�����܂Ń��[�v
		for( int i = 0 ; i < FirstMatrix.Rows ; i++ )
		{
			//�񐔕��܂Ń��[�v
			for( int j = 0 ; j < FirstMatrix.Columns ; j++ )
			{
				ResultMatrix->Elements[i][j] = FirstMatrix.Elements[i][j] + SecondMatrix.Elements[i][j];
			}
		}
		//���Z��true��Ԃ�
		return (true);
	}
	//�قȂ��false��Ԃ�
	else
	{
		return (false);
	}
}
//���Z
bool Matrix2_Sub( Matrix_t FirstMatrix , Matrix_t SecondMatrix , Matrix_t* ResultMatrix )
{
	//1�ڂ�2�ڍs��̃T�C�Y����v���Ă���Ό��Z������
	if( FirstMatrix.Rows == SecondMatrix.Rows && FirstMatrix.Columns == SecondMatrix.Columns )
	{
		//�s�����܂Ń��[�v
		for( int i = 0 ; i < FirstMatrix.Rows ; i++ )
		{
			//�񐔕��܂Ń��[�v
			for( int j = 0 ; j < FirstMatrix.Columns ; j++ )
			{
				ResultMatrix->Elements[i][j] = FirstMatrix.Elements[i][j] - SecondMatrix.Elements[i][j];
			}
		}
		//���Z��true��Ԃ�
		return (true);
	}
	//�قȂ��false��Ԃ�
	else
	{
		return (false);
	}
}
//��Z
bool Matrix2_Mul( Matrix_t FirstMatrix , Matrix_t SecondMatrix , Matrix_t* ResultMatrix )
{
	//1�ڍs��̗񐔂�2�ڂ̍s��̍s������v���Ă���Ώ�Z������
	if( FirstMatrix.Rows == SecondMatrix.Rows && FirstMatrix.Columns == SecondMatrix.Columns )
	{
		//1�ڂ̍s��̍s�����܂Ń��[�v
		for( int i = 0 ; i < FirstMatrix.Rows ; i++ )
		{
			//2�ڂ̍s��̗񐔕��܂Ń��[�v
			for( int j = 0 ; j < SecondMatrix.Columns ; j++ )
			{
				//1�ڍs��̗�(2�ڂ̍s��̍s���ł���)���܂Ń��[�v
				for( int k = 0 ; k < FirstMatrix.Columns ; k++ )
				{
					ResultMatrix->Elements[i][j] += FirstMatrix.Elements[i][k] * SecondMatrix.Elements[k][j];
				}
			}
		}
		//��Z��true��Ԃ�
		return (true);
	}
	//�قȂ��false��Ԃ�
	else
	{
		return (false);
	}
}
//���Z
bool Matrix2_Div( Matrix_t FirstMatrix , Matrix_t SecondMatrix , Matrix_t* ResultMatrix )
{
	//1�ڍs��̗񐔂�2�ڂ̍s��̍s������v���Ă���Ώ�Z������
	if( FirstMatrix.Rows == SecondMatrix.Rows && FirstMatrix.Columns == SecondMatrix.Columns )
	{
		//1�ڂ̍s��̍s�����܂Ń��[�v
		for( int i = 0 ; i < FirstMatrix.Rows ; i++ )
		{
			//2�ڂ̍s��̗񐔕��܂Ń��[�v
			for( int j = 0 ; j < SecondMatrix.Columns ; j++ )
			{
				//1�ڍs��̗�(2�ڂ̍s��̍s���ł���)���܂Ń��[�v
				for( int k = 0 ; k < FirstMatrix.Columns ; k++ )
				{
					ResultMatrix->Elements[i][j] += FirstMatrix.Elements[i][k] / SecondMatrix.Elements[k][j];
				}
			}
		}
		//��Z��true��Ԃ�
		return (true);
	}
	//�قȂ��false��Ԃ�
	else
	{
		return (false);
	}
}
//LU����������
bool Matrix2_LUDecomposition( Matrix_t Matrix , Matrix_t* LMatrix , Matrix_t* UMatrix )
{
	//���������s��̍s�������[�v����
	for( int i = 0 ; i < Matrix.Rows ; i++ )
	{
		//�s��L�̑Ίp������1�ɂ���
		LMatrix->Elements[i][i] = 1.0;

		//�s��U�̑Ίp�������v�Z����
		UMatrix->Elements[i][i] = Matrix.Elements[i][i];
		for( int k = 0 ; k < i ; k++ )
		{
			UMatrix->Elements[i][i] -= LMatrix->Elements[i][k] * UMatrix->Elements[k][i];
		}

		//���������s��̗񐔕����[�v����
		for( int j = i+1 ; j < Matrix.Columns ; j++ )
		{
			//�s��L��(j,i)�������v�Z
			LMatrix->Elements[j][i] = Matrix.Elements[j][i];
			for( int k = 0 ; k < i ; k++ )
			{
				LMatrix->Elements[j][i] -= LMatrix->Elements[j][k] * UMatrix->Elements[k][i];
			}
			LMatrix->Elements[j][i] /= UMatrix->Elements[i][i];

			//U��(j,i)�������X�V
			UMatrix->Elements[j][i] = 0.0;

			//L��(i,j)�������X�V
			LMatrix->Elements[i][j] = 0.0;

			//U��(i,j)�������X�V
			UMatrix->Elements[i][j] = Matrix.Elements[i][j];
			for( int k = 0 ; k < i ; k++ )
			{
				UMatrix->Elements[i][j] -= LMatrix->Elements[i][k] * UMatrix->Elements[k][j];
			}
		}
	}

	return (true);
}

//�K�E�X�̏����@
int Matrix2_GaussianElimination( Matrix_t CoefficientMatrix ,
								 Matrix_t* X_VectorMatrix , 
								 Matrix_t VectorMatrix )
{
	//�W���s�����O�p�s��ɂ������̂��i�[
	Matrix_t CffcMatrix;
	Matrix2_Initialize( &CffcMatrix , CoefficientMatrix.Rows , CoefficientMatrix.Columns );
	//�O�i�������̃x�N�g�����i�[
	Matrix_t VctrMatrix;
	Matrix2_Initialize( &VctrMatrix , VectorMatrix.Rows , VectorMatrix.Columns );

	//�\��
	printf( "�O�i�����O�̌W���s��\n" );
	Matrix2_DrawAllElements( CffcMatrix );
	printf( "�O�i�����O�̉��̃x�N�g��\n" );
	Matrix2_DrawAllElements( VctrMatrix );

	//�O�i����
	printf("�O�i����:%d\n" ,Matrix2_ForwardElimination( CoefficientMatrix , VectorMatrix , &CffcMatrix , &VctrMatrix ) );
	//�\��
	printf( "�O�i������̌W���s��\n" );
	Matrix2_DrawAllElements( CffcMatrix );
	printf( "�O�i������̉��̃x�N�g��\n" );
	Matrix2_DrawAllElements( VctrMatrix );

	//�����
	Matrix2_BackSubstitution( CffcMatrix , X_VectorMatrix , VctrMatrix );

	return (1);
}
//�O�i����
int Matrix2_ForwardElimination( Matrix_t CoefficientMatrix ,
								Matrix_t VectorMatrix ,
								Matrix_t* ResultCffcMatrix , 
								Matrix_t* ResultVctrMatrix )
{
	//�ԋp�l(�ő僋�[�v��)
	int cnt = 0;

	//�W���s��̌��ʊi�[�p�s���������
	*ResultCffcMatrix = CoefficientMatrix;
	//���̃x�N�g���̌��ʊi�[�p�s���������
	*ResultVctrMatrix = VectorMatrix;

	//�W���s��̑Ίp�����̐��������[�v
	for( int k = 0 ; k < CoefficientMatrix.Rows ; k++ )
	{
		//�Ίp�����̉�����̈�ԉ��܂Ń��[�v
		for( int i = k+1 ; i < CoefficientMatrix.Rows ; i++ )
		{
			//���݂̍s�̐����ɂ�����W�����v�Z
			double cffc = CoefficientMatrix.Elements[i][k] / CoefficientMatrix.Elements[k][k];

			//�����Z�����Ă���
			//�Ίp�s�񂩂獶�[�܂Ń��[�v
			for( int j = k ; j < CoefficientMatrix.Columns ; j++ )
			{
				//�W���s����v�Z
				ResultCffcMatrix->Elements[i][j] = CoefficientMatrix.Elements[i][j] - cffc * CoefficientMatrix.Elements[k][j];
				//�J�E���g+1
				cnt++;
			}

			//���̃x�N�g�����v�Z
			ResultVctrMatrix->Elements[i][0] = VectorMatrix.Elements[i][0] - cffc * VectorMatrix.Elements[k][0];
		}
	}

	return (cnt);
}
//�����
int Matrix2_BackSubstitution( Matrix_t CoefficientMatrix ,
							  Matrix_t* X_VectorMatrix , 
							  Matrix_t VectorMatrix )
{
	//�ԋp�l(�ő僋�[�v��)
	int cnt = 0;

	//���̐��������[�v(�t��)
	for( int i = VectorMatrix.Rows - 1 ; i >= 0 ; i-- )
	{
		//����ɂȂ郂�m���v�Z����
		double denominator = VectorMatrix.Elements[i][0];
		//�W���s��̉E�[�̐�������Ίp�����܂Ń��[�v
		for( int j = CoefficientMatrix.Columns - 1 ; j > i ; j-- )
		{
			denominator -= X_VectorMatrix->Elements[j][0] * CoefficientMatrix.Elements[i][j];
			//���[�v�񐔂��L��
			cnt++;
		}
		//�l���m��
		X_VectorMatrix->Elements[i][0] = denominator / CoefficientMatrix.Elements[i][i];
	}

	return (cnt);
}


//�I������
void Matrix2_Finalize( Matrix_t* Matrix )
{
	for( int i = 0 ; i < Matrix->Rows ; i++ )
	{
		free( Matrix->Elements[i] );
	}
	free( Matrix->Elements );
}