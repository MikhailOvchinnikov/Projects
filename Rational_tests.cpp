/*#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// Перечислимый тип для статуса задачи


TaskStatus Next(TaskStatus task_status) {
    return static_cast<TaskStatus>(static_cast<int>(task_status) + 1);
}
// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса


void RemoveZeros(TasksInfo& m)
{
    for (const auto& i : m)
    {
        if (i.second == 0)
        {
            m.erase(i.first);
        }
    }
}

class TeamTasks {
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const string& person) const
    {
        return data.at(person);
    }

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string& person)
    {
        data[person][TaskStatus::NEW]++;
    }

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
        const string& person, int task_count)
    {
        TasksInfo copy = data[person];
        TasksInfo update;
        TasksInfo old;
        for (TaskStatus status = TaskStatus::NEW; status != TaskStatus::DONE; status = Next(status))
        {
            update[Next(status)] = min(task_count, copy[status]);
            if (task_count < copy[status])
            {
                data[person][status] -= task_count;
                data[person][Next(status)] += task_count;
                old[status] = copy[status] - task_count;
                break;
            }
            else
            {
                old[status] = 0;
                data[person][status] -= copy[status];
                data[person][Next(status)] += copy[status];
                //cout << data[person][Next(status)] << endl;
                task_count -= copy[status];
            }
        }

        RemoveZeros(old);
        RemoveZeros(update);
        RemoveZeros(data[person]);

        return {update, old};
    }
private:
    map<string, TasksInfo> data;
};

void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
        ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
        ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
        ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}*/

#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
using namespace std;

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        }
        catch (exception& e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        }
        catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

class Rational {
private:
    int up_figure;
    int down_figure;
public:
    Rational() {
        up_figure = 0;
        down_figure = 1;
    }

    Rational(int numerator, int denominator) {
        if ((numerator < 0 && denominator < 0) || (numerator > 0 && denominator < 0))
        {
            numerator = -numerator;
            denominator = -denominator;
        }
        else if (numerator == 0)
        {
            denominator = 1;
        }

        int temp_n = abs(numerator);
        int temp_d = abs(denominator);
        while (temp_n > 0 && temp_d > 0)
        {
            if (temp_n > temp_d)
            {
                temp_n %= temp_d;
            }
            else
            {
                temp_d %= temp_n;
            }
        }
        up_figure = numerator / (temp_n + temp_d);
        down_figure = denominator / (temp_n + temp_d);
    

    }

    int Numerator() const {
        return up_figure;
    }

    int Denominator() const {
        return down_figure;
    }



};

bool operator==(const Rational& left, const Rational& right)
{
    return (left.Numerator() == right.Numerator() && left.Denominator() == right.Denominator());
}

Rational operator+(const Rational& left, const Rational& right)
{
    int up;
    int down;
    up = left.Numerator() * right.Denominator() + right.Numerator() * left.Denominator();
    down = left.Denominator() * right.Denominator();
    return { up, down };
}
Rational operator-(const Rational& left, const Rational& right)
{
    int up;
    int down;
    up = left.Numerator() * right.Denominator() - right.Numerator() * left.Denominator();
    down = left.Denominator() * right.Denominator();
    return { up, down };
}

Rational operator*(const Rational& left, const Rational& right)
{
    int up;
    int down;
    up = left.Numerator() * right.Numerator();
    down = left.Denominator() * right.Denominator();
    return { up, down };
}

Rational operator/(const Rational& left, const Rational& right)
{
    int up;
    int down;
    up = left.Numerator() * right.Denominator();
    down = left.Denominator() * right.Numerator();
    return { up, down };
}

istream& operator>>(istream& stream, Rational& u_d)
{
    int up;
    int down;
    char temp;
    if (stream >> up && stream >> temp && stream >> down)
    {
        if (temp == '/')
        {
            u_d = { up, down };
        }
    }
    return stream;
}

ostream& operator<<(ostream& stream, const Rational& u_d)
{
    stream << u_d.Numerator() << '/' << u_d.Denominator();
    return stream;
}

bool operator<(const Rational& f, const Rational& s)
{
    return f.Numerator() / (double)f.Denominator() < s.Numerator() / (double)s.Denominator();
}

bool operator>(const Rational& f, const Rational& s)
{
    return f.Numerator() / (double)f.Denominator() > s.Numerator() / (double)s.Denominator();
}

void WholeTest()
{
    Rational r;
    AssertEqual((r.Numerator(), r.Denominator()), (0, 1), "Test 1");
    Rational r2(2, 4);
    AssertEqual((r2.Numerator(), r2.Denominator()), (1, 2), "Test 2");
    Rational r3(3, -9);
    AssertEqual((r3.Numerator(), r3.Denominator()), (-1, 3), "Test 3");
    Rational r4(0, -9);
    AssertEqual((r4.Numerator(), r4.Denominator()), (0, 1 ), "Test 4");
    Rational r5(-6, -20);
    AssertEqual((r5.Numerator(), r5.Denominator()), (3, 10), "Test 5");

}

void AllTest()
{
    TestRunner test;
    test.RunTest(WholeTest, "General Test");
}

int main() {
    {
        AllTest();

        const set<Rational> rs = { {1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2} };
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{ {1, 25}, { 1, 2 }, { 3, 4 }}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}



