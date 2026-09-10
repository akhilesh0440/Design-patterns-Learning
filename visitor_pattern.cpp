#include <iostream>
#include <vector>

struct Orc;
struct Goblin;
/*Our visutir 'base class' which tells us, which type of objects
(Orcs's, Goblin's) that we can extend (i.e. visit).*/
struct MonsterVisitor
{
    virtual ~MonsterVisitor() = default;
    virtual void visit(const Orc &orc) const = 0;
    virtual void visit(const Goblin &goblin) const = 0;
};
// Base class
struct Monster
{
    virtual ~Monster() {}
    virtual void accept(const MonsterVisitor &visitor) = 0;
};

struct Orc : public Monster
{
    Orc() { std::cout << "Orc::Orc()\n"; }
    void accept(const MonsterVisitor &visitor) override
    {
        std::cout << "Orc::accept\n";
        visitor.visit(*this);
    }
};

struct Goblin : public Monster
{
    Goblin() { std::cout << "Goblin::Goblin()\n"; }
    void accept(const MonsterVisitor &visitor) override
    {
        std::cout << "Goblin::accept\n";
        visitor.visit(*this);
    }
};

struct DrawMonsterVisitor : public MonsterVisitor
{
    void visit(const Orc &orc) const override
    {
        std::cout << "Drawing orc from MonsterVisitor\n"
                  << std::endl;
    }
    void visit(const Goblin &goblin) const override
    {
        std::cout << "Drawing goblin from MonsterVisitor\n"
                  << std::endl;
    }
};

void drawAllMonster(const std::vector<Monster *> &monsters)
{
    for (auto const &m : monsters)
    {
        m->accept(DrawMonsterVisitor{});
    }
}

int main()
{
    std::vector<Monster *> monsters;
    monsters.emplace_back(new Orc);
    monsters.emplace_back(new Goblin);

    Monster *myMonster = new Orc;
    drawAllMonster(monsters);
    return 0;
}