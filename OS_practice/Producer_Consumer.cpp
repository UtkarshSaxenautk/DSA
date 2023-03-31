#include <cstdlib>
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
using namespace std;

mutex g_mutex;
bool g_ready = false;
int g_data = 0;

int produceData()
{
    int random = rand() % 100;
    cout << "Produce data " << random << "\n";
    return random;
}

void consumeData(int g_data)
{
    cout << "Recieve data : " << g_data << "\n";
}

void consumer()
{
    while (true)
    {
        while (!g_ready)
        {
            this_thread ::sleep_for(chrono::seconds(5));
        }
        unique_lock<mutex> ul(g_mutex);
        consumeData(g_data);
        g_ready = false;
    }
}

void producer()
{
    while (true)
    {
        unique_lock<mutex> ul(g_mutex);
        g_data = produceData();
        g_ready = true;
        ul.unlock();
        while (g_ready)
        {
            this_thread::sleep_for(chrono::seconds(5));
            ;
        }
    }
}

void consumerthread()
{
    consumer();
}

void producethread()
{
    producer();
}

int main()
{
    thread t1(consumerthread);
    thread t2(producethread);
    t1.join();
    t2.join();
    return 0;
}