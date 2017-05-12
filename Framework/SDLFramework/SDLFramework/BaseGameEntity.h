#pragma once
#include "Vector2D.h"
#include "FWApplication.h"

class BaseGameEntity
{
private:

	//unieke id van het object.
	const int m_ID;
	bool m_tag;
	static int m_iNextValidId;

	//Verhoog met 1 na instellen van id.
	void setId();
protected:
	Vector2D  m_position;
	int m_width;
	int m_height;
	SDL_Texture* m_texture;
public:
	BaseGameEntity(double x, double y, int width, int height);
	~BaseGameEntity();
	virtual void update(double deltaTime) = 0;
	const int getID();
	const bool getTag();
	void setTag(const bool);
	virtual void draw();
	int getWidth();
	int getHeight();
	void setPosition(Vector2D);
	void setX(double);
	void setY(double);
	Vector2D& getPosition();
	Vector2D getConstPosition() const;
};