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


//��(1) : ������, ��(2): ��������, ��(3): ���ʾƷ�, ��(4): ������ �Ʒ�, ��(5): ���κ�, ��(6):���κ�

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

    cout<<"���������� ����: \n";
    cin >> n;
    if(n<=1){
        cout<<">>2�� �̻��� ������ �Է��Ͻʽÿ�.";
        Sleep(1500);
        return;
    }
    cout<<"\n";

    for(int i=0;i<n;i++){
        cout<<i+1<<"��° ��������(x��): ";
        cin >> x[i];
        cout<<i+1<<"��° ���Ӻ���(y��): ";
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
    cout<<">>�����Ϸ�\n";
    Sleep(3000);
}

void output(){
    cout <<"�����ϰ� ���� ���Ӻ����� ���������� �Է��Ͻÿ�.\n";
    cin >> in;
    cout<< m*in+b;
}

void show(){
    for(int i=0;i<v.size();i++){
        cout << i+1 << ". ����: "<< v[i].first << "  y���� ��: " << v[i].second <<"\n";
    }
    cout<<">>�޴� ȭ������ ���ư����� �ƹ� Ű�� �����ʽÿ�.\n";

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
        cout<<"**�� ���� �Է��� �Ŀ��� Enter Ű�� �����ʽÿ�.**\n\n";
        cout << "OP.1) �⺻ ���� �����Ϸ��� 1�� �����ÿ�.\n";
        cout << "OP.2) �������� �����Ϸ��� 2�� �����ÿ�.\n";
        cout << "OP.3) ������ �⺻���� ������ 3�� �����ÿ�.\n";

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

