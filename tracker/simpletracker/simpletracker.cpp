
#include "simpletracker.h"

using namespace NyaTracker;

std::vector<std::shared_ptr<Object>> SimpleTracker::Process(std::vector<std::shared_ptr<Object>> & objects) {
	// Этапы трекирования:
	// 1. Сопоставляем с объектами в памяти
	this->compare(objects);
	
	// 2. Удаляем несопоставившиеся
	this->removeOld();
	
	// 3. Добавим новые
	this->addNew();
	
	// Особенности: в мясополосе не трекируем. Если квадратиков в зоне много, все помечаем как бракованные.
	// Трекируем только надёжные перемещения, когда рядом ничего нет.
	
	// Создаём результат с трекируемыми объектами
	std::vector<std::shared_ptr<Object>> list;
	return std::move(list);
}

// Функция сопоставления
void SimpleTracker::compare(std::vector<std::shared_ptr<Object>> & objects) {
	
}

// Удаление старых
void SimpleTracker::removeOld() {
	
}

// Добавление новых
void SimpleTracker::addNew() {
	
}
