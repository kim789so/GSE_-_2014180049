

#define MAX_OBJECTS_COUNT 50

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
	void Init(Pos pos, float size, Color color);
	void Update();

public:
	Pos GetPos() { return m_pos; }
	float GetSize() { return m_size; }
	Color GetColor() { return m_color; }

public:
	void SetPos(const Pos pos) { m_pos = pos; }
	void SetSize(float size) { m_size = size; }
	void SetColor(Color color) { m_color = color; }

public:
	bool CheckCollision(CObject& other);

protected:
	Pos m_pos;
	Pos m_vPos;
	float m_size;
	Color m_color;


};