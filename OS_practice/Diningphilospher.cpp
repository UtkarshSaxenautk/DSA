#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

int main()
{
    int nop = 10;
    struct Chopstics
    {
    public:
        Chopstics()
        {
            ;
        }
        mutex mu;
    };

    auto eat = [](Chopstics &leftch, Chopstics &rightch, int index)
    {
        unique_lock<mutex> llock(leftch.mu);

        unique_lock<mutex> rlock(rightch.mu);

        cout << "Philospher " << index << " is eating"
             << "\n";
        chrono::milliseconds timeout(2000);
        this_thread::sleep_for(timeout);

        cout << "Philospher " << index << " has finihsed"
             << "\n";
    };

    Chopstics chop[nop];

    thread philospher[nop];

    cout << "Philospher " << 1 << " is thinking.."
         << "\n";
    philospher[0] = thread(eat, ref(chop[0]), ref(chop[nop - 1]), 1);

    for (int i = 1; i < nop; i++)
    {
        cout << "Philospher " << i + 1 << " is thinking.."
             << "\n";
        philospher[i] = thread(eat, ref(chop[i]), ref(chop[i - 1]), (i + 1));
    }

    for (auto &p : philospher)
    {
        p.join();
    }

    return 0;
}