#ifndef RPGAME_TURN_HPP
#define RPGAME_TURN_HPP

#include <string>

class Turn
{
    std::string* messages;
    int messageCount;
    int packCount;
    int* packages;
    bool packed;
    TurnType tType;

public:
    Turn();
    ~Turn();

    void Reset(std::string*, int);

    void SetIterations(int);
    void SetMessageCount(int);
    void SetMessage(std::string, unsigned);
    void ClearPackages();
    void SetType(TurnType);

    int GetIterations();
    int GetMessageCount();
    std::string* GetMessages();
    int* GetPackages();
    TurnType GetType();
    bool IsPacked();

    void Pack();

};


#endif
