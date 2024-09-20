#include<iostream>

class Temperature{
    private:
    int temperature;
    int incrementStep;
    public :
    Temperature(){
        temperature = 0;
        incrementStep = 1;
    }
    void setIncrementStep(int step)
    {
        incrementStep =  step;
    }
    int getTemperature()
    {
        return temperature;
    }
    void increment()
    {
        temperature += incrementStep;
    }  
    void resetTemp()
    {
        temperature = 0;
    }  


};

using namespace std;

int main() {
    Temperature t;
    t.setIncrementStep(5);
    cout << "Current Temperature : " << t.getTemperature() << endl;
    t.increment();
    cout << "Current Temperature : " << t.getTemperature() << endl;
    t.increment();
    cout << "Current Temperature : " << t.getTemperature() << endl;
    t.increment();
    
    return 0;
}
