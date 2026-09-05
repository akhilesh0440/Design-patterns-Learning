#include <iostream>
#include <vector>

class Logger {
public:
	/* Retrieve the single instance of the object created
	, and we'll enforce, only 1 of these obejects gets created,
	  in our code logic.
	  */

	static Logger& GetInstance() {
		static Logger* s_instance = new Logger;
		return *s_instance;
	}

	void addMessgae(std::string message) {
		m_messges.push_back(message);
	}

	void printMessage() {
		std::cout << "Accesing the lgo" << std::endl;
		for (auto& e : m_messges) {
			std::cout << e << std::endl;
		}
	}

private:
	
	Logger() {
		std::cout << "Logger was Created" << std::endl;
	}

	~Logger() {
		std::cout << "Logger was Destroyed" << std::endl;
	}
	std::vector<std::string> m_messges;

};


/*int main() {

	Logger::GetInstance().addMessgae("Calling 1");
	Logger::GetInstance().addMessgae("Calling 2");
	Logger::GetInstance().addMessgae("Calling 3");
	Logger::GetInstance().printMessage();
	return 0;
}*/