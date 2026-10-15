#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Alien
{
public:
    int mID;
    std::string mName;
    std::vector<int> mData;

    // Constructor
    Alien(int id, std::string name) : mID(id), mName(name)
    {
    }

    // Clone function --
    // It's very explicit, we can parameterize it if we need
    std::unique_ptr<Alien> Clone()
    {
        std::unique_ptr<Alien> clone = std::make_unique<Alien>(*this);
        return clone;
    }

    // Copy Constructor
    Alien(const Alien &rhs)
    {
        mID = -1;
        mName = rhs.mName;
        mData = rhs.mData;
    }

    // Setup Alien data
    //  (Simulating some 'slow' operation for setting up our object)
    void DataDownload()
    {
        for (int i = 0; i < 100; i++)
        {
            mData.push_back(i);
        }
    }
    // Print for debugging
    void print()
    {
        std::cout << mID << " " << mName << std::endl;
        for (auto elem : mData)
        {
            std::cout << elem;
        }
        std::cout << std::endl;
    }
};

int main()
{
    Alien default_(0, "default_");
    default_.DataDownload();
    default_.print();

    std::unique_ptr<Alien> SuperAlien = default_.Clone();
    SuperAlien->mData[0] = 9;
    SuperAlien->print();
}