#include <iostream>
#include <memory>

using namespace std;

// Just the Interface we want to enforce, for different
//  behaviours(i.e. Part of the strategy pattern)
struct ICombat
{
    virtual ~ICombat() {}
    virtual void Execute() = 0;
};

struct NoCombat : public ICombat
{
    void Execute()
    {
        cout << "NoCombat::Execute()\n";
    }
};

struct MeleeCombat : public ICombat
{
    void Execute()
    {
        cout << "MeleeCombat::Execute()\n";
    }
};

struct Orc
{
    Orc()
    {
        mCombatStrategy = make_unique<NoCombat>();
    }

    void DoActions()
    {
        mCombatStrategy->Execute();
    }

    void SetCombatStrategy(unique_ptr<ICombat>&& c)
    {
        mCombatStrategy = move(c);
    }

private:
    unique_ptr<ICombat> mCombatStrategy;
};

int main()
{

    Orc orc;
    orc.DoActions();
    orc.SetCombatStrategy(make_unique<MeleeCombat>());
    orc.DoActions;
    return 0;
}