//
// Created by 贾智超 on 2024/7/20.
//

#ifndef WORKERCLASS_H
#define WORKERCLASS_H
#include <iostream>
#include <string>
#include <memory>

class Person {
public:
    Person() = default;
    virtual ~Person() = default;

    virtual void ShowNumber() = 0;
    virtual void ShowName() = 0;
    virtual void ShowSpace() = 0;
    virtual void ShowDuty() = 0;

    virtual void write(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;

    void ChangeNumber(const int n) { number = n; }
    void ChangeName(const std::string& Name) { name = Name; }
    std::string Name() const { return name; }
    int Number() const { return number; }

    static std::unique_ptr<Person> deserialize(std::istream& is);

protected:
    enum workerkind { Worker = 1, Manager = 2, Boss = 3 };

private:
    int number{};  // 员工编号
    std::string name{};  // 员工姓名
};


class Worker : public Person {
public:
    Worker() = default;
    explicit Worker(std::istream& is) {
        int n;
        std::string Name;
        is >> n >> Name;
        ChangeNumber(n);
        ChangeName(Name);
    }

    Worker(int n, const std::string& Name) {
        ChangeNumber(n);
        ChangeName(Name);
    }

    static std::unique_ptr<Worker> fromStream(std::istream& is) {
        int n;
        std::string Name;
        is >> n >> Name;
        return std::make_unique<Worker>(n, Name);
    }

    void ShowNumber() override ;
    void ShowName() override ;
    void ShowSpace() override ;
    void ShowDuty() override ;
    void write(std::ostream& os) const override {
        os << static_cast<int>(Person::Worker) << ' ' << Number() << ' ' << Name() << '\n';
    }

    void read(std::istream& is) override ;

    ~Worker() override = default;
};

class Manager : public Person {
public:
    Manager() = default;

    explicit Manager(std::istream& is) {
        int n;
        std::string Name;
        is >> n >> Name;
        ChangeNumber(n);
        ChangeName(Name);
    }
    Manager(int n, const std::string& Name) {
        ChangeNumber(n);
        ChangeName(Name);
    }

    static std::unique_ptr<Manager> fromStream(std::istream& is) {
        int n;
        std::string Name;
        is >> n >> Name;
        return std::make_unique<Manager>(n, Name);
    }

    void ShowNumber() override ;
    void ShowName() override ;
    void ShowSpace() override ;
    void ShowDuty() override ;

    void write(std::ostream& os) const override {
        os << static_cast<int>(Person::Manager) << ' ' << Number() << ' ' << Name() << '\n';
    }

    void read(std::istream& is) override ;

    ~Manager() override = default;
};

class Boss : public Person {
public:
    Boss() = default;
    explicit Boss(std::istream& is) {
        int n;
        std::string Name;
        is >> n >> Name;
        ChangeNumber(n);
        ChangeName(Name);
    }

    Boss(int n, const std::string& Name) {
        ChangeNumber(n);
        ChangeName(Name);
    }

    static std::unique_ptr<Boss> fromStream(std::istream& is) {
        int n;
        std::string Name;
        is >> n >> Name;
        return std::make_unique<Boss>(n, Name);
    }

    void ShowNumber() override ;
    void ShowName() override ;
    void ShowSpace() override ;
    void ShowDuty() override ;

    void write(std::ostream& os) const override {
        os << static_cast<int>(Person::Boss) << ' ' << Number() << ' ' << Name() << '\n';
    }

    void read(std::istream& is) override ;

    ~Boss() override = default;
};
#endif //WORKERCLASS_H
