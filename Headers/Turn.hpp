#ifndef RPGAME_TURN_HPP
#define RPGAME_TURN_HPP

#include <string>

enum TurnType
{
    Move,
    Attack,
    Inventory
};

class Turn
{
    std::string* messages;
    int iterations;
    int* packages;
    bool packed;
    TurnType tType;

public:
    Turn();
    ~Turn();

    void Reset(std::string*, int);

    void SetIterations(int);
    void SetMessages(std::string*);
    void ClearPackages();
    void SetType(TurnType);

    int GetIterations();
    std::string* GetMessages();
    int* GetPackages();
    TurnType GetType();
    bool IsPacked();

    void Pack();

};


#endif
