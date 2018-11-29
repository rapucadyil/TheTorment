#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
private:

public:

	Character();
	~Character() {}

	virtual void tick();
	virtual void draw();
};

#endif