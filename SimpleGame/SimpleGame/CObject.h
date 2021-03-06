
#include "Define.h"
#define MAX_OBJECTS_COUNT 50

enum ObjectType {
	OBJECT_BUILDING,
	OBJECT_CHARACTER,
	OBJECT_BULLET,
	OBJECT_ARROW,
	OBJECT_ROCKET

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
	void Init(TeamType teamType, ObjectType objType, Pos pos, float size, Color color, float level);
	void Update(float time);

public:
	ObjectType GetObjType() { return m_objType; }
	Pos GetPos() { return m_pos; }
	float GetSize() { return m_size; }
	Color GetColor() { return m_color; }
	float GetLife() { return m_life; }
	float GetShieldLife() { return m_shiledLife; }
	float GetLifeTime() { return m_lifeTime; }
	float GetTime() { return m_time; }
	TeamType GetTeamType() { return m_teamType; }
	vector<CObject*> GetBullet() { return m_bullet; }
	vector<CObject*> GetArrow() { return m_arrow; }
	float GetLevel() { return m_level; }
public:
	void SetPos(const Pos pos) { m_pos = pos; }
	int GetCol() { return m_col; }
	int GetRow() { return m_row; }
	void SetSize(float size) { m_size = size; }
	void SetColor(Color color) { m_color = color; }

public:
	void GotDamage(float damage) { m_life -= damage; }
	void GotShiledDamage(float damage) { m_shiledLife -= damage; }
	float GetPTime() { return m_pTime * 1000.0f; }
	float GetPA() { return m_pA; }
	bool GotRocketDmg() { return m_gotRocketDmg; }
	void Die() { m_life = 0.0f; }

public:
	void Move();
	void CreateBullet();
	void CreateArrow();
	void CreateRocket();

public:
	bool IsOnShield();
public:
	bool CheckCollision(CObject* other);

protected:
	Pos m_pos;
	Pos m_vPos;
	float m_size;
	Color m_color;
	float m_life, m_lifeTime;
	float m_time;
	float m_level;
	ObjectType m_objType;
	DWORD m_bulletCreateTime;
	DWORD m_arrowCreateTime;
	DWORD charTime;
	DWORD m_shieldDuTime;
	DWORD m_shieldActiveTime;
	DWORD m_rocketTime;
	TeamType m_teamType;
	vector<CObject*> m_bullet;
	vector<CObject*> m_arrow;
	int m_col, m_row;
	float m_pTime;
	float m_pA;
	float m_shiledLife;
	bool m_gotRocketDmg;
};