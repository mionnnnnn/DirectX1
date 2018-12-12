#include "Timer.h"

Timer::Timer() {
	_time = 0;
}
Timer::~Timer() {

}

void Timer::Start() {
	_time = 0;
}

void Timer::Update() {
	_time++;
}

void Timer::Draw() {
	std::string label = "TIME : " + std::to_string(_time / 60);
	DrawString(500, 27, label.c_str(), GetColor(255, 255, 255));
}

bool Timer::TimeCheck() {
	if (_time > 120) {
		return true;
	}
	return false;
}