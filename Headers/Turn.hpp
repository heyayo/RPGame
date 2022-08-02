#ifndef RPGAME_TURN_HPP
#define RPGAME_TURN_HPP

enum TurnType
{
    Move,
    Attack,
    Inventory
};

template<typename T>
class Turn
{
    const char** messages;
    int iterations;
    T* packages;
    bool packed;
    TurnType tType;

public:
    Turn(const char**, int, TurnType);
    ~Turn();

    void Reset(const char** mesgPack, int iter);

    void SetIterations(int iter);
    void SetMessages(const char**);
    void ClearPackages();

    int GetIterations();
    const char** GetMessages();
    T* GetPackages();
    TurnType GetType();

    void Pack();

};


#endif
