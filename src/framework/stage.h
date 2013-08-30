
#ifndef STAGE_H
#define STAGE_H

struct Stage
{
	virtual void update () {};
	virtual void draw_scene () {};
};

extern Stage null_stage;

#endif // STAGE_H

