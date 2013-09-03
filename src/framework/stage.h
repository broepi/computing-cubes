
#ifndef STAGE_H
#define STAGE_H

struct Stage
{
	virtual void update () {};
	virtual void drawScene () {};
};

extern Stage nullStage;

#endif // STAGE_H

