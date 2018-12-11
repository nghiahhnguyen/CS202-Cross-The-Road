class CVEHICLE;

#include "header.h"
#include "cvehicle.h"

class CTRAFFICLIGHT
{
private:
	bool green = true;
public:
	void draw();
	CTRAFFICLIGHT() {}
	bool getGreen()
	{
		return green;
	}
	void setGreen(bool x)
	{
		green = x;
	}
};
