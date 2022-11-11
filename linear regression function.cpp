#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>

using namespace std;

int n, f;
double xm, ym, x[1000], y[1000];
double m, m1, m2, b;
double in;
vector<pair<int, int>> v;


void gotoxy(int x, int y){
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


//┌(1) : 왼쪽위, ┐(2): 오른쪽위, └(3): 왼쪽아래, ┘(4): 오른쪽 아래, │(5): 세로벽, ─(6):가로벽

void start(){
    system("cls");
    char y=1, u=2, k=3, f=4, n=5, g=6;

    system("color 0c");
    gotoxy(55, 10);
    cout << y << g << g <<g << g << g << g << g << g << g << g << g << g << g << g << u <<"\n";
    gotoxy(55, 11);
    cout << n << "              " << n <<"\n";
    gotoxy(55, 12);
    cout << n << "              " << n <<"\n";
    gotoxy(55, 13);
    cout << n << "              " << n <<"\n";
    gotoxy(55, 14);
    cout << n << "     start    " << n <<"\n";
    gotoxy(55, 15);
    cout << n << "              " << n <<"\n";
    gotoxy(55, 16);
    cout << n << "              " << n <<"\n";
    gotoxy(55, 17);
    cout << n << "              " << n <<"\n";
    gotoxy(55, 18);
    cout << k << g << g <<g << g << g << g << g << g << g << g << g << g << g << g << f <<"\n";

    Sleep(3000);
}

void finish(){

}

void input(){

    cout<<"독립변수의 개수: \n";
    cin >> n;
    if(n<=1){
        cout<<">>2쌍 이상의 변수를 입력하십시오.";
        Sleep(1500);
        return;
    }
    cout<<"\n";

    for(int i=0;i<n;i++){
        cout<<i+1<<"번째 독립변수(x축): ";
        cin >> x[i];
        cout<<i+1<<"번째 종속변수(y축): ";
        cin >> y[i];
        cout<<"\n";
    }

    for(int i=0;i<n;i++){
        xm+=x[i];
        ym+=y[i];
    }
    xm=xm/n;
    ym=ym/n;

    for(int i=0;i<n;i++){
        m1+=(x[i]-xm)*(y[i]-ym);
        m2+=(x[i]-xm)*(x[i]-xm);

    }

    m=m1/m2;
    //cout << m <<"\n";

    b=ym-m*xm;
    v.push_back(pair<int,int>(m,b));
    cout<<">>설정완료\n";
    Sleep(3000);
}

void output(){
    cout <<"예측하고 싶은 종속변수의 독립변수를 입력하시오.\n";
    cin >> in;
    cout<< m*in+b;
}

void show(){
    for(int i=0;i<v.size();i++){
        cout << i+1 << ". 기울기: "<< v[i].first << "  y절편 값: " << v[i].second <<"\n";
    }
    cout<<">>메뉴 화면으로 돌아가려면 아무 키나 누르십시오.\n";

    while(!_kbhit()){
        Sleep(100);
    }

}

int main()
{
    start();
    system("cls");
    system("color 0f");
    while(1){
        system("cls");
        cout<<"**각 수를 입력한 후에는 Enter 키를 누르십시오.**\n\n";
        cout << "OP.1) 기본 값을 설정하려면 1을 누르시오.\n";
        cout << "OP.2) 예측값을 측정하려면 2을 누르시오.\n";
        cout << "OP.3) 설정된 기본값을 보려면 3을 누르시오.\n";

        int f;
        cin >> f;
        if(f==1){
            system("cls");
            input();

        }else if(f==2){
            system("cls");
            output();

        }else if(f==3){
            system("cls");
            show();

        }
    }

    //cout << b;

}

