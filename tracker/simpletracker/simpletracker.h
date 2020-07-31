// Nya tracker
// 

#ifndef _SIMPLETRACKER_H
#define _SIMPLETRACKER_H

#include "tracker.h"

namespace NyaTracker {

	// Слабенький трекер для построения поля векторов типичных перемещений в кадре
	class SimpleTracker : public Tracker {
		
	public:
		// Трекируем объекты
		// in:  детектируемые объекты
		// out: трекированные объекты
		virtual std::vector<std::shared_ptr<Object>> Process(std::vector<std::shared_ptr<Object>> & objects);
		
	protected:
		// Функция сопоставления
		virtual void compare(std::vector<std::shared_ptr<Object>> & objects);
		// Удаление старых
		virtual void removeOld();
		// Добавление новых
		virtual void addNew();
	};
	
};

#endif
