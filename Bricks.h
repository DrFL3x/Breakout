#pragma once
#include "Line.h"
//#include "Ball.h"
#include "ParseData.h"

#define BLOCKS_NUM 60


class Bricks : public Line
{
public:

	//aray of brick structs

	//Bricks* field [60] = {0};
	

	Bricks(SDL_Renderer * renderer)
	: Line(renderer, 100, 700, 100, 30), brick_renderer(renderer), one_brick{ 300,300, 30,15 }
	{}

	

	~Bricks() {}
	
	
	void create();
	//void create_pattern(/*int level_flag*/);
	//void place_blocks();
	void place_rectangle(int x, int y, int w, int h);
	void render(uint8_t r, uint8_t g, uint8_t b, uint8_t a); 
	bool ball_brick_collided( SDL_FRect & ball, SDL_Rect& brick);

	SDL_Rect& get_geometry() { return one_brick; }
	
	
	void print_brick_data();
	
	SDL_Rect one_brick;
	SDL_Renderer* brick_renderer;

private:


};








class BrickType
{
public:
	BrickType( int color, int hardness, int breakscore)
		: color(color), hardness(hardness), breakscore(breakscore)
	{}
	~BrickType() {}

private:
	int color, hardness, breakscore;


};