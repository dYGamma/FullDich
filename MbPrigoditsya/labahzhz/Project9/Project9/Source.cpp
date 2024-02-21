/*
���
7 �������
������� ����� Angle ��� ������ � ������ �� ���������, ����������� ��������� � �������� � �������. ����������� ������ ���� �����������:
������� � �������, ���������� � ��������� 0-360, ���������� � ���������� ���� �� �������� ��������, ��������� ������, ��������� �����.
*/

#define _USE_MATH_DEFINES
#include "iostream"
#include "cmath"

using namespace std;

class Angle {
private:
    int degrees;
    int minute;
public:
    Angle(int deg = 0, int min = 0) {
        degrees = deg;
        minute = min;
    }
    double to_radian() {
        return ((degrees * M_PI / 180) + (minute * M_PI / (180 * 60)));
    }
    void simplify() {
        degrees += (minute / 60);
        if (minute < 0) minute = 60 - abs(minute % 60);
        else minute = abs(minute % 60);
        degrees %= 360;
        if (degrees < 0) degrees += 360;
    }
    bool operator >(Angle obj) {
        simplify(); obj.simplify();
        if (degrees > obj.degrees) return true;
        if (degrees < obj.degrees) return false;
        if (minute > obj.minute) return true;
        return false;
    }
    bool operator <(Angle obj) {
        if (degrees < obj.degrees) return true;
        if (degrees > obj.degrees) return false;
        if (minute < obj.minute) return true;
        return false;
    }
    bool operator ==(Angle obj) {
        if (degrees == obj.degrees && minute == obj.minute) return true;
        return false;
    }
    friend ostream& operator << (ostream& output, Angle& ang)
    {
        output << ang.degrees << (char)176 << ang.minute << '\'';
        return output;
    }
    void increase_an(int deg, int min = 0) {
        if (min == 0) {
            degrees += deg;
            return;
        }
        degrees += (deg + (min / 60));
        degrees += (minute + (min % 60)) / 60;
        if (minute + (min % 60) < 0) {
            degrees--;
            minute = 60 - abs(minute + (min % 60));
            return;
        }
        minute = (minute + (min % 60)) % 60;
    }
    void reduce_an(int deg, int min = 0) {
        if (min == 0) {
            degrees -= deg;
            return;
        }
        degrees -= (deg - (min / 60));
        degrees -= (minute - (min % 60)) / 60;
        if (minute - (min % 60) < 0) {
            degrees--;
            minute = 60 - abs(minute - (min % 60));
            return;
        }
        minute = (minute - (min % 60)) % 60;
    }
    double get_sin() {
        simplify();
        double summand = to_radian();
        double result = 0;
        for (int i = 3; abs(summand) > 0.000000000000000001; i += 2) {
            result += summand;
            summand = (-1) * summand * to_radian() * to_radian() / ((i - 1) * i);
        }
        if (abs(result) < 0.00000000000001) return 0;
        return result;
    }
    void get(int& deg, int& min) {
        deg = degrees;
        min = minute;
    }
    void set(int deg, int min) {
        degrees = deg;
        minute = min;
    }
};

void help();

void main()
{
    setlocale(LC_ALL, "Russian");
    int deg, min;
    bool valid_input;
    do {
        valid_input = true;
        cout << "������� ����: ";
        cin >> deg >> min;
        if (cin.fail() || min * deg < 0) {
            cout << "������������ ����.\n";
            cin.clear();
            valid_input = false;
        }
        while (cin.get() != '\n');
    } while (!valid_input);
    Angle ang(deg, min);
    help();
    char c;
    ang.simplify();
    cout << " ������� ����: " << ang << endl;
    do {
        cout << "�������: ";
        cin >> c;
        while (cin.get() != '\n');
        if (c < '0' || c > '7') {
            cout << " ����������� �������.\n";
            continue;
        }
        if (cin.fail()) {
            cout << " ������������ ������.\n";
            cin.clear();
            continue;
        }
        switch (c) {
        case '1': {
            cout << " �������� � �������: " << ang.to_radian() << endl;
            cout << " ������� ����: " << ang << endl;
            break;
        }
        case '2': {
            int deg, min;
            cout << " �� �������(������� � ������): ";
            cin >> deg >> min;
            if (cin.fail() || deg * min < 0) {
                cout << " ������������ ����. ������� � ������ ������ ���� ������ �����.\n";
                cin.clear();
                while (cin.get() != '\n');
                continue;
            }
            while (cin.get() != '\n');
            ang.increase_an(deg, min);
            ang.simplify();
            cout << " ������� ����: " << ang << endl;
            break;
        }
        case '3': {
            int deg, min;
            cout << " �� �������(������� � ������): ";
            cin >> deg >> min;
            if (cin.fail() || deg * min < 0) {
                cout << " ������������ ����.������� � ������ ������ ���� ������ �����.\n";
                cin.clear();
                while (cin.get() != '\n');
                continue;
            }
            while (cin.get() != '\n');
            ang.reduce_an(deg, min);
            ang.simplify();
            cout << "  ������� ����: " << ang << endl;
            break;
        }
        case '4': {
            cout << " ����� ����: " << ang.get_sin() << endl;
            cout << " ������� ����: " << ang << endl;
            break;
        }
        case '5': {
            cout << "������� ������ ����: ";
            cin >> deg >> min;
            while (cin.get() != '\n');
            if (cin.fail() || min * deg < 0) {
                cout << "������������ ����.������� � ������ ������ ���� ������ �����.\n";
                cin.clear();
                continue;
            }
            Angle ang2(deg, min);
            ang2.simplify();
            if (ang > ang2) cout << ang << " > " << ang2 << endl;
            if (ang < ang2) cout << ang << " < " << ang2 << endl;
            if (ang == ang2) cout << ang << " == " << ang2 << endl;
            break;
        }
        case '6': {
            help();
            break;
        }
        case '7': {
            do {
                valid_input = true;
                cout << "������� ����: ";
                cin >> deg >> min;
                if (cin.fail() || min * deg < 0) {
                    cout << "������������ ����.\n";
                    cin.clear();
                    valid_input = false;
                }
                while (cin.get() != '\n');
            } while (!valid_input);
            ang.set(deg, min);
            ang.simplify();
            cout << "  ������� ����: " << ang << endl;
        }
        case '0': {}
        }
    } while (c != '0');
}

void help() {
    cout << "����������:\n";
    cout << " 1 ��������� � �������.\n";
    cout << " 2 ���������.\n";
    cout << " 3 ���������.\n";
    cout << " 4 �������� �����.\n";
    cout << " 5 �������� ����.\n";
    cout << " 6 ������.\n";
    cout << " 7 ������ ����� ����.\n";
    cout << " 0 �����.\n";
}

