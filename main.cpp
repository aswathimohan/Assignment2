#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;
int modify(int *vec,int c);
int * String(int const * src, size_t len);
const int len = 150;
double eval(int *pj);
int modify(int *vec,int c);
int * String(int const * src, size_t len);

int main()
{
	int vec[150] = {0};
	int *sbest, *snew;
	double fbest = 0, fnew = 0;
	sbest = String(vec, 150);
	fbest = eval(sbest);
	for( int i = 1; i <150; i++)
	{
		modify(sbest, i);
		snew = String(sbest, 150);
		for(int a =0; a<150; a++){
			cout<<snew[a]<<endl;
		}
		fnew = eval(snew);
		cout<<fnew<<endl;
		if (fnew > fbest)
		{
			fbest = fnew;
			sbest = String(snew, 150);
		}
	}
	cout << "Best Fitness :" << fbest << endl;
	cout << "String :" << endl;
	for(int k = 0; k < 150; k++){
		cout << sbest[k];
	}
}

int modify(int *vec,int count )
{
	for( int i = 0; i < count; i++)
	{
		if (i%4== 0)
		{
		 vec[i+2] = 1;
		 
		}
		else{
		 vec[149-i] = 1;
		}
		
	}
}


int * String(int const * s, size_t len)
{
	int * p = (int*) malloc(len * sizeof(int));
	memcpy(p, s, len * sizeof(int));
	return p;
}
