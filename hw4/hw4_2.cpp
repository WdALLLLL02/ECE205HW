#include <iostream>
using namespace std;
void input_scores(double scores[],int size);
void input_scores(double scores[],int size){
    for(int i=0;i<size;i++){
        cin>>scores[i];
    }
}

double max(double scores[],int size);
double max(double scores[],int size){
    double max=scores[0];
    for(int i=1;i<size;i++){
        if(scores[i]>max){
            max=scores[i];
        }
    }
    return max;
}

double min(double scores[],int size);
double min(double scores[],int size){
    double min=scores[0];
    for(int i=1;i<size;i++){
        if(scores[i]<min){
            min=scores[i];
        }
    }
    return min;
}
double score(double scores[],int size,double difficulty);
double score(double scores[],int size,double difficulty){
    double sum=0;
    for(int i=0;i<size;i++){
        sum+=scores[i];
    }
    double maxi=max(scores,size);
    double minimum=min(scores,size);
    sum=sum-maxi-minimum;
    double final_score=sum*difficulty*0.6;
    return final_score;
}

int main(){
    double difficulty;
    cin>>difficulty;
    if(difficulty<1.2||difficulty>3.8){
        cout<<"Invalid difficulty" <<endl;
        return 0;
    }
    double scores[7];
    input_scores(scores, 7);
    for(int i=0;i<7;i++){
        if(scores[i]<0||scores[i]>10){
            cout<<"Invalid score"<<endl;
            return 0;
        }
    }
    double result=score(scores,7,difficulty);
    cout<<"Final score: "<<result<<endl;
    return 0;
}
