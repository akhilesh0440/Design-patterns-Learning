#include <string>
#include <iostream>
#include <forward_list>
#include <map>

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
	// Message is our 'enum' {PLAYSOUND, HANDLEPHYSICS, LOG};
	virtual void AddIObserver(int message, IObserver *IObserver)
	{
		auto it = mIObservers.find(message);
		if (it == mIObservers.end())
		{
			mIObservers[message] == ObserversList();
		}
		mIObservers[message].push_front(IObserver);
	}

	virtual void REmoveObervers(int message, IObserver *IObserver)
	{
		// mIObservers.remove(IObserver);
		auto it = mIObservers.find(message);
		if (it != mIObservers.end())
		{
			ObserversList &list = mIObservers[message];
			for (ObserversList::iterator li = list.begin(); li != list.end();)
			{
				if ((*li) == IObserver)
				{
					list.remove(IObserver);
				}
				else
				{
					++li;
				}
			}
		}
	}

	void NotifyAll()
	{
		for (ObserverMap::iterator it = mIObservers.begin(); it != mIObservers.end(); ++it)
		{
			for (auto &o : mIObservers[it->first])
			{
				o->OnNotify();
			}
		}
	}

	void Notify(int message)
	{
		for (auto &o : mIObservers[message])
		{
			o->OnNotify();
		}
	}

private:
	typedef std::forward_list<IObserver *> ObserversList;
	typedef std::map<int, ObserversList> ObserverMap;
	ObserverMap mIObservers;
};

// Concrete implementation of our IIObserver
class Watcher : public IObserver
{
public:
	explicit Watcher(ISubject &subject, int message, const std::string &name) : mSubject(subject), mName(name), mMessage(message)
	{
		mSubject.AddIObserver(message, this);
	}

	~Watcher()
	{
		mSubject.REmoveObervers(mMessage, this);
	}

	void OnNotify() override
	{
		std::cout << "watcher-" << mName << std::endl;
	}

private:
	std::string mName;
	ISubject &mSubject;
	int mMessage;
};

class SomeSubject : public ISubject
{
public:
	enum MessageTypes
	{
		PLAYSOUND,
		HANDLEPHYSICS,
		LOG
	};
};

int main()
{
	SomeSubject subject;

	std::string name;
	int i;

	Watcher watcher1(subject, SomeSubject::PLAYSOUND, "Watecher-1");
	Watcher watcher2(subject, SomeSubject::PLAYSOUND, "Watecher-2");
	Watcher watcher3(subject, SomeSubject::LOG, "Watecher-3");

	// 	subject.AddIObserver(&watcher1);
	// 	subject.AddIObserver(&watcher2);
	// 	subject.AddIObserver(&watcher3);

	subject.NotifyAll();

	// subject.REmoveObervers(&watcher3);
	std::cout << std::endl;

	subject.Notify(SomeSubject::LOG);

	std::cout << std::endl;
	subject.Notify(SomeSubject::LOG);

	return 0;
}