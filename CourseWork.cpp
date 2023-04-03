#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student
{
    string Full_Name;
    int marks[5];
    int average;
    int scholarship;
    Student* next;
    Student* sort;
};

struct Group
{
    int number;
    float value;
    Group* value_link;
    Student* link1;
    Group* link2;
};

void Console_Group_Student(Group*& Back, Student*& p)
{
    string a;
    int x, i;
    int array[5];

    cout << "Введите ФИО студента: " << endl;
    cin.ignore();
    getline(cin, a);
    if (a == "0")
    {
        Back->link1 = 0;
        return;
    }
    Back->link1 = new Student;
    p = Back->link1;

    p->Full_Name = a;

    cout << "Введите набор оценок студента за последнюю сессию: " << endl;
    for (i = 0; i < 5; i++)
    {
        cin >> array[i];
        p->marks[i] = array[i];
    }

    for (int i = 0; i < 5; i++)
    {
        p->average += p->marks[i];
    }
    p->average = p->average / 5;

    cout << "Введите размер стипендии студента: " << endl;
    cin >> x;
    p->scholarship = x;

    p->next = 0;
}

int Console_Student_Student(Student*& p)
{
    string a;
    int x, i;
    int array[5];

    cout << "Введите ФИО студента: " << endl;
    cin.ignore();
    getline(cin, a);
    if (a == "0")
    {
        p->next = 0;
        return 1;
    }
    p->next = new Student;
    p = p->next;

    p->Full_Name = a;

    cout << "Введите набор оценок студента за последнюю сессию: " << endl;
    for (i = 0; i < 5; i++)
    {
        cin >> array[i];
        p->marks[i] = array[i];
    }

    for (int i = 0; i < 5; i++)
    {
        p->average += p->marks[i];
    }
    p->average = p->average / 5;

    cout << "Введите размер стипендии студента: " << endl;
    cin >> x;
    p->scholarship = x;

    return 0;
}

int Console_Group_Group(Group*& Back)
{
    int x;

    cout << "Введите номер группы: " << endl;
    cin >> x;
    if (x == 0)
    {
        Back->link2 = 0;
        return 1;
    }
    Back->link2 = new Group;
    Back = Back->link2;

    Back->number = x;

    return 0;
}

void File_Group_Student(Group*& Back, Student*& p, ifstream& y)
{
    string a;
    int x, i;
    int array[5];

    y.ignore();
    getline(y, a);
    if (a == "0")
    {
        Back->link1 = 0;
        return;
    }
    Back->link1 = new Student;
    p = Back->link1;

    p->Full_Name = a;

    for (i = 0; i < 5; i++)
    {
        y >> array[i];
        p->marks[i] = array[i];
    }

    y >> x;
    p->scholarship = x;

    p->next = 0;
}

int File_Student_Student(Student*& p, ifstream& y)
{
    string a;
    int x, i;
    int array[5];

    y.ignore();
    getline(y, a);
    if (a == "0")
    {
        p->next = 0;
        return 1;
    }
    p->next = new Student;
    p = p->next;

    p->Full_Name = a;

    for (i = 0; i < 5; i++)
    {
        y >> array[i];
        p->marks[i] = array[i];
    }

    y >> x;
    p->scholarship = x;

    return 0;
}

int File_Group_Group(Group*& Back, ifstream& y)
{
    int x;

    y >> x;
    if (x == 0)
    {
        Back->link2 = 0;
        return 1;
    }
    Back->link2 = new Group;
    Back = Back->link2;

    Back->number = x;

    return 0;
}


void Menu() //функция вывода пунктов меню
{
    cout << "1) Консольный ввод данных о потоке" << endl;
    cout << "2) Консольный вывод данных о потоке" << endl;
    cout << "3) Добавление студента" << endl;
    cout << "4) Удаление студента" << endl;
    cout << "5) Добавление группы" << endl;
    cout << "6) Удаление группы" << endl;
    cout << "7) Файловый ввод данных о потоке" << endl;
    cout << "8) Файловый вывод данных о потоке" << endl;
    cout << "9) допольнительное задание 1" << endl;
    cout << "10) допольнительное задание 2" << endl;
    cout << "11) Выход" << endl;
}
int main()
{
    ifstream y;
    ofstream f;
    Group* Top = 0, * Back, * z = 0, * d, * TopValue = 0, * BackValue = 0;
    Student* p = 0, * t, * h, * TopSort = 0, * BackSort = 0;
    string a;
    int k1, k2, x, i, k, n = 0;
    int array[5];
    bool exit = false, flag = false;
    setlocale(0, "RUS");

    while (!exit) // пока exit не станет равна true
    {
        Menu(); //функция меню
        cin >> n;
        switch (n) {
            case 1:              //Консольный ввод данных о потоке
                if (Top != 0)
                    cout << "Вы уже произвели ввод потока" << endl;
                else
                {
                    cout << "Введите номер группы: " << endl;
                    cin >> x;
                    if (x == 0)
                    {
                        return 0;
                    }
                    Top = new Group;
                    Back = Top;
                    Back->number = x;
                    Console_Group_Student(Back, p);
                    while (1)
                    {
                        if (Back->link1 == 0) break;
                        if (Console_Student_Student(p)) break;
                    }
                    while (1)
                    {
                        if (Console_Group_Group(Back)) break;
                        Console_Group_Student(Back, p);
                        while (1)
                        {
                            if (Back->link1 == 0) break;
                            if (Console_Student_Student(p)) break;
                        }
                    }
                    cout << "Консольный ввод успешно завершен" << endl;
                }
                break;

            case 2:                //Консольный вывод данных о потоке
                if (Top == 0)
                    cout << "У вас нет данных о потоке сначала выполните консольный ввод или файловый ввод" << endl;
                else {
                    Back = Top;
                    while (Back) {
                        cout << Back->number << endl;
                        p = Back->link1;
                        while (p) {
                            cout << p->Full_Name << endl;
                            for (i = 0; i < 5; i++) {
                                cout << p->marks[i] << " ";
                            }
                            cout << "\n";
                            cout << p->scholarship << endl;
                            p = p->next;
                        }
                        Back = Back->link2;
                        cout << "\n";
                    }
                }
                break;
            case 3:                //Добавление студента
                if (Top == 0)
                    cout << "У вас нет данных о потоке сначала выполните консольный ввод или файловый ввод" << endl;
                else
                {
                    k = 0;
                    cout << "Введите номер группы в которую хотите добавить студента: " << endl;
                    cin >> x;
                    Back = Top;
                    while (Back->number != x)
                    {
                        if (Back->link2 == 0)
                        {
                            cout << "Нет группы с таким номером" << endl;
                            k = 1;
                            break;
                        }
                        Back = Back->link2;
                    }
                    if (k != 1)
                    {
                        p = Back->link1;
                        if (p == 0)
                        {
                            Console_Group_Student(Back, p);
                            if (Back->link1 == 0)
                                cout << "Операция добавления студента успешно отменена" << endl;
                            else
                                cout << "Добавление студента успешно произведено" << endl;
                        }
                        else
                        {
                            while (p->next != 0)
                            {
                                p = p->next;
                            }
                            Console_Student_Student(p);
                            if (p->next != 0)
                                cout << "Добавление студента успешно произведено" << endl;
                            else
                                cout << "Операция добавления студента успешно отменена" << endl;
                            p->next = 0;
                        }
                    }
                }
                break;
            case 4:            //Удаление студента
                if (Top == 0)
                    cout << "У вас нет данных о потоке сначала выполните консольный ввод или файловый ввод" << endl;
                else
                {
                    k = 0;
                    cout << "Введите номер группы из которой хотите удалить студента: " << endl;
                    cin >> x;
                    Back = Top;
                    while (Back->number != x)
                    {
                        if (Back->link2 == 0)
                        {
                            cout << "Нет группы с таким номером" << endl;
                            k = 1;
                            break;
                        }
                        Back = Back->link2;
                    }
                    if (k != 1)
                    {
                        p = Back->link1;
                        cout << "Введите ФИО студента, которого хотите удалить из группы: " << endl;
                        cin.ignore();
                        getline(cin, a);
                        if (Back->link1 == 0)
                        {
                            cout << "Студента с предложенным ФИО в этой группе нет" << endl;
                        }
                        while (p)
                        {
                            if (p->Full_Name == a)                                  //удаление с начала
                            {
                                p = p->next;
                                delete Back->link1;
                                Back->link1 = p;
                                cout << "Удаление студента успешно произведено" << endl;
                                break;
                            }
                            if (p->next == 0)
                            {
                                cout << "Студента с предложенным ФИО в этой группе нет" << endl;
                                break;
                            }
                            if ((p->next->Full_Name == a) && (p->next->next != 0))  //удаление с середины
                            {
                                t = p->next->next;
                                delete p->next;
                                p->next = t;
                                cout << "Удаление студента успешно произведено" << endl;
                                break;
                            }
                            if ((p->next->Full_Name == a) && (p->next->next == 0))  //удаление с конца
                            {
                                delete p->next;
                                p->next = 0;
                                cout << "Удаление студента успешно произведено" << endl;
                                break;
                            }
                            p = p->next;
                        }
                    }
                }
                break;
            case 5:            //Добавление группы
                if (Top == 0)
                    cout << "У вас нет данных о потоке сначала выполните консольный ввод или файловый ввод" << endl;
                else
                {
                    Back = Top;
                    while (Back->link2 != 0)
                    {
                        Back = Back->link2;
                    }
                    if (Console_Group_Group(Back))
                        cout << "Операция добавления группы успешно отменена" << endl;
                    else
                    {
                        cout << "Добавление группы успешно произведено" << endl;
                        Back->link1 = 0;
                        Back->link2 = 0;
                    }
                }
                break;
            case 6:      //Удаление группы
                if (Top == 0)
                    cout << "У вас нет данных о потоке сначала выполните консольный ввод или файловый ввод" << endl;
                else
                {
                    k = 0;
                    cout << "Введите номер группы, которую хотите удалить: " << endl;
                    cin >> x;
                    Back = Top;
                    while (Back->number != x)
                    {
                        if (Back->link2 == 0)
                        {
                            cout << "Нет группы с таким номером" << endl;
                            k = 1;
                            break;
                        }
                        Back = Back->link2;
                    }
                    if (k != 1)
                    {
                        if (Back->link1 != 0)                    //удаление студентов из группы если они есть
                        {
                            p = Back->link1;
                            while (p)
                            {
                                t = p->next;
                                delete p;
                                p = t;
                            }
                            Back->link1 = 0;
                        }
                        if (Back == Top)                         //удаление если группа стоит первой
                        {
                            Back = Back->link2;
                            delete Top;
                            Top = Back;
                            if (Top == 0)
                            {
                                cout << "Групп в потоке больше нет" << endl;
                            }
                            cout << "Группа удалена успешно" << endl;
                        }
                        else
                        {
                            z = Top;                             //удаление с середины или с конца
                            while (z->link2 != Back)
                            {
                                z = z->link2;
                            }
                            Back = Back->link2;
                            delete z->link2;
                            z->link2 = Back;
                            cout << "Группа удалена успешно" << endl;
                        }
                    }
                }
                break;
            case 7:                 //Файловый ввод данных о потоке
                if (Top != 0)
                    cout << "Вы уже произвели ввод потока" << endl;
                else
                {
                    y.open("Vvod.txt");

                    y >> x;
                    if (x == 0)
                    {
                        system("cls");
                        return 0;
                    }
                    Top = new Group;
                    Back = Top;
                    Back->number = x;
                    File_Group_Student(Back, p, y);
                    while (1)
                    {
                        if (Back->link1 == 0) break;
                        if (File_Student_Student(p, y)) break;
                    }
                    while (1)
                    {
                        if (File_Group_Group(Back, y)) break;
                        File_Group_Student(Back, p, y);
                        while (1)
                        {
                            if (Back->link1 == 0) break;
                            if (File_Student_Student(p, y)) break;
                        }
                    }
                    y.close();
                    cout << "Файловый ввод успешно завершен" << endl;
                }
                break;
            case 8:
                if (Top == 0)
                    cout << "У вас нет данных о потоке сначала выполните консольный ввод или файловый ввод" << endl;
                else
                {
                    f.open("Vivod.txt");
                    Back = Top;
                    while (Back)
                    {
                        f << endl;
                        f << Back->number << endl;
                        p = Back->link1;
                        while (p)
                        {
                            f << p->Full_Name << endl;
                            for (i = 0; i < 5; i++)
                            {
                                f << p->marks[i] << " ";
                            }
                            f << endl;
                            f << p->scholarship << endl;
                            p = p->next;
                        }
                        Back = Back->link2;
                    }
                    f.close();
                    cout << "Вывод в файл успешно произведен" << endl;
                }
                break;
                // дополнительное задание 1
                //Вывести в порядке роста номеров перечень всех групп потока, в которых количество студентов, не получающих стипендию, превышает заданное число
            case 9:
                cout << "Задайте количество студентов, не получающих стипендию" << endl;
                cin >> x;
                flag = false;
                Back = Top;
                while (Back)
                {
                    k1 = 0;
                    p = Back->link1;
                    while (p)
                    {
                        for (i = 0; i < 5; i++)
                        {
                            if (p->marks[i] < 4)
                            {
                                k1++;
                                break;
                            }
                        }
                        p = p->next;
                    }
                    Back->value = k1;
                    if (Back->value >= x)
                    {
                        if (TopValue == 0)
                        {
                            TopValue = Back;
                            BackValue = TopValue;
                            BackValue->value_link = 0;
                        }
                        else
                        {
                            if (Back->number <= TopValue->number)
                                flag = false;
                            while (Back->number >= BackValue->number)
                            {
                                flag = true;
                                z = BackValue;
                                BackValue = BackValue->value_link;
                                if (BackValue == 0)
                                    break;
                            }
                            if (!flag)
                            {
                                d = TopValue;
                                TopValue = Back;
                                BackValue = TopValue;
                                BackValue->value_link = d;
                            }
                            if (flag)
                            {
                                d = BackValue;
                                BackValue = Back;
                                z->value_link = BackValue;
                                BackValue->value_link = d;
                            }
                        }
                    }
                    Back = Back->link2;
                }
                BackValue = TopValue;
                cout << "\n";
                cout << "Вывод в порядке возрастания номеров тех групп, в которых количество студентов, не получающих стипендию превышает заданное значение: " << endl;
                cout << endl;
                while (BackValue)
                {
                    cout << BackValue->number << endl;
                    cout << "\n";
                    BackValue = BackValue->value_link;
                }
                break;
                // дополнительное задание 2
                //Вывести в алфавитном порядке фамилии N (вводится с клавиатуры) первых по среднему баллу студентов потока
                case 10:
                cout << "Какое количество студентов вы хотите увидеть?";
                cin >> k2;
                BackSort = TopSort = 0;
                Back = Top;
                while (Back)
                {
                    h = Back->link1;
                    while (h)
                    {
                        BackSort = TopSort;
                        if (TopSort == 0)
                        {
                            TopSort = h;
                            BackSort = TopSort;
                            BackSort->sort = 0;
                        }
                        else
                        {
                            if ((BackSort->Full_Name > h->Full_Name) && (BackSort->average == h->average))
                                flag = false;
                            else
                            {
                                while (h->average >= BackSort->average)
                                {
                                    flag = true;
                                    p = BackSort;
                                    BackSort = BackSort->sort;
                                    if (BackSort == 0)
                                        break;
                                    if ((BackSort->Full_Name > h->Full_Name) && (BackSort->average == h->average))
                                        break;
                                }

                            }
                            if (!flag)
                            {

                                t = TopSort;
                                TopSort = h;
                                BackSort = TopSort;
                                BackSort->sort = t;
                            }
                            if (flag)
                            {
                                t = BackSort;
                                BackSort = h;
                                p->sort = BackSort;
                                BackSort->sort = t;
                            }
                        }
                        h = h->next;
                    }
                    Back = Back->link2;
                }
                BackSort = TopSort;
                cout << "Вывод списка всех студентов потока, отсортированный по алфавиту и среднему баллу: " << endl;
                cout << endl;
                for(int i = 0; i < k2; i++)
                {
                    cout << BackSort->Full_Name << endl;
                    cout << BackSort->average << endl;
                    cout << "\n";
                    BackSort = BackSort->sort;
                }
                break;
                case 11:     //Выход
                    exit = true;
                break;
            default:
                break;
        }
    }
        return 0;
}