#pragma once
#include "Cell.h"
#include"List.h"
#include "Camera.h"


class Grid
{
public:
	List<Cell*>* GetCells();
	List<int> getInxInCamera();
	void checkCellColitionCamera(Camera *camera);
	void Init(string gridPath);

	Grid();
	~Grid();

private:
	List<Cell*>* CellList;
	List <int> inxInCamara;


};

