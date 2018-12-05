#include "Score.h"

Score::Score() {
	_score = 0;
}

Score::~Score()
{}

void Score::Start() {
	_score = 0;
}

void Score::Update() {

}

void Score::Draw() {
	std::string label = "SCORE : " + std::to_string(_score);
	DrawString(500, 0, label.c_str(), GetColor(255, 255, 255));
}

void Score::AddScore() {
	_score += 10;
}