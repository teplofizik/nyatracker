// Nya tracker
// 

#ifndef _TRACKER_H
#define _TRACKER_H

#include "object.h"

#include <vector>
#include <memory>

namespace NyaTracker {

	// Базовый класс для трекеров
	// Tracker:
	//   SimpleTracker => слабенький трекер для построения поля векторов типичных перемещений в кадре, автонастройки матрицы проекции и т.д.
	class Tracker {
		
	public:
		// Трекируем объекты
		// in:  детектируемые объекты
		// out: трекированные объекты
		virtual std::vector<std::shared_ptr<Object>> Process(std::vector<std::shared_ptr<Object>> objects) = 0;
	};
	
};

#endif
