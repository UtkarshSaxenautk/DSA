#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <cstdlib>
using namespace std;

mutex g_mutex;
bool g_ready = false;
int g_data = 0;

int produceData()
{
    int randomNumber = rand() % 1000;
    cout << "produce data: " << randomNumber << "\n";
    return randomNumber;
}

void consumeData(int data) { cout << "receive data: " << data << "\n"; }

// consumer thread function
void consumer()
{
    while (true)
    {
        while (!g_ready)
        {
            // sleep for 1 second
            this_thread::sleep_for(std::chrono::seconds(1));
        }
        unique_lock<std::mutex> ul(g_mutex);
        consumeData(g_data);
        g_ready = false;
    }
}

// producer thread function
void producer()
{
    while (true)
    {
        unique_lock<std::mutex> ul(g_mutex);

        g_data = produceData();
        g_ready = true;
        ul.unlock();
        while (g_ready)
        {
            // sleep for 1 second
            this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
}

void consumerThread() { consumer(); }

void producerThread() { producer(); }

int main()
{
    thread t1(consumerThread);
    thread t2(producerThread);
    t1.join();
    t2.join();
    return 0;
}