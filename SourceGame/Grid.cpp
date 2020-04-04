#include"Grid.h"
#include"Collision.h"


List<Cell*>* Grid::GetCells()
{
	return CellList;
}

List<int> Grid::getInxInCamera()
{
	return inxInCamara;
}

void Grid::checkCellColitionCamera(Camera*camera)
{
	if(inxInCamara.Count>0)
		inxInCamara.Clear();

	for (int i = 0; i < CellList->Count; i++) {
		if (Collision::AABBCheck(camera, CellList->at(i))) {
			List<int> temp = CellList->at(i)->getInxObjects();
			for (int j = 0; j < temp.Count; j++) {
				inxInCamara._Add(temp[j]);
			}
			temp.Clear();
		}
  }
}

void Grid::Init(string gridPath)
{
	ifstream fs(gridPath);

	int count;
	fs >> count;
	ignoreLineIfstream(fs, 1);
	int x, y, with, countObj;
	for (int i = 0; i < count; i++) {
		Cell  *cell = new Cell();
		fs >> x >> y >> with >> with>> countObj;
		cell->setX(x);
		cell->setY(y);
		cell->setHeight(with);
		cell->setWidth(with);
		if (countObj > 0) {
			List<int> inxObjList;
			for (int j = 0; j < countObj; j++) {
				int index;
				fs >> index;
				inxObjList._Add(index);

			}
			cell->setInxObjects(inxObjList);
		}
		CellList->_Add(cell);
		ignoreLineIfstream(fs, 1);
		
	}

}



Grid::Grid()
{
	CellList = new List<Cell*>();
}

Grid::~Grid()
{
}