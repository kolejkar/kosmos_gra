#ifndef LISC_H
#define LISC_H

#include <iostream>
#include <stdio.h>
#include <sstream>

class object
{
	public:
	 int x,y; //wspó³rzêdne
	 int type; //typ
	 int id;
};

enum Team
{
        RockPeople, //ludzie z astreoid
        Earth, //ziemianie
};

class planet : public object
{
       public:
	Team team;
        int offer;
        bool air; //life
};

class star : public object
{
};

class rock : public object
{
        public:
                int gold;
};

std::string intToStr(int number)
{
        std::ostringstream stream;
        stream << number;
        std::string str=stream.str();
        return str;
}

#endif
