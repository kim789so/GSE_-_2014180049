
#include "Define.h"
#define MAX_OBJECTS_COUNT 50

enum ObjectType {
	OBJECT_BUILDING,
	OBJECT_CHARACTER,
	OBJECT_BULLET,
	OBJECT_ARROW

};

enum TeamType{
	TEAM_RED,
	TEAM_BLUE
};
struct Pos
{
	float x, y, z;
	Pos() {};
	Pos(float newX, float newY, float newZ)
	{
		x = newX;
		y = newY;
		z = newZ;
	}
};




struct Color
{
	float r, g, b, a;
	Color() {};
	Color(float newR, float newG, float newB, float newA)
	{
		r = newR;
		g = newG;
		b = newB;
		a = newA;
	}
};


class CObject
{
public:
	void Init(TeamType teamType, ObjectType objType, Pos pos, float size, Color color);
	void Update(float time);

public:
	ObjectType GetObjType() { return m_objType; }
	Pos GetPos() { return m_pos; }
	float GetSize() { return m_size; }
	Color GetColor() { return m_color; }
	float GetLife() { return m_life; }
	float GetLifeTime() { return m_lifeTime; }
	float GetTime() { return m_time; }
	TeamType GetTeamType() { return m_teamType; }
	vector<CObject*> GetBullet() { return m_bullet; }
	vector<CObject*> GetArrow() { return m_arrow; }
public:
	void SetPos(const Pos pos) { m_pos = pos; }
	void SetSize(float size) { m_size = size; }
	void SetColor(Color color) { m_color = color; }

public:
	void GotDamage(float damage) { m_life -= damage; }
	void Die() { m_life = 0.0f; }

public:
	void Move();
	void CreateBullet();
	void CreateArrow();

public:
	bool CheckCollision(CObject* other);

protected:
	Pos m_pos;
	Pos m_vPos;
	float m_size;
	Color m_color;
	float m_life, m_lifeTime;
	float m_time;
	ObjectType m_objType;
	DWORD m_bulletCreateTime;
	DWORD m_arrowCreateTime;
	TeamType m_teamType;
	vector<CObject*> m_bullet;
	vector<CObject*> m_arrow;
};