// Nya tracker
// 

#include <memory>

#ifndef _MAP_H
#define _MAP_H

namespace NyaTracker {

	// Карта признаков
	class Map {
		
	public:
		Map(int Cols, int Rows);
		
	protected:
		int Cols;
		int Rows;
		
		std::unique_ptr<float[]> Data;
		
		void erase();
	};
};

#endif
