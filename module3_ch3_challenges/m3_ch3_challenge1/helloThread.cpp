#include <thread>
#include <iostream>

using namespace std;

bool ShouldQuit = false;
int ThreadCounter = 0;

void HelloWorldThread();

int main()
{
	char ThreadDisplay;

	cout << "Normal Hello World! Thread #: \n";
	
	thread Hello(HelloWorldThread);

	while (!ShouldQuit)
	{

		cout << "Enter key to display ThreadCounter: ";
		cin >> ThreadDisplay;
		cout << "ThreadCounter == " << ThreadCounter << endl;

		ShouldQuit = (ThreadDisplay == 'Q' || ThreadDisplay == 'q');
	}
	Hello.join();
	return 0;
}

void HelloWorldThread()
{
	while (!ShouldQuit)
	{
		ThreadCounter++;
		if (ThreadCounter >= 1000)
		{
			ThreadCounter = 0;
		}
	}
}