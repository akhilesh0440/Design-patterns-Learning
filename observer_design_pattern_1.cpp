#include <string>
#include <iostream>
#include <forward_list>

// Abstract class which we derive from
//  "Base class"
class IObserver
{
public:
	virtual ~IObserver() {}
	virtual void OnNotify() = 0;
};

class ISubject
{
public:
	virtual ~ISubject() {}
	void AddIObserver(IObserver *IObserver)
	{
		mIObservers.push_front(IObserver);
	}

	void REmoveObervers(IObserver *IObserver)
	{
		mIObservers.remove(IObserver);
	}

	void NotifyAll()
	{
		for (auto &o : mIObservers)
		{
			o->OnNotify();
		}
	}

private:
	std::forward_list<IObserver *> mIObservers;
};

// Concrete implementation of our IIObserver
class Watcher : public IObserver
{
public:
	explicit Watcher(ISubject &subject, const std::string &name) : mSubject(subject), mName(name)
	{
		mSubject.AddIObserver(this);
	}

	~Watcher()
	{
		mSubject.REmoveObervers(this);
	}

	void OnNotify() override
	{
		std::cout << "watcher-" << mName << std::endl;
	}

private:
	std::string mName;
	ISubject &mSubject;
};

class SomeSubject : public ISubject
{
public:
};

int main()
{
	SomeSubject subject;

	std::string name;
	int i;

	Watcher watcher1(subject, "Watecher-1");
	Watcher watcher2(subject, "Watecher-2");
	{
		Watcher watcher3(subject, "Watecher-3");

		// 	subject.AddIObserver(&watcher1);
		// 	subject.AddIObserver(&watcher2);
		// 	subject.AddIObserver(&watcher3);
	}

	subject.NotifyAll();

	// subject.REmoveObervers(&watcher3);
	std::cout << std::endl;

	subject.NotifyAll();

	return 0;
}