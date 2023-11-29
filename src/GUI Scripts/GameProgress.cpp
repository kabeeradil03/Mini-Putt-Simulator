#include "GUI.h"

int coursesUnlocked;

//maybe??
int equipmentUnlocked;

int course1Stars;
int course2Stars;
int course3Stars;

GameProgress::GameProgress() {
	coursesUnlocked = 1;
	equipmentUnlocked = 1;
	course1Stars = 0;
	course2Stars = 0;
	course3Stars = 0;
}

//returns number of stars to display & changes internal score
//also unlocks next level if applicable (need at least one star)
int GameProgress::checkScore(int numShots, int courseNum) {
	//get scoring system from Arjun
	if (numShots == 1) {
		if (courseNum == 1) {
			course1Stars = 3;
			if (coursesUnlocked == 1) {
				coursesUnlocked = 2;
			}
		}
		else if (courseNum == 2) {
			course2Stars = 3;
			if (coursesUnlocked == 2) {
				coursesUnlocked = 3;
			}
		}
		else {
			course3Stars = 3;
		}
		return 3;
	}
	else if (numShots > 1 && numShots <= 3) {
		if (courseNum == 1) {
			if (course1Stars < 2) {
				course1Stars = 2;
			}
			if (coursesUnlocked == 1) {
				coursesUnlocked = 2;
			}
		}
		else if (courseNum == 2) {
			if (course2Stars < 2) {
				course2Stars = 2;
			}
			if (coursesUnlocked == 2) {
				coursesUnlocked = 3;
			}
		}
		else {
			if (course3Stars < 2) {
				course3Stars = 2;
			}
		}
		return 2;
	}
	else if (numShots > 3 && numShots <= 5) {
		if (courseNum == 1) {
			if (course1Stars < 1) {
				course1Stars = 1;
			}
			if (coursesUnlocked == 1) {
				coursesUnlocked = 2;
			}
		}
		else if (courseNum == 2) {
			if (course2Stars < 1) {
				course2Stars = 1;
			}
			if (coursesUnlocked == 2) {
				coursesUnlocked = 3;
			}
		}
		else {
			if (course3Stars < 1) {
				course3Stars = 1;
			}
		}
		return 1;
	}
	else {
		return 0;
	}
}

//accessors
int GameProgress::getAmtCourses() {
	return coursesUnlocked;
}

int GameProgress::getAmtEquipment() {
	return equipmentUnlocked;
}

int GameProgress::getAmtC1() {
	return course1Stars;
}

int GameProgress::getAmtC2() {
	return course2Stars;
}

int GameProgress::getAmtC3() {
	return course3Stars;
}
