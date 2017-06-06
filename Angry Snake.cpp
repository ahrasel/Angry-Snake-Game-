/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
# include "iGraphics.h"
#include <stdlib.h>
#include <time.h>

int c_x,c_y;				//Snake X And Y Co-Ordinate
int keyboardtest=0;			//For Keyboard Control
int s_x,s_y;				//Snake Size X And Y Co-Ordinate
int f_x,f_y;				//Snake Food X And Y Co-Ordinate
int snake_speed=0;			//Snake Speed Up
int button_pressed = 0;		//Button Pressed For Menu
int pause = 0;				//Snake Pused and Resume
int level_up=0;				//Game Level increase
int game_over=0;			//Speed Level Control
int s_size=0;				//snake Size increase
int score_int=0;			//Integer Value Score
char score[100];			//String Value Score
int newgame_button = 0;		//New Game Button Value	
int game_mode = 0;			//Game Mode Button value
int free_life = 0;			//Free life Game Mode value
int toure_mode = 0;			//Toure Game Mode value
int easy_mode = 0;			//Easy game Mode value
int hard_mode = 0;			//Hard Mode value
int about_button = 0;		//About Button
int help_button = 0;		//For halp button
int exit_button = 0;		//For Exit Button
int back_button=0;			//For Back button
int gameover_button=0;		//For Game Over Button
int show_level=0;			//Show Level Incrase
int load=0;					//Game Loading value
int start_game=0;			//Start Game After Loading
/* 
	function iDraw() is called again and again by the system.
*/
void iDraw()
{	
	iClear();
	iShowBMP(0,0, "rasel.bmp");			//Game Load Picture
	iFilledRectangle(180,266,load,30);  //Loadin Bar
	
	if(start_game ==1)
	{
	iShowBMP(0,0, "main_menu.bmp");		//Main Menu
	}
//--------------New Game Button start------------------------
	if(newgame_button==1)
	{
		if(level_up >= 0 && level_up <= 5)
		{
			show_level=1;
			snake_speed=3;
			iShowBMP(0,0, "first_level.bmp");
		}

		else if(level_up >= 6 && level_up <= 10)
		{
			show_level=2;
			snake_speed=4;
			iShowBMP(0,0, "second_level.bmp");
		}

		else if(level_up >= 11 && level_up <= 15)
		{
			show_level=3;
			snake_speed=5;
			iShowBMP(0,0, "third_level.bmp");
		}

		else if(level_up >= 16 && level_up <= 20)
		{
			show_level=4;
			snake_speed=6;
			iShowBMP(0,0, "foureth_level.bmp");
		}

		else if(level_up >= 21)
		{
			show_level=5;
			snake_speed=10;
			iShowBMP(0,0, "fifth_level.bmp");
		}

		iSetColor(255,0,0);
		iFilledRectangle(c_x,c_y,s_x,s_y);
		//iFilledCircle(f_x,f_y,5);
		iShowBMP(f_x,f_y, "ersr.bmp");
		iSetColor(25,255,255);
		iRectangle(0,0,720,20);
		iText(200,2,"Prees Space Button Pause Game",GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(25,255,255);
		iText(20,2,"LEVEL - ",GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(score,"%d",show_level);				//Convert Int value to String
		iText(130,2,score,GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(score,"%d",score_int);
		iText(610,2,"Score:",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(680,2,score,GLUT_BITMAP_TIMES_ROMAN_24);
		if(pause==1)
		{	
			iSetColor(176,23,31);
			iText(220,258,"Prees Space For Continue",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(220,220,"Prees Q For Exit Game",GLUT_BITMAP_TIMES_ROMAN_24);
		}
		
	}
//---------------New Game Button End------------------------

//---------------Game Mode Button Start------------------------
	 	
	if(game_mode == 1)
	{
		iShowBMP(0,0, "game mode.bmp");
		iSetColor(75,0,130);
		iFilledRectangle(15,10,50,20);
		iFilledRectangle(14,11,50,20);
		iSetColor(224,102,255);
		iText(25,13,"Exit",GLUT_BITMAP_HELVETICA_18);
//--------------Free Life Mode Start------------------------

		if(free_life == 1 && game_mode == 1)
		{
			if(c_x >685 || c_x < 1 || c_y > 479 || c_y < 20)
			{
				game_over=0;
				c_x=100;
				c_y=100;
			}
			else if(level_up >= 0 && level_up <= 5)
			{
				show_level=1;
				snake_speed=3;
				iShowBMP(0,0, "first_level.bmp");
			}

			else if(level_up >= 6 && level_up <= 10)
			{
				show_level=2;
				snake_speed=4;
				iShowBMP(0,0, "second_level.bmp");

			}

			else if(level_up >= 11 && level_up <= 15)
			{
				show_level=3;
				snake_speed=5;
				iShowBMP(0,0, "third_level.bmp");

			}

			else if(level_up >= 16 && level_up <= 20)
			{
				show_level=4;
				snake_speed=6;
				iShowBMP(0,0, "foureth_level.bmp");

			}

			else if(level_up >= 21)
			{
				show_level=5;
				snake_speed=10;
				iShowBMP(0,0, "fifth_level.bmp");

			}

			iSetColor(255,0,0);
			iFilledRectangle(c_x,c_y,s_x,s_y);
			iShowBMP(f_x,f_y, "ersr.bmp");
			iSetColor(25,255,255);
			iRectangle(0,0,720,20);
			iText(200,2,"Prees Space Button Pause Game",GLUT_BITMAP_TIMES_ROMAN_24);
			iSetColor(25,255,255);
			iText(20,2,"LEVEL - ",GLUT_BITMAP_TIMES_ROMAN_24);
			sprintf(score,"%d",show_level);
			iText(130,2,score,GLUT_BITMAP_TIMES_ROMAN_24);
			sprintf(score,"%d",score_int);
			iText(610,2,"Score:",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(680,2,score,GLUT_BITMAP_TIMES_ROMAN_24);
			
			if(pause == 1)
			{	
				iSetColor(176,23,31);
				iText(220,258,"Prees Space For Continue",GLUT_BITMAP_TIMES_ROMAN_24);
				iText(220,220,"Prees Q For Exit Game",GLUT_BITMAP_TIMES_ROMAN_24);
			}
		 	
	}

//--------------Free Life Mode End------------------------



//--------------Toure Mode Start------------------------
	else if(toure_mode == 1 && game_mode == 1)
	{
			if(level_up >= 0 && level_up <= 5)
			{
				show_level=1;
				snake_speed=3;
				iShowBMP(0,0, "first_level.bmp");
			}

			else if(level_up >= 6 && level_up <= 10)
			{
				show_level=2;
				snake_speed=4;
				iShowBMP(0,0, "second_level.bmp");

			}

			else if(level_up >= 11 && level_up <= 15)
			{
				show_level=3;
				snake_speed=5;
				iShowBMP(0,0, "third_level.bmp");

			}

			else if(level_up >= 16 && level_up <= 20)
			{
				show_level=4;
				snake_speed=6;
				iShowBMP(0,0, "foureth_level.bmp");

			}

			else if(level_up >= 21)
			{
				show_level = 5;
				snake_speed = 10;
				iShowBMP(0,0, "fifth_level.bmp");

			}

			iSetColor(255,0,0);
			iFilledRectangle(c_x,c_y,s_x,s_y);
			iShowBMP(f_x,f_y, "ersr.bmp");
			iSetColor(25,255,255);
			iRectangle(0,0,720,20);
			iText(200,2,"Prees Space Button Pause Game",GLUT_BITMAP_TIMES_ROMAN_24);
			iSetColor(25,255,255);
			iText(20,2,"LEVEL - ",GLUT_BITMAP_TIMES_ROMAN_24);
			sprintf(score,"%d",show_level);
			iText(130,2,score,GLUT_BITMAP_TIMES_ROMAN_24);
			sprintf(score,"%d",score_int);
			iText(610,2,"Score:",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(680,2,score,GLUT_BITMAP_TIMES_ROMAN_24);
			
			if(pause==1)
			{	
				iSetColor(176,23,31);
				iText(220,258,"Prees Space For Continue",GLUT_BITMAP_TIMES_ROMAN_24);
				iText(220,220,"Prees Q For Exit Game",GLUT_BITMAP_TIMES_ROMAN_24);
			}
		 	
	}
//---------------Toure Mode end------------------------


//---------------Easy Mode Start------------------------
	else if(easy_mode == 1 && game_mode == 1)
		{
	 		snake_speed=3;
			iShowBMP(0,0, "fifth_level.bmp");
			iSetColor(25,255,255);
			iRectangle(0,0,720,20);
			iText(200,2,"Prees Space Button Pause Game",GLUT_BITMAP_TIMES_ROMAN_24);
			iSetColor(25,255,255);
			iText(20,2,"Easy Mode",GLUT_BITMAP_TIMES_ROMAN_24);
			sprintf(score,"%d",score_int);
			iText(610,2,"Score:",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(680,2,score,GLUT_BITMAP_TIMES_ROMAN_24);
			iSetColor(255,0,0);
			iFilledRectangle(c_x,c_y,s_x,s_y);
			//iFilledCircle(f_x,f_y,5);
			iShowBMP(f_x,f_y, "ersr.bmp");
			
			if(pause == 1)
			{	
				iSetColor(176,23,31);
				iText(220,258,"Prees Space For Continue",GLUT_BITMAP_TIMES_ROMAN_24);
				iText(220,220,"Prees Q For Exit Game",GLUT_BITMAP_TIMES_ROMAN_24);
			}
		}

//---------------Easy Mode end------------------------


//---------------Hard Mode Start------------------------

	 else if(hard_mode == 1 && game_mode == 1)
		{
	 		snake_speed=10;
			iShowBMP(0,0, "third_level.bmp");
			iSetColor(25,255,255);
			iRectangle(0,0,720,20);
			iText(200,2,"Prees Space Button Pause Game",GLUT_BITMAP_TIMES_ROMAN_24);			iSetColor(25,255,255);
			iText(20,2,"Hard Mode",GLUT_BITMAP_TIMES_ROMAN_24);
			sprintf(score,"%d",score_int);
			iText(610,2,"Score:",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(680,2,score,GLUT_BITMAP_TIMES_ROMAN_24);
			iSetColor(255,0,0);
			iFilledRectangle(c_x,c_y,s_x,s_y);
			//iFilledCircle(f_x,f_y,5);
			iShowBMP(f_x,f_y, "ersr.bmp");
			
			if(pause == 1)
			{	
				iSetColor(176,23,31);
				iText(220,258,"Prees Space For Continue",GLUT_BITMAP_TIMES_ROMAN_24);
				iText(220,220,"Prees Q For Exit Game",GLUT_BITMAP_TIMES_ROMAN_24);
			}
		}
//---------------Hard Mode end------------------------
	 //-------------------About Buton start --------------------------	 
	if(about_button == 1)
	{
		iShowBMP(0,0, "about.bmp");
		iSetColor(139,95,101	);
		iFilledRectangle(15,10,50,20);
		iFilledRectangle(14,11,50,20);
		iSetColor(224,102,255);
		iText(25,13,"Exit",GLUT_BITMAP_HELVETICA_18);
	}
//---------------About Button End----------------------------------
	}

//---------------Game Mode Button End------------------------


//-------------------Help Buton start --------------------------	 
	if(help_button == 1)
	{
		iShowBMP(0,0, "help.bmp");
		iSetColor(139,95,101	);
		iFilledRectangle(15,10,50,20);
		iFilledRectangle(14,11,50,20);
		iSetColor(224,102,255);
		iText(25,13,"Exit",GLUT_BITMAP_HELVETICA_18);
	}
//---------------Help Button End----------------------------------
		

//------------------Game Over Code Start---------------------------
	if(game_over == 1)
	{
		iShowBMP(0,0, "gm over.bmp");
		iSetColor(139,95,101	);
		iFilledRectangle(15,10,50,20);
		iFilledRectangle(14,11,50,20);
		iSetColor(224,102,255);
		iText(25,13,"Exit",GLUT_BITMAP_HELVETICA_18);
		iSetColor(25, 255, 255);
		iText(285, 106, "Your Score Is:", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(346, 80, score , GLUT_BITMAP_TIMES_ROMAN_24);
	}
	
//---------------------Game Over Code end -------------------------------

}

/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		printf("%d %d \n\n",mx,my);
//-----------------------Button Value Get By Mouse Click start------------------------
		if((mx >= 1 && mx <= 125) && (my >= 335 && my <= 490))//strat new game button
			{
				newgame_button = 1;
				//printf("game Start Button");
			}

		else if((mx >= 1 && mx <= 116) && (my >= 157 && my <= 303))//game Mode button
			{
				game_mode = 1;
				//printf("Game mode Button");

			}
		else  if((mx >= 1 && mx <= 125) && (my >= 20 && my <= 155))//game help button
			{
				help_button = 1;
				//printf("Game Help Button");
			}
		else if(game_mode == 1)
			{
				
				if((mx >= 17 && mx <= 218) && (my >= 235 && my <= 287))//free life mode
					{
						free_life=1;
						//printf("free life Mode");
					}
				else if((mx >= 18 && mx <= 214) && (my >= 169 && my <= 223) && game_mode == 1)//Toure mode
					{
						toure_mode = 1;
						//printf("Toure mode");
					}

				else if((mx >= 275 && mx <= 468) && (my >= 238 && my <= 288))//Easy mode
					{
						easy_mode = 1;
						//printf("Easy mode");
					
					}
				else if((mx >= 274 && mx <= 472) && (my >= 172 && my <= 222))//Hard Mode
					{
						hard_mode = 1;
						//printf("Hard Mode");
					
					}
				else if((mx >= 136 && mx <= 383) && (my >= 101 && my <= 150))//About button
				{
					
						about_button=1;
				}
		}
		
		if((mx >= 613 && mx <= 710) && (my >= 140 && my <= 182))//game over Exit Button
			{
				gameover_button = 1;
				exit(0);
				//printf("game over Buatton");
			}
		if((mx >= 638 && mx <= 718) && (my >= 416 && my <= 512))//Main Menu Exit button
			{
				exit(0);
				
			}
		if((mx >= 13 && mx <= 165) && (my >= 10 && my <= 31))//Exit button
				{
					
						exit(0);
				}
		
//---------------------Button Value Get By Mouse Click End------------------------
			
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{

	//Snake Puse and Resume Code Start

	if( key == ' ' && pause == 0)
	{
		pause = 1;
	}
	else if( key == ' ' && pause == 1 )
	{
		pause = 0;
	}
	else if(key == 'q')
	{
		exit(0);
	}
	//Snake Puse and Resume Code End
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{
	//Keyboard Control Start
	if(key == GLUT_KEY_RIGHT)		//Right Move
	{
		
		keyboardtest = 1;
	}
	if(key == GLUT_KEY_LEFT)		//left Move
	{
		
		keyboardtest = 2;
	}
	if(key == GLUT_KEY_UP)			//Move Up
	{
	
		keyboardtest = 3;
	}
	if(key == GLUT_KEY_DOWN)		//Move Down
	{
		
		keyboardtest = 4;
	}
	//Keyboard Control End
}

void snakemove()		//Snake Move Function
{
	
	if( pause == 1 )			//Snake Puse And Resume Condition
	{
		return;
	}
	
//End Keyboard Control Code Start

	if(keyboardtest == 1)
	{
		c_x += snake_speed;
		s_x = s_size;
		s_y = 5;
		if(c_x > 685)
		{
			game_over = 1;
		}
	}
		
	if(keyboardtest == 2)
	{
		c_x -= snake_speed;
		s_x = s_size;
		s_y = 5;
		if(c_x < 1)
		{
			game_over = 1;
		}
	}
	if(keyboardtest == 3)
	{
		c_y += snake_speed;
		s_x = 5;
		s_y = s_size;
		if(c_y > 479)
		{
			game_over = 1;
		}
	}
		
	if(keyboardtest == 4)
	{
		c_y -= snake_speed;
		s_x = 5;
		s_y = s_size;
		if(c_y < 20)
		{
			game_over = 1;
		}
		
	}

	if(score_int == 50)
	{
		game_over = 1;
	}
	//End Keyboard Contor Code End


	//Food Code Start
	if(( f_x <= c_x + s_x || f_x <= c_x + s_x - 8) && (f_x >= c_x  || f_x >= c_x - 8) && ( (f_y <= c_y + s_y  || f_y <= c_y + s_y - 8) && (f_y >= c_y  || f_y >= c_y - 8)) )
	{
		level_up += 1;
		if(s_size < 100)
		{
		s_size += 5;
		}
		score_int++;

		f_x = (100 + (rand() % 300));
		f_y = (100 + (rand() % 300));
	}
	//Food Code End

}
	
void gameload()			//Game Loading Function
{
	load+=2;
		
	if(load==392)
	{
		start_game=1;
	}

}
int main()
{ 
	c_x=25;
	c_y=103;
	s_x=30;
	s_y=5;
	f_x=100;
	f_y=100;
	keyboardtest=0;
	snake_speed=0;
	level_up=0;
	game_over=0;
	game_mode=0;
	load=2;
	s_size=30;

	srand(time(NULL));			//Random Number Function

	iSetTimer(10,gameload);
	iSetTimer(10,snakemove);

	iInitialize(720,512, "Angry Snake");
	return 0;
}	