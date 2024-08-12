//
// Created by 贾智超 on 2024/7/22.
//
#include "Functions.h"

#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>
#include <fstream>
#include "WorkerClass.h"

void Exit() {
    std::cout<<"Already exit!"<<std::endl;
}

//read用于将文件中的信息重新储存到容器中
void ReadInfo(std::vector<std::unique_ptr<Person>> &loadedObjects) {
    // 从文件加载对象
    std::ifstream ifs("WokerManager.txt", std::ios::binary);
    if (!ifs.is_open()) {
        throw std::runtime_error("Could not open file for reading.");
    }

    while (ifs) {
        try {
            auto obj = Person::deserialize(ifs);
            loadedObjects.push_back(std::move(obj));
        } catch (const std::exception&) {
            break; // 如果文件结束，捕获异常并退出循环
        }
    }
    ifs.close();
}

void SaveInfo(const std::vector<std::unique_ptr<Person>> &objects) {
    // 保存到文件
    std::ofstream ofs("WorkerManager.txt", std::ios::binary);
    if (!ofs.is_open()) {
        throw std::runtime_error("Could not open file for writing.");
    }

    for (const auto& obj : objects) {
        obj->write(ofs);
    }
    ofs.close();
}


void AddInformation(std::vector<std::unique_ptr<Person>> &WInfo) {
    int n,kind;
    std::cout << "Please insert numbers of information you want to add:";
    std::cin >> n;
    std::cin .get();
    std::cout << "Please select a job position:"
              <<"\n 1. Worker"
              <<"\n 2. Manager"
              <<"\n 3. Boss"<<std::endl;
    std::cin >> kind;
    WInfo.reserve(n);
    switch (kind) {
        case 1:
            for (size_t i = 0; i < n; i++) {
                int num;
                std::string Name;
                std::cout << "Please input the serial number:";
                std::cin >>num ;
                std::cout << "Please input the name:";
                std::cin >> Name;
                WInfo.push_back(std::make_unique<Worker>(num, Name)); // 赋值
            }

            break;
        case 2:
            for (size_t i = 0; i < n; i++) {
                int num;
                std::string Name;
                std::cout << "Please input the serial number:";
                std::cin >>num ;
                std::cout << "Please input the name:";
                std::cin >> Name;
                WInfo.push_back(std::make_unique<Manager>(num, Name));// 赋值
            }

            break;
        case 3:
            for (size_t i = 0; i < n; i++) {
                int num;
                std::string Name;
                std::cout << "Please input the serial number:";
                std::cin >>num ;
                std::cout << "Please input the name:";
                std::cin >> Name;
                WInfo.push_back(std::make_unique<Boss>(num, Name)); // 赋值
            }

            break;
        default:
            std::cout << "Input Error！";
    }
    SaveInfo(WInfo);
    std::cout << "Add Information Successfully!" << std::endl;
}

void ShowInformation(std::vector<std::unique_ptr<Person>> &loadedObjects) {
    try{
        for (auto& obj : loadedObjects) {
            obj->ShowName();
            obj->ShowNumber();
            obj->ShowSpace();
            obj->ShowDuty();
        }
    }catch (const std::exception&e) {
        std::cerr << "Error"<<e.what()<<std::endl;
    }
}

void DeleteInformation(std::vector<std::unique_ptr<Person>> &Objects) {
    try {
        int choice = 1;
        while (choice)
        {
            std::cout << "Please input the info you want to delete: ";
            int num;
            std::string Name;
            std::cout << "Input number: ";
            std::cin >> num;
            std::cout << "Input Name: ";
            std::cin >> Name;
            for  (auto it = Objects.begin(); it != Objects.end(); ++it) {
                if ((*it)->Number() == num && (*it)->Name() == Name) {
                    Objects.erase(it);
                    std::cout << "Delete Successfully!" << std::endl;
                    break;
                }
            }
            std::cout << "0. Exit ";
            std::cout << "\n1. Delete" << std::endl;
            std::cout << "Input choice: ";
            std::cin >> choice;
        }
    }catch (const std::exception&e) {
        std::cerr << "Error"<<e.what()<<std::endl;
    }

}

void ModifyInformation(std::vector<std::unique_ptr<Person>> &Objects) {
    try {
        std::cout << "Modify Information" << std::endl;
        int choice,num;
        std::string Name;
        std::cout << "1. Modify Name"
                  << "\n2. Modify Number"
                  << "\n3. Modify Position"
                  << "\n"<<std::endl;
        std::cout << "Input choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
            {
                std::cout << "Please input the name you want to modify: ";
                std::cin >> Name;
                bool found=false;
                for(const auto& obj : Objects) {
                    if(obj->Name() == Name) {
                        std::cout << "Please input the new name: ";
                        std::string newName;
                        std::cin >> newName;
                        obj->ChangeName(newName);
                        found=true;
                    }
                }
                if (!found) {
                    std::cout << "No person with that name found." << std::endl;
                }
                break;
            }
            case 2: {
                std::cout << "Please input the number you want to modify: ";
                std::cin >> num;
                bool found=false;
                for(const auto& obj : Objects) {
                    if(obj->Number()==num) {
                        std::cout << "Please input the new name: ";
                        int newNum;
                        std::cin >> newNum;
                        obj->ChangeNumber(newNum);
                        found=true;
                    }
                }
                if (!found) {
                    std::cout << "No person with that number found." << std::endl;
                }
                break;
            }
            case 3: {
                std::cout << "Please input the person you want to modify: "
                        <<"\nInput name:";
                std::cin >> Name;
                std::cout << "\nInput number: ";
                std::cin >> num;
                bool found=false;
                for(auto& obj : Objects) {
                    if(obj->Number()==num && obj->Name()==Name) {
                        std::cout << "Please input the new position: ";
                        std::cout << "\n 1. Worker";
                        std::cout << "\n 2. Manager";
                        std::cout << "\n 3. Boss"<<std::endl;
                        int position;
                        std::cin >> position;
                        switch (position) {
                            case 1:
                                obj = std::make_unique<Worker>(num, Name);
                                found = true;
                                break;
                            case 2:
                                obj = std::make_unique<Manager>(num, Name);
                                found = true;
                                break;
                            case 3:
                                obj = std::make_unique<Boss>(num, Name);
                                found = true;
                                break;
                            default:
                                std::cout << "Invalid position!" << std::endl;
                            break;
                        }
                    }
                }
                if (!found) {
                    std::cout << "No person with that name and number found." << std::endl;
                }
                break;
            }
            default:
                std::cout << "Invalid choice!" << std::endl;
            break;
            }
    }catch (const std::exception&e) {
        std::cerr << "Error"<<e.what()<<std::endl;
    }

}

void FindInformation(std::vector<std::unique_ptr<Person>> &Objects) {
    try {
        std::cout << "Find Information"
                  <<"\n1. Find by Name"
                  << "\n2. Find by Number"<<std::endl;
        int choice;
        std::cout << "Input choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1: {
                std::cout << "Input the num you want to find: ";
                int num;
                bool found=false;
                std::cin >> num;
                for  (const auto& obj : Objects) {
                        if (obj->Number() == num) {
                            found=true;
                            obj->ShowNumber();
                            obj->ShowName();
                            obj->ShowSpace();
                            obj->ShowDuty();
                    }
                }
                if (!found) {
                    std::cout << "No person with that  number found." << std::endl;
                }
                break;
            }
            case 2: {
                bool found=false;
                std::cout << "Input the name you want to find: ";
                std::string Name;
                std::cin >> Name;
                for (const auto& obj : Objects) {
                    if (obj->Name() == Name) {
                        found=true;
                        obj->ShowNumber();
                        obj->ShowName();
                        obj->ShowSpace();
                        obj->ShowDuty();
                    }
                }
                if (!found) {
                    std::cout << "No person with that name and number found." << std::endl;
                }
                break;
            }
            default:
                std::cout << "Invalid choice!" << std::endl;
                break;
        }

    }catch (const std::exception&e) {
        std::cerr << "Error"<<e.what()<<std::endl;
    }
}

bool compareByNumber(const std::unique_ptr<Person>& p1, const std::unique_ptr<Person>& p2) {
    return p1->Number() < p2->Number();
}

void SortInformation(std::vector<std::unique_ptr<Person>> &Objects) {
    std::cout << "Sort Information By Number"<<std::endl;
    std::sort(Objects.begin(), Objects.end(), compareByNumber);
    ShowInformation(Objects);
}

void ClearAlltxt(std::vector<std::unique_ptr<Person>> &Objects) {
    Objects.clear();
    std::cout << "All information has been cleared." << std::endl;
}





