#ifndef RPGAME_V2_HPP
#define RPGAME_V2_HPP

class V2
{
public:
    int x,y;
    V2(int a = 0, int b = 0);
    ~V2();

    int Length();

    V2& operator+=(V2&);
    V2& operator-=(V2&);
    V2 operator-(V2&);
    bool operator==(V2&);
};


#endif
