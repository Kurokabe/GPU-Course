#pragma once
/*--------------------------------------*\
|*
 Public
 *|
 \*-------------------------------------*/
class DataCreator
    {
	/*--------------------------------------*\
|*
	 Constructor
	 *|
	 \*-------------------------------------*/
    public:
	DataCreator(int dataMax);
	virtual ~DataCreator(void);
	/*--------------------------------------*\
|*
	 Methodes
	 *|
	 \*-------------------------------------*/
    public:
	/**
	 * in [0,255]
	 */
	int* getTabData();
	void print();
	int getLength();
    private:
	void createDataTriangulaire();
	void melangerData();
	void swap(int i, int j);
	/*--------------------------------------*\
|*
	 Attributs
	 *|
	 \*-------------------------------------*/
    private:
// Inputs
	int dataMax;
// Tools
	int n;
	int nbMelange;
// Outputs
	int *tabData;
    };
/*----------------------------------------------------------------------*\
|*
 End
 *|
 \*---------------------------------------------------------------------*/
