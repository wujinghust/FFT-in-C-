#include"fft.h"
#include<vector>
#include<iostream>
#include<fstream>

#define Num 16384

int main()
{
	double Init_Data[Num]={0};
	int Length=Num,i=0;
	char *out="out.txt";
	char *in="input.txt";
	//FILE *output,*input;
	double  Result_Data[Num]={0};
	//for (int i = 0; i < Num; i++)
	//	Init_Data[i]=3*sin(i*2*PI*50/128)+5*sin(i*2*PI*30/128);

	ifstream fin(in);
	ofstream fout(out);

	do
	{
		fin >>  Init_Data[i++];
		double tmp=0;
	} while (i<Num);

	FFT Result=FFT(Init_Data,Length);
	Result.iterative_fft();
	Result.output(Result_Data);
	
	fout << "FFT:    ===========================" <<endl;
	 for (int i = 0; i < Num; i ++)
        {
			fout << Result_Data[i] << "   ";
        }
	 fin.close();
	 fout.close();
	 return 0;
}