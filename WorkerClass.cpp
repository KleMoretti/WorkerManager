//
// Created by 贾智超 on 2024/7/22.
//
#include"WorkerClass.h"
#include<iostream>

// 静态成员函数实现
std::unique_ptr<Person> Person::deserialize(std::istream& is) {
        int kind;
        is >> kind;


        switch (kind) {
                case Person::Worker:
                        return Worker::fromStream(is);
                case Person::Manager:
                        return Manager::fromStream(is);
                case Person::Boss:
                        return Boss::fromStream(is);
                default:
                        throw std::runtime_error("Unknown worker kind.");
        }
}

void Worker::ShowNumber() {
        std::cout<<"The Worker's number is "<<Number()<<std::endl;
}

void Worker::ShowName() {
        std::cout<<"The Worker's Name is "<<Name()<<std::endl;
}

void Worker::ShowSpace() {
        std::cout<<"The Person's position is Worker!"<<std::endl;
}

void Worker::ShowDuty() {
        std::cout<<"The Worker's duty is complete the tasks "
                   "assigned by the manager!"<<std::endl;
}



void Worker::read(std::istream& is)  {
        int kind;
        int n;
        std::string Name;
        is >> kind >> n >> Name;

        if (kind != static_cast<int>(Person::Worker)) {
                throw std::runtime_error("Incorrect worker kind.");
        }

        ChangeNumber(n);
        ChangeName(Name);
}

void Manager::ShowNumber() {
        std::cout<<"The Manager's number is "<<Number()<<std::endl;
}

void Manager::ShowName() {
        std::cout<<"The Manager's Name is "<<Name()<<std::endl;
}

void Manager::ShowSpace() {
        std::cout<<"The Person's position is Manager!"<<std::endl;
}

void Manager::ShowDuty() {
        std::cout<<"The Manager's duty is complete the tasks assigned by the boss,"
                   " and disassemble and distribute to the staff"<<std::endl;
}



void Manager::read(std::istream& is) {
        int kind;
        int n;
        std::string Name;
        is >> kind >> n >> Name;

        if (kind != static_cast<int>(Person::Manager)) {
                throw std::runtime_error("Incorrect worker kind.");
        }

        ChangeNumber(n);
        ChangeName(Name);
}

void Boss::ShowNumber() {
        std::cout<<"The Boss's number is "<<Number()<<std::endl;
}

void Boss::ShowName() {
        std::cout<<"The Boss's Name is "<<Name()<<std::endl;
}

void Boss::ShowSpace() {
        std::cout<<"The Person's position is Boss!"<<std::endl;
}

void Boss::ShowDuty() {
        std::cout<<"The Manager's duty is overall management "
                   "of all business affairs"<<std::endl;
}



void Boss::read(std::istream& is) {
        int kind;
        int n;
        std::string Name;
        is >> kind >> n >> Name;

        if (kind != static_cast<int>(Person::Boss)) {
                throw std::runtime_error("Incorrect worker kind.");
        }

        ChangeNumber(n);
        ChangeName(Name);
}
