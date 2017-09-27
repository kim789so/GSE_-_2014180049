

class CCobject
{
public:
	void init(float x, float y, float z, float size, float r, float g, float b, float a);
	float getx() { return m_x; }
	float gety() { return m_y; }
	float getz() { return m_z; }
	float getsize() { return m_size; }
	float getr() { return m_r; }
	float getg() { return m_g; }
	float getb() { return m_b; }
	float geta() { return m_a; }

private:
	float m_x, m_y, m_z, m_size, m_r, m_g, m_b, m_a;

};