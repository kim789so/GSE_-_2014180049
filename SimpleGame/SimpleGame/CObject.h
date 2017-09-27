

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

	Pos GetPos() { return m_pos; }
	float GetSize() { return m_size; }
	Color GetColor() { return m_color; }

protected:
	Pos m_pos;
	float m_size;
	Color m_color;

};