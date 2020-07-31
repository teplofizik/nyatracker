
#include "map.h"

using namespace NyaTracker;

Map::Map(int Cols, int Rows) : Cols(Cols), Rows(Rows) {
	this->Data = std::make_unique<float[]>(Cols * Rows);
}
