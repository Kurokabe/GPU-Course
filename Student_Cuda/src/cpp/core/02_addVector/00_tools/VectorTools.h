
#pragma once

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/


class VectorTools
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/


	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	static bool isAddVector_Ok(float* ptrV1, float* ptrV2, float* ptrW, int n);

	static float* createV1(int n);
	static float* createV2(int n);

	static void print(float* ptrV, int n);

    private:

	static void addVectorCPU(float* ptrV1, float* ptrV2, float* ptrW, int n);

	static bool isEquals(float* ptrV1, float* ptrV2, int n, float epsilon);


	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/


    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/
