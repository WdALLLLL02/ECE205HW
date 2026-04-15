#include <iostream>
using namespace std;

class speedometer{
private:
    double distance;
    double time;
public:
    void setdistance(double d);
    void setTime(double t);
    double computeaveragespeed();
};
void speedometer::setdistance(double d){
    distance = d;
}
void speedometer::setTime(double t){
    time = t;
}
double speedometer::computeaveragespeed(){
    if (time == 0)
        return 0;

    return distance / (time / 60.0);
}
int main(){
    speedometer rider;
    double d, t;
    cout << "distance traveled in miles: ";
    cin >> d;
    cout << "time taken in minutes: ";
    cin >> t;
    rider.setdistance(d);
    rider.setTime(t);
    cout << "average speed: "
         << rider.computeaveragespeed()
         << " miles per hour" << endl;
    return 0;
}